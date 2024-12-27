
/**
 * DMOJ - Dibujos para colorear
 * Temáticas: Range tree + Lazy progation + Programacion dinamica
 *  
 * Idea: Tenemos una recta númerica [1,5*10^5] sobre la cual aplicamos una opera
 * cion del tipo (a,b) que sigifica ir por todos los numeros naturales en el
 * intervalo [a,b] y cambiarle su color (inicialmente todos son blancos, y 
 * los cambios son: blanco->negro o negro->blanco) luego de realizar todas las 
 * operaciones buscar la longitud de la subsecuencia de puntos concecutivos que
 * su color sea negro. Para resolver el problema vamos a modelar la recta como
 * un arbol de rango con lazy propagation. Unas vez procesada todas las 
 * operaciones vamos hacer una propagación completa del arbol de forma que para
 * cada numero natural en el rango [1,5*10^5] sepamos cuantas operaciones lo 
 * afectaron eso lo vamos almacenar en data. Ahora si data[i] tiene un valor par
 * implica que el punto termina con el mismo color inicial es decir blanco, por
 * tanto podemos modular en dos todos los valores alamcenados en data y luego solo
 * tendrías que buscar la mayor secuencias de 1 consecutivos en data.
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
		// TODO Auto-generated method stub
		int querys = nextInt(), a, b,minA=Integer.MAX_VALUE,maxB=Integer.MIN_VALUE;

		RangeTreeLP treeLP = new RangeTreeLP(MAX_N);

		treeLP.build(1, 1, 500000);

		for (int i = 0; i < querys; i++) {
			a = nextInt();
			b = nextInt();
			treeLP.update(1,Math.min(a,b), Math.max(a,b), 1, 500000);
			minA=Math.min(minA, a);
			minA=Math.min(minA, b);
			maxB=Math.max(maxB, a);
			maxB=Math.max(maxB, b);
		}
		treeLP.updateData(1, 1, 500000);
		out.printf("%d\n", treeLP.solution(minA,maxB));
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

		private int[] data;
		private int[] lz;

		public RangeTreeLP(int n) {
			data = new int[n];
			lz = new int[n << 2];
		}

		public int solution(int minA, int maxB) {
			int best=0,tmp=0;
			for(int i=minA;i<=maxB;i++){
				if(data[i]==1)tmp++; else tmp=0;
				best=Math.max(tmp, best);
			}
				
			return best;
		}

		public void build(int index, int left, int rigth) {
			if (left == rigth) {
				lz[index] = 0;
				data[left] = 0;
			} else {
				int tm = (left + rigth) / 2;
				this.build(index * 2, left, tm);
				this.build(index * 2 + 1, tm + 1, rigth);
				lz[index] = 0;
			}
		}

		public void update(int index, int l, int r, int left, int rigth) {
			if (l > r)
				return;
			if (rigth < l || r < left)
				return;
			if (l <= left && rigth <= r) {
				this.lz[index]=this.lz[index]+1;
			}else {
				int tm = (left + rigth) / 2;
				this.update(index * 2, l, r, left, tm);
				this.update(index * 2 + 1, l, r, tm + 1, rigth);
			}
		}

		public void updateData(int index, int left, int rigth) {
			if (left == rigth) {
				data[left] += lz[index];
				data[left] %= 2;
			} else {
				int tm = (left + rigth) / 2;
				lz[index * 2] += lz[index];
				lz[index * 2 + 1] += lz[index];
				this.updateData(index * 2, left, tm);
				this.updateData(index * 2 + 1, tm + 1, rigth);
				
			}
			lz[index]=0;
		}
	}
}