using System;
using Codingame.Multiplayer.UnleashTheGeek;
using Codingame.Multiplayer.UnleashTheGeek.Agents;
using Codingame.Multiplayer.UnleashTheGeek.Services;

class Player
{
	static void Main()
	{
		InputService.ReadInitialData();

		// game loop
		while (true)
		{
			var game = InputService.ReadGame();

			game.OnRound();
			var output = new MCAgent(game).Think();

			for (var i = 0; i < 5; i++)
			{
				Console.WriteLine(output[i].GetOutput()); // WAIT|MOVE x y|DIG x y|REQUEST item
			}
		}
	}
}