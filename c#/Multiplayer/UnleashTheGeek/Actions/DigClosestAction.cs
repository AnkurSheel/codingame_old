using System.Linq;
using Codingame.Multiplayer.UnleashTheGeek.Models;

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