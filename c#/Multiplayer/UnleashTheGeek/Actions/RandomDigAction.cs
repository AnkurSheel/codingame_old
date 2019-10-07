using System;
using Codingame.Multiplayer.UnleashTheGeek.Models;

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