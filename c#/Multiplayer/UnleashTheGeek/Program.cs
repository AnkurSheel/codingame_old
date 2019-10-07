using System;
using Codingame.Multiplayer.UnleashTheGeek;

class Player
{
	static void Main()
	{
		InputService.ReadInitialData();

		// game loop
		while (true)
		{
			var game = InputService.ReadGame();

			var output = new ReactAgent(game).Think();

			for (var i = 0; i < 5; i++)
			{
				Console.WriteLine(output[i].GetOutput()); // WAIT|MOVE x y|DIG x y|REQUEST item
			}
		}
	}
}