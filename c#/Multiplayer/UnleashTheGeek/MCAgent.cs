using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using Codingame.Multiplayer.UnleashTheGeek.a;
using Codingame.Multiplayer.UnleashTheGeek.Actions;
using Codingame.Multiplayer.UnleashTheGeek.Models;

namespace Codingame.Multiplayer.UnleashTheGeek
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