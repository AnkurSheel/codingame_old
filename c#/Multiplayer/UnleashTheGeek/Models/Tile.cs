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
		public int[,] ArrivalTimers = new int[2, Constants.SimulationDepth];

		int _simulateOre;

		public Tile(int x, int y)
		{
			Position = new Coordinate(x, y);
		}

		public void Update(bool hole, string ore)
		{
			if (!ore.Equals("?"))
			{
				Ore = int.Parse(ore);
				IsSeen = true;
			}
			else
			{
				Ore = 0;
			}

			_simulateOre = Ore;
			HasHole = hole;
		}

		public void Simulate(Game game)
		{
			for (var i = 0; i < Constants.SimulationDepth; i++)
			{
				if (Ore <= 0)
				{
					return;
				}

				while ((ArrivalTimers[0, i] > 0 || ArrivalTimers[1, i] > 0) && Ore > 0)
				{
					for (var j = 0; j < 2; j++)
					{
						if (ArrivalTimers[j, i]-- > 0)
						{
							game.Players[j].Score += Constants.SimulationDepth - i + 1;
						}
					}
				}
			}
		}

		public void Reset()
		{
			Ore = _simulateOre;
			for (var i = 0; i < Constants.SimulationDepth; i++)
			{
				ArrivalTimers[0, i] = 0;
				ArrivalTimers[1, i] = 0;
			}
		}
	}
}