using System;

namespace Codingame.Multiplayer.UnleashTheGeek
{
	public class Coordinate
	{
		public int X;
		public int Y;

		public Coordinate(int x, int y)
		{
			X = x;
			Y = y;
		}

		public int Mannattan(Coordinate pos)
		{
			return Math.Abs(X - pos.X) + Math.Abs(Y - pos.Y);
		}

		public string ToOutput()
		{
			return $"{X} {Y}";
		}
	}
}