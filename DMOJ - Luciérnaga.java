
/**
 * DMOJ - Luciérnaga
 * Temáticas: Programación Dinámica + Suma de Prefijo
 *  
 * Idea: Construir en prefijo de suma con las consultas (a,b) donde en la altura
 * a incremento en uno porque a partir de esa altura a todas las alturas enteras hasta
 * b tienen un obstáculo adicional luego para equilibrar decremento en uno el valor de la 
 * posición en (b+1) y luego ver el menor valor en suma de prefijo que se genera 
 * y la cantidad de veces. Cuando es una estalagmita la consulta se debe procesar
 * de la forma (1,x) siendo x la altura de la estalagmita. En el caso las estalactitas
 * a consulta sería de la forma (H-x+1,H) siendo H la altura de la cueva y x la 
 * el largo de la estalactita. La idea es muy similar al problema Tarea de impacto
 * del mismo jurado la diferencia radica que en aquel se debe buscar el mayor valor.
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
		int N=nextInt(), H=nextInt(),a;
		long [] ps =new long [H+2];
		Arrays.fill(ps, 0);
		for(int i=0;i<N;i++) {
			a=nextInt();
			if(i%2==0) {ps[1]++;ps[a+1]--;}
			else { ps[H-a+1]++; ps[H+1]--;}
		}
		long best=Long.MAX_VALUE;
		int count =1;
		
		for(int i=1;i<=H;i++) {
			ps[i]+=ps[i-1];
			if(best>ps[i]){best=ps[i]; count=1;}
			else if(ps[i]== best) count++;
		}
		out.printf("%d %d",best,count);
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