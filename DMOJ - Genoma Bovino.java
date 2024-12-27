/**
 * DMOJ - Genoma Bovino.
 * Temáticas: String + Operadores a nivel de bits 
 *  
 * Idea: A cada nucleótidos que conforma el ADN le asigno una potencia de dos en
 * el intervalo de 1 a 8. Lo siguiente vamos a definir el valor de cada posición
 * en el genoma de las vacas de un tipo (con manchas por ejemplo) por cada posicion
 * del genoma su valor va ser una operacion de tipo or con los valores asociados
 * a los nucleótidos presentes en las vacas de ese grupo en dicha posicion.
 * 
 * Una vez hecho este procedimiento para los dos grupos de vacas tenemos en dos 
 * arreglos la codificación númerica del genoma de cada grupo por posicion.
 * 
 * Para determinar si una posición es potencial bastará con hacer una operación
 * de tipo nand a nivel de bit con los valores en esa posición en los arreglos
 * de codificacion si el valor arrojado es igual a 15 esa posición es potencial 
 * ya que significa que los nucleótidos presentes en grupo no estan presentes
 * en el otro grupo
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
	private final int MAX_N = 110;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';

	private int[] movX = {  0, 0, 1, -1 , 1,  1, -1, -1 };
	private int[] movY = { -1, 1, 0,  0 , 1, -1,  1, -1 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000009;


	public void solve() throws Exception {
		int nCowsB;
		int nCowsA = nCowsB =nextInt();
		int M = nextInt();

		int [] bitsA = new int [M];
		int [] bitsB = new int [M];

		String cow;

		Arrays.fill(bitsA, 0);
		Arrays.fill(bitsB, 0);

		for(int i=0;i<nCowsA;i++) {
			cow =next();
			for(int j=0;j<M;j++) {
				switch (cow.charAt(j)) {
					case 'A': bitsA[j] = (bitsA[j] | 1);  break;
					case 'C': bitsA[j] = (bitsA[j] | 2);break;
					case 'G': bitsA[j] = (bitsA[j] | 4);break;
					case 'T': bitsA[j] = (bitsA[j] | 8);break;
				}
			}
		}
		
		for(int i=0;i<nCowsB;i++) {
			cow =next();
			for(int j=0;j<M;j++) {
				switch (cow.charAt(j)) {
					case 'A': bitsB[j] = (bitsB[j] | 1);  break;
					case 'C': bitsB[j] = (bitsB[j] | 2);break;
					case 'G': bitsB[j] = (bitsB[j] | 4);break;
					case 'T': bitsB[j] = (bitsB[j] | 8);break;
				}
			}
		}
		
		int answer =0;
		for(int i=0;i<M;i++) {
			if(nand(bitsA[i] , bitsB[i],4) == (1<<4)-1)
				answer++;
		}
		
		out.printf("%d\n", answer);
	}



	private int nand(int n1, int n2, int bits) {
		
		int number = 0;
		
		for(int i=0;i<bits;i++) {
			if(!((n1 & 1<<i)== 1<<i && (n2 & 1<<i)== 1<<i)) {
				number+=(1<<i);
			}
		}
		
		return number;
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
