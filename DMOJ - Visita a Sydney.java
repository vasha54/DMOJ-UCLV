/**
 * DMOJ - Visita a Sydney
 * Temáticas: Recursividad + Recorrido en el arbol
 *  
 * Idea: Aplicar el recorrido entreorden hasta una profundidad K del árbol y 
 * tomando los valores para cada nivel del árbol.
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
	private final int MAX_N = 5000010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';

	private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1 };
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000000;

	public void solve() throws Exception {
		int K = nextInt();
		int [] values = new int [(1<<K)];
		for(int i=0;i<(1<<K)-1;i++) {
			values[i] = nextInt();
		}
	    List< List<Integer> > levels = new ArrayList<List<Integer> >();
	    for(int i=0;i<K;i++) {
	    	levels.add(new ArrayList<Integer>());
	    }
	    
	    travelBettwenOrder(0, K, values, 0, (1<<K)-2, levels);
	    
	    for(int i=0;i<K;i++) {
	    	for( int j=0;j<levels.get(i).size();j++) {
	    		if(j!=0) out.print(" ");
	    		out.printf("%d",levels.get(i).get(j));
	    	}
	    	out.println();
	    }
	}

	public void travelBettwenOrder(int depth,int maxDepth, int [] values, 
			int begin, int end, List< List<Integer> > levels) {
		if(depth < maxDepth) {
			int pivot = (begin+end)/2;
			travelBettwenOrder(depth+1, maxDepth, values, begin, pivot-1, levels);
			levels.get(depth).add(values[pivot]);
			travelBettwenOrder(depth+1, maxDepth, values, pivot+1, end, levels);
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
