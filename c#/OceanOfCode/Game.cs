using OceanOfCode.Model;

namespace OceanOfCode
{
    public class Game
    {
        public Game()
        {
            Players = new[] { new Player(0), new Player(1) };
        }

        public Map Map { get; set; }

        public Player[] Players { get; }

        public Player Me { get; set; }

        public void SetMe(int id)
        {
            Me = Players[id];
        }
    }
}
