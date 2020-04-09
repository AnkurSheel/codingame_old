using System;

namespace OceanOfCode
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            Io.Initialize();
            
            string[] inputs;

            // Write an action using Console.WriteLine()
            // To debug: Console.Error.WriteLine("Debug messages...");

            Console.WriteLine("7 7");

            // game loop
            while (true)
            {
                Io.ReadTurn();

                // Write an action using Console.WriteLine()
                // To debug: Console.Error.WriteLine("Debug messages...");

                Console.WriteLine("MOVE N TORPEDO");
            }
        }
    }
}