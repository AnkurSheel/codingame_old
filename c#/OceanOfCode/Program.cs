using System;

namespace OceanOfCode
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            Game game = new Game();
            Io.Initialize(game);
            
            Console.WriteLine("7 7");

            // game loop
            while (true)
            {
                Io.ReadTurn(game);

                // Write an action using Console.WriteLine()
                // To debug: Console.Error.WriteLine("Debug messages...");

                Console.WriteLine(game.Me.GetAction());
            }
        }
    }
}