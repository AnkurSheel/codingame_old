using System.Collections.Generic;

namespace Codingame.Multiplayer.UnleashTheGeek.Models
{
	public class Player
	{
		public int Score;
		public int RadarCooldown;
		public int TrapCooldown;
		public List<Robot> Robots = new List<Robot>();
		public List<Coordinate> Radars = new List<Coordinate>();
	}
}