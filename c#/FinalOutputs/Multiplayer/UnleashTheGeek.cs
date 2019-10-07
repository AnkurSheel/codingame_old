using System;
using Codingame.Multiplayer.UnleashTheGeek.Models;
using Codingame.Multiplayer.UnleashTheGeek;
using System.Collections.Generic;
using System.Linq;
using Codingame.Multiplayer.UnleashTheGeek.Actions;


 // 08/10/2019 11:40


namespace Codingame.Multiplayer.UnleashTheGeek
{
	public static class Constants
	{
		public static int Height;
		public static int Width;
		public static Random RND = new Random(100);
	}
}

namespace Codingame.Multiplayer.UnleashTheGeek
{
	public class Coordinate
	{
		public int X;
		public int Y;

		public Coordinate(int x, int y)
		{
			X = x;
			Y = y;
		}

		public int Mannattan(Coordinate pos)
		{
			return Math.Abs(X - pos.X) + Math.Abs(Y - pos.Y);
		}
	}
}

namespace Codingame.Multiplayer.UnleashTheGeek
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

			game.Players[0].Score = int.Parse(inputs[0]); // Amount of ore delivered
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
			game.Players[0].RadarCooldown = int.Parse(inputs[1]); // turns left until a new radar can be requested
			game.Players[0].TrapCooldown = int.Parse(inputs[2]); // turns left until a new trap can be requested

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
					game.Players[type].Robots.Add(new Robot(id, x, y, item));
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

class Player
{
	static void Main()
	{
		InputService.ReadInitialData();

		// game loop
		while (true)
		{
			var game = InputService.ReadGame();

			var output = new ReactAgent(game).Think();

			for (var i = 0; i < 5; i++)
			{
				Console.WriteLine(output[i].GetOutput()); // WAIT|MOVE x y|DIG x y|REQUEST item
			}
		}
	}
}

namespace Codingame.Multiplayer.UnleashTheGeek
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
			return _game.Players[0].Robots.Select(r => new RandomDigAction(r, _game)).OfType<IAction>().ToList();
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
	public class RandomDigAction : IAction
	{
		readonly Robot _robot;
		readonly Game _game;

		public RandomDigAction(Robot robot, Game game)
		{
			_robot = robot;
			_game = game;
		}

		public void Apply()
		{
			throw new NotImplementedException();
		}

		public string GetOutput()
		{
			if (_robot.HasOre)
			{
				return "MOVE 0 " + _robot.Position.Y;
			}

			if (_robot.Position.X > 10)
			{
				var tile = _game.GetTile(_robot.Position);
				var digLocation = tile.NeighBours[Constants.RND.Next(0, tile.NeighBours.Count)];
				return "DIG " + digLocation.Position.X + " " + digLocation.Position.Y;
			}

			return "MOVE " + Constants.RND.Next(4, Constants.Width) + " " + Constants.RND.Next(1, Constants.Height - 2);
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
namespace Codingame.Multiplayer.UnleashTheGeek.Models
{
	public class Game
	{
		public Player[] Players = {new Player(), new Player()};
		public Tile[,] Board = new Tile[Constants.Width, Constants.Height];
		public static int[] dx = {0, 0, -1, 1};
		public static int[] dy = {-1, 1, 0, 0};

		public Game()
		{
			for (var x = 0; x < Constants.Width; x++)
			{
				for (var y = 0; y < Constants.Height; y++)
				{
					Board[x, y] = new Tile(x, y);
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
		public int Score;
		public int RadarCooldown;
		public int TrapCooldown;
		public List<Robot> Robots = new List<Robot>();
		public List<Coordinate> Radars = new List<Coordinate>();
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
		public Coordinate Position;
		public RobotItem Item;

		public bool HasOre => Item == RobotItem.ORE;


		public Robot(int id, int x, int y, int item)
		{
			Id = id;
			Position = new Coordinate(x, y);

			Item = (RobotItem) item;
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

		public Tile(int x, int y)
		{
			Position = new Coordinate(x, y);
		}

		public void Update(bool hole, string ore)
		{
			if (!ore.Equals("?"))
			{
				Ore = int.Parse(ore);
				HasHole = hole;
				IsSeen = true;
			}
		}
	}
}