using Codingame.Multiplayer.UnleashTheGeek.Actions;
using Codingame.Multiplayer.UnleashTheGeek.Models;
using Codingame.Multiplayer.UnleashTheGeek.Services;

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