﻿using Codingame.Multiplayer.UnleashTheGeek.Models;

namespace Codingame.Multiplayer.UnleashTheGeek.Actions
{
	public class MoveToBaseAction : IAction
	{
		readonly Robot _robot;

		public MoveToBaseAction(Robot robot)
		{
			_robot = robot;
		}

		public void Apply()
		{
		}

		public string GetOutput()
		{
			return "MOVE 0 " + _robot.Position.Y;
		}
	}
}