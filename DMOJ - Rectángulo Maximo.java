
/**
 * DMOJ - Rectángulo Maximo
 * Temáticas: Programación de Dinámica + Prefix Sum
 *  
 * Idea: Determinar dada una matriz determinar la submatriz con mayor suma sus
 * elementos.
 * 
 */

import java.io.*;
import java.math.*;
import java.util.*;
import java.util.function.BiConsumer;
import java.util.*;
import java.lang.*;
import java.util.regex.*;
import java.util.stream.Stream;

public class Main {

	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private final int MAX_N = 500010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';
	private final double EPS = 1e-9;

	private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1, 2, 2, -2, -2 };
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1, -2, 2, 2, -2 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000007L;

	private void solve() throws Exception {
			
		int N = nextInt();
		long [][] dp =new long [N+1][N+1];
		
		
		Arrays.fill(dp[0], 0L);
		for(int i=1;i<=N;i++) {
			dp[i][0] = 0L;
			for(int j=1;j<=N;j++) {
				dp[i][j]= nextLong() + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			}
		}
		
		long answer=Long.MIN_VALUE;
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				answer = Math.max(answer, generateAllRectangule(i,j,dp));
			}
		}
		out.printf("%d\n", answer);
	}

	private long generateAllRectangule(int _row,int _column, long[][] dp) {
		long t = Long.MIN_VALUE;
		long subMatriz;
		for(int r=0;r<_row;r++){
			for(int c=0;c<_column;c++){
				subMatriz=dp[_row][_column];
				subMatriz-=dp[_row][c];
				subMatriz-=dp[r][_column];
				subMatriz+=dp[r][c];
				t=Math.max(t,subMatriz);
			}
		}
		return t;
	}

	Main() throws Exception {
		/*
		 * Esta entrada se debe activar cuando se hace una ejercicio de lectura hasta
		 * fin de fichero copiar la entrada en un fichero "Input.txt" y comentar el otro
		 * in . A la hor de enviar comentar este y descomentar el otro
		 */
		// in = new BufferedReader(new FileReader("Input.txt"));
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

	public static void main(String[] args) throws Exception {
		new Main();
	}

}