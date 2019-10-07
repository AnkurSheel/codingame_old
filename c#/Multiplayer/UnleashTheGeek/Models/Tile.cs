using System.Collections.Generic;

namespace Codingame.Multiplayer.UnleashTheGeek.Models
{
	public class Tile
	{
		public int Ore;
		public bool HasHole;
		public bool HasTrap;
		public bool IsSeen;
		public Coordinate Position;
		public List<Tile> NeighBours = new List<Tile>();

		public Tile(int x, int y)
		{
			Position = new Coordinate(x, y);
		}

		public void Update(bool hole, string ore)
		{
			if (!ore.Equals("?"))
			{
				Ore = int.Parse(ore);
				HasHole = hole;
				IsSeen = true;
			}
		}
	}
}