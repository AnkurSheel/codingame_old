using OceanOfCode.Model;
using OceanOfCode.Services;

namespace OceanOfCode.Agent
{
    public class ReactAgent
    {
        private readonly Player _myPlayer;

        private readonly Game _game;

        private Direction _lastDirection;

        public ReactAgent(Game game)
        {
            _myPlayer = game.Me;
            _game = game;
        }

        public string GetAction()
        {
            switch (_lastDirection)
            {
                case Direction.North:
                    if (CanMove(_game.Map.GetNorthPosition(_myPlayer.Position)))
                    {
                        return MoveNorth();
                    }

                    break;
                case Direction.South:
                    if (CanMove(_game.Map.GetSouthPosition(_myPlayer.Position)))
                    {
                        return MoveSouth();
                    }

                    break;
                case Direction.East:
                    if (CanMove(_game.Map.GetEastPosition(_myPlayer.Position)))
                    {
                        return MoveEast();
                    }

                    break;
                case Direction.West:
                    if (CanMove(_game.Map.GetWestPosition(_myPlayer.Position)))
                    {
                        return MoveWest();
                    }

                    break;
            }

            //foreach (var previousPosition in _myPlayer.PreviousPositions)
            //{
            //    Io.Debug($"{previousPosition}");
            //}

            var position = _game.Map.GetNorthPosition(_myPlayer.Position);
            if (CanMove(position))
            {
                _lastDirection = Direction.North;
                return MoveNorth();
            }

            position = _game.Map.GetEastPosition(_myPlayer.Position);
            if (CanMove(position))
            {
                _lastDirection = Direction.East;
                return MoveEast();
            }

            position = _game.Map.GetSouthPosition(_myPlayer.Position);
            if (CanMove(position))
            {
                _lastDirection = Direction.South;
                return MoveSouth();
            }

            position = _game.Map.GetWestPosition(_myPlayer.Position);
            if (CanMove(position))
            {
                _lastDirection = Direction.West;
                return MoveWest();
            }

            _myPlayer.PreviousPositions.Clear();
            return "SURFACE";
            //return "MOVE N TORPEDO";
        }

        private string MoveWest()
        {
            return "MOVE W";
        }

        private string MoveSouth()
        {
            return "MOVE S";
        }

        private string MoveEast()
        {
            return "MOVE E";
        }

        private string MoveNorth()
        {
            return "MOVE N";
        }

        private bool CanMove(Cell position)
        {
            return !_myPlayer.PreviousPositions.Contains(position) && _game.Map.IsValid(position);
        }
    }

    public enum Direction
    {
        Unknown = 0,

        North = 1,

        South = 2,

        East = 3,

        West = 4
    }
}
