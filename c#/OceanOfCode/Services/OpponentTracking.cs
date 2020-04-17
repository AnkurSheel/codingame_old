using System;
using System.Collections.Generic;
using System.Linq;

using OceanOfCode.Model;

namespace OceanOfCode.Services
{
    public class OpponentTracking
    {
        private readonly Map _map;

        private List<Cell> _possiblePositions;

        public OpponentTracking(Map map)
        {
            _map = map;
            _possiblePositions = new List<Cell>();
        }

        public void ParseOrders(string orders)
        {
            var tokens = orders.Split(' ');
            foreach (var token in tokens)
            {
                Io.Debug(token);
            }

            if (tokens[0] == "MOVE")
            {
                ParseMove(tokens[1]);
                Io.Debug($"possible positions {_possiblePositions.Count}");
                if (_possiblePositions.Count < 10)
                {
                    DebugPositions(_possiblePositions);
                }
            }
            else if (tokens[0] == "SURFACE")
            {
                Io.Debug($"SURFACE possible positions {_possiblePositions.Count}");
                var region = Convert.ToInt32(tokens[1]);
                var xMin = (region - 1) % 3 * 5;
                var xMax = xMin + 4;
                var yMin = (region - 1) / 3 * 5;
                var yMax = yMin + 4;
                Io.Debug($"Region {region} : {xMin} {yMin} : {xMax} {yMax}");
                var positions = new HashSet<Cell>();
                for (var i = xMin; i <= xMax; i++)
                {
                    for (var j = yMin; j < yMax; j++)
                    {
                        positions.Add(_map.Cells[i, j]);
                    }
                }

                var next = new HashSet<Cell>();
                foreach (var possiblePosition in _possiblePositions)
                {
                    if (positions.Contains(possiblePosition))
                    {
                        next.Add(possiblePosition);
                    }
                }

                _possiblePositions = next.ToList();
            }
        }

        private void ParseMove(string moveDirection)
        {
            var next = new HashSet<Cell>();
            foreach (var possiblePosition in _possiblePositions)
            {
                var position = new Cell(-1, -1);
                if (moveDirection == "E")
                {
                    position = _map.GetEastPosition(possiblePosition);
                }
                else if (moveDirection == "W")
                {
                    position = _map.GetWestPosition(possiblePosition);
                }
                else if (moveDirection == "N")
                {
                    position = _map.GetNorthPosition(possiblePosition);
                }
                else if (moveDirection == "S")
                {
                    position = _map.GetSouthPosition(possiblePosition);
                }

                if (_map.IsValid(position))
                {
                    next.Add(position);
                }
            }

            _possiblePositions = next.ToList();
        }

        public void InitializePossibleOptions()
        {
            foreach (var cell in _map.Cells)
            {
                if (_map.IsValid(cell))
                {
                    _possiblePositions.Add(cell);
                }
            }

            Io.Debug($"positions {_possiblePositions.Count}");
        }

        private void DebugPositions(IReadOnlyCollection<Cell> positions)
        {
            Io.Debug($"positions {positions.Count}");
            foreach (var possiblePosition in positions)
            {
                Io.Debug(possiblePosition.ToString());
            }
        }
    }
}
