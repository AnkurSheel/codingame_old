using System.Collections.Generic;
using System.Linq;

using Codingame.Multiplayer.UnleashTheGeek.Actions;
using Codingame.Multiplayer.UnleashTheGeek.Models;

namespace Codingame.Multiplayer.UnleashTheGeek.Services
{
	public class DigService
	{
		public static List<MCDigAction> FindPossibleDigLocations(Robot robot, Game game)
		{
			return game.OreTiles.OrderBy(t => MoveService.MoveTime(robot.Position, t.Position)).Take(10)
				.Select(t => new MCDigAction(robot, game, t)).ToList();
		}
	}
}