/**
 * DMOJ - Tavas y Saddas
 * Temáticas: Recursividad + Ordenamiento + Busqueda Binaria
 *  
 * Idea: Con recursividad genero todos los posibles números y los almacenos en una
 * lista que ordeno para con busqueda binaria buscar el indice qu ocupa el n que 
 * me piden.
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
	private long MOD = 1000000000;

	public void solve() throws Exception {
		List<Long> numbers = new ArrayList<Long>();
		generateNumbers(0L, numbers);
		Collections.sort(numbers);
		long n =nextLong();
		out.printf("%d\n", Collections.binarySearch(numbers, n)+1);
	}

	public void generateNumbers(long number,List<Long> numbers) {
		if(number <= MOD) {
			if(number>0L) numbers.add(number);
			if(number*10L+4L <=MOD) generateNumbers(number*10L+4L, numbers);
			if(number*10L+7L <=MOD) generateNumbers(number*10L+7L, numbers);
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

	
}
