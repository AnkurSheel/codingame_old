namespace Codingame.Multiplayer.UnleashTheGeek.Actions
{
	public interface IAction
	{
		void Apply();
		string GetOutput();
	}
}