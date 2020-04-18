using OceanOfCode.Agent;
using OceanOfCode.Model;

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
            return $"{Constants.Move} {_direction.ToString()[0]}";
        }
    }
}
