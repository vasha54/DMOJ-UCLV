/**
 * DMOJ - Lavando los Platos
 * Temáticas: Estructura de Datos + Pila
 *  
 *  Idea: Simulacion con pilas
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
		int N = nextInt();

		Stack<Integer> sucios=new Stack<Integer>();
		Stack<Integer> fregados=new Stack<Integer>();
		Stack<Integer> limpios=new Stack<Integer>();

		for(int i=N;i>=1;i--) sucios.add(i);

		while(sucios.empty()==false || fregados.empty()==false ) {
			int command =nextInt();
			int dishes = nextInt();

			switch (command) {
			case 1: 
				while(!sucios.empty() && dishes>0) {
					dishes--;
					fregados.add(sucios.pop());
				}
				break;
			case 2:
				while(!fregados.empty() && dishes>0) {
					dishes--;
					limpios.add(fregados.pop());
				}
				break;
			}
		}
		while(limpios.empty()==false) {
			out.printf("%d\n",limpios.pop());
		}
	}

	Main() throws Exception {
		/*
		 * Esta entrada se debe activar cuando se hace una ejercicio de lectura hasta
		 * fin de fichero copiar la entrada en un fichero "Input.txt" y comentar el otro
		 * in . A la hor de enviar comentar este y descomentar el otro
		 */
		//in = new BufferedReader(new FileReader("Input.txt"));
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

}
