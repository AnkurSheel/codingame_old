using System;

using OceanOfCode.Agent;
using OceanOfCode.Services;

namespace OceanOfCode
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var game = new Game();
            Io.Initialize(game);

            Console.WriteLine("7 7");

            var agent = new ReactAgent(game);
            while (true)
            {
                Io.ReadTurn(game);
                Console.WriteLine(agent.GetAction());
            }
        }
    }
}
