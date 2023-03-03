/**
 * DMOJ - Lectura Veloz
 * Temáticas: Add -Hoc 
 *  
 * Idea: Simulacion 
 * 
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

	private int[] movX = {  0, 0, 1, -1 , 1,  1, -1, -1 };
	private int[] movY = { -1, 1, 0,  0 , 1, -1,  1, -1 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000009;


	public void solve() throws Exception {
		long pages=nextLong(),cows=nextInt();
		long S,T,R;
		for(int i=0;i<cows;i++) {
			S=nextLong();
			T=nextLong();
			R=nextLong();
			out.printf("%d\n", read(pages,S,T,R));
		}
	}

	private long read(long _pages, long _s, long _t, long _r){
		long timeRead=0;
		long serie=_t*_s;

		while (_pages > serie){
			_pages -= serie;
			timeRead+=(_t+_r);
		}

		if (_pages == serie){
			timeRead+=(_t);
			_pages -= serie;
		}

		while ( _pages > 0 ){
			_pages -= _s;
			timeRead ++;
		}     

		return timeRead;
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
