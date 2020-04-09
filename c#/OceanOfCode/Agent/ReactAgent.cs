using OceanOfCode.Model;

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
