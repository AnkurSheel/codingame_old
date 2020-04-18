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


            var position = GetStartingPosition(game);
            Io.WriteLine($"{position.X} {position.Y}");

            var agent = new ReactAgent(game);
            while (true)
            {
                Io.ReadTurn(game, agent);
                Io.WriteLine(agent.GetAction());
            }
        }

        private static Cell GetStartingPosition(Game game)
        {
            Cell position = new Cell(0,0);
            if (game.Map.IsValid(position))
            {
                return position;
            }
            position = new Cell(0, 14);
            if (game.Map.IsValid(position))
            {
                return position;
            }
            position = new Cell(14, 0);
            if (game.Map.IsValid(position))
            {
                return position;
            }
            position = new Cell(14, 14);
            if (game.Map.IsValid(position))
            {
                return position;
            }
            while (true)
            {
                position = new Cell(Constants.Random.Next(15), Constants.Random.Next(15));
                if (game.Map.IsValid(position))
                {
                    return position;
                }
            }
        }
    }
}
