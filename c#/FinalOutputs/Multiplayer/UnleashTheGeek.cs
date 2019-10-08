using System;
using Codingame.Multiplayer.UnleashTheGeek;
using Codingame.Multiplayer.UnleashTheGeek.Agents;
using Codingame.Multiplayer.UnleashTheGeek.Services;
using System.Linq;
using Codingame.Multiplayer.UnleashTheGeek.Models;
using Codingame.Multiplayer.UnleashTheGeek.Actions;
using System.Collections.Generic;
using System.Diagnostics;
using Codingame.Multiplayer.UnleashTheGeek.a;


 // 09/10/2019 09:08


namespace Codingame.Multiplayer.UnleashTheGeek
{
	public static class Constants
	{
		public static int Height;
		public static int Width;
		public static Random RND = new Random(100);
		public static int SimulationDepth = 20;
		public static int SearchDepth = 20;
	}
}

namespace Codingame.Multiplayer.UnleashTheGeek
{
	public class Coordinate
	{
		public int X;
		public int Y;
		readonly int _x;
		readonly int _y;

		public Coordinate(int x, int y)
		{
			X = x;
			Y = y;
			_x = x;
			_y = y;
		}

		public int Manhattan(Coordinate pos)
		{
			return Math.Abs(X - pos.X) + Math.Abs(Y - pos.Y);
		}

		public string ToOutput()
		{
			return $"{X} {Y}";
		}

		public bool IsSame(Coordinate pos)
		{
			return X == pos.X && Y == pos.Y;
		}

		public void Update(Coordinate pos)
		{
			Update(pos.X, pos.Y);
		}

		public void Update(int x, int y)
		{
			X = x;
			Y = y;
		}

		public void Reset()
		{
			X = _x;
			Y = _y;
		}
	}
}

class Player
{
	static void Main()
	{
		InputService.ReadInitialData();

		// game loop
		while (true)
		{
			var game = InputService.ReadGame();

			game.OnRound();
			var output = new MCAgent(game).Think();

			for (var i = 0; i < 5; i++)
			{
				Console.WriteLine(output[i].GetOutput()); // WAIT|MOVE x y|DIG x y|REQUEST item
			}
		}
	}
}

namespace Codingame.Multiplayer.UnleashTheGeek.Actions
{
	public class DigClosestAction : IAction
	{
		readonly Robot _robot;
		readonly Game _game;

		public DigClosestAction(Robot robot, Game game)
		{
			_robot = robot;
			_game = game;
		}

		public void Apply()
		{
		}

		public string GetOutput()
		{
			if (_robot.HasOre)
			{
				return "MOVE 0 " + _robot.Position.Y;
			}

			var targetOre = _game.OreTiles.OrderBy(t => t.Position.Manhattan(_robot.Position)).FirstOrDefault();
			if (targetOre == null)
			{
				return "MOVE " + GetRandomPosition().ToOutput();
			}

			return "DIG " + targetOre.Position.ToOutput();
		}

		Coordinate GetRandomPosition()
		{
			if (_robot.Position.X > 10)
			{
				var tile = _game.GetTile(_robot.Position);
				var digLocation = tile.NeighBours[Constants.RND.Next(0, tile.NeighBours.Count)];
				return digLocation.Position;
			}

			return new Coordinate(Constants.RND.Next(4, Constants.Width), Constants.RND.Next(1, Constants.Height - 2));
		}
	}
}
namespace Codingame.Multiplayer.UnleashTheGeek.Actions
{
	public interface IAction
	{
		void Apply();
		string GetOutput();
	}
}

namespace Codingame.Multiplayer.UnleashTheGeek.Actions
{
	public class MCDigAction : IAction
	{
		readonly Robot _robot;
		readonly Game _game;
		public Tile _tile;

		public MCDigAction(Robot robot, Game game, Tile tile)
		{
			_robot = robot;
			_game = game;
			_tile = tile;
		}

		public void Apply()
		{
			var time = _robot.Time;
			var moveTime = MoveService.MoveTime(_robot.Position, _tile.Position);
			var backToStart = MoveService.MoveTime(_tile.Position, _game.Board[0, _tile.Position.Y].Position);
			if (time + moveTime < Constants.SimulationDepth)
			{
				_tile.ArrivalTimers[_robot.Player.Id, time + moveTime]++;
			}
			_robot.Time += moveTime + backToStart;
			_robot.Position.Update(_game.Board[0, _tile.Position.Y].Position);
		}

		public string GetOutput()
		{
			return "DIG " + _tile.Position.ToOutput();
		}
	}
}

namespace Codingame.Multiplayer.UnleashTheGeek.a
{
	public class PlaceRadarAction : IAction
	{
		readonly Robot _robot;
		readonly Game _game;

		public PlaceRadarAction(Robot robot, Game game)
		{
			_robot = robot;
			_game = game;
		}

		public void Apply()
		{
		}

		public string GetOutput()
		{
			if (!_robot.HasRadar)
			{
				if (_robot.Position.X == 0)
				{
					return "REQUEST RADAR";
				}

				return "MOVE 0 " + _robot.Position.Y;
			}

			var radarTile = RadarService.GetBestRadarLocation(_game);
			return "DIG " + radarTile.ToOutput();
		}
	}
}
namespace Codingame.Multiplayer.UnleashTheGeek.Actions
{
	public class WaitAction : IAction
	{
		public void Apply()
		{
		}

		public string GetOutput()
		{
			return "WAIT";
		}
	}
}


namespace Codingame.Multiplayer.UnleashTheGeek.Agents
{
	public class MCAgent
	{
		readonly Game _game;
		readonly List<Robot> _robots;

		public MCAgent(Game game)
		{
			_game = game;
			_robots = _game.Players[0].Robots;
		}

		public List<IAction> Think()
		{
			var output = new IAction[5];
			output[0] = new PlaceRadarAction(_game.Players[0].Robots[0], _game);
			var noActionRobots = new List<Robot>();
			for (var i = 1; i < 5; i++)
			{
				var robot = _robots[i];
				if (robot.HasOre || _game.OreTiles.Count == 0 || robot.IsDead)
				{
					output[i] = new DigClosestAction(robot, _game);
				}
				else
				{
					noActionRobots.Add(robot);
				}
			}

			if (noActionRobots.Any())
			{
				var actions = Search(noActionRobots);
				foreach (var robot in noActionRobots)
				{
					var index = noActionRobots.IndexOf(robot);
					var realIndex = _robots.IndexOf(robot);
					output[realIndex] = actions[index];
				}
			}

			return output.ToList();
		}

		private List<IAction> Search(List<Robot> robots)
		{
			foreach (var robot in robots)
			{
				robot.PossibleActions = DigService.FindPossibleDigLocations(robot, _game);
			}

			var best = new Solution(robots);
			Score(best);
            Console.Error.WriteLine($"First Score: {best.Score}");
			var stopWatch = Stopwatch.StartNew();
			var simulations = 0;
			while (stopWatch.ElapsedMilliseconds < 40)
			{
				simulations++;
				var solution = new Solution(robots);
				Score(solution);
				if (solution.Score > best.Score)
				{
					best = solution;
				}
			}

			Console.Error.WriteLine($"Simulations : {simulations} Time: {stopWatch.ElapsedMilliseconds} Score: {best.Score}");
			return best.DigActions.Select(d => d.First()).OfType<IAction>().ToList();
		}

		public void Score(Solution solution)
		{
			_game.Reset();
			foreach (var actions in solution.DigActions)
			{
				foreach (var digAction in actions)
				{
					digAction.Apply();
				}
			}

			foreach (var oreTile in _game.OreTiles)
			{
				oreTile.Simulate(_game);
			}

			solution.Score = _game.Players[0].Score;
		}

		public class Solution
		{
			public List<MCDigAction>[] DigActions;
			public double Score;

			public Solution(List<Robot> robots)
			{
				DigActions = robots.Select(r => new List<MCDigAction>()).ToArray();
				for (var i = 0; i < robots.Count; i++)
				{
					var robot = robots[i];
					for (var j = 0; j < Constants.SearchDepth; j++)
					{
						var selectedAction = robot.PossibleActions[Constants.RND.Next(robot.PossibleActions.Count)];
						DigActions[i].Add(selectedAction);
					}
				}
			}
		}
	}
}


namespace Codingame.Multiplayer.UnleashTheGeek.Agents
{
	public class ReactAgent
	{
		readonly Game _game;

		public ReactAgent(Game game)
		{
			_game = game;
		}

		public List<IAction> Think()
		{
			var output = _game.Players[0].Robots.Select(r => new DigClosestAction(r, _game)).OfType<IAction>().ToList();
			output[0] = new PlaceRadarAction(_game.Players[0].Robots[0], _game);

			return output;
		}
	}
}

namespace Codingame.Multiplayer.UnleashTheGeek.Models
{
	public class Game
	{
		public Player[] Players = {new Player(0), new Player(1)};
		public Tile[,] Board = new Tile[Constants.Width, Constants.Height];

		static readonly int[] dx = {0, 0, -1, 1};
		static readonly int[] dy = {-1, 1, 0, 0};

		public List<Tile> AllTiles = new List<Tile>();
		public List<Tile> OreTiles = new List<Tile>();

		public Game()
		{
			for (var x = 0; x < Constants.Width; x++)
			{
				for (var y = 0; y < Constants.Height; y++)
				{
					Board[x, y] = new Tile(x, y);
					AllTiles.Add(Board[x, y]);
				}
			}

			for (var x = 0; x < Constants.Width; x++)
			{
				for (var y = 0; y < Constants.Height; y++)
				{
					FindNeighbours(Board[x, y]);
				}
			}
		}

		public Tile GetTile(Coordinate position)
		{
			return Board[position.X, position.Y];
		}

		public void OnRound()
		{
			OreTiles = AllTiles.Where(t => t.Ore > 0).ToList();
		}

		public void Reset()
		{
			Players[0].Reset();
			Players[1].Reset();
			foreach (var tile in AllTiles)
			{
				tile.Reset();
			}
		}

		void FindNeighbours(Tile tile)
		{
			for (var i = 0; i < 4; i++)
			{
				var x = tile.Position.X + dx[i];
				var y = tile.Position.Y + dy[i];
				if (OnBoard(x, y))
				{
					tile.NeighBours.Add(Board[x, y]);
				}
			}
		}

		bool OnBoard(int x, int y)
		{
			return x >= 0 && x < Constants.Width && y >= 0 && y < Constants.Height;
		}

		bool OnBoard(Coordinate position)
		{
			return OnBoard(position.X, position.Y);
		}
	}
}

namespace Codingame.Multiplayer.UnleashTheGeek.Models
{
	public class Player
	{
		public int Id;
		public int Score;
		public int RadarCooldown;
		public int TrapCooldown;
		public List<Robot> Robots = new List<Robot>();
		public List<Coordinate> Radars = new List<Coordinate>();
		int _score;

		public Player(int id)
		{
			Id = id;
		}

		public void Update(int score, int radarCooldown, int trapCooldown)
		{
			Score = score;
			_score = score;
			RadarCooldown = radarCooldown;
			TrapCooldown = trapCooldown;
		}

		public void Reset()
		{
			Score = _score;
			foreach (var robot in Robots)
			{
				robot.Reset();
			}
		}
	}
}

namespace Codingame.Multiplayer.UnleashTheGeek.Models
{
	public enum RobotItem
	{
		NONE = -1,
		RADAR = 2,
		TRAP = 3,
		ORE = 4
	}

	public class Robot
	{
		public int Id;
		public Player Player;
		public Coordinate Position;
		public RobotItem Item;
		public int Time;
		public List<MCDigAction> PossibleActions = new List<MCDigAction>();

		public bool IsDead => Position.X == -1;
		public bool HasOre => Item == RobotItem.ORE;
		public bool HasRadar => Item == RobotItem.RADAR;


		public Robot(int id, int x, int y, int item, Player player)
		{
			Id = id;
			Player = player;
			Position = new Coordinate(x, y);
			Item = (RobotItem) item;
		}

		public void Reset()
		{
			Time = 0;
			Position.Reset();
		}
	}
}

namespace Codingame.Multiplayer.UnleashTheGeek.Models
{
	public class Tile
	{
		public int Ore;
		public bool HasHole;
		public bool HasTrap;
		public bool IsSeen;
		public Coordinate Position;
		public List<Tile> NeighBours = new List<Tile>();
		public int[,] ArrivalTimers = new int[2, Constants.SimulationDepth];

        int _simulateOre;

		public Tile(int x, int y)
		{
			Position = new Coordinate(x, y);
        }

		public void Update(bool hole, string ore)
		{
			if (!ore.Equals("?"))
			{
				Ore = int.Parse(ore);
				IsSeen = true;
			}
            else
            {
                Ore = 0;
            }
            _simulateOre = Ore;
            HasHole = hole;

        }

        public void Simulate(Game game)
		{
			for (var i = 0; i < Constants.SimulationDepth; i++)
			{
				if (Ore <= 0)
				{
					return;
				}

				while ((ArrivalTimers[0, i] > 0 || ArrivalTimers[1, i] > 0) && Ore > 0)
				{
					for (var j = 0; j < 2; j++)
					{
						if (ArrivalTimers[j, i]-- > 0)
						{
							game.Players[j].Score += Constants.SimulationDepth - i + 1;
						}
					}
				}
			}
		}

		public void Reset()
		{
			Ore = _simulateOre;
			for (var i = 0; i < Constants.SimulationDepth; i++)
			{
				ArrivalTimers[0, i] = 0;
				ArrivalTimers[1, i] = 0;
			}
		}
	}
}


namespace Codingame.Multiplayer.UnleashTheGeek.Services
{
	public class DigService
	{
		public static List<MCDigAction> FindPossibleDigLocations(Robot robot, Game game)
		{
			return game.OreTiles.OrderBy(t => MoveService.MoveTime(robot.Position, t.Position)).Take(10)
				.Select(t => new MCDigAction(robot, game, t)).ToList();
		}
	}
}


namespace Codingame.Multiplayer.UnleashTheGeek.Services
{
	public static class InputService
	{
		public static void ReadInitialData()
		{
			string[] inputs;
			inputs = Console.ReadLine().Split(' ');
			Constants.Width = int.Parse(inputs[0]);
			Constants.Height = int.Parse(inputs[1]);
			// size of the map
		}

		public static Game ReadGame()
		{
			var game = new Game();
			var inputs = Console.ReadLine().Split(' ');

			game.Players[1].Score = int.Parse(inputs[1]);
			for (var i = 0; i < Constants.Height; i++)
			{
				inputs = Console.ReadLine().Split(' ');
				for (var j = 0; j < Constants.Width; j++)
				{
					var ore = inputs[2 * j]; // amount of ore or "?" if unknown
					var hole = int.Parse(inputs[2 * j + 1]); // 1 if cell has a hole
					game.Board[j, i].Update(hole == 1, ore);
				}
			}

			inputs = Console.ReadLine().Split(' ');
			var entityCount = int.Parse(inputs[0]); // number of entities visible to you
			game.Players[0].Update(int.Parse(inputs[0]), int.Parse(inputs[1]), int.Parse(inputs[2]));
			for (var i = 0; i < entityCount; i++)
			{
				inputs = Console.ReadLine().Split(' ');
				var id = int.Parse(inputs[0]); // unique id of the entity
				var type = int.Parse(inputs[1]); // 0 for your robot, 1 for other robot, 2 for radar, 3 for trap
				var x = int.Parse(inputs[2]);
				var y = int.Parse(inputs[3]); // position of the entity
				var
					item = int.Parse(
						inputs[4]); // if this entity is a robot, the item it is carrying (-1 for NONE, 2 for RADAR, 3 for TRAP, 4 for ORE)
				if (type < 2)
				{
					game.Players[type].Robots.Add(new Robot(id, x, y, item, game.Players[type]));
				}
				else if (type == 2)
				{
					game.Players[0].Radars.Add(new Coordinate(x, y));
				}
				else if (type == 3)
				{
					game.Board[x, y].HasTrap = true;
				}
			}

			return game;
		}
	}
}
namespace Codingame.Multiplayer.UnleashTheGeek.Services
{
	public class MoveService
	{
		public static int MoveTime(Coordinate start, Coordinate target)
		{
			if (target.IsSame(start))
			{
				return 0;
			}

			return target.Manhattan(start) / 4 + 1;
		}
	}
}


namespace Codingame.Multiplayer.UnleashTheGeek.Services
{
	public class RadarService
	{
		public static List<Tile> GetUnknownPosition(Game game)
		{
			return game.AllTiles.Where(t => !t.IsSeen).ToList();
		}

		public static Coordinate GetBestRadarLocation(Game game)
		{
			var unknown = GetUnknownPosition(game);
			return unknown.OrderByDescending(tile => unknown.Count(other => InRange(tile, other))).FirstOrDefault()
				       ?.Position ?? new Coordinate(0, 0);
		}

		public static bool InRange(Tile tile, Tile otherTile)
		{
			return tile.Position.Manhattan(otherTile.Position) <= 4;
		}
	}
}