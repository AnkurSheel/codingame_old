using System.Text;

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

        public bool IsValid(Cell cell)
        {
            if (IsOutOfBounds(cell.X, cell.Y))
            {
                return false;
            }

            var cellType = Cells[cell.Y, cell.X].Type;

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
                }
            }
        }

        private void CheckAndAddNeighbour(Cell currentCell, int x, int y, Direction direction)
        {
            if (IsOutOfBounds(x, y))
            {
                return;
            }

            var newCell = Cells[y, x];
            if (IsValid(newCell))
            {
                currentCell.Neighbours.Add(direction, newCell);
            }
        }

        private bool IsOutOfBounds(int x, int y)
        {
            if (y < 0 || y >= 15 || x < 0 || x >= 15)
            {
                return true;
            }

            return false;
        }
    }
}
