using System.Collections.Generic;

namespace OceanOfCode.Model
{
    public class Player
    {
        private int _silenceCooldown;

        private int _torpedoCooldown;

        private int _sonarCooldown;

        public Player(int id)
        {
            Id = id;
            PreviousPositions = new HashSet<Cell>();
        }

        public int Id { get; }

        public int Life { get; set; }

        public Cell Position { get; set; }

        public HashSet<Cell> PreviousPositions { get; }

        public void Initialize(
            Cell position,
            int life,
            int torpedoCooldown,
            int sonarCooldown,
            int silenceCooldown,
            int mineCooldown)
        {
            Position = position;
            Life = life;
            _torpedoCooldown = torpedoCooldown;
            _sonarCooldown = sonarCooldown;
            _silenceCooldown = silenceCooldown;

            PreviousPositions.Add(Position);
        }

        public bool IsTorpedoCharged()
        {
            return _torpedoCooldown == 0;
        }

        public bool IsSonarCharged()
        {
            return _sonarCooldown == 0;
        }

        public bool IsSilenceCharged()
        {
            return _silenceCooldown == 0;
        }
    }
}
