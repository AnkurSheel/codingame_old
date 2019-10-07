using System;


 // 07/10/2019 05:12


/**
 * Deliver more ore to hq (left side of the map) than your opponent. Use radars to find ore but beware of traps!
 **/
class Player
{
	static void Main(string[] args)
	{
		string[] inputs;
		inputs = Console.ReadLine().Split(' ');
		var width = int.Parse(inputs[0]);
		var height = int.Parse(inputs[1]); // size of the map

		// game loop
		while (true)
		{
			inputs = Console.ReadLine().Split(' ');
			var myScore = int.Parse(inputs[0]); // Amount of ore delivered
			var opponentScore = int.Parse(inputs[1]);
			for (var i = 0; i < height; i++)
			{
				inputs = Console.ReadLine().Split(' ');
				for (var j = 0; j < width; j++)
				{
					var ore = inputs[2 * j]; // amount of ore or "?" if unknown
					var hole = int.Parse(inputs[2 * j + 1]); // 1 if cell has a hole
				}
			}

			inputs = Console.ReadLine().Split(' ');
			var entityCount = int.Parse(inputs[0]); // number of entities visible to you
			var radarCooldown = int.Parse(inputs[1]); // turns left until a new radar can be requested
			var trapCooldown = int.Parse(inputs[2]); // turns left until a new trap can be requested
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
			}

			for (var i = 0; i < 5; i++)
			{
				// Write an action using Console.WriteLine()
				// To debug: Console.Error.WriteLine("Debug messages...");

				Console.WriteLine("WAIT"); // WAIT|MOVE x y|DIG x y|REQUEST item
			}
		}
	}
}