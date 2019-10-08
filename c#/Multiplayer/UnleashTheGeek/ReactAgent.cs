using System.Collections.Generic;
using System.Linq;
using Codingame.Multiplayer.UnleashTheGeek.a;
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
			var output = _game.Players[0].Robots.Select(r => new DigClosestAction(r, _game)).OfType<IAction>().ToList();
			output[0] = new PlaceRadarAction(_game.Players[0].Robots[0], _game);

			return output;
		}
	}
}