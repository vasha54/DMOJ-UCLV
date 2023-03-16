/**
 * DMOJ - Juego del Viajero Veloz
 * Temáticas: Estructura de Datos + Cola
 *  
 *  Idea: Simulacion con colas
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
		int cases =nextInt();
		
		while(cases >0) {
			cases--;
			int nplayers=nextInt();
			int nlength =nextInt();
			int ndices =nextInt();
			
			Queue<Player> players = new ArrayDeque<Player>();
			Queue<Player> winners = new ArrayDeque<Player>();
			Queue<Integer> dices = new ArrayDeque<Integer>();
			
			
			for(int i=1;i<=nplayers;i++) {
				players.add(new Player(i,1));
			}
			
			int [] boards =new int [nlength+1];
			
			for(int i=1;i<=nlength;i++)
				boards[i] = nextInt();
			
			for(int i=0;i<ndices;i++)
				dices.add(nextInt());
			
			
			while( players.isEmpty()==false && dices.isEmpty()==false ){
				Player p = players.poll();
				int dice = dices.poll();
				
				int pos = p.pos+dice+boards[p.pos+dice];
				p.pos = pos;
				
				if( p.pos ==nlength)winners.add(p);
				else players.add(p);
			}
			
			if(winners.isEmpty())out.printf("-1\n");
			else {
				out.printf("%d", winners.poll().order);
				while(winners.isEmpty()==false) {
					out.printf(" %d", winners.poll().order);
				}
				out.println();
			}
			
			
			
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
	
	private class Player{
		public int order;
		public int pos;
		
		public Player(int _order,int _pos) {
			this.order = _order;
			this.pos= _pos;
		}
	}

}
