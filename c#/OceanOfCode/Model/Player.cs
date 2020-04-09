using System.Collections.Generic;

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
