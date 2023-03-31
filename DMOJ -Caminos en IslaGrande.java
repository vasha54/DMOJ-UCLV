
/**
 * DMOJ -Caminos en IslaGrande
 * Temáticas: Teoría de Grafos + Componentes Conexas + DFS
 *  
 *  Idea:  Lo primero es detectar las regiones, de cada region es necesario
 *  conocer cuantos vertices y aristas conforman dicha región. Para detectar
 *  las regiones se puede utilizar un dfs o bfs. Como se tiene que calcular
 *  la cantidad de mínima y máxima de regiones que pueden quedar luego de 
 *  construir K caminos nuevos entre ciudades. Para calcular la mínima 
 *  cantidad de regiones vamos asumir que tenemos R regiones si el valor
 *  de (R-1) <= K entonces la cantidad mínima de regiones después de construir
 *  K caminos es 1, en caso contrario de las R regiones podremos unir en 
 *  una región K+1 regiones por lo que nos quedaría R - (K+1)+1 regiones. 
 *  Para buscar la máxima cantidad de regiones lo primero es distribuir 
 *  los K caminos en las regiones de forma que cada región quede como un 
 *  grafo completo. Si aún quedan K caminos por distribuir vamos a realizar 
 *  el siguiente procedimiento, colocamos las regiones de forma ordenada 
 *  acorde a la cantidad de ciudades que componen la region. Luego mientras 
 *  exista dos regiones y K > 0 sacos las dos primeras regiones A y B, 
 *  decremento la cantidad de regiones en uno, K la decremento en el 
 *  producto de la cantidad de ciudades de A y la cantidad de ciudades 
 *  de B, le sumo la cantidad de B a A para fusionar las dos ciudades 
 *  como grafo completo, adicionar la region A a la colección en la primera 
 *  posición. Una vez terminado el proceso la cantidad de regiones que 
 *  queden será la máxima.
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
	private final int MAX_N = 10010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';

	private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1 };
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 10000;

	public void solve() throws Exception {
		int N=nextInt(),M=nextInt(),A,B;
		long K = nextLong();
		
		Graph graph =new Graph(N);
		
		for(int i=0;i<M;i++) {
			A = nextInt();
			B = nextInt();
			graph.addEdge(A, B);
		}
		
		graph.reform(K);
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
		private List< List<Integer> >graph;
		private int nodes;
		
		public Graph(int _nodes) {
			this.nodes =_nodes;
			graph  =new ArrayList< List<Integer> >();
			for(int i=0;i<=this.nodes;i++) {
				graph.add(new ArrayList<Integer>());
			}
		}
		
		public void reform(long K) {
			
			List<Region> regions =new ArrayList<Region>();
			
			boolean [] visited = new boolean[this.nodes+1];
			Arrays.fill(visited, false);
			long cRegions = 0L;
			
			for(int i=1;i<=nodes;i++) {
				if(visited[i]==false) {
					regions.add(this.scannerRegion(i,visited));
					cRegions++;
				}
			}
			
			long minRegions,maxRegions;
			
			if(cRegions-1L <= K) minRegions=1L;
			else minRegions = cRegions- (K+1L)+1L;
			
			Collections.sort(regions);
			
			for(int i=0;i<regions.size() && K>0;i++) {
				//out.printf("regions with %d nodes and %d edges\n", regions.get(i).cCountNodes,regions.get(i).cEdges);
				if(regions.get(i).cMaxEdges > regions.get(i).cEdges) {
					K-=(regions.get(i).cMaxEdges - regions.get(i).cEdges);
					regions.get(i).cEdges=regions.get(i).cMaxEdges;
				}
			}
			
			
			maxRegions=regions.size();	
			
			for(int i=1;i<regions.size() && K > 0;i++) {
				regions.get(0).cMaxEdges=regions.get(0).cMaxEdges+regions.get(i).cMaxEdges;
				regions.get(0).cEdges=regions.get(0).cEdges+regions.get(i).cEdges;
				K-=(regions.get(0).cCountNodes*regions.get(i).cCountNodes);
				regions.get(0).cCountNodes=regions.get(0).cCountNodes+regions.get(i).cCountNodes;
				maxRegions--;
			}
			
			
			
			out.printf("%d %d\n",minRegions,maxRegions);
		}

		private Region scannerRegion(int node, boolean[] visited) {
			long nodesV=0L;
			long edgesV=0L;
			
			Stack<Integer> dfs =new Stack<Integer>();
			
			visited[node] =true;
			dfs.add(node);
			
			while(dfs.isEmpty()==false) {
				node = dfs.pop();
				nodesV++;
				for(Integer nextNode : graph.get(node)) {
					if(visited[nextNode]==false) {
						dfs.add(nextNode);
						visited[nextNode] = true;
					}
					if(node<nextNode)
						edgesV++;
				}
			}
			
			return new Region(nodesV, edgesV);
		}

		public void addEdge(int a,int b) {
			graph.get(a).add(b);
			graph.get(b).add(a);
		}
	}
	
	private class Region implements Comparable<Region>{
		public long cCountNodes;
		public long cEdges;
		public long cMaxEdges;
		
		public Region(long _nodes,long _edges) {
			cCountNodes = _nodes;
			cEdges = _edges;
			cMaxEdges = cCountNodes*(cCountNodes-1)/2L;
		}

		@Override
		public int compareTo(Region _re) {
			if(this.cCountNodes>_re.cCountNodes) return -1;
			else if(this.cCountNodes < _re.cCountNodes) return 1;
			return 0;
		}
	}
}
