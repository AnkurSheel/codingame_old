using System.ComponentModel;
using OceanOfCode.Model;
using System;
using OceanOfCode.Agent;
using OceanOfCode.Services;
using System.Text;
using System.Collections.Generic;


 // 10/04/2020 08:41



namespace OceanOfCode
{
    public class Game
    {
        public Game()
        {
            Players = new[] { new Player(0, this), new Player(1, this) };
        }

        public Map Map { get; set; }

        public Player[] Players { get; }

        public Player Me { get; set; }

        public void SetMe(int id)
        {
            Me = Players[id];
            Me.IsMe = true;
        }

    }
}


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

namespace OceanOfCode.Agent
{
    public class ReactAgent
    {
        private readonly Player _myPlayer;

        private readonly Game _game;

        public ReactAgent(Game game)
        {
            _myPlayer = game.Me;
            _game = game;
        }

        public string GetAction()
        {
            var position = new Cell(_myPlayer.Position.X, _myPlayer.Position.Y - 1);
            if (CanMove(position))
            {
                return "MOVE N";
            }

            position = new Cell(_myPlayer.Position.X + 1, _myPlayer.Position.Y);
            if (CanMove(position))
            {
                return "MOVE E";
            }

            position = new Cell(_myPlayer.Position.X, _myPlayer.Position.Y + 1);
            if (CanMove(position))
            {
                return "MOVE S";
            }

            position = new Cell(_myPlayer.Position.X - 1, _myPlayer.Position.Y);
            if (CanMove(position))
            {
                return "MOVE W";
            }

            _myPlayer.PreviousPositions.Clear();
            return "SURFACE";
            //return "MOVE N TORPEDO";
        }

        private bool CanMove(Cell position)
        {
            return !_myPlayer.PreviousPositions.Contains(position) && _game.Map.IsValid(position.X, position.Y);
        }
    }
}
namespace OceanOfCode.Model
{
    public class Cell
    {
        public Cell(int x, int y)
        {
            X = x;
            Y = y;
            Type = CellType.Unknown;
        }

        public Cell(int x, int y, CellType type)
        {
            X = x;
            Y = y;
            Type = type;
        }

        public int X { get; }

        public int Y { get; }

        public CellType Type { get; }

        public override string ToString()
        {
            return $"x:{X} y:{Y}";
        }

        protected bool Equals(Cell other)
        {
            return X == other.X && Y == other.Y;
        }

        public override bool Equals(object obj)
        {
            if (ReferenceEquals(null, obj))
            {
                return false;
            }

            if (ReferenceEquals(this, obj))
            {
                return true;
            }

            if (obj.GetType() != GetType())
            {
                return false;
            }

            return Equals((Cell)obj);
        }

        public override int GetHashCode()
        {
            return 31 * X + 17 * Y;
        }
    }
}
namespace OceanOfCode.Model
{
    public enum CellType
    {
        Unknown = 0,

        Sea = 1,

        Island = 2
    }
}

namespace OceanOfCode.Model
{
    public class Map
    {
        public int Width { get; }

        public int Height { get; }

        public Cell[,] Cells { get; }

        public Map(int width, int height)
        {
            Width = width;
            Height = height;
            Cells = new Cell[height, width];
        }

        public void Build(int row, string line)
        {
            for (var index = 0; index < line.Length; index++)
            {
                var ch = line[index];

                var cellType = CellType.Sea;
                if (ch == 'x')
                {
                    cellType = CellType.Island;
                }

                Cells[row, index] = new Cell(index, row, cellType);
            }
        }

        public override string ToString()
        {
            var sb = new StringBuilder();
            for (var i = 0; i < Height; i++)
            {
                for (var j = 0; j < Width; j++)
                {
                    if (Cells[i, j].Type == CellType.Sea)
                    {
                        sb.Append('.');
                    }
                    else if (Cells[i, j].Type == CellType.Island)
                    {
                        sb.Append('x');
                    }
                }

                sb.AppendLine();
            }

            return sb.ToString();
        }

        public bool IsValid(int x, int y)
        {
            if (y < 0 || y >= 15 || x < 0 || x >= 15)
            {
                return false;
            }

            var cellType = Cells[y, x].Type;

            return cellType == CellType.Sea;
        }
    }
}

namespace OceanOfCode.Model
{
    public class Player
    {
        private readonly Game _game;

        public Player(int id, Game game)
        {
            _game = game;
            Id = id;
            PreviousPositions = new HashSet<Cell>();
        }

        public int Id { get; }

        public bool IsMe { get; set; }

        public int TorpedoCooldown { get; set; }

        public int Life { get; set; }

        public Cell Position { get; set; }

        public HashSet<Cell> PreviousPositions { get; }

        public void Initialize(
            int x,
            int y,
            int life,
            int torpedoCooldown,
            int sonarCooldown,
            int silenceCooldown,
            int mineCooldown)
        {
            Position = new Cell(x, y);
            Life = life;
            TorpedoCooldown = torpedoCooldown;

            PreviousPositions.Add(Position);
        }
    }
}


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

        public static void WriteLine(string output)
        {
            Console.WriteLine(output);
        }

        private static string ReadLine()
        {
            var input = Console.ReadLine();
            Debug(input);
            return input;
        }
    }
}