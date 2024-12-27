/**
 * DMOJ - Double Cola
 * Temáticas: Aritmetica-Algebra: Sucesiones
 *  
 * Idea: Simular la situación descrita y ver comportamiento que va sucesiendo
 * en la cola 
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
       int cases = nextInt();
       long N,lBegin,lEnd,range=0L;
       String [] characters = {"Sheldon","Leonard","Penny","Rajesh","Howard"};
       
       while(cases>0) {
    	   cases--;
    	   N=nextLong();
    	   lBegin = 1;
    	   lEnd = 5;
    	   range=(lEnd-lBegin+1);
    	   while(lEnd<N) {
    		   range=(lEnd-lBegin+1)*2L;
    		   lBegin=lEnd+1L;
    		   lEnd=lBegin+range-1;
    	   }
    	   N=(N-lBegin)/((lEnd-lBegin+1L)/5L);
    	   out.printf("%s\n",characters[(int) N]);
       }
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