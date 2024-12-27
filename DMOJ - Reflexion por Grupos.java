/**
 * DMOJ - Reflexión por Grupos
 * Temáticas: String 
 *  
 * Idea: Dada una secuencia de caracteres invertir el orden de los caracteres cada
 * subsecuencias de K caracteres de longitud.
 * . 
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

	private int[] movX = { 0, 0, 1, -1 };
	private int[] movY = { -1, 1, 0, 0 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000009;

	boolean isVolwels (char _a) {
		return (_a=='A'|| _a=='E'|| _a=='I'|| _a=='O'|| _a=='U');
	}

	public void solve() throws Exception {

		int K = nextInt();
		while(K!=0) {
			String sequence =next();
			String inverse = "";
			int L = sequence.length()/K;
			for(int i=0;i<sequence.length();i+=L) {
				String subK=sequence.substring(i,i+L);
				for(int j=subK.length()-1;j>=0;j--) {
					inverse=inverse+subK.charAt(j);
				}
			}
			out.println(inverse);
			K = nextInt();
		}
	}

	Main() throws Exception {
		/*
		 * Esta entrada se debe activar cuando se hace una ejercicio de lectura hasta
		 * fin de fichero copiar la entrada en un fichero "Input.txt" y comentar el otro
		 * in . A la hor de enviar comentar este y descomentar el otro
		 */
		// in = new BufferedReader(new FileReader("Inpu.txt"));
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

	String next() throws Exception {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null)
				return null;
			eat(line);
		}
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws Exception {
		new Main();
	}

}
