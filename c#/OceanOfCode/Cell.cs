namespace OceanOfCode
{
    public class Cell
    {
        public Cell(int x, int y, CellType type)
        {
            X = x;
            Y = y;
            Type = type;
        }

        public int X { get; }

        public int Y { get; }

        public CellType Type { get; }
    }
}