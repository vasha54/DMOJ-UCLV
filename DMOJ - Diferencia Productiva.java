/**
 * DMOJ - Diferencia Productiva
 * Temáticas: Ordenamiento + Busqueda Binaria
 *  
 *  Idea: Dada un conjunto elaborar el mayor subconjunto de elementos no 
 *  necesariamente concecutivos tal que el valor de la diferencia del mayor y 
 *  el menor elemento del subconjunto sea menor o igual a un valor dado.
 *  Mientras mas elemento tenga el subconjunto mayor será el mismo.
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
		int n =nextInt(),answer=1;
		long D =nextLong();
		long [] values =new long [n];
		for(int i=0;i<n;i++) values[i]=nextLong();
		Arrays.sort(values);
		
		for(int i=0;i<n;i++) {
			answer=Math.max(answer, subSet(i,D,values,n));
		}
		
		out.printf("%d\n", answer);
	}

	

	private int subSet(int i, long d, long[] values, int n) {
		int pivot ,tBegin = i, bestPos = i, tEnd = n-1;
		
		while(tBegin<=tEnd) {
			pivot = (tBegin+tEnd)/2;
			if(values[pivot]-values[i]<=d) {
				bestPos=Math.max(bestPos, pivot);
				tBegin=pivot+1;
			}
			else
				tEnd=pivot-1;
		}
		
		return (bestPos-i)+1;
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


}
