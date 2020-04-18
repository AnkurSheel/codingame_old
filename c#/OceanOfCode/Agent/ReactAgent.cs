using System;
using System.Collections.Generic;

using OceanOfCode.Actions;
using OceanOfCode.Model;
using OceanOfCode.Services;

namespace OceanOfCode.Agent
{
    public class ReactAgent
    {
        private readonly Player _myPlayer;

        private readonly FloodFill _floodFill;

        private readonly OpponentTracking _opponentTracking;

        private readonly Game _game;

        public ReactAgent(Game game)
        {
            _myPlayer = game.Me;
            _game = game;
            _opponentTracking = new OpponentTracking(_game.Map);
            _opponentTracking.InitializePossibleOptions();
            _floodFill = new FloodFill(_game.Map);
        }

        public string GetAction()
        {
            var actions = new List<IAction>();

            //if (ShouldFireTorpedo())
            //{
            //    return $"TORPEDO {_game.Opponent.Position.X} {_game.Opponent.Position.Y}";
            //}

            var direction = GetMoveDirection();
            if (direction == Direction.Unknown)
            {
                actions.Add(new Surface());
                _myPlayer.PreviousPositions.Clear();
            }
            else
            {
                actions.Add(new Move(direction));
            }


            var ret = string.Empty;
            for (var index = 0; index < actions.Count; index++)
            {
                var action = actions[index];
                ret += action.GetAction();
                if (index != actions.Count - 1)
                {
                    ret += " ";
                }
            }

            return ret;
            //return "MOVE N TORPEDO";
        }

        //private bool ShouldFireTorpedo()
        //{
        //    Io.Debug(_game.Opponent.ToString());
        //    return _myPlayer.IsTorpedoCharged() && ManhattanDistance(_myPlayer.Position, _game.Opponent.Position) <= 4;
        //}

        public float ManhattanDistance(Cell position1, Cell position2)
        {
            Io.Debug(position1.ToString());
            Io.Debug(position2.ToString());
            return Math.Abs(position1.X - position1.X) + Math.Abs(position1.Y - position2.Y);
        }

        private Direction GetMoveDirection()
        {
            var bestScore = int.MinValue;
            var bestDirection = Direction.Unknown;

            var previousPositions = new HashSet<Cell>(_myPlayer.PreviousPositions);
            var position = _game.Map.GetNorthPosition(_myPlayer.Position);
            previousPositions.Add(_myPlayer.Position);
            if (CanMove(position))
            {
                var size = _floodFill.FindOpenArea(position, previousPositions);
                if (size > bestScore)
                {
                    bestScore = size;
                    bestDirection = Direction.North;
                }
            }

            position = _game.Map.GetSouthPosition(_myPlayer.Position);
            if (CanMove(position))
            {
                var size = _floodFill.FindOpenArea(position, previousPositions);
                if (size > bestScore)
                {
                    bestScore = size;
                    bestDirection = Direction.South;
                }
            }

            position = _game.Map.GetEastPosition(_myPlayer.Position);
            if (CanMove(position))
            {
                var size = _floodFill.FindOpenArea(position, previousPositions);
                if (size > bestScore)
                {
                    bestScore = size;
                    bestDirection = Direction.East;
                }
            }

            position = _game.Map.GetWestPosition(_myPlayer.Position);
            if (CanMove(position))
            {
                var size = _floodFill.FindOpenArea(position, previousPositions);

                if (size > bestScore)
                {
                    bestScore = size;
                    bestDirection = Direction.West;
                }
            }

            return bestDirection;
        }

        public void ParseOpponentOrders(string opponentOrders)
        {
            _opponentTracking.ParseOrders(opponentOrders);
        }

        private bool CanMove(Cell position)
        {
            return !_myPlayer.PreviousPositions.Contains(position) && _game.Map.IsValid(position);
        }
    }
}
