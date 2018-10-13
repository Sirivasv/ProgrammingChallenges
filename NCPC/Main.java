import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import javafx.util.Pair;
import java.util.Scanner;

public class Main {

	public static BigInteger sumLimit;
	public static Integer idLimit;
	public static Map<Pair<Integer, BigInteger>, Integer> memo; 
	public static ArrayList<BigInteger> bids;
	public static ArrayList<String> names;
	public static ArrayList<String> winners;

	public static int DP(int id, BigInteger currentSum) {

		Pair<Integer, BigInteger> currentState = new Pair(id, currentSum);

		if (memo.containsKey(currentState)) {
			return memo.get(currentState);
		}

		if (id == idLimit) {
			Integer isValid = (currentSum.equals(sumLimit))?(1):(0);
			memo.put(currentState, isValid);
			return  memo.get(currentState);
		}

		BigInteger newSum = currentSum.add(bids.get(id));
		
		Integer takeThisElement = DP(id + 1, newSum);
		Integer takeNotThisElement = DP(id + 1, currentSum);

		memo.put(currentState, (takeThisElement + takeNotThisElement > 0)?(1):(0));
		
		if (takeThisElement == 1) {
			winners.add(names.get(id));
		}

		return memo.get(currentState);
	}

	public static void main(String args[]) {

		memo = new HashMap<Pair<Integer, BigInteger>, Integer>();
		bids = new ArrayList<BigInteger>();
		names = new ArrayList<String>();
		winners = new ArrayList<String>();


		Scanner reader = new Scanner(System.in);


		idLimit = reader.nextInt();

		sumLimit = reader.nextBigInteger();

		for (int i = 0; i < idLimit; ++i) {
			String currentName = reader.next();
			BigInteger currentBid = reader.nextBigInteger();
			bids.add(currentBid);
			names.add(currentName);
		}

		DP(0, BigInteger.ZERO);

		System.out.println(winners.size());
		for (int i = 0; i < winners.size(); ++i) {
			System.out.println(winners.get(i));
		}

	} 

}