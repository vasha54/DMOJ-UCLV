/**
 * DMOJ -Vigilando el Museo
 * Temáticas: Estructura de Datos + Fenwick Tree
 *  
 *  Idea: Cada cámara aporta una cantidad de N de posiciones seguras. La camara
 *  inesima aporta una cantidad que es igual a la cantidad de camaras que se 
 *  ubican posterior a ella (las i+1 en adelante) y que su columna sea menor o
 *  igual que la columna de la camara i. La entrada de las posiciones de las 
 *  camaras deben ser procesadas en el orden inverso que fueron aportadas para
 *  de esta forma cuando proceso una camara ya procese las camaras que estan en filas
 *  posteriores a ella y puedo conocer cuantas tienen una columna menor que ella (con ayuda del Fenwick Tree)
 *  y dicha cantidad será la cantidad de lugares que aportará la camara que se procesa
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
		int ncameras = nextInt();
		long protects=0;
		Stack<Integer> pos = new Stack<Integer>();

		for(int i=0;i<ncameras;i++) {
			pos.add(nextInt());
		}

		FenwickTree ft = new FenwickTree(ncameras);

		while(pos.isEmpty()==false) {
			protects+=ft.sum(pos.peek());
			ft.add(pos.pop(),1L);
		}

		out.printf("%d\n", protects);
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

	private class FenwickTree{
		public long [] bit;
		public int nodes;

		public FenwickTree(int _nnodes) {
			bit = new long [_nnodes+1];
			Arrays.fill(bit,0L);
			nodes=_nnodes+1;
		}

		public void add(int idx, long delta) {
			for(;idx<this.nodes;idx+=idx&-idx) bit[idx] += delta;
		}

		public long sum(int idx) {
			long ret = 0L;
			for(;idx>0;idx-=idx&-idx) ret += bit[idx];
			return ret;
		}

		long sum(int l, int r) {
			return sum(r)-sum(l-1);
		}

	}

}
