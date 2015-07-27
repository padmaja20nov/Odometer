package TennisGame;
import java.util.ArrayList;

public class Set {
	
	private ArrayList<Game> set = new ArrayList<Game>();
	private int setPoint[] = new int [2];
	private int currentGame;
	
	public final int SET_THRESHOLD = 6; 
	
	public Set () {
		currentGame = 0;
		set.add(new Game());
	}
	
	public int whoWonSet (int player) {
		int winner = set.get(currentGame).whoWonGame(player);
		if (winner != -1) {
			setPoint[winner]++;
			set.add(new Game());
			currentGame++;
			if (setPoint[winner] >= SET_THRESHOLD) {
				if (Math.abs(setPoint[0] - setPoint[1]) == 2) {
					return winner;
				}
			}
		}
		return -1;
	}
	
}
