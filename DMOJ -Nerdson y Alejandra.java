/**
 * DMOJ -Nerdson y Alejandra
 * Temáticas: Programacion Dinámica + Cantidad de subsecuencia no consecutivas
 *  
 *  Idea: Dada una secuencias de caracteres contar dentro estas cuantas veces
 *  esta contenida la secuencia 'papa' no necesariamente de forma consecutivas
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
	private final int MAX_N = 10010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';

	private int[] movX = {  0, 0, 1, -1 , 1,  1, -1, -1 };
	private int[] movY = { -1, 1, 0,  0 , 1, -1,  1, -1 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000009;


	public void solve() throws Exception {
		int c=nextInt();
		String text =next();
		out.printf("%d", countSubsequence(text, "papa"));
		
	}

	Main() throws Exception {
		/*
		 * Esta entrada se debe activar cuando se hace una ejercicio de lectura hasta
		 * fin de fichero copiar la entrada en un fichero "Input.txt" y comentar el otro
		 * in . A la hor de enviar comentar este y descomentar el otro
		 */
		//in = new BufferedReader(new FileReader("Input.txt"));
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

	private int nextInt() throws Exception {return Integer.parseInt(next());}

	private long nextLong() throws Exception {return Long.parseLong(next());}

	private double nextDouble() throws Exception {return Double.parseDouble(next());}

	public static void main(String[] args) throws Exception {new Main();}  

	public long countSubsequence(String _text, String _pattern){
		int m=_text.length();
	    int n=_pattern.length();
	    long [][] dp =new long [m+10][n+10]; 
	    for (int i=0;i<=m;i++) dp[i][0] = 1;
	    
	    for(int j=1;j<=n;j++) dp[0][j] = 0;

        for(int i=1;i<=m;i++)
           for (int j=1;j<=n;j++)
        	   dp[i][j] = ((_text.charAt(i-1) == _pattern.charAt(j-1) ? dp[i-1][j-1]:0)+dp[i-1][j]);

	    return dp[m][n];

	}
}
