/**
 * DMOJ - Arreglos Mágicos
 * Temáticas: Aritmetica - Algebra
 *  
 * Idea: Buscar todos los subarreglos de elementos consecutivos cuyos valores 
 * sean iguales. Luego cada subarreglo que cumple con la condición que todos
 * sus elementos son iguales va aportar a las solución final N(N+1)/2 donde N
 * es la cantidad de elementos de ese subarreglo.
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
	private final int MAX_N = 1000010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';
	private final double EPS = 1e-9;
	
	private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1 };
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000000;
	

	public void solve() throws Exception {
		int nelements=nextInt();
		long v , answer=0;
		Interval x =new Interval(nextLong());
		Stack<Interval> intervals =new Stack<Interval>();
		intervals.add(x);
		
		for(int i=1;i<nelements;i++) {
			v= nextLong();
			if(intervals.peek().value==v)
				intervals.peek().increment();
			else 
				intervals.add(new Interval(v));
		}
		
		while(intervals.empty()==false) {
			answer+=intervals.pop().cArrayMagic();
		}
		
		out.printf("%d\n", answer);
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
	
	private class Interval{
		public long value;
		public long frecuency;
		
		public Interval(long _v) {
			this.value=_v;
			this.frecuency=1;
		}
		
		public void increment() {
			this.frecuency++;
		}
		
		public long cArrayMagic() {
			return (this.frecuency*(this.frecuency+1L))/2L;
		}
	}
}