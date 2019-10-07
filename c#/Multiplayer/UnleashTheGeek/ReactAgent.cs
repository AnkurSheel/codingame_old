using System.Collections.Generic;
using Codingame.Multiplayer.UnleashTheGeek.Actions;
using Codingame.Multiplayer.UnleashTheGeek.Models;

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
			return new List<IAction>
				{
					new WaitAction(),
					new WaitAction(),
					new WaitAction(),
					new WaitAction(),
					new WaitAction()
				};
		}
	}
}