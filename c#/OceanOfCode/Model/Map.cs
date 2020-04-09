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
            if (cell.Y < 0 || cell.Y >= 15 || cell.X < 0 || cell.X >= 15)
            {
                return false;
            }

            var cellType = Cells[cell.Y, cell.X].Type;

            return cellType == CellType.Sea;
        }

        public Cell GetWestPosition(Cell position)
        {
            return new Cell(position.X - 1, position.Y);
        }

        public Cell GetSouthPosition(Cell position)
        {
            return new Cell(position.X, position.Y + 1);
        }

        public Cell GetEastPosition(Cell position)
        {
            return new Cell(position.X + 1, position.Y);
        }

        public Cell GetNorthPosition(Cell position)
        {
            return new Cell(position.X, position.Y - 1);
        }
    }
}
