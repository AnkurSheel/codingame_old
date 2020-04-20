using System.Text;

using OceanOfCode.Services;

namespace OceanOfCode.Model
{
    public class Map
    {
        public int Width { get; }

        public int Height { get; }

        public Cell[,] Cells { get; }

        public Map(int width, int height)
        {
            Width = width;
            Height = height;
            Cells = new Cell[height, width];
        }

        public void Build(int row, string line)
        {
            for (var index = 0; index < line.Length; index++)
            {
                var ch = line[index];

                var cellType = CellType.Sea;
                if (ch == 'x')
                {
                    cellType = CellType.Island;
                }

                Cells[row, index] = new Cell(index, row, cellType);
            }
        }

        public override string ToString()
        {
            var sb = new StringBuilder();
            for (var i = 0; i < Height; i++)
            {
                for (var j = 0; j < Width; j++)
                {
                    if (Cells[i, j].Type == CellType.Sea)
                    {
                        sb.Append('.');
                    }
                    else if (Cells[i, j].Type == CellType.Island)
                    {
                        sb.Append('x');
                    }
                }

                sb.AppendLine();
            }

            return sb.ToString();
        }

        public bool IsValid(int x, int y)
        {
            if (IsOutOfBounds(x, y))
            {
                return false;
            }

            var cellType = Cells[y, x].Type;

            return cellType == CellType.Sea;
        }

        public void SetupCells()
        {
            for (var i = 0; i < Height; i++)
            {
                for (var j = 0; j < Width; j++)
                {
                    CheckAndAddNeighbour(Cells[i, j], j, i - 1, Direction.North);
                    CheckAndAddNeighbour(Cells[i, j], j, i + 1, Direction.South);
                    CheckAndAddNeighbour(Cells[i, j], j - 1, i, Direction.West);
                    CheckAndAddNeighbour(Cells[i, j], j + 1, i, Direction.East);
                    CheckAndAddTorpedoLocations(Cells[i, j], Direction.North);
                    CheckAndAddTorpedoLocations(Cells[i, j], Direction.South);
                    CheckAndAddTorpedoLocations(Cells[i, j], Direction.West);
                    CheckAndAddTorpedoLocations(Cells[i, j], Direction.East);
                }
            }

            var sb = new StringBuilder();
            for (var i = 0; i < Height; i++)
            {
                for (var j = 0; j < Width; j++)
                {
                    sb.Append($"{Cells[i, j].TorpedoTargets.Count}  ");
                }

                sb.AppendLine();
            }

            Io.Debug(sb.ToString());
        }

        private void CheckAndAddNeighbour(
            Cell currentCell,
            int x,
            int y,
            Direction direction)
        {
            if (IsValid(x, y))
            {
                currentCell.Neighbours.Add(direction, Cells[y, x]);
            }
        }

        private void CheckAndAddTorpedoLocations(Cell currentCell, Direction direction)
        {
            var x = currentCell.X;
            var y = currentCell.Y;
            for (var i = 1; i <= 4; i++)
            {
                switch (direction)
                {
                    case Direction.North:
                        y = currentCell.Y - i;
                        break;
                    case Direction.South:
                        y = currentCell.Y + i;
                        break;
                    case Direction.East:
                        x = currentCell.X + i;
                        break;
                    case Direction.West:
                        x = currentCell.X - i;
                        break;
                }

                if (!IsValid(x, y))
                {
                    return;
                }

                currentCell.TorpedoTargets.Add(Cells[y, x]);
            }
        }

        public bool IsOutOfBounds(int x, int y)
        {
            if (y < 0 || y >= 15 || x < 0 || x >= 15)
            {
                return true;
            }

            return false;
        }
    }
}
