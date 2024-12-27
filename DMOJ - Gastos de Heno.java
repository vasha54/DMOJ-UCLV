/**
 * DMOJ - Gastos de Heno
 * Temáticas: Programación dinamica + Tabla acumulativa
 *  
 * Idea: Tener acumulada la suma de todos los valores hasta la posición i para
 * cuando deseamos obtener la suma en el rango [a,b] sea dp[b]-dp[a-1]
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
		int nvalues=nextInt(),nqueries=nextInt(),a,b;
		long [] dp =new long [nvalues+10];
		long x;
		dp[0]=0;
		
		for(int i=1;i<=nvalues;i++) {
			x =nextLong();
			dp[i]=x+dp[i-1];
		}
		
		for(int i=1;i<=nqueries;i++) {
			a=nextInt();
			b=nextInt();
			out.printf("%d\n", dp[b]-dp[a-1]);
		}
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

	private String next() throws Exception {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null)
				return null;
			eat(line);
		}
		return st.nextToken();
	}

	private int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	private long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	private double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}
	
	private int  gcd(int a,int b) { // a>= b
        while (b > 0){
            a=a%b;
            a ^= b; 
            b ^= a;
            a ^= b;
        }
        return a;
    }

	public static void main(String[] args) throws Exception {
		new Main();
	}

}
