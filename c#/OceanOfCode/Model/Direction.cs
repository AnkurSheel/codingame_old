using System.ComponentModel;

namespace OceanOfCode.Model
{
    public enum Direction
    {
        Unknown = 0,

        North = 1,

        South = 2,

        East = 3,

        West = 4
    }

    public static class DirectionExtensions
    {
        public static Direction FromChar(char ch)
        {
            if (ch == 'E')
            {
                return Direction.East;
            }
            else if (ch == 'W')
            {
                return Direction.West;
            }
            else if (ch == 'N')
            {
                return Direction.North;
            }
            else if (ch == 'S')
            {
                return Direction.South;
            }

            throw new InvalidEnumArgumentException();
        }
    }
}
