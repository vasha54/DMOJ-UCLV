/**
 * DMOJ - Land Acquisition 
 * Temáticas: Programación Dinámica + Convex Hull Trick 
 *  
 * Idea: Tenemos como entrada un conjunto de rectángulos  que pueden diferir en 
 * cuanto a sus dimensiones y deseamos adquirirlos todos. El adquirir un 
 * subconjunto de esos rectángulos incurre en un costo que no es proporcional al
 * tamaño del subconjunto ni de su área total, más bien es el producto del mayor 
 * ancho de todos los rectángulos, multiplicado por la mayor de las alturas. Se 
 * desea ingeniosamente particionar los rectángulos en grupos tal que su costo 
 * sea minimizado. Además los rectángulos no pueden ser rotados, por lo que no 
 * se puede intercambiar el largo por el ancho de ninguno de ellos. 
 * 
 * Sean A y B dos rectángulos cualesquiera. Supongamos que las dimensiones de A 
 * son mayores o iguales a las correspondientes dimensiones de B. Entonces, 
 * podemos eliminar el rectángulo B de la entrada ya que su presencia no afecta 
 * la respuesta, porque es posible computar una óptima solución sin él y luego 
 * insertarlo en el grupo que contiene al rectángulo A sin cambiar el costo. 
 * El rectángulo B es entonces irrelevante.
 * 
 * Primero ordenamos los rectángulos en orden ascendente por la altura, y 
 * procedemos a verificar uno por uno eliminando los irrelevantes. 
 * La lista de rectángulos restantes cumple que sus alturas son crecientes y su
 * ancho decreciente (de lo contrario, existirı́a una contradicción ya que 
 * asumimos que todos los rectángulos irrelevante han sido eliminados).
 * 
 * En la lista ordenada de los restantes rectángulos, si cada subconjunto a 
 * adquirir en grupo es contiguo se garantiza el óptimo (Se demuestra). 
 * El problema lo hemos reducido a como particionar la lista de los rectángulos 
 * en grupos contiguos de tal manera que el costo sea mı́nimo. 
 * 
 * Aqui es donde viene la extrapolacion de la situación cada rectangulo rele
 * vante se va convertir en una función del tipo mx+n donde m es la altura
 * y n el ancho de longitud.
 * 
 * Notar que las lı́neas dadas están en orden decreciente por sus pendientes, 
 * por lo que cada lı́nea es añadida a la derecha, esto ocurre por que están 
 * ordenadas por su ancho(width). Las preguntas pueden ser respondidas en 
 * tiempo logarı́tmico, dando un tiempo para responderlas todas de O(N log N ), 
 * pero podemos modificar nuestra estructura de datos tomando ventaja del hecho 
 * de que los valores de las preguntas están en orden no decreciente (ninguna 
 * pregunta ocurre más a la izquierda que su predecesor, entonces ninguna lı́nea 
 * tiene mayor pendiente que la procesada anteriormente), por lo que podemos 
 * reemplazar la búsqueda binaria por un puntero a la lı́nea actual, reduciendo 
 * el costo de responder todas las preguntas en O(N ). Como fue necesario 
 * ordenar los rectángulos por su altura, el tiempo del algoritmo que predomina 
 * es el de la ordenación, por lo que la complejidad temporal será O(N log N ).
 */

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
		int N = nextInt();
	    Rectangle [] rects =new Rectangle[N];
	    for(int i=0;i<N;i++) {
	    	rects[i]=new Rectangle(nextLong(), nextLong());
	    }
	    Arrays.sort(rects);
	    
	    
	    Rectangle [] rectRelevant = new Rectangle[N];
	    
	    int countRectRelevant = 0;
		for (int i = 0; i < N; ++i)
		{
			while (countRectRelevant > 0 && rectRelevant[countRectRelevant - 1].w⁢i⁢d⁢t⁢h <= rects[i].w⁢i⁢d⁢t⁢h)
				--countRectRelevant;
			rectRelevant[countRectRelevant++] = new Rectangle(rects[i].heigth, rects[i].w⁢i⁢d⁢t⁢h) ;
		}
		
		
		long [] cost = new long [countRectRelevant+1];
		cost[0] = 0L;
		
		ConvexHullTrick chullTrick =new ConvexHullTrick(countRectRelevant);
		
		chullTrick.add(new Line(rectRelevant[0].w⁢i⁢d⁢t⁢h, cost[0]));

		for (int i = 0; i < countRectRelevant; ++i)
		{
			cost[i + 1] = chullTrick.query(rectRelevant[i].heigth);
			if (i < countRectRelevant - 1)
				chullTrick.add(new Line(rectRelevant[i + 1].w⁢i⁢d⁢t⁢h, cost[i + 1]));
		}
		
		out.printf("%d\n", cost[countRectRelevant]);
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

	class Rectangle implements Comparable<Rectangle>{
		long w⁢i⁢d⁢t⁢h;
		long heigth;
		
		public Rectangle(long _h,long _w) {
			this.w⁢i⁢d⁢t⁢h = _w;
			this.heigth = _h;
		}
		
		public int compareTo(Rectangle _rect) {
			if(this.heigth > _rect.heigth) return 1;
			else if(this.heigth < _rect.heigth) return -1;
			else if(this.w⁢i⁢d⁢t⁢h>_rect.w⁢i⁢d⁢t⁢h) return 1;
			else if(this.w⁢i⁢d⁢t⁢h < _rect.w⁢i⁢d⁢t⁢h) return -1;
			
			return 0;
		}
	}
	
	private class Line{
		long m, n;
		public Line(long _m, long _n){
			this.m =_m;
			this.n =_n;
		}
	}
	
	private class ConvexHullTrick{
		
		int size;
		int ptr;
		
		Line [] r;
		
		public ConvexHullTrick(int n) {
			size=0;
			ptr=0;
			r = new Line[n];
			for(int i=0;i<n;i++)r[i]= new Line(0L,0L);
		}

		public long query(long x) {
			ptr = Math.min(ptr, size - 1);
			while (ptr + 1 < size && r[ptr + 1].m * x + r[ptr + 1].n < r[ptr].m * x + r[ptr].n)
				++ptr;
			return r[ptr].m * x + r[ptr].n;
		}

		public void add(Line line) {
			while (size >= 2 && bad(r[size - 2], r[size - 1], line))
				--size;
			r[size++] = line;
		}

		private boolean bad(Line l1, Line l2, Line l3) {
			return (l3.n - l1.n) * (l1.m - l2.m) < (l2.n - l1.n) * (l1.m - l3.m);
		}
		
	}

}
