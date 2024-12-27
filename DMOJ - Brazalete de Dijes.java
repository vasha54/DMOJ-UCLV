/**
 * DMOJ - Brazalete de Dijes
 * Temáticas: Programación Dinámica + Mochila 0_1
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
		int N =nextInt(),Wi,Di;
		int M = nextInt();
		int [] weight= new int [M+5];
		Arrays.fill(weight, 0);

		  for(int i=0;i<N;++i){
		      Wi =nextInt();
		      Di =nextInt();
		      for (int j=M; j>=Wi; --j){
		    	  if(weight[j]<weight[j-Wi]+Di)
		    		 weight[j]=weight[j-Wi]+Di;
		        }
		    }
		  out.printf("%d\n",weight[M]);
	}

	public long  iSqrtNewton(long n){
		long x=1;
		boolean decreased=false;
		for(;;){
			long nx=(x+n/x)>>1;
			if(x==nx || nx>x && decreased)
				break;
			decreased = nx<x;
			x=nx;
		}
		return x;
	}

	private long[] squareRoot(long m, long n) {
		long sqrtM=0,sqrtN=0;
		if(n>0L)sqrtN = iSqrtNewton(n);
		if(m>0L)sqrtM = iSqrtNewton(m);
		long [] answer = {sqrtM,sqrtN};
		return answer;
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
