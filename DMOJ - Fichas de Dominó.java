/**
 * DMOJ - Fichas de Dominó
 * Temáticas: Teoria de Grafo + DFS
 *  
 * Idea: Armar el grafo dirigido que propone el problema y realizar l dfs sobre
 * comenzando por los nodos especificados y contar al final cuantos nodos han sido
 * visitados luego de l dfs sobr el grafo.
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
		int cases = nextInt();
		while(cases>0) {
			cases--;
			int nnodes=nextInt(),nedges=nextInt(),ndfs=nextInt(),a,b;
			Graph graph=new Graph(nnodes);
			for(int i=0;i<nedges;i++) {
				a = nextInt();
				b = nextInt();
				graph.addEdge(a, b);
			}
			for(int i=0;i<ndfs;i++) {
				a=nextInt();
				graph.dfs(a);
			}
			out.printf("%d\n", graph.solutions());	
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
	
	public class Graph{
		public int nodes;
		public List<List<Integer> > listady;
		public boolean [] visited;
		
		public Graph(int _nodes) {
			listady = new ArrayList<>();
			nodes = _nodes;
			for(int i=0;i<=nodes;i++)
				listady.add(new ArrayList<Integer>());
			visited = new boolean[nodes+1];
			Arrays.fill(visited, false);
		}
		
		public int solutions() {
			int count =0;
			for(int i=1;i<=this.nodes;i++) 
				if(visited[i]) 
					count++;
			return count;
		}

		public void dfs(int a) {
			Stack<Integer> sdfs =new Stack<Integer>();
			visited[a]=true;
			sdfs.add(a);
			
			while(sdfs.empty()==false) {
				a=sdfs.pop();
				for (Integer x : listady.get(a)) {
					if(visited[x]==false) {
						visited[x]=true;
						sdfs.add(x);
					}
				}
			}
		}

		public void addEdge(int a,int b) {
			listady.get(a).add(b);
		}
	}
	
}
