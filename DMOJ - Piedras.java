/**
 * DMOJ - Piedras
 * Temáticas: Teoria de Juego
 *  
 * Idea: Para una cantidad de 0 piedra gana el segundo jugador por tanto es una 
 * posicion perdedora para el primer jugador. Siempre que el jugador que le toca
 * jugar pueda alcanzar una posición perdedora l para el primer jugador a partir
 * de l ganará la partida. 
 * 
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
		int N =nextInt(), K=nextInt();
	    int [] isWinnig =new int[K+1];
	    int [] moves = new int [N];
	    boolean removeStone;
	    
	    for(int i=0;i<N;i++) moves[i] = nextInt();
	    
	    Arrays.fill(isWinnig, -1);
	    Arrays.sort(moves);
	    
	    isWinnig[0]=0;
	    
	    for(int i=1;i<=K;i++) {
	    	removeStone =false;
	    	for(int j=0;j<N;j++) {
	    	    if(i-moves[j]>=0 && isWinnig[i-moves[j]]==0) {
	    	    	isWinnig[i]=1;
	    	    	removeStone=true;
	    	    	break;
	    	    }
	    	}
	    	if(!removeStone)isWinnig[i]=0;
	    }
	    
	    out.printf("%s\n", ((isWinnig[K]==1)?"First":"Second"));
	    
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