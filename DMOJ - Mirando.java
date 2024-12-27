/**
 * DMOJ - Mirando
 * Temáticas: Estructura de datos + Range Tree 
 *  
 * Idea: Buscar el primer elemento que sea mayor que un valor dado
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
	private final int MAX_N = 500010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';
	private final double EPS = 1e-9;

	private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1, 2, 2, -2, -2 };
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1, -2, 2, 2, -2 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000000;

	private void solve() throws Exception {
		int nelements = nextInt();
		int[] data = new int[nelements + 1];
		for (int i = 1; i <= nelements; i++) {
			data[i] = nextInt();
		}
		RangeTree tree = new RangeTree(nelements, data);
		tree.build(1, 1, nelements);
		for (int i = 1; i < nelements; i++) {
			out.printf("%d\n", tree.query(1, data[i], i+1, nelements, 1, nelements));
		}
		out.printf("%d\n",0);
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

	private class RangeTree {

		private int nelements;
		private int[] data;
		private int[] rt;

		public RangeTree(int _nelements, int[] _data) {
			this.nelements = _nelements;
			this.data = new int[this.nelements + 1];
			for (int i = 1; i <= _nelements; i++) {
				this.data[i] = _data[i];
			}
			this.rt = new int[this.nelements << 2];
		}

		public void build(int indexTree, int left, int rigth) {
			if (left == rigth) {
				rt[indexTree] = data[left];
				return;
			}
			int MID = (left + rigth) / 2;
			build(indexTree * 2, left, MID);
			build(indexTree * 2 + 1, MID + 1, rigth);
			rt[indexTree] = Math.max(rt[indexTree * 2], rt[indexTree * 2 + 1]);
		}

		public int query(int indexTree, int x, int l, int r, int left, int rigth) {
			if (left > r || rigth < l)
				return 0;

			if (l <= left && rigth <= r) {
				if (rt[indexTree] <= x)
					return 0;
				while (left != rigth) {
					int MID = (left + rigth) / 2;
					if (rt[2 * indexTree] > x) {
						indexTree = 2 * indexTree;
						rigth = MID;
					} else {
						indexTree = 2 * indexTree + 1;
						left = MID + 1;
					}
				}
				return left;
			}
			
			int MID = (left + rigth) / 2;
			int rs = query(2 * indexTree, x, l, r, left, MID);
			if (rs != 0) return rs;
			return query(2 * indexTree + 1,x, l, r, MID + 1, rigth);

		}

	}

}
