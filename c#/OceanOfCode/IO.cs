using System;

namespace OceanOfCode
{
    public static class Io
    {
        public static void Initialize()
        {
            var player = new Player();
            var inputs = ReadLine().Split(' ');
            var width = int.Parse(inputs[0]);
            var height = int.Parse(inputs[1]);
            player.Id = int.Parse(inputs[2]);
            
            var map = new Map(width, height);

            for (var i = 0; i < map.Height; i++)
            {
                var line = ReadLine();
                map.Build(i, line);
            }
        }

        public static void ReadTurn()
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
        }
        private static string ReadLine()
        {
            var input = Console.ReadLine();
            Console.Error.WriteLine(input);
            return input;
        }
    }
}