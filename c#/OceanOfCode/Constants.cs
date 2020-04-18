using System;

namespace OceanOfCode
{
    public static class Constants
    {
        public const bool Local = false;

        public const bool DebugOn = false;
        
        public const bool ForInput = false;

        public static readonly Random Random = new Random(123);

        public const string Move = "MOVE";

        public const string Surface = "SURFACE";

        public const string Silence = "SILENCE";

        public const string Sonar = "SONAR";

        public const string Torpedo = "TORPEDO";
    }
}
