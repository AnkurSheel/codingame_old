using System.Collections.Generic;
using System.Linq;

using Codingame.Multiplayer.UnleashTheGeek.Models;

namespace Codingame.Multiplayer.UnleashTheGeek.Services
{
	public class RadarService
	{
		public static List<Tile> GetUnknownPosition(Game game)
		{
			return game.AllTiles.Where(t => !t.IsSeen).ToList();
		}

		public static Coordinate GetBestRadarLocation(Game game)
		{
			var unknown = GetUnknownPosition(game);
			return unknown.OrderByDescending(tile => unknown.Count(other => InRange(tile, other))).FirstOrDefault()
				       ?.Position ?? new Coordinate(0, 0);
		}

		public static bool InRange(Tile tile, Tile otherTile)
		{
			return tile.Position.Manhattan(otherTile.Position) <= 4;
		}
	}
}