using OceanOfCode.Agent;

namespace OceanOfCode.Actions
{
    public class Move : IAction
    {
        private readonly Direction _direction;

        public Move(Direction direction)
        {
            _direction = direction;
        }

        public string GetAction()
        {
            return $"MOVE {_direction.ToString()[0]}";
        }
    }
}
