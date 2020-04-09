using System.Dynamic;
using System.Text;

namespace OceanOfCode
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
    }
}