import java.util.Scanner;
import java.math.BigInteger;
class Main{
	public static void main( String[] args ){
		Scanner sc = new Scanner( System.in );
		int N = sc.nextInt(), K;
		int a, b;
		BigInteger A, B, C, D, E, F;
		String lee, arr[];
		for( int i = 0; i < N; i++ ){
			K = sc.nextInt();
			System.out.print( K + " " );
			lee = sc.next();
			arr = lee.split( "/" );
			A = new BigInteger( arr[0] );
			B = new BigInteger( arr[1] );
			if( B.compareTo( BigInteger.ONE ) == 0 ){
				System.out.print( B + "/" + A.add( BigInteger.ONE ) + "\n");
				continue;
			}
			else{
				C = A.mod( B );
				D = B.subtract(C);
				E = C.add(D);
				F = D.add(E.multiply( A.divide(B) ));
				System.out.print( E + "/" + F +"\n");
			}

		}
	}
}