namespace Codingame.Multiplayer.UnleashTheGeek.Models
{
	public enum RobotItem
	{
		NONE = -1,
		RADAR = 2,
		TRAP = 3,
		ORE = 4
	}

	public class Robot
	{
		public int Id;
		public Coordinate Position;
		public RobotItem Item;

		public bool HasOre => Item == RobotItem.ORE;
		public bool HasRadar=> Item == RobotItem.RADAR;


		public Robot(int id, int x, int y, int item)
		{
			Id = id;
			Position = new Coordinate(x, y);

			Item = (RobotItem) item;
		}
	}
}