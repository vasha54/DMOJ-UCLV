/**
 * DMOJ - La rana Cruana
 * Temáticas: Estructura de datos: Range Tree + Lazy Progation
 *  
 * Idea: Se tiene N (2<=N<=10^5) cada piedra tiene un valor A (0<=A<=10^5). Las
 * piedras se enumeran de la 1 a la N de izquierda a derecha. Cuando se esta en 
 * la piedra i siempre se puede saltar hacia la izquierda hacia una piedra que 
 * esta en la posicion j siempre y cuando j>=i-A[i] y j<i. Se desea saber de 
 * cuantas formas puedo salir de la piedra N y llegar a la piedra 1. La respuesta
 * debe ser modulada 10^9+7
 * 
 * Si puedo calcular de cuantas formas puedo llegar a la piedra i (Z) entonces 
 * dicho valor deberia adicionarselos a las posibles formas de llegar a las 
 * piedras que estan en el 'rango' de [i-A[i],i-1] y sabiendo que para la piedra
 * N la cantidad de formas de llegar a ella es 1 porque de ella parto puedo 
 * utilizar un range tree con lazy propagation de la siguiente manera.
 * 
 * Incialemente todos nodos hojas del árbol su valor sera 0 excepto el nodo hoja
 * que representa el rango [N,N] el cual su valor sera 1. Vez descrito esto 
 * vamos a realizar el siguiente procedimiento
 * 
 * Por cada x que pertenezca [N,2]:
 *     si A[x] == 0:
 *        continuar a la siguiente piedra
 *     nways = query(1,x,x,1,N)
 *     left = max(1,x-A[x])
 *     rigth = x-1
 *     updateLazyProgation(1,nways,left,rigth,1,N)
 *     
 * Imprimir query(1,1,1,1,N)
 * 
 * En las actualizaciones y consulta se debe tener en cuenta modular por el
 * valor 10^9+7 
 */

import java.io.*;
import java.math.*;
import java.util.*;
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
		int nstones = nextInt();
		int[] jumps = new int[nstones + 1];
		for (int i = 2; i <= nstones; i++)
			jumps[i] = nextInt();

		RangeTreeLP rtlp = new RangeTreeLP(nstones);
		rtlp.build(1, 1, nstones);

		for (int i = nstones; i >= 2; i--) {
			if (jumps[i] == 0)
				continue;

			int r = i - 1;
			int l = Math.max(i - jumps[i], 1);
			long ways = rtlp.query(1, i, i, 1, nstones) % MOD;
			rtlp.update(1, ways, l, r, 1, nstones);
		}
		out.printf("%d\n", rtlp.query(1, 1, 1, 1, nstones) % MOD);
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

	private class RangeTreeLP {

		private long[] data;
		private long[] lazy;
		private int nelements;

		public RangeTreeLP(int nstones) {
			this.data = new long[(nstones + 1) << 2];
			this.lazy = new long[(nstones + 1) << 2];
			this.nelements = nstones;
		}

		public void update(int indexTree, long ways, int l, int r, int left, int rigth) {
			if (r < left || rigth < l)
				return;

			if (l <= left && rigth <= r) {
				lazy[indexTree] = (lazy[indexTree] + ways) % MOD;
				return;
			}

			if (lazy[indexTree] != 0L) {
				lazy[2 * indexTree] = (lazy[2 * indexTree] + lazy[indexTree]) % MOD;
				lazy[2 * indexTree + 1] = (lazy[2 * indexTree + 1] + lazy[indexTree]) % MOD;
				lazy[indexTree] = 0L;
			}

			int MID = (left + rigth) / 2;

			if (l <= MID)
				update(indexTree * 2, ways, l, r, left, MID);
			if (MID < r)
				update(indexTree * 2 + 1, ways, l, r, MID + 1, rigth);
		}

		public long query(int indexTree, int l, int r, int left, int rigth) {
			if (r < left || rigth < l)
				return 0L;
			if (l <= left && rigth <= r) {
				if (lazy[indexTree] != 0L) {
					data[indexTree] = (data[indexTree] + lazy[indexTree]) % MOD;
					if (left != rigth) {
						lazy[2 * indexTree] = (lazy[2 * indexTree] + lazy[indexTree]) % MOD;
						lazy[2 * indexTree + 1] = (lazy[2 * indexTree + 1] + lazy[indexTree]) % MOD;
					}
					lazy[indexTree] = 0L;
				}
				return data[indexTree] % MOD;
			}

			if (lazy[indexTree] != 0L) {
				lazy[2 * indexTree] = (lazy[2 * indexTree] + lazy[indexTree]) % MOD;
				lazy[2 * indexTree + 1] = (lazy[2 * indexTree + 1] + lazy[indexTree]) % MOD;
				lazy[indexTree] = 0L;
			}

			long al = 0L, ar = 0L;

			int MID = (left + rigth) / 2;

			if (l <= MID)
				al = query(indexTree * 2, l, r, left, MID);
			if (MID < r)
				ar = query(indexTree * 2 + 1, l, r, MID + 1, rigth);

			return (al + ar) % MOD;
		}

		public void build(int indexTree, int left, int rigth) {
			if (left == rigth) {
				lazy[indexTree] = 0;
				data[indexTree] = (left == nelements ? 1L % MOD : 0L % MOD);
				return;
			}
			int MID = (left + rigth) / 2;
			this.build(2 * indexTree, left, MID);
			this.build(2 * indexTree + 1, MID + 1, rigth);
			lazy[indexTree] = data[indexTree] = 0L;
		}

	}

}