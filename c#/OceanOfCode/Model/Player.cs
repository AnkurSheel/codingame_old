﻿using System.Collections.Generic;

using OceanOfCode.Agent;

namespace OceanOfCode.Model
{
    public class Player
    {

        public Player(int id)
        {
            Id = id;
            PreviousPositions = new HashSet<Cell>();
        }

        public int Id { get; }

        public int TorpedoCooldown { get; set; }

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
            TorpedoCooldown = torpedoCooldown;

            PreviousPositions.Add(Position);
        }
    }
}
