import java.util.Scanner;
import java.math.BigInteger;

public class Matrix {
	public static void main(String[] args) {
		// create scanner object
		Scanner s = new Scanner(System.in);
		
		BigInteger mtr[][] = new BigInteger[2][2];
		
		mtr[0][0] = s.nextBigInteger();
		mtr[0][1] = s.nextBigInteger();
		mtr[1][0] = s.nextBigInteger();
		mtr[1][1] = s.nextBigInteger();
		
		BigInteger ident[][] = new BigInteger[2][2];
		
		ident[0][0] = new BigInteger("1");
		ident[0][1] = new BigInteger("0");
		ident[1][0] = new BigInteger("0");
		ident[1][1] = new BigInteger("1");
		
		int ans[] = new int[150];
		int idans = 0;
		
		for (;;) {
			int fl = 1;
			for (int i = 0; i < 2; ++i) 
				for (int j = 0; j < 2; ++j) 
					if (mtr[i][j].compareTo(ident[i][j]) != 0)
						fl = 0;
			if (fl == 1)
				break;
			if (mtr[0][0].compareTo(mtr[0][1]) == 1) {
				//System.out.format("** %d %d\n", mtr[0][0], mtr[0][1]);
				ans[idans] = 0;
				idans++;
				mtr[0][0] = mtr[0][0].subtract(mtr[0][1]);
				mtr[1][0] = mtr[1][0].subtract(mtr[1][1]);
			} else {
				ans[idans] = 1;
				idans++;
				mtr[0][1] = mtr[0][1].subtract(mtr[0][0]);
				mtr[1][1] = mtr[1][1].subtract(mtr[1][0]);
			}
		}
		
		for (int i = idans - 1; i >= 0; --i)
			System.out.format("%d", ans[i]);
		System.out.println("");
		
		// read several types of input
		//int i = s.nextInt();
		//boolean b = s.nextBoolean();
		//String st = s.next();
		
		// output: use the possibility you like more
		//System.out.println("Case #"+i+": "+st);
		//System.out.format("Case %d#: %s\n", i, s);
	}
}