/**
 * DMOJ - La Tarea de Rub
 * Temáticas: Teoria de Grafo + Djikstraj
 *  
 * Idea: Recorrido minimo costo de las celdas de la primera columna hacia 
 * cualquiera de las celdas de la derecha
 *    
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


	public void solve() throws Exception {
		int rows=nextInt(),columns=nextInt();
		
		long [][] cost = new long[rows+5][columns+5];
		long [][] distance = new long[rows+5][columns+5];
		boolean [][] marks = new boolean [rows+5][columns+5];
		
		PriorityQueue<Cell> queue = new PriorityQueue<Cell>();
		
		for(int i=1;i<=rows;i++) {
			for(int j=1;j<=columns;j++) {
				cost[i][j]=nextLong();
				distance[i][j] = (j==1 ? cost[i][j]: Long.MAX_VALUE);
				marks[i][j] = false;
				if(j==1) {
					queue.add(new Cell(i,j,distance[i][j]));
				}
			}
		}
		
		while(queue.isEmpty()==false) {
			Cell c = queue.poll();
			if(!marks[c.row][c.column]) {
				
				for(int e=0;e<movX.length;e++) {
					int nr= c.row+movY[e];
					int nc = c.column+movX[e];
					if(isValidCell(nr,nc,rows,columns)) {
						if(c.dist+cost[nr][nc] < distance[nr][nc]) {
							distance[nr][nc] = c.dist+cost[nr][nc];
							Cell ncell = new Cell(nr, nc, distance[nr][nc]);
							queue.add(ncell);
						}
					}
				}
				
				marks[c.row][c.column] =true;
			}
		}
		
		long answer=distance[1][columns];
		for(int i=1;i<=rows;i++) {
			answer=Math.min(answer, distance[i][columns]);
		}
		out.printf("%d\n", answer);
		
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
    
    
    private class Cell implements Comparable<Cell>{
    	public int row;
    	public int column;
    	public long dist;
    	
    	public Cell(int _r,int _c,long _d) {
    		this.row =_r;
    		this.column = _c;
    		this.dist = _d;
    	}

		@Override
		public int compareTo(Cell _cell) {
			if(this.dist < _cell.dist) return -1;
			else if (this.dist > _cell.dist) return 1;
			return 0;
		}
		
		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return "row:"+this.row+" column:"+this.column+" dist:"+this.dist;
		}
    }
    
    private boolean isValidCell(int i, int j, int rows, int columns) {
		
		return (1 <= i && i <= rows && 1 <= j && j <= columns);
	}
    
}