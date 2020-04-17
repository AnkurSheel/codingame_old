using System;

using OceanOfCode.Agent;
using OceanOfCode.Model;
using OceanOfCode.Services;

namespace OceanOfCode
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var game = new Game();
            Io.Initialize(game);

            while (true)
            {
                var position = new Cell(game.Random.Next(7), game.Random.Next(7, 15));
                if (game.Map.IsValid(position))
                {
                    Io.WriteLine($"{position.X} {position.Y}");
                    break;
                }
            }

            var agent = new ReactAgent(game);
            while (true)
            {
                Io.ReadTurn(game, agent);
                Io.WriteLine(agent.GetAction());
            }
        }
    }
}
