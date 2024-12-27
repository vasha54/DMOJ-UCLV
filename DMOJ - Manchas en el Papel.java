/**
 * DMOJ - Manchas en el Papel
 * Temáticas: Teoria de Grafos + Componente Conexa
 *  
 * Idea: Dado un grafo sobre tablero detectada las componentes conexa y ver cual
 * tiene mas nodos. Utilizar un BFS para esto
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
		int rows =nextInt(),columns =nextInt();
		char [][] board = new char[rows][columns];
		
		for(int i=0;i<rows;i++) {
			board[i] =next().toCharArray();
		}
		
		int componentes=0;
		long area =0,areat;
		
		for(int i=0;i<rows;i++) {
			for(int j=0;j<columns;j++) {
				if (board[i][j] == '0')
					continue;
				
				areat=scanArea(i,j,board,rows,columns);
				componentes++;
				area = Math.max(areat, area);
			}
		}
		
		out.printf("%d %d\n", componentes,area);
		
	}
		
    

	private long scanArea(int i, int j, char[][] _board, int rows, int columns) {
		int area=0;
		Queue<Cell> bfs =new ArrayDeque<Cell>();
		
		_board[i][j]='0';
		
		bfs.add(new Cell(i,j));
		
		while(bfs.isEmpty()==false) {
			Cell current = bfs.poll();
			for(int e=0;e<movX.length;e++) {
				int nr=current.row+movY[e];
				int nc=current.column+movX[e];
				if(isValidCell(nr,nc,rows,columns) && _board[nr][nc]=='1') {
					bfs.add(new Cell(nr, nc));
					_board[nr][nc]='0';
				}
			}
			area++;
		}
		return area;
	}



	private boolean isValidCell(int nr, int nc, int rows, int columns) {
		
		return (0<=nr && nr<rows && 0<=nc && nc<columns);
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
    
    private class Cell{
    	public int row;
    	public int column;
    	
    	public Cell(int _r,int _c) {
    		this.row =_r;
    		this.column = _c;
    	}
    }
    
    
}
