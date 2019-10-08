using System;
using Codingame.Multiplayer.UnleashTheGeek.Models;
using Codingame.Multiplayer.UnleashTheGeek.Services;

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