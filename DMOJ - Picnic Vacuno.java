/**
 * DMOJ - Picnic Vacuno.
 * Temáticas: Teoria de Grafos + DFS
 *  
 *  Idea: Ver del grafo cuales son los nodos que se pueden acceder desde cualquier
 *  otro nodo.
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

	private int[] movX = {  0, 0, 1, -1 , 1,  1, -1, -1 };
	private int[] movY = { -1, 1, 0,  0 , 1, -1,  1, -1 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000009;


	public void solve() throws Exception {
		int cows =nextInt(),N=nextInt(),edges=nextInt(),a,b;
		Graph graph =new Graph(N);
		List<Integer> pos =new ArrayList<Integer>();
		for(int i=0;i<cows;i++) pos.add(nextInt());
		for(int i=0;i<edges;i++) {
			a=nextInt();
			b=nextInt();
			graph.addEgde(a, b);
		}
		
		out.printf("%d\n",graph.pastizales(pos));
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

	private class Graph{
		public List<ArrayList<Integer> > lAdyancencia;
		public boolean [][] matrizAy;
		public int nodes;
		
		public Graph(int _nodes) {
			this.nodes =_nodes;
			lAdyancencia =new ArrayList<ArrayList<Integer> >(this.nodes+1);
			matrizAy=new boolean[this.nodes+1][this.nodes+1];
			for(int i=0;i<this.nodes+1;i++) {
				lAdyancencia.add(new ArrayList<Integer>());
				Arrays.fill(matrizAy[i], false);
			}
		}
		
		public int pastizales(List<Integer> pos) {
			int answer =0;
			int [] access = new int [this.nodes+1];
			boolean [] visited = new boolean [this.nodes+1];
			Arrays.fill(access, 0);
			int ncows = pos.size();
			
			for(int i=0;i<ncows;i++) {
				Arrays.fill(visited,false);
				dfs(pos.get(i),access,visited);
			}
			
			for(int i=0;i<access.length;i++)
				if(access[i]==ncows) answer++;
			return answer;
		}

		private void dfs(int node, int[] access, boolean[] visited) {
			access[node]++;
			visited[node]=true;
			int nvecinos = lAdyancencia.get(node).size(),vecino;
			for(int i=0;i<nvecinos;i++) {
				vecino = lAdyancencia.get(node).get(i);
				if(visited[vecino]==false) {
					dfs(vecino, access, visited);
				}
			}
		}
		
		private void dfsStack(int node) {
			Stack<Integer> dfsStack =new Stack<Integer>();
			boolean [] visited =new boolean [this.nodes+1];
			Arrays.fill(visited, false);
			
			int nvecinos,vecino;
			
			dfsStack.add(node);
			
			while(dfsStack.empty()==false) {
				node = dfsStack.pop();
				visited[node] =true;
				nvecinos = lAdyancencia.get(node).size();
				for(int i=0;i<nvecinos;i++) {
					vecino = lAdyancencia.get(node).get(i);
					if(visited[vecino] == false) {
						dfsStack.add(vecino);
						visited[vecino] = true;
					}
				}
			}
			
		}

		public void addEgde(int a,int b) {
			if(matrizAy[a][b]==false) {
				lAdyancencia.get(a).add(b);
				matrizAy[a][b]=true;
			}
		}
	}

}
