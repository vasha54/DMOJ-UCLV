/**
 * DMOJ - Juego de Dígitos Vacuno
 * Temáticas: Teoria de Juego
 *  
 * Idea: Para cualquier número del 1 al 9 gana Besie. Para cualquier otro número
 * Besie podra ganar si una de las dos opciones (sustraer el mayor digito o 
 * sustraer el mínimo digito) produce un valor para el cual ya se conoce que ella
 * pierde cuando se comienza el juego en ese número.
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
	private final int MAX_N = 1000010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';

	private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1 };
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000000;

	public void solve() throws Exception {
		int cases = nextInt(),z,y;
		boolean [] wins = new boolean[MAX_N];
		
		for(int i=1;i<=9;i++) {
			wins[i]=true;
		}
		
		for(int i=10;i<MAX_N;i++) {
			z=i-f(i);
			y=i-g(i);
			if(!wins[z] || !wins[y]) wins[i]=true;
			else wins[i] =false;
				
		}
		
		while(cases>0) {
			cases--;
			z=nextInt();
			out.printf("%s\n",(wins[z]?"YES":"NO"));
		}
	}

	
	

	private int g(int i) {
		int digit=Integer.MAX_VALUE;
		while(i>0) {
			if(i%10!=0)
				digit = Math.min(digit,i%10);
			i/=10;
		}
		return digit;
	}

	private int f(int i) {
		int digit=Integer.MIN_VALUE;
		while(i>0) {
			if(i%10!=0)
				digit = Math.max(digit,i%10);
			i/=10;
		}
		return digit;
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
