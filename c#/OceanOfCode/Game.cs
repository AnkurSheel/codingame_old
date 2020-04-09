using System.ComponentModel;

using OceanOfCode.Model;

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