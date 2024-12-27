/**
 * DMOJ - Juego de Dados
 * Temáticas: Teoria de grafos + Disktraj
 *  
 * Idea: Simular el tablero como si fuera un grafo dirigido y ponderado. 
 * La ponderación va tener los valores de 1 y 0. Será cero cuando entre celda i y
 * j exista un atajo que vaya de i a j, mientras 1 será entre los nodos i y j 
 * siempre y cuando i<j y i+6>=j. Aplicar un disktraj desde el nodo 1 y ver el
 * resultado en el nodo NxM
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
		int N=nextInt(),M=nextInt(),npaths=nextInt(),A,B;
		
		Node [] graph = new Node[(N*M)+1];
		
		for(int i=0;i<graph.length;i++) {
			graph[i]=new Node();
			if(i-1>=1)graph[i-1].addEdge(i,1);
			if(i-2>=1)graph[i-2].addEdge(i,1);
			if(i-3>=1)graph[i-3].addEdge(i,1);
			if(i-4>=1)graph[i-4].addEdge(i,1);
			if(i-5>=1)graph[i-5].addEdge(i,1);
			if(i-6>=1)graph[i-6].addEdge(i,1);
		}
		
		for(int i=0;i<npaths;i++) {
			A=nextInt();
			B=nextInt();
			graph[A].addEdge(B,0);
		}
		
		disktraj(graph,1);
		out.printf("%d\n", graph[N*M].dist);
	}

	private void disktraj(Node[] graph, int source) {
		// TODO Auto-generated method stub
		PriorityQueue<PqEntry> queue = new PriorityQueue<PqEntry>();
		boolean [] visited =new boolean[graph.length];
		Arrays.fill(visited, false);
		
		graph[source].dist=0;
		queue.add(new PqEntry(source, 0));
		
		while(queue.isEmpty()==false) {
			PqEntry entry = queue.remove();
			int nod = entry.node;
			int dist =entry.dist;
			
			
			int nneigborns = graph[nod].neigborns.size();
			
			for(int i=0;i<nneigborns;i++) {
				int next = graph[nod].neigborns.get(i);
				if(visited[next]==false) {
					if(dist+ graph[nod].weights.get(i)<graph[next].dist) {
						graph[next].dist = dist+ graph[nod].weights.get(i);
						queue.add(new PqEntry(next,graph[next].dist));
					}
				}
			}
			
			visited[nod]=true;
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
	
	private class PqEntry implements Comparable<PqEntry>{
		private int node;
		private int dist;
		
		public PqEntry(int _n,int _d) {
			this.node = _n;
			this.dist = _d;
		}

		@Override
		public int compareTo(PqEntry b) {
			if(dist<b.dist) return -1;
			if(dist > b.dist) return 1;
			if(dist == b.dist && node<b.node) return -1;
			if(dist == b.dist && node >b.node) return 1;
			return 0;
		}
	}

	private class Node{
		private List<Integer> neigborns;
		private List<Integer> weights;
		private int parent;
		private int dist;
		
		public Node() {
			this.neigborns=new ArrayList<Integer>();
			this.weights=new ArrayList<Integer>();
			this.parent=-1;
			this.dist=Integer.MAX_VALUE;
		}
		
		public void addEdge(int b,int w) {
			this.neigborns.add(b);
			this.weights.add(w);
		}
	}

}
