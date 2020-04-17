using System;
using System.Collections.Generic;
using System.Linq;

using OceanOfCode.Actions;
using OceanOfCode.Model;
using OceanOfCode.Services;

namespace OceanOfCode.Agent
{
    public class ReactAgent
    {
        private readonly Player _myPlayer;

        public OpponentTracking OpponentTracking { get; }

        private readonly Game _game;

        private Direction _lastDirection;

        public ReactAgent(Game game)
        {
            _myPlayer = game.Me;
            _game = game;
            OpponentTracking = new OpponentTracking(_game.Map);
            OpponentTracking.InitializePossibleOptions();

        }

        public string GetAction()
        {
            var actions = new List<IAction>();

            //if (ShouldFireTorpedo())
            //{
            //    return $"TORPEDO {_game.Opponent.Position.X} {_game.Opponent.Position.Y}";
            //}

            MoveInSameDirection(actions);

            if (!actions.Any())
            {
                MoveInNewDirection(actions);
            }

            if (!actions.Any())
            {
                _myPlayer.PreviousPositions.Clear();
                actions.Add(new Surface());
            }

            actions.Add(new Torpedo());

            var ret = string.Empty;
            for (var index = 0; index < actions.Count; index++)
            {
                var action = actions[index];
                if (index != actions.Count - 1)
                {
                    ret = action.GetAction();
                }

                ret += " ";
            }

            return ret;
            //return "MOVE N TORPEDO";
        }

        private bool ShouldFireTorpedo()
        {
            Io.Debug(_game.Opponent.ToString());
            return _myPlayer.IsTorpedoCharged() && ManhattanDistance(_myPlayer.Position, _game.Opponent.Position) <= 4;
        }

        public float ManhattanDistance(Cell position1, Cell position2)
        {
            Io.Debug(position1.ToString());
            Io.Debug(position2.ToString());
            return Math.Abs(position1.X - position1.X) + Math.Abs(position1.Y - position2.Y);
        }

        private void MoveInNewDirection(ICollection<IAction> action)
        {
            var position = _game.Map.GetNorthPosition(_myPlayer.Position);
            if (CanMove(position))
            {
                _lastDirection = Direction.North;
                action.Add(new MoveNorth());
                return;
            }

            position = _game.Map.GetEastPosition(_myPlayer.Position);
            if (CanMove(position))
            {
                _lastDirection = Direction.East;
                action.Add(new MoveEast());
                return;
            }

            position = _game.Map.GetSouthPosition(_myPlayer.Position);
            if (CanMove(position))
            {
                _lastDirection = Direction.South;
                action.Add(new MoveSouth());
                return;
            }

            position = _game.Map.GetWestPosition(_myPlayer.Position);
            if (CanMove(position))
            {
                _lastDirection = Direction.West;
                action.Add(new MoveWest());
            }
        }

        private void MoveInSameDirection(ICollection<IAction> action)
        {
            switch (_lastDirection)
            {
                case Direction.North:
                    if (CanMove(_game.Map.GetNorthPosition(_myPlayer.Position)))
                    {
                        action.Add(new MoveNorth());
                    }

                    break;
                case Direction.South:
                    if (CanMove(_game.Map.GetSouthPosition(_myPlayer.Position)))
                    {
                        action.Add(new MoveSouth());
                    }

                    break;
                case Direction.East:
                    if (CanMove(_game.Map.GetEastPosition(_myPlayer.Position)))
                    {
                        action.Add(new MoveEast());
                    }

                    break;
                case Direction.West:
                    if (CanMove(_game.Map.GetWestPosition(_myPlayer.Position)))
                    {
                        action.Add(new MoveWest());
                    }

                    break;
            }
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
