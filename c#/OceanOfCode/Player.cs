using System.Diagnostics.Contracts;

namespace OceanOfCode
{
    public class Player
    {
        private readonly Game _game;

        public Player(int id, Game game)
        {
            _game = game;
            Id = id;
        }

        public int Id { get; }

        public bool IsMe { get; set; }

        public int TorpedoCooldown { get; set; }

        public int Life { get; set; }

        public Cell Position { get; set; }

        public void Initialize(int x, int y, int life, int torpedoCooldown, int sonarCooldown, int silenceCooldown, int mineCooldown)
        {
            Position = new Cell(x, y, CellType.Unknown);
            Life = life;
            TorpedoCooldown = torpedoCooldown;
        }

        public string GetAction()
        {
            return "MOVE N TORPEDO";
        }
    }
}