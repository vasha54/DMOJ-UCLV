/**
 * DMOJ - Lista de Baldes
 * Temáticas: Ordenamiento
 *  
 * Idea: Ordenar los incicios y finales de ordeños en caso de tiempo similares 
 * los tiempos que se corresponde a los inicios de ordeños tienen prioridad. Luego
 * recorrer los tiempos y cada vez que encuentro un tiempo de inicio se suma los
 * baldes y cada vez que encuentro un tiempo de finalización se resta los baldes
 * .Quedarme con el mayor numero que genera este procedimiento en cualquier momento.
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
		int nbaldes = nextInt(),O,C,B;
		List<Balde> baldes =new ArrayList<Balde>();
		
		for(int i=0;i<nbaldes;i++) {
			O = nextInt();
			C = nextInt();
			B = nextInt();
			
			baldes.add(new Balde(O, B, TypeBalde.OPEN));
			baldes.add(new Balde(C, B, TypeBalde.CLOSE));
		}
		
		Collections.sort(baldes);
		
		int answer = 0;
		int baldesUse = 0;
		for(int i=0;i<2*nbaldes;i++) {
			
			if(baldes.get(i).type == TypeBalde.OPEN)
				baldesUse += baldes.get(i).nbalde;
			else if(baldes.get(i).type == TypeBalde.CLOSE)
				baldesUse -= baldes.get(i).nbalde;
			
			answer = Math.max(answer, baldesUse);
		}
		
		out.printf("%d\n", answer);
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

	private class Balde implements Comparable<Balde>{
		public int time;
		public int nbalde;
		public TypeBalde type;
		
		public Balde(int _time, int _nbalde, TypeBalde _type) {
			this.time = _time;
			this.nbalde = _nbalde;
			this.type = _type;
		}

		@Override
		public int compareTo(Balde balse) {
			if(this.time < balse.time) return -1;
			else if(this.time > balse.time) return 1;
			else if(this.time == balse.time) 
				return (this.type.ordinal() < balse.type.ordinal() ? -1: 1);
			return 0;
		}
		
		@Override
		public String toString() {
			return "{time:"+this.time+"; baldes:"+this.nbalde+"; type:"+this.type.toString()+"}";
		}
	}
	
	private enum TypeBalde{
		OPEN,
		CLOSE
	}
}
