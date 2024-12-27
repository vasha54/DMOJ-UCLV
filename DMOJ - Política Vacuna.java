/**
 * DMOJ - Política Vacuna
 * Temáticas: Teoria de Grafos + LCA + Ordenamiento + Poda
 *  
 * Idea: Construir el LCA del arbol dado y buscar el par posible (v,x) donde x y v
 * pertenezcan el mismo partido que la distancia entre los nodos x y v sea mayor
 * de los que integran. 
 * 
 * Una vez construido el LCA vamos a coger todas las vacas de un mismo partido
 * para buscar el par(x,v) que maxime la siguiente expresion:
 * |heights[x]-heights[z]| + |heights[x]-heights[v]|
 * 
 * Donde: 
 * -z es el nodo LCA(x,v)
 * -heigths es un arreglo que guarda la altura/profundidad de cada nodo con 
 * respecto al nodo padre.
 * 
 * Las vacas las voy a ordenar de forma decreciente de acuerdo a su altura/profundidad
 * (heigths) ya que el par (x,v) que estoy buscando la vaca x siempre su altura/profundidad
 * va ser igual a la máxima altura/profundidad de todas la vacas del mismo partido
 * (Papel y lapiz y mira si puedes poner un contraejemplo que se rompa porque estuve
 * buscando y nada siempre se cumplia). Ahora solo tendría que escogers esas vacas 
 * xs compararla entre ellas y con el resto del mismo partido para buscar la 
 * solucion. Esto parece que se va en tiempo pero si le hacemos dos pequeña podas 
 * entra en tiempo:
 * La primera ya la tocamos la altura/profundidad de la vaca x deber ser la mayor
 * posible una vez que no se cumpla paramos el proceso. 
 * La segunda es como vamos recalculando constantemente la distancia y nos vamos
 * quedando con la mejor cuando se cumpla lo siguiente 2*heigths[x]<=distance ya 
 * podemos parar. La explicación es la siguiente la vaca y que buscamos para asociar
 * con x como estan ordenadas de forma decreciente su valor heigths en el mejor de
 * los casos puede ser igual a x y su lca con x sea precisamente la raiz del nodo
 * por tanto la distancia que aportaria sería 2*heigths[x] en cualquier otra variante
 * que la heigths[v] sea menor que heigths[x] no va mejorar como va a mejorar las que
 * vienen a continuación por tanto ya puedo detener el proceso de busqueda. Aqui
 * la claves es que el LCA (x,v) sea en O(1).
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
		int nnodes =nextInt(), npartidos = nextInt(),kpartido,parent,root=0;
		
		List<List<Integer>> partidos= new ArrayList<List<Integer>>();
		
		List<Integer>[] tree  = new List[nnodes+1];
		
		for(int i=0;i<=nnodes;i++)
			tree[i] = new ArrayList<Integer>();
		
		
		for(int i=0;i<=npartidos;i++)
			partidos.add(new ArrayList<Integer>());
		
		
		
		for(int i=1;i<=nnodes;i++) {
			kpartido =nextInt();
			parent =nextInt();
			partidos.get(kpartido).add(i);
			if(parent==0)root=i;
			else {
				tree[parent].add(i);
				tree[i].add(parent);
			}
		}
		
		LCA lca = new LCA(tree,root);
		
		for(int i=1;i<=npartidos;i++) {
		   List<Integer> partido = partidos.get(i);
		   lca.answer(partido);
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

	private class LCA{
		
		private class SortbyHeigths implements Comparator<Integer>{
		    public int compare(Integer a, Integer b){
		        return heigths[b]-heigths[a];
		    }
		}
		
		private int[] parent,preOrder,I,head,A,heigths;
	    private int time;

	    private void dfs1(List<Integer>[] tree, int u, int p) {
	        parent[u] = p;
	        I[u] = preOrder[u] = time++;
	        for (int v : tree[u]) {
	            if (v == p)
	                continue;
	            dfs1(tree, v, u);
	            if (Integer.lowestOneBit(I[u]) < Integer.lowestOneBit(I[v])) {
	                I[u] = I[v];
	            }
	        }
	        head[I[u]] = u;
	    }

	    

		private void dfs2(List<Integer>[] tree, int u, int p, int up,int h) {
	        A[u] = up | Integer.lowestOneBit(I[u]);
	        heigths[u]=h;
	        for (int v : tree[u]) {
	            if (v == p)
	                continue;
	            dfs2(tree, v, u, A[u],h+1);
	        }
	    }

	    public LCA(List<Integer>[] tree, int root) {
	        int n = tree.length;
	        preOrder = new int[n];
	        I = new int[n];
	        head = new int[n];
	        A = new int[n];
	        parent = new int[n];
	        heigths =new int [n];

	        dfs1(tree, root, -1);
	        dfs2(tree, root, -1, 0,0);
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
	    
	    public void answer(List<Integer> partido) {
			
	    	int distance = Integer.MIN_VALUE;
	    	Collections.sort(partido,new SortbyHeigths());
	    	
	    	int nsize = partido.size();
	    	int x,y,z,mh=heigths[partido.get(0)];
	    	
	    	for(int i=0;i<nsize ;i++) {
	    		x = partido.get(i);
	    		if(heigths[x]*2<=distance || heigths[x]!=mh) break;
	    		
	    		for(int j=i+1;j<nsize;j++) {
	    			y = partido.get(j);
	    			z = this.lca(x, y);
	    			distance = Math.max(distance, Math.abs(heigths[x]-heigths[z])+Math.abs(heigths[y]-heigths[z]));
		    	}
	    	}
	    	out.printf("%d\n", distance);
		}
	}

}
