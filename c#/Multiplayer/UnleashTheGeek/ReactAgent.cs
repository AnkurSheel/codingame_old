using System.Collections.Generic;
using System.Linq;
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
			return _game.Players[0].Robots.Select(r => new RandomDigAction(r, _game)).OfType<IAction>().ToList();
		}
	}
}