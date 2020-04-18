using System.Collections.Generic;
using System.Linq;

using OceanOfCode.Model;

namespace OceanOfCode.Services
{
    public class FloodFill
    {
        private readonly Map _map;

        public FloodFill(Map map)
        {
            _map = map;
        }

        public int FindOpenArea(Cell position, HashSet<Cell> previousPositions)
        {
            var seen = new HashSet<Cell>();
            var open = new List<Cell>();

            seen.Add(position);
            open.Add(position);

            while (open.Any())
            {
                var nextCell = open.First();
                open.RemoveAt(0);
                AddIfCanVisit(previousPositions, _map.GetNorthPosition(nextCell), seen, open);
                AddIfCanVisit(previousPositions, _map.GetSouthPosition(nextCell), seen, open);
                AddIfCanVisit(previousPositions, _map.GetEastPosition(nextCell), seen, open);
                AddIfCanVisit(previousPositions, _map.GetWestPosition(nextCell), seen, open);
            }

            return seen.Count;
        }

        private void AddIfCanVisit(
            IReadOnlyCollection<Cell> previousPositions,
            Cell newPos,
            ISet<Cell> seen,
            ICollection<Cell> open)
        {
            if (_map.IsValid(newPos) && !previousPositions.Contains(newPos) && seen.Add(newPos))
            {
                open.Add(newPos);
            }
        }
    }
}
