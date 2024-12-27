/**
 * DMOJ - El Vuelo de la Bruja
 * Temáticas: Programación Dinamica + Suma Acumulativa + Busqueda Binaria
 *  
 * Idea: Hago una tabla de suma acumulativa de los pesos de las escobas tal que
 * pueda calcular de forma constante cuanto pesas todas las escobas hasta la 
 * escoba i. Luego para saber cuanto pesas las escobas en el rango de j a i solo
 * tengo que aplicar la expresión escobas[i]-escobas[j-1]. Luego para hallar la 
 * M hago una busqueda binaria en el rango de 0 a K (K es la cantidad de escobas 
 * inicial) para buscar el maximo M que todas las subsecuencias de tamaño M el 
 * pesos de escobas de esas subsecuencias no supere el limite de peso escoba 
 * inicialmente dado.
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
	private final int MAX_N = 5000010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';

	private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1 };
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 10000;

	public void solve() throws Exception {
		int cases = nextInt();
		
		while(cases>0) {
			cases--;
			long weigthLimit = nextLong();
			int nEscobas = nextInt(),begin,end,pivot;
			long [] escobas = new long [nEscobas+1];
			escobas[0]=0L;
			for(int i=1;i<=nEscobas;i++) {
				escobas[i]=escobas[i-1]+nextLong();
			}
			
			int M =0;
			
			begin=1;
			end=nEscobas;
			
			while(begin<=end){
				pivot=(begin+end)/2;
				if(check(escobas,pivot,nEscobas,weigthLimit)==true) {
					M=Math.max(pivot, M);
					begin=pivot+1;
				}else {
					end=pivot-1;
				}
			}
			
			out.printf("%d\n", M);
		}
	}

	private boolean check(long[] escobas, int m, int nEscobas, long weigthLimit) {
		for(int i=m;i<=nEscobas;i++) {
			if(escobas[i]-escobas[i-m]>weigthLimit)
				return false;
		}
		return true;
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
