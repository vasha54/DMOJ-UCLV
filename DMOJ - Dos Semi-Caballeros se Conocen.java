/**
 * DMOJ - Dos Semi-Caballeros se Conocen
 * Temáticas: Teoría de Grafos + BFS
 *  
 * Idea: Sobre un tablero de ajedrez se tiene dos piezas con su forma de desplazarse
 * ambas se desplazan de forma simultanea y se desea conocer si en algún momento
 * las piezas pudieran coincidir en el mismo instante en cualquier casilla del 
 * tablero. Existe un grupo de casillas que no se puede acceder.
 * 
 * Para resolver el problema realizaremos un BFS por cada pieza para ver a todas
 * las celdas que pueden llegar. A cada casilla que pueda acceder se guarda la 
 * paridad de la cantidad de pasos con que llego. Si el valor es 0 es que llego 
 * con una cantidad de pasos par a dicha celda si fuera 1 la cantidad de pasos
 * fue impar. Luego solo tengo que chequear si existe alguna casilla o celda
 * que ambas piezas accedieron y con la misma paridad de cumplirse lo anterior
 * la respuesta es YES sino será NO.
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
	private final double EPS = 1e-9;
	
	private int[] movX = { 0, 0, 1, -1, 1,  1,-1, -1,  2, 2, -2, -2};
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1, -2, 2,  2, -2};
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000000;
	

	public void solve() throws Exception {
		int cases = nextInt();
		char [][] board =new char [8][8];
		int [][][] cost = new int [2][8][8];
		Queue<Cell> kignths =new ArrayDeque<Cell>();
		while(cases >0) {
			cases--;
			
			for(int i=0;i<8;i++) {
				board[i] = next().toCharArray();
				Arrays.fill(cost[0][i], Integer.MAX_VALUE);
				Arrays.fill(cost[1][i], Integer.MAX_VALUE);
				for(int j=0;j<8;j++) {
					if(board[i][j] == 'K') {
						kignths.add(new Cell(i, j));
					}
				}
			}
			
			while(kignths.isEmpty()==false) {
				Cell cell = kignths.poll();
				bfs(cell,board,cost[kignths.size()]);
			}
			
			boolean find = false;
			
			for(int i=0;i<8 && !find;i++) {
				for(int j=0;j<8 && !find;j++) {
					if(cost[0][i][j] == cost[1][i][j] && board[i][j]!='#' &&cost[0][i][j]!= Integer.MAX_VALUE)
						find =true;
				}
			}
			
			out.printf("%s\n", (find?"YES":"NO"));
		}
	}

	

	private void bfs(Cell cell, char[][] board, int[][] is) {
		is[cell.r][cell.c]=0;
		Queue<Cell> qBFS = new LinkedList<Cell>();
		qBFS.add(cell);
		
		while(qBFS.isEmpty()==false) {
			cell = qBFS.remove();
			for(int i=8;i<movX.length;i++) {
				Cell next = new Cell(cell.r+movY[i], cell.c+movX[i]);
				if(next.isValid() && is[next.r][next.c]==Integer.MAX_VALUE) {
					is[next.r][next.c]=(1+is[cell.r][cell.c])%2;
					qBFS.add(next);
				}
			}
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
	
	private class Cell{
		public int r,c;
		
		public Cell(int _r,int _c) {
			this.r=_r;
			this.c=_c;
		}
		
		public boolean isValid() {
			return (0<=this.r && this.r<8  && 0<=this.c && this.c<8);
		}
	}
}