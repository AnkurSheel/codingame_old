using System;
using System.ComponentModel;

using OceanOfCode.Model;

namespace OceanOfCode
{
    public class Game
    {
        public Random Random { get; }

        public Game()
        {
            Players = new[] { new Player(0, this), new Player(1, this) };
            Random = new Random(123);
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