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

                foreach (var neighbour in nextCell.Neighbours)
                {
                    var cell = neighbour.Value;
                    if (!previousPositions.Contains(cell) && seen.Add(cell))
                    {
                        open.Add(cell);
                    }
                }
            }

            return seen.Count;
        }
    }
}
