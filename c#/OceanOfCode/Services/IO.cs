using System;

using OceanOfCode.Model;

namespace OceanOfCode.Services
{
    public static class Io
    {
        public static void Initialize(Game game)
        {
            var inputs = ReadLine().Split(' ');
            var width = int.Parse(inputs[0]);
            var height = int.Parse(inputs[1]);

            var myId = int.Parse(inputs[2]);
            game.SetMe(myId);

            game.Map = new Map(width, height);

            for (var i = 0; i < game.Map.Height; i++)
            {
                var line = ReadLine();
                game.Map.Build(i, line);
            }
        }

        public static void ReadTurn(Game game)
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
            game.Me.Initialize(x, y, myLife, torpedoCooldown, sonarCooldown, silenceCooldown, mineCooldown);
        }

        public static void Debug(string output)
        {
            Console.Error.WriteLine(output);
        }

        private static string ReadLine()
        {
            var input = Console.ReadLine();
            Debug(input);
            return input;
        }
    }
}