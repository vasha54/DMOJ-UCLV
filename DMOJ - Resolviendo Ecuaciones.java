/**
 * DMOJ - Resolviendo Ecuaciones
 * Temáticas: Teoria de Numeros + Ecuaciones diofanticas 
 *  
 * Idea: Dada una función de la forma ax+by=c ver si tiene o no solución. Basta
 * con comprobar que el gcd(a,b) sea divisor de C.
 *    
 * . 
 */
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.*;
import java.lang.*;
import java.util.regex.*;

public class Main {

	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private final int MAX_N = 110;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';

	private int[] movX = { 0, 0, 1, -1 };
	private int[] movY = { -1, 1, 0, 0 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000009;


	public void solve() throws Exception {
		int cases =nextInt(),A,B,C,gcdAB;
		boolean solution;
		
		while(cases>0) {
			cases--;
			solution =false;
			
			A = nextInt();
			B = nextInt();
			C = nextInt();
			
			gcdAB = gcd(Math.max(A, B), Math.min(A, B));
			
			if(C%gcdAB==0) solution=true;
			
			out.printf("%s\n", (solution?"YES":"NO"));
		}
	}
	
	public int  gcd(int a,int b) { // a>= b
        while (b > 0){
            a=a%b;
            a ^= b; 
            b ^= a;
            a ^= b;
        }
        return a;
    }
	
	public long powCubic(long x) {
		return x*x*x;
	}
	
	public long powSquare(long x) {
		return x*x;
	}


	Main() throws Exception {
		/*
		 * Esta entrada se debe activar cuando se hace una ejercicio de lectura hasta
		 * fin de fichero copiar la entrada en un fichero "Input.txt" y comentar el otro
		 * in . A la hor de enviar comentar este y descomentar el otro
		 */
		// in = new BufferedReader(new FileReader("Inpu.txt"));
		// out = new PrintWriter(new FileWriter("Output.txt"));
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		solve();
		in.close();
		out.close();
	}

	private void eat(String str) {
		st = new StringTokenizer(str);
	}

	String next() throws Exception {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null)
				return null;
			eat(line);
		}
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws Exception {
		new Main();
	}

}
