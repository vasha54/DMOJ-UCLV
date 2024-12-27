/**
 * DMOJ - Fabrica de Leche
 * Temáticas: Teoria de Grafos + DFS
 *  
 *  Idea: Ver del grafo cuales son los nodos que se pueden acceder desde cualquier
 *  otro nodo. Para esto vamos a invertir el sentido de las aristas del grafo 
 *  original y para cada nodo vamos realizar un dfs y con este vamos a ver cuantos
 *  nodos puede acceder y si dicha cantidad coincide con la cantidad de nodos entonces
 *  este es uno de los nodos solicitados
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
		int N =nextInt(),a,b;
		Graph graph =new Graph(N);
		
		for(int i=0;i<N-1;i++) {
			a = nextInt();
			b = nextInt();
			graph.addEgde(b, a);
		}
		
		out.printf("%d\n", graph.station());
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
		public int nodes;
		
		public Graph(int _nodes) {
			this.nodes =_nodes;
			lAdyancencia =new ArrayList<ArrayList<Integer> >(this.nodes+1);
			for(int i=0;i<this.nodes+1;i++) {
				lAdyancencia.add(new ArrayList<Integer>());
			}
		}
		
		public int station() {
			// TODO Auto-generated method stub
			int stationSelect =-1;
			
			int [] access = new int [this.nodes+1];
			boolean [] visited = new boolean [this.nodes+1];
			
			for(int i=1;i<=this.nodes && stationSelect ==-1;i++){
				Arrays.fill(access, 0);
				Arrays.fill(visited, false);
				if(visited[i]==false)
					this.dfs(i,access,visited);
				if(access[i] == this.nodes)
					stationSelect = i;
			}
			
			return stationSelect;
		}

		private int dfs(int node, int[] access, boolean[] visited) {
			access[node]++;
			visited[node]=true;
			int nvecinos = this.lAdyancencia.get(node).size(),vecino;
			for(int i=0;i<nvecinos;i++) {
				vecino = this.lAdyancencia.get(node).get(i);
				if(!visited[vecino])
					access[node]+=dfs(vecino, access, visited);
			}
			return access[node];
		}

		public void addEgde(int a,int b) {
			lAdyancencia.get(a).add(b);
		}
	}

}
