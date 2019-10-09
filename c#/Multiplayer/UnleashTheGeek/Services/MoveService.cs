﻿namespace Codingame.Multiplayer.UnleashTheGeek.Services
{
	public class MoveService
	{
		public static int MoveTime(Coordinate start, Coordinate target)
		{
			if (target.Manhattan(start) <= 1)
			{
				return 0;
			}

			return target.Manhattan(start) / 4 + 1;
		}
	}
}