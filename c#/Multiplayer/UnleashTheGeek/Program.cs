using System;
using Codingame.Multiplayer.UnleashTheGeek.Agents;
using Codingame.Multiplayer.UnleashTheGeek.Models;
using Codingame.Multiplayer.UnleashTheGeek.Services;

class Player
{
	static void Main()
	{
		InputService.ReadInitialData();

		var game = new Game();
		// game loop
		while (true)
		{
			InputService.ReadGame(game);

			game.OnRound();
			var output = new MCAgent(game).Think();

			for (var i = 0; i < 5; i++)
			{
				Console.WriteLine(output[i].GetOutput()); // WAIT|MOVE x y|DIG x y|REQUEST item
			}
		}
	}
}