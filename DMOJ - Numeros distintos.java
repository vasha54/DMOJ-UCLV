
/**
 * DMOJ - Números distintos
 * Temáticas: Estructura de Datos+ Algoritmo de Mo
 *  
 * Idea: Dada una colección de valores que pueden repetirse dado varios intervalos
 * de la colección determinar cuantos elementos únicos (los que se repiten cuenta 
 * una sola vez) existen en dicho intervalo. Trabajar con el algoritmo de Mo de
 * tal forma de preprocesar de las consultas de forma ordenada de forma que la 
 * solución de una consulta pueda formar parte de la solución de otra consulta.  
 * . 
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

	private int[] movX = { 0, 0, 1, -1 };
	private int[] movY = { -1, 1, 0, 0 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000009;

	class Query {
		int L;
		int R;
		int order;
		int answer;

		Query(int L, int R,int O) {
			this.L = L;
			this.R = R;
			this.order =O;
		}
	}

	void algorithmMo(int a[], int n, ArrayList<Query> q, int m) {
		// Find block size
		int block = (int) Math.sqrt(n);
		
		int maxValue = Integer.MIN_VALUE;
		
		for(int i=1;i<=n;i++) {
			maxValue = Math.max(maxValue, a[i]);
		}
		
		int [] marks = new int [maxValue+1];
		Arrays.fill(marks, 0);

		// Sort all queries so that queries of same blocks
		// are arranged together.
		Collections.sort(q, new Comparator<Query>() {

			// Function used to sort all queries so that all queries
			// of the same block are arranged together and within a block,
			// queries are sorted in increasing order of R values.
			public int compare(Query x, Query y) {

				// Different blocks, sort by block.
				if (x.L / block != y.L / block)
					return (x.L < y.L ? -1 : 1);

				// Same block, sort by R value
				return (x.R < y.R ? -1 : 1);
			}
		});

		// Initialize current L, current R and currentAnswer
		int currL = 0, currR = 0;
		int currElement = 0;

		// Traverse through all queries
		for (int i = 0; i < m; i++) {
			// L and R values of current range
			int L = q.get(i).L, R = q.get(i).R;

			// Remove extra elements of previous range. 
			while (currL < L) {
				marks[a[currL]]--;
				if(marks[a[currL]] <=0)
					currElement --;
				currL++;
			}

			// Add Elements of current Range
			while (currL > L) {
				if(marks[a[currL - 1]] <=0)
				  currElement++;
				marks[a[currL - 1]]++;
				currL--;
			}
			while (currR <= R) {
				if(marks[a[currR]] <=0)
					currElement++;
				marks[a[currR]]++;
				currR++;
			}

			// Remove elements of previous range.
			while (currR > R + 1) {
				marks[a[currR - 1]]--;
				if(marks[a[currR - 1]] <= 0)
					currElement--;
				currR--;
			}

			q.get(i).answer=currElement;
		}
		
		Collections.sort(q, new Comparator<Query>() {
			public int compare(Query x, Query y) {
				return (x.order < y.order ? -1 : 1);
			}
		});
		
		for (int i = 0; i < m; i++) {
			out.println(q.get(i).answer);
		}
	}

	public void solve() throws Exception {

		int nNumbers = nextInt();
		int l, r;
		int[] values = new int[nNumbers+1];
		for (int i = 1; i <= nNumbers; i++) {
			values[i] = nextInt();
		}
		int nQuerys = nextInt();
		ArrayList<Query> querys = new ArrayList<Query>();

		for (int i = 0; i < nQuerys; i++) {
			l = nextInt();
			r = nextInt();
			querys.add(new Query(l, r, i));
		}
		algorithmMo(values, nNumbers, querys, nQuerys);

	}

	Main() throws Exception {
		/*
		 * Esta entrada se debe activar cuando se hace una ejercicio de lectura hasta
		 * fin de fichero copiar la entrada en un fichero "Input.txt" y comentar el otro
		 * in . A la hor de enviar comentar este y descomentar el otro
		 */
		// in = new BufferedReader(new FileReader("Inpu.txt"));
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

	String next() throws Exception {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null)
				return null;
			eat(line);
		}
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws Exception {
		new Main();
	}

}
