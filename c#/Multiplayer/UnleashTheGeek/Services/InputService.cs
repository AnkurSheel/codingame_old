using System;

using Codingame.Multiplayer.UnleashTheGeek.Models;

namespace Codingame.Multiplayer.UnleashTheGeek.Services
{
	public static class InputService
	{
		public static void ReadInitialData()
		{
			string[] inputs;
			inputs = Console.ReadLine().Split(' ');
			Constants.Width = int.Parse(inputs[0]);
			Constants.Height = int.Parse(inputs[1]);
			// size of the map
		}

		public static Game ReadGame()
		{
			var game = new Game();
			var inputs = Console.ReadLine().Split(' ');

			game.Players[1].Score = int.Parse(inputs[1]);
			for (var i = 0; i < Constants.Height; i++)
			{
				inputs = Console.ReadLine().Split(' ');
				for (var j = 0; j < Constants.Width; j++)
				{
					var ore = inputs[2 * j]; // amount of ore or "?" if unknown
					var hole = int.Parse(inputs[2 * j + 1]); // 1 if cell has a hole
					game.Board[j, i].Update(hole == 1, ore);
				}
			}

			inputs = Console.ReadLine().Split(' ');
			var entityCount = int.Parse(inputs[0]); // number of entities visible to you
			game.Players[0].Update(int.Parse(inputs[0]), int.Parse(inputs[1]), int.Parse(inputs[2]));
			for (var i = 0; i < entityCount; i++)
			{
				inputs = Console.ReadLine().Split(' ');
				var id = int.Parse(inputs[0]); // unique id of the entity
				var type = int.Parse(inputs[1]); // 0 for your robot, 1 for other robot, 2 for radar, 3 for trap
				var x = int.Parse(inputs[2]);
				var y = int.Parse(inputs[3]); // position of the entity
				var
					item = int.Parse(
						inputs[4]); // if this entity is a robot, the item it is carrying (-1 for NONE, 2 for RADAR, 3 for TRAP, 4 for ORE)
				if (type < 2)
				{
					game.Players[type].Robots.Add(new Robot(id, x, y, item, game.Players[type]));
				}
				else if (type == 2)
				{
					game.Players[0].Radars.Add(new Coordinate(x, y));
				}
				else if (type == 3)
				{
					game.Board[x, y].HasTrap = true;
				}
			}

			return game;
		}
	}
}