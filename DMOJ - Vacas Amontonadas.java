
/**
 * DMOJ - Vacas Amontonadas
 * Temáticas: Range tree +  Busqueda Binaria
 *  
 * Idea: Ordenar las N vacas acorde a sus posiciones de forma creciente. Vamos
 * a construir un Range Tree que me permita dentro de un rango de posiciones [1,N]
 * saber cual es la vaca más alta. Las posibles vacas amontonadas son las que van
 * estar en el rango de [2,N-1]. Para chequear si la vaca i es amontonada debemos:
 * 
 * Buscar posL es la posición más a la izquierda en arreglo donde exista una vaca
 * cuya posición con respecto a la posición de la vaca i no supere la diferencia D.
 * 
 * Buscar posR es la posición más a la derecha en arreglo donde exista una vaca
 * cuya posición con respecto a la posición de la vaca i no supere la diferencia D.
 * 
 * Ambas búsquedas como las vacas están ordenadas lo podemos hacer utilizando búsqueda
 * binaria implementando un lowwer y upper bounds.
 * 
 * Luego solo debemos ver con el rango Tree si en los intervalos de [posL,i] y
 * [i,posR] existen vacas cuyas alturas superen el doble de la altura de la vaca
 * en i de ser así la vaca i se cuenta como amontonada.
 * 
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
	private final int MAX_N = 500010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';
	private final double EPS = 1e-9;

	private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1, 2, 2, -2, -2 };
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1, -2, 2, 2, -2 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000000;

	private void solve() throws Exception {
		// TODO Auto-generated method stub
		int ncows=nextInt();
		long D = nextLong();
		Cow [] cows= new Cow[ncows+1];
		
		for(int i=1;i<=ncows;i++)
			cows[i]=new Cow(nextLong(), nextLong());
		
		Arrays.sort(cows,1,ncows+1);
		
		//for(int i=1;i<=ncows;i++)out.printf("%s\n", cows[i].toString());
		
		int answer=0;
		
		RangeTree tree =new RangeTree(cows, ncows);
		tree.build(1, 1, ncows);
		
		for(int i=2;i<=ncows-1;i++) {
			int leftPos = searchLeft(cows,i,D);
			int rigthPos = searchRigth(cows,i,D);
			
			long mLeft=tree.query(1, leftPos, i, 1, ncows);
			long mRigth=tree.query(1, i, rigthPos, 1, ncows);
			
			if(mLeft>=cows[i].heigth*2L && mRigth>=cows[i].heigth*2L)
				answer++;
		}
		
		out.printf("%d\n", answer);
			
	}

	private int searchRigth(Cow[] cows, int i, long d) {
		// TODO Auto-generated method stub
		int index = i;
		int begin=i;
		int end=cows.length-1;
		int pivot;
		while(begin<=end) {
			pivot=(begin+end)/2;
			
			if(Math.abs(cows[i].pos-cows[pivot].pos)<=d) {
				index=Math.max(index, pivot);
				begin=pivot+1;
			}
			else
				end=pivot-1;
				
		}
		return index;
	}

	private int searchLeft(Cow[] cows, int i, long d) {
		// TODO Auto-generated method stub
		int index = i;
		int begin=1;
		int end=i;
		int pivot;
		while(begin<=end) {
			pivot=(begin+end)/2;
			
			if(Math.abs(cows[i].pos-cows[pivot].pos)<=d) {
				index=Math.min(index, pivot);
				end=pivot-1;
			}
			else
				begin=pivot+1;	
		}
		return index;
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

	private class Cow implements Comparable<Cow> {
		
		public long pos,heigth;
		
		public Cow(long _p,long _h) {
			this.pos=_p;
			this.heigth =_h;
		}

		@Override
		public int compareTo(Cow _cow) {
			// TODO Auto-generated method stub
			if(this.pos < _cow.pos)return -1;
			else return 1;
		}
		
		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return "Cow pos:"+this.pos+" heigth:"+this.heigth;
		}
	}
	
	private class RangeTree {
		private Cow [] data ;
		private long [] rt;
		
		public RangeTree(Cow [] _cows, int ncows) {
			 this.data = Arrays.copyOf(_cows, _cows.length);
			 this.rt = new long[data.length << 2];
		}
		
		public void build(int index,int left,int rigth) {
			if(left==rigth) {
				this.rt[index]=this.data[left].heigth;
			}else {
				int pivot = (left+rigth)/2;
				this.build(index*2, left, pivot);
				this.build(index*2+1, pivot+1, rigth);
				this.rt[index]=Math.max(this.rt[index*2], this.rt[index*2+1]);
			}
		}
		
		public long query(int index,int l,int r, int left, int rigth) {
			if(r<l) 
				return 0L;
			if(rigth<l || r<left)  
				return 0L;
			if(l<=left && rigth<=r) 
				return this.rt[index];
			else {
				int pivot = (left+rigth)/2;
				long qLeft = 0L;
				long qRigth = 0L;
				
				if(l<=pivot) qLeft = this.query(2*index, l, r, left, pivot);
				if(pivot<r) qRigth = this.query(2*index+1, l, r, pivot+1, rigth);
				
				return Math.max(qLeft, qRigth);
			}
			
		}
	}
}