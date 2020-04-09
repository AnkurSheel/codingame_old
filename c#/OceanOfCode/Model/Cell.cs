namespace OceanOfCode.Model
{
    public class Cell
    {
        public Cell(int x, int y)
        {
            X = x;
            Y = y;
            Type = CellType.Unknown;
        }

        public Cell(int x, int y, CellType type)
        {
            X = x;
            Y = y;
            Type = type;
        }

        public int X { get; }

        public int Y { get; }

        public CellType Type { get; }

        public override string ToString()
        {
            return $"x:{X} y:{Y}";
        }

        protected bool Equals(Cell other)
        {
            return X == other.X && Y == other.Y;
        }

        public override bool Equals(object obj)
        {
            if (ReferenceEquals(null, obj))
            {
                return false;
            }

            if (ReferenceEquals(this, obj))
            {
                return true;
            }

            if (obj.GetType() != GetType())
            {
                return false;
            }

            return Equals((Cell)obj);
        }

        public override int GetHashCode()
        {
            return 31 * X + 17 * Y;
        }
    }
}
