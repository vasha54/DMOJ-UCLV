/**
 * DMOJ - El Arado Robot
 * Temáticas: Estructura de Datos: RangeTree + LazyPropagation
 *  
 * Idea: Se tiene un campo forma de matriz. Con un arado automático se aran Q
 * rectángulos dentro del campo . De cada rectangulo se define por su vertice
 * superior izquierdo y su vertice inferior derecho. El arado arará aquellas 
 * celdas dentro de los rectangulos. Se quiere dado los rectangulos la cantidad
 * de celdas que serán aradas en el campo o no. Los rectangulos pueden solapar 
 * por lo que una celda puede ser arada varias veces pero solo cuante una vez.
 * 
 * Si modelamos el campo como matriz donde [i,j] será false si la celda [i,j] no
 * ha sido arada y true si lo ha sido al menos una vez, la respuesta sera luego
 * de ejecutar los Q ordenes de rectángulos ver la cantidad de true que tiene 
 * la matriz. Para hacer esto de manera eficiente cada fila del campo lo vamos
 * almacenar en un Range Tree con Lazy Progration de esta forma podemos realizar
 * los arados rectangulares de manera eficiente. Luego para la respuesta final
 * solo tengo que recorrer todos los arboles e ir sumando la cantidad de true de 
 * cada arbol
 * 
 *  La idea sería esta:
 *  Por cada i que pertenece [1,Q]:
 *  	Leer X1,Y1,X2,Y2
 *      Por cada y que pertnece a [Y1,Y2]:
 *      	tree[y].updateLazy(1,X1,X2,1,X)
 *      
 *  answer =0
 *  Por cada r que pertenece [1,rows]
 *  	answer+=tree[r].query(1,1,X,1,X)
 *  Imprimir answer
 *  
 *  Donde:
 *  X es la cantidad de columnas
 *  rows la cantidad de filas
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
		int columns=nextInt(),rows=nextInt(),nquerys=nextInt(),c1,c2,r1,r2,answer;
		
		RangeTreeLP [] tree = new RangeTreeLP[rows+1];
		for(int i=1;i<=rows;i++) {
			tree[i]=new RangeTreeLP(columns);
			tree[i].build(1,1,columns);
		}
		
		for(int i=0;i<nquerys;i++) {
			c1=nextInt();
			r1=nextInt();
			c2=nextInt();
			r2=nextInt();
			for(int j=r1;j<=r2;j++)
				tree[j].update(1,c1,c2,1,columns);
		}
		answer = 0;
		
		for(int i=1;i<=rows;i++)
			answer+=tree[i].query(1,1,columns,1,columns);
		
		out.printf("%d\n", answer);
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
	
	private class RangeTreeLP{

		boolean [] data;
		int [] rt;
		boolean [] lazy;
		
		public RangeTreeLP(int columns) {
			data=new boolean[columns+1];
			rt= new int[(columns+1)<<2];
			lazy = new boolean[(columns+1)<<2];
		}

		public int query(int indexTree, int l, int r, int left, int rigth) {
			if(rigth<l || r<left) return 0;
			
			if(l<=left && rigth<=r)
				return rt[indexTree];
			
			int MID =(left+rigth)/2,aL=0,aR=0;
			if(l<=MID) aL=query(indexTree*2, l, r, left, MID);
			if(MID<rigth) aR=query(indexTree*2+1, l, r, MID+1, rigth);
			return aL+aR;
		}

		public void update(int indexTree, int l, int r, int left, int rigth) {
			if(rigth<l || r<left) return;
			
			if(l<=left && rigth<=r) {
				lazy[indexTree]=true;
				rt[indexTree]=rigth-left+1;
				return;
			}
			
			if(lazy[indexTree]==true) {
				return;
			}
			
			int MID =(left+rigth)/2;
			
			if(l<=MID) update(indexTree*2, l, r, left, MID);
			if(MID<rigth)update(indexTree*2+1, l, r, MID+1, rigth);
			
			if(lazy[indexTree]==false)
				rt[indexTree]=rt[indexTree*2]+rt[indexTree*2+1];
		}

		public void build(int indexTree, int left, int rigth) {
			if(left==rigth) {
				data[left]=false;
				rt[indexTree] = 0;
				lazy[indexTree] =false;
			}else {
				int MID =(left+rigth)/2;
				build(indexTree*2, left, MID);
				build(indexTree*2+1, MID+1, rigth);
				rt[indexTree]=rt[indexTree*2]+rt[indexTree*2+1];
				lazy[indexTree]=false;
			}
			
		}
		
	}
}
