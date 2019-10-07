﻿namespace Codingame.Multiplayer.UnleashTheGeek.Models
{
	public class Game
	{
		public Player[] Players = {new Player(), new Player()};
		public Tile[,] Board = new Tile[Constants.Width, Constants.Height];
		public static int[] dx = {0, 0, -1, 1};
		public static int[] dy = {-1, 1, 0, 0};

		public Game()
		{
			for (var x = 0; x < Constants.Width; x++)
			{
				for (var y = 0; y < Constants.Height; y++)
				{
					Board[x, y] = new Tile(x, y);
				}
			}

			for (var x = 0; x < Constants.Width; x++)
			{
				for (var y = 0; y < Constants.Height; y++)
				{
					FindNeighbours(Board[x, y]);
				}
			}
		}

		public Tile GetTile(Coordinate position)
		{
			return Board[position.X, position.Y];
		}

		void FindNeighbours(Tile tile)
		{
			for (var i = 0; i < 4; i++)
			{
				var x = tile.Position.X + dx[i];
				var y = tile.Position.Y + dy[i];
				if (OnBoard(x, y))
				{
					tile.NeighBours.Add(Board[x, y]);
				}
			}
		}

		bool OnBoard(int x, int y)
		{
			return x >= 0 && x < Constants.Width && y >= 0 && y < Constants.Height;
		}

		bool OnBoard(Coordinate position)
		{
			return OnBoard(position.X, position.Y);
		}
	}
}