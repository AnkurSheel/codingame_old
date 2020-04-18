using System;
using System.IO;

using OceanOfCode.Agent;
using OceanOfCode.Model;

namespace OceanOfCode.Services
{
    public static class Io
    {
        private static StreamReader file;

        public static void Initialize(Game game)
        {
            if (Constants.Local)
            {
                file = new StreamReader(@".\in.txt");
            }

            var inputs = ReadLine().Split(' ');
            var width = int.Parse(inputs[0]);
            var height = int.Parse(inputs[1]);

            var myId = int.Parse(inputs[2]);

            game.Map = new Map(width, height);

            for (var i = 0; i < game.Map.Height; i++)
            {
                var line = ReadLine();
                game.Map.Build(i, line);
            }

            game.SetMe(myId);
        }

        public static void ReadTurn(Game game, ReactAgent agent)
        {
            var inputs = ReadLine().Split(' ');
            var x = int.Parse(inputs[0]);
            var y = int.Parse(inputs[1]);
            var myLife = int.Parse(inputs[2]);
            var oppLife = int.Parse(inputs[3]);
            var torpedoCooldown = int.Parse(inputs[4]);
            var sonarCooldown = int.Parse(inputs[5]);
            var silenceCooldown = int.Parse(inputs[6]);
            var mineCooldown = int.Parse(inputs[7]);
            var sonarResult = ReadLine();
            var opponentOrders = ReadLine();
            game.Me.Initialize(x,
                               y,
                               myLife,
                               torpedoCooldown,
                               sonarCooldown,
                               silenceCooldown,
                               mineCooldown);
            agent.ParseOpponentOrders(opponentOrders);
        }

        public static void Debug(string output)
        {
            if (Constants.DebugOn)
            {
                Console.Error.WriteLine(output);
            }
        }

        public static void WriteLine(string output)
        {
            Console.WriteLine(output);
        }

        private static string ReadLine()
        {
            if (Constants.Local)
            {
                return file.ReadLine();
            }
            else
            {
                var input = Console.ReadLine();
                if (Constants.ForInput)
                {
                    Debug("IN");
                    Debug(input);
                    Debug("/IN");
                }
                else
                {
                    Debug(input);
                }

                return input;
            }
        }
    }
}
