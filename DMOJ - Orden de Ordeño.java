/**
 * DMOJ - Orden de Ordeño
 * Temáticas: Greedy + Estructura de Datos + Range Tree
 *  
 *  Idea: Como los instantes de tiempo de las vacas están en el rango de 0 a 
 *  10000 vamos aprovechar este detalle y vamos a crear un arreglo de Vacas con 
 *  esa capacidad donde en cada posición va a ver una vaca con una cantidad de 
 *  litros igual a cero. En este arreglo en la posición i voy a colocar aquella 
 *  vaca que su instante de tiempo inferior de ordeño es i y su cantidad de 
 *  litros de leche es superior a cualquier otra vaca que su tiempo inferior de 
 *  ordeño es i pero su cantidad de litro es inferior. En caso de que exista 
 *  una vaca con el mismo instante inferior de ordeño i y litros de leche 
 *  superior a esta vaca se almacena en una cola con prioridad donde la 
 *  prioridad se define de la siguiente manera:
 *  	tiempo inferior de ordeño menor.
 *  	litros de leche menor.
 *  Construyo un RangeTree donde por cada rango busco la vaca que menos aporta 
 *  así como la suma de todos los litros de leche del rango. Luego mientras la 
 *  cola con prioridad no este vacía saco la vaca que esta en el frente. 
 *  Busco en el RangeTree la vaca que menos aporta en el rango de 0 a Z donde 
 *  Z es el instante inferior de ordeño de la vaca que saque de la cola. Si la 
 *  vaca encontrada da un aporte inferior a la sacada de la cola, actualizo el 
 *  RangeTree con la vaca de la cola y la que estaba en el RangeTree pasa a la 
 *  cola. En caso contrario la vaca sacada de la cola es deshechada. Luego solo 
 *  tengo que hacer una consulta de todo el rango RangeTree que me devuelva 
 *  la suma de todos los litros de leche de ordeño de las vacas presentes.
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

	private int[] movX = {  0, 0, 1, -1 , 1,  1, -1, -1 };
	private int[] movY = { -1, 1, 0,  0 , 1, -1,  1, -1 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000009;


	public void solve() throws Exception {
		int ncows=nextInt(),maxTime =Integer.MIN_VALUE;
		Cow [] cows = new Cow[MAX_N];
		PriorityQueue<Cow> cowsPQ =new PriorityQueue<Cow>();

		for(int i=0;i<cows.length;i++) {
			cows[i]=new Cow(0L,i);
		}
		
		
		for(int i=0;i<ncows;i++) {
			Cow tmp =new Cow(nextLong(), nextInt()+3);
            maxTime=Math.max(maxTime, tmp.time);
			cowsPQ.add(tmp);	
		}
		RangeTree tree = new RangeTree(cows);
		tree.initTree(1, 1, maxTime);

		while(cowsPQ.isEmpty()==false && cowsPQ.peek().milk>0) {
			Cow cow = cowsPQ.poll();
			Cow t =tree.query1(1, 3, cow.time-1, 1, maxTime);
			//out.printf("%s\n",cow.toString());
			//out.printf("%s\n",t.toString());
			if(cow.time>t.time && cow.milk > t.milk) {
				cow.time=t.time;
				tree.update(1, cow.time, cow, 1, maxTime);
                if(t.milk!=Long.MAX_VALUE && t.time!=Integer.MAX_VALUE && t.milk!=0)
                	cowsPQ.add(t);
			}
		}
		
		out.printf("%d\n", tree.query2(1, 1, maxTime, 1, maxTime));
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

	private int nextInt() throws Exception {return Integer.parseInt(next());}

	private long nextLong() throws Exception {return Long.parseLong(next());}

	private double nextDouble() throws Exception {return Double.parseDouble(next());}

	public static void main(String[] args) throws Exception {new Main();}  

	private class Cow implements Comparable<Cow>{
		public int time;
		public long milk;

		public Cow(long _m,int _t) {
			this.time = _t;
			this.milk = _m;
		}

		@Override
		public int compareTo(Cow _cow) {
			if( this.time < _cow.time ) return -1;
			else if( this.time > _cow.time ) return 1;
			else if( this.milk > _cow.milk ) return -1;
			else if( this.milk < _cow.milk ) return 1;
			else return 0;
		}
		
		@Override
		public String toString() {
			return "{time:"+this.time+";milk:"+this.milk+"}";
		}
	}

	private class RangeTree{

		public Cow [] niz;
		public Cow [] RT;
		public long [] milks;

		public RangeTree(Cow [] _array) {
			niz = Arrays.copyOf(_array, _array.length);
			RT = new Cow [niz.length << 2];
			milks = new long [niz.length << 2];
			Arrays.fill(milks, 0);
		}

		public void initTree(int idx, int left, int right){
			if(left == right){ RT[idx] = niz[left]; milks[idx]=RT[idx].milk;}
			else{
				int MID =(left+right)/2;
				initTree(2*idx, left, MID);
				initTree(2*idx+1, MID+1, right);
				
				if(RT[2*idx].milk<=RT[2*idx+1].milk) RT[idx] = RT[2*idx];
				else RT[idx] = RT[2*idx+1];
				milks[idx]=milks[2*idx]+milks[2*idx+1];
			}
		}

		public void update(int idx, int x, Cow val, int left, int right){
			if(left == right){ RT[idx] = val;milks[idx]=RT[idx].milk;}
			else{
				int MID =(left+right)/2;
				if (x <= MID) update(2*idx, x, val, left, MID);
				else update(2*idx+1, x, val, MID+1, right);
				if(RT[2*idx].milk<=RT[2*idx+1].milk)
					RT[idx] = RT[2*idx];
				else
					RT[idx] = RT[2*idx+1];
				milks[idx]=milks[2*idx]+milks[2*idx+1];
			}
		}

		public Cow query1(int idx, int l, int r, int left, int right){
			
			if (l <= left && right <= r) 
				return RT[idx];
			Cow tl = new Cow(Long.MAX_VALUE, Integer.MAX_VALUE);
			Cow tr = new Cow(Long.MAX_VALUE, Integer.MAX_VALUE);
			
			int MID =(left+right)/2;
			if (l <= MID) {
				tl = query1(2*idx, l, r, left, MID);
			} 
			if (r > MID) {
				tr = query1(2*idx+1, l, r, MID+1, right);
			}
			
			if(tl.milk<=tr.milk)
				return tl;
			else
				return tr;
		}
		
		public long query2(int idx, int l, int r, int left, int right){
			if (l <= left && right <= r) return milks[idx];
			long ret = 0L;
			int MID =(left+right)/2;
			if (l <= MID) {
				ret+= query2(2*idx, l, r, left, MID);
			} 
			if (r > MID) {
				ret+= query2(2*idx+1, l, r, MID+1, right);
			} 
			return ret;
		}
	}
}
