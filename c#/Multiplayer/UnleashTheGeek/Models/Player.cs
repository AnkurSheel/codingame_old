using System.Collections.Generic;

namespace Codingame.Multiplayer.UnleashTheGeek.Models
{
	public class Player
	{
		public int Id;
		public int Score;
		public int RadarCooldown;
		public int TrapCooldown;
		public List<Robot> Robots = new List<Robot>();
		public List<Coordinate> Radars = new List<Coordinate>();
		int _score;

		public Player(int id)
		{
			Id = id;
		}

		public void Update(int score, int radarCooldown, int trapCooldown)
		{
			Score = score;
			_score = score;
			RadarCooldown = radarCooldown;
			TrapCooldown = trapCooldown;
		}

		public void Reset()
		{
			Score = _score;
			foreach (var robot in Robots)
			{
				robot.Reset();
			}
		}
	}
}