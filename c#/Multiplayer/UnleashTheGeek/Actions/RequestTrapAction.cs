using Codingame.Multiplayer.UnleashTheGeek.Models;

namespace Codingame.Multiplayer.UnleashTheGeek.Actions
{
	public class RequestTrapAction : IAction
	{
		readonly Robot _robot;

		public RequestTrapAction(Robot robot)
		{
			_robot = robot;
		}

		public void Apply()
		{
		}

		public string GetOutput()
		{
			return "REQUEST TRAP";
		}
	}
}