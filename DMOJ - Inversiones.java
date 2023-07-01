/**
 * DMOJ - Inversiones
 * Temáticas: Estructuras de datos + Fenwick Tree + Cola con Prioridad
 *  
 * Idea: Se tiene N (N<=10^5) elementos cuyos valores oscilan en el [-10^9 , 10^9]  
 * en una colección y se quiere conocer de dicha colección cuantas tripletas 
 * (A,B,C) se pueden formar con dichos valores tal que se cumplan las siguientes 
 * reglas:
 * 	1. A>B>C
 * 	2. La posición de A en la colección debe ser < que la posición de B en la coleccion
 * y a su vez la posición de B en la colección debe ser < que la posición de C
 * 
 * Si nos concentramos en cuantas tripletas va estar un valor x ocupando el valor
 * B nos daremos cuenta que responde al resultado de f(x)*g(x) donde f(x) retorna
 * la cantidad de valores mayores que x y ocupan una posición menor que x en la 
 * colección. Mientras g(x) retorna la cantidad de elementos menores que x en la
 * colección pero con una posición mayor que la de x. Entonces la cuestion es como
 * calcular para cada valor x de la colección su f(x)*g(x) de manera eficiente, 
 * sumar todos estos valores para dar la respuesta final. Matematicamente seria 
 * algo como:
 * 
 * 		Sumatoria(i,[1,N],f(X[i])*g(X[i]))
 * 
 * Lo primero será renumerar todos los valores de la colección para que los valores
 * de la colección estén en el rango de 1 a N. Para hacer esto de la siguiente manera
 * al menor valor de la colección se le asigna el valor 1 al segundo menor valor 
 * se le asigna el valor 2 y asi sucesivamente hasta tener una nueva colección de 
 * valores cuyo rango de valores oscila [1,N]. Notese que esta renumeración no afecta
 * el sentido de precedencia de valores con respectos a los operadores relacionales.
 * Dos valores indenticos en la colección original deben recibir la misma renumeración
 * en la nueva colección.
 * 
 * Para calcular f(x) y g(x) lo haremos usando Fenwick Tree ya que nos permite realizar
 * suma de prefijos actualizable y nos permitará conocer en cualquier momento
 * cuantos valores hay menores o mayores que x. 
 * 
 * Por cada i que pertenece [1,N]:
 * 		f[i] = tMax.sum(X[i]+1,N)
 * 		tMax.add(X[i],1)
 * 
 * Por cada i que pertence [N,1]:
 * 		g[i] = tMin.sum(1,X[i]-1)
 * 		tMin.add(X[i],1)
 * 
 * answer = 0
 * Por cada i que pertenece [1,N]:
 * 		answer += g[i]*f[i]
 * 
 * Imprimir answer
 **/

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
		int cases = nextInt(), N,id;
		int [] values;
		long v, answer;
		long [] answers;
		PriorityQueue<Tuple> pq = new PriorityQueue<Tuple>();
		while (cases > 0) {
			cases--;
			N = nextInt();
			values = new int[N + 1];
			answers = new long[N + 1];
			for (int i = 1; i <= N; i++) {
				v = nextLong();
				pq.add(new Tuple(v, i));
			}

			id = 1;
			Tuple last = pq.remove(), current;

			values[last.second] = id;

			while (pq.isEmpty() == false) {
				current = pq.remove();
				if (current.first != last.first)
					id++;
				values[current.second] = id;
				last = current;
			}

			answer = 0L;
			FenwickTree treeMax =new FenwickTree(N);
			FenwickTree treeMin =new FenwickTree(N);

			for (int i = 1; i <= N; i++) {
				answers[i] = treeMax.sum(values[i] + 1, N);
				treeMax.add(values[i], 1);
			}

			for (int i = N; i >= 1; i--) {
				answers[i] *= treeMin.sum(1, values[i] - 1);
				treeMin.add(values[i], 1);
				answer += answers[i];
			}

			out.printf("%d\n", answer);
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

	private class Tuple implements Comparable<Tuple> {
		long first;
		int second;

		public Tuple(long f, int s) {
			this.first = f;
			this.second = s;
		}

		@Override
		public int compareTo(Tuple t2) {
			if (this.first < t2.first)
				return -1;
			else if (this.first == t2.first && this.second < t2.second)
				return -1;
			else if (this.first > t2.first)
				return 1;
			else if (this.first == t2.first && this.second > t2.second)
				return 1;
			return 0;
		}
	}

	private class FenwickTree {
		public long[] bit;
		public int nodes;

		public FenwickTree(int _nnodes) {
			bit = new long[_nnodes + 1];
			Arrays.fill(bit, 0L);
			nodes = _nnodes + 1;
		}

		public void add(int idx, long delta) {
			for (; idx < this.nodes; idx += idx & -idx)
				bit[idx] += delta;
		}

		public long sum(int idx) {
			long ret = 0L;
			for (; idx > 0; idx -= idx & -idx)
				ret += bit[idx];
			return ret;
		}

		long sum(int l, int r) {
			if(l>r) return 0L;
			return sum(r) - sum(l - 1);
		}
	}
}