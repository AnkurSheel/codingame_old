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

            var random = new Random();
            while (true)
            {
                var position = new Cell(random.Next(7), random.Next(7, 15));
                if (game.Map.IsValid(position.X, position.Y))
                {
                    Io.WriteLine($"{position.X} {position.Y}");
                    break;
                }
            }

            var agent = new ReactAgent(game);
            while (true)
            {
                Io.ReadTurn(game);
                Io.WriteLine(agent.GetAction());
            }
        }
    }
}
