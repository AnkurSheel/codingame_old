using System.Collections.Generic;
using Codingame.Multiplayer.UnleashTheGeek.Actions;

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
		public Player Player;
		public Coordinate Position;
		public RobotItem Item;
		public int Time;
		public List<MCDigAction> PossibleActions = new List<MCDigAction>();

		public bool IsDead => Position.X == -1;
		public bool HasOre => Item == RobotItem.ORE;
		public bool HasRadar => Item == RobotItem.RADAR;
		public bool HasTrap => Item == RobotItem.TRAP;

		public Robot(int id, int x, int y, int item, Player player)
		{
			Id = id;
			Player = player;
			Position = new Coordinate(x, y);
			Item = (RobotItem) item;
		}

		public void Reset()
		{
			Time = 0;
			Position.Reset();
		}
	}
}