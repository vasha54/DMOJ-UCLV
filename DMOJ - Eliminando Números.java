
/**
 * DMOJ - Eliminando Números
 * Temáticas: Teoria de Numeros + Criba numeros primos + Busqueda binaria
 *  
 * Idea: Realizar una criba linear para generar todos los posibles primos hasta
 * el maximo posible N y despues para cada posible valor con busqueda binaria cuento
 * cuantos primos menor o iguales existen menores que el. 
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

	public  int upper_bound(ArrayList<Integer> primes, int key){
        int mid, best = -1;
  
        int low = 0;
        int high = primes.size()-1;
  
        while (low <= high) {
        	
            mid = (high + low) / 2;
            //out.printf("mid %d %d\n ", mid,primes.get(mid));
            if (key < primes.get(mid)) {
                high = mid - 1;
            }
            else {
                low= mid+1;
                best=Math.max(mid, best);
            }
        }
        return best+1;    
    }
	
	public void solve() throws Exception {
	
		
		int [] lp = new int [MAX_N+1] ;
		ArrayList<Integer> pr =new  ArrayList<Integer>() ;
		for( int i=2;i<=MAX_N;++i){
		   if(lp[i]==0){
		      lp[i]=i;
		      pr.add(i);
		   }
		   for( int j =0; j<( int )pr.size() && pr.get(j)<=lp[ i ] && i * pr.get(j) <= MAX_N; ++j ) {
		        lp[ i * pr.get(j) ] = pr.get(j) ;
		   }
		}
		
		int N;

		for (int i=1;i<=10;i++) {
			N = nextInt();
			out.printf("%d\n",upper_bound(pr,N));
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
