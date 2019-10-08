using System;

namespace Codingame.Multiplayer.UnleashTheGeek
{
	public class Coordinate
	{
		public int X;
		public int Y;
		readonly int _x;
		readonly int _y;

		public Coordinate(int x, int y)
		{
			X = x;
			Y = y;
			_x = x;
			_y = y;
		}

		public int Manhattan(Coordinate pos)
		{
			return Math.Abs(X - pos.X) + Math.Abs(Y - pos.Y);
		}

		public string ToOutput()
		{
			return $"{X} {Y}";
		}

		public bool IsSame(Coordinate pos)
		{
			return X == pos.X && Y == pos.Y;
		}

		public void Update(Coordinate pos)
		{
			Update(pos.X, pos.Y);
		}

		public void Update(int x, int y)
		{
			X = x;
			Y = y;
		}

		public void Reset()
		{
			X = _x;
			Y = _y;
		}
	}
}