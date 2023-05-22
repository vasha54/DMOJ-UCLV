
/**
 * DMOJ - Los barcos más anchos
 * Temáticas: Teoria de Grafos + LCA + Kruskal + Centro del arbol
 *  
 * Idea: Dado el grafo lo primero es conformar un arbol de expasión maxima esto nos
 * garantiza que el camino entre cualquier lago se utilice los rios de mayor ancho.
 * Para esto vamos a implementar un kruskal con lar aristas ordenadas de forma 
 * decreciente. Con el arbol formado vamos a calcular el posible nodo central
 * del arbol para partir de el conformar el LCA. Para todas las consultas vamos
 * a determinar los LCA y ver cuales son comunes. Este detalle es importante porque
 * z puede ser el LCA(x1,v1) y LCA(x2,v2) y se realizo un dfs que calcule el camino 
 * de z a al resto de los nodos habre calculado con un dfs un mas consultas.
 * 
 * 
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
	private long MOD = 1000000000;

	private void solve() throws Exception {
		int nnodes = nextInt(), nedges = nextInt(), nquerys = nextInt(), A, B, W;

		List<Edge> edges = new ArrayList<Edge>();
		List<Query> querys = new ArrayList<Query>();
		Node[] tree = new Node[nnodes + 1];
		DisJoinSet dsu = new DisJoinSet(nnodes);

		for (int i = 0; i <= nnodes; i++)
			tree[i] = new Node();

		for (int i = 0; i < nedges; i++) {
			A = nextInt();
			B = nextInt();
			W = nextInt();
			edges.add(new Edge(A, B, W));
		}

		for (int i = 0; i < nquerys; i++) {
			A = nextInt();
			B = nextInt();
			querys.add(new Query(A, B));
		}

		Collections.sort(edges, new Edge());

		for (int i = 0; i < nedges && dsu.ncomponents > 1; i++) {
			Edge e = edges.get(i);
			if (dsu.root(e.a) != dsu.root(e.b)) {
				dsu.join(e.a, e.b);
				tree[e.a].addEdge(e.b, e.weight);
				tree[e.b].addEdge(e.a, e.weight);
			}
		}

		int root = searchCenterTree(tree, nnodes);

		LCA lca = new LCA(tree, root);
		lca.answer(querys, tree);
	}

	private int searchCenterTree(Node[] tree, int nnodes) {
		int center = Integer.MIN_VALUE;

		Queue<Integer> bfs = new ArrayDeque<Integer>();

		for (int i = 1; i <= nnodes; i++) {
			if (tree[i].degree == 0 || tree[i].degree == 1) {
				center = i;
				bfs.add(i);
				tree[i].degree = 0;
			}
		}

		while (bfs.isEmpty() == false) {
			center = bfs.remove();
			for (int x : tree[center].neighborns) {
				tree[x].degree--;
				if (tree[x].degree == 1) {
					bfs.add(x);
					tree[x].degree = 0;
				}
			}
		}
		return center;
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

	private class Edge implements Comparator<Edge> {

		int a, b, weight;

		public Edge(int _a, int _b, int _w) {
			this.a = _a;
			this.b = _b;
			this.weight = _w;
		}

		public Edge() {

		}

		@Override
		public int compare(Edge a, Edge b) {
			// TODO Auto-generated method stub
			return b.weight - a.weight;
		}

	}

	private class DisJoinSet {
		public int[] parent;
		public int[] sizes;
		public int ncomponents;

		public DisJoinSet(int n) {
			this.ncomponents = n;
			parent = new int[this.ncomponents + 1];
			sizes = new int[this.ncomponents + 1];
			for (int i = 0; i < this.ncomponents + 1; i++)
				sizes[parent[i] = i] = 1;
		}

		public int root(int x) {
			if (x == parent[x])
				return x;
			else {
				parent[x] = root(parent[x]);
				return parent[x];
			}
		}

		void join(int a, int b) {
			int x = root(a);
			int y = root(b);
			if (x != y) {
				if (sizes[x] < sizes[y]) {
					int tmp = x;
					x = y;
					y = tmp;
				}
				parent[y] = x;
				sizes[x] += sizes[y];
				this.ncomponents--;
			}
		}
	}

	private class Node {
		private List<Integer> neighborns;
		private List<Integer> weigths;
		private int degree;

		public Node() {
			this.neighborns = new ArrayList<Integer>();
			this.weigths = new ArrayList<Integer>();
			this.degree = 0;
		}

		public void addEdge(int b, int w) {
			this.neighborns.add(b);
			this.weigths.add(w);
			this.degree++;
		}
	}

	private class Query {
		int x, y, z;

		public Query(int _x, int _y) {
			this.x = _x;
			this.y = _y;
			this.z = Integer.MIN_VALUE;
		}

		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return "{x:" + x + ",y:" + y + ",z:" + z + "}";
		}
	}

	private class LCA {

		private class SortbyLCA implements Comparator<Integer> {
			public int compare(Integer a, Integer b) {
				return lca[b] - lca[a];
			}
		}

		private int[] parent, preOrder, I, head, A, lca;
		private int[][] dp;
		private int time;

		private void dfs1(Node[] tree, int u, int p) {
			parent[u] = p;
			I[u] = preOrder[u] = time++;
			for (int v : tree[u].neighborns) {
				if (v == p)
					continue;
				dfs1(tree, v, u);
				if (Integer.lowestOneBit(I[u]) < Integer.lowestOneBit(I[v])) {
					I[u] = I[v];
				}
			}
			head[I[u]] = u;
		}

		private void dfs2(Node[] tree, int u, int p, int up, int h) {
			A[u] = up | Integer.lowestOneBit(I[u]);
			for (int v : tree[u].neighborns) {
				if (v == p)
					continue;
				dfs2(tree, v, u, A[u], h + 1);
			}
		}

		public LCA(Node[] tree, int root) {
			int n = tree.length;
			preOrder = new int[n];
			I = new int[n];
			head = new int[n];
			A = new int[n];
			parent = new int[n];
			lca = new int[n];
			dp = new int[n][n];
			for (int i = 0; i < n; i++) {
				Arrays.fill(dp[i], Integer.MAX_VALUE);
				// dp[i][i]=0;
			}

			Arrays.fill(lca, 0);

			dfs1(tree, root, -1);
			dfs2(tree, root, -1, 0, 0);
		}

		private int enterIntoStrip(int x, int hz) {
			if (Integer.lowestOneBit(I[x]) == hz)
				return x;
			int hw = Integer.highestOneBit(A[x] & (hz - 1));
			return parent[head[I[x] & -hw | hw]];
		}

		public int lca(int x, int y) {
			int hb = I[x] == I[y] ? Integer.lowestOneBit(I[x]) : Integer.highestOneBit(I[x] ^ I[y]);
			int hz = Integer.lowestOneBit(A[x] & A[y] & -hb);
			int ex = enterIntoStrip(x, hz);
			int ey = enterIntoStrip(y, hz);
			return preOrder[ex] < preOrder[ey] ? ex : ey;
		}

		public void answer(List<Query> querys, Node[] tree) {

			ArrayList<Integer> initDFS = new ArrayList<Integer>();

			for (int i = 0; i < querys.size(); i++) {
				querys.get(i).z = this.lca(querys.get(i).x, querys.get(i).y);
				lca[querys.get(i).z]++;
			}

			for (int i = 1; i < tree.length; i++) {
				if (lca[i] > 0)
					initDFS.add(i);
			}

			Collections.sort(initDFS, new SortbyLCA());
			boolean[] visited = new boolean[tree.length];

			for (int r : initDFS) {
				Arrays.fill(visited, false);
				dfs3(r, tree, visited);
			}

			for (int i = 0; i < querys.size(); i++) {
				Query q = querys.get(i);
				out.printf("%d\n", Math.min(dp[q.z][q.x], dp[q.z][q.y]));
			}
		}

		private void dfs3(int r, Node[] tree, boolean[] visited) {
			visited[r] = true;
			Stack<Integer> dfs = new Stack<Integer>();
			int sizeN = tree[r].neighborns.size(), nextN, nextW, curr;

			for (int i = 0; i < sizeN; i++) {
				nextN = tree[r].neighborns.get(i);
				nextW = tree[r].weigths.get(i);
				visited[nextN] = true;
				dfs.add(nextN);
				dp[r][nextN] = Math.min(dp[r][r], nextW);
			}

			while (dfs.isEmpty() == false) {
				curr = dfs.pop();
				sizeN = tree[curr].neighborns.size();
				for (int i = 0; i < sizeN; i++) {
					nextN = tree[curr].neighborns.get(i);
					nextW = tree[curr].weigths.get(i);
					if (visited[nextN] == false) {
						visited[nextN] = true;
						dfs.add(nextN);
						dp[r][nextN] = Math.min(dp[r][curr], nextW);
					}
				}
			}
		}
	}

}
