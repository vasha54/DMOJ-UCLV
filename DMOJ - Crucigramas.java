/**
 * DMOJ - Crucigramas
 * Temáticas: Add - Hoc
 *  
 * Idea: Validar cada celda si puede ser o no el incio de una pista ya sea verical
 * u horizontal
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
		int rows = nextInt(), columns = nextInt();
		char [][] board =new char [rows][columns];
		
		for(int i=0;i<rows;i++)
			board[i]= next().toCharArray();
		
		int numerosPistas =0;
		List<Cell> cells =new ArrayList<Cell>();
		
		for(int i=0;i<rows;i++) {
			for(int j=0;j<columns;j++) {
				if(board[i][j] == '.' && checkCell(i,j,rows,columns,board)) {
					numerosPistas++;
					cells.add(new Cell(i+1,j+1));
				}
			}
		}
		
		out.printf("%d\n",numerosPistas);
		for(int i=0;i<numerosPistas;i++)
			out.printf("%s\n", cells.get(i).toString());
		
	}
		
    
	private boolean checkCell(int i, int j, int rows, int columns, char[][] board) {
		return isHintHorizontal(i,j,rows,columns,board) || isHintVertical(i,j,rows,columns,board);
	}


	private boolean isHintVertical(int i, int j, int rows, int columns, char[][] board) {
		if((i-1<0 || (i-1>=0 && board[i-1][j]=='#')) 
				&& i+2<rows && board[i+1][j]=='.' && board[i+2][j]=='.')
			return true;
		return false;
	}


	private boolean isHintHorizontal(int i, int j, int rows, int columns, char[][] board) {
		if((j-1<0 || (j-1>=0 && board[i][j-1]=='#')) 
			    && j+2<columns && board[i][j+1]=='.' && board[i][j+2]=='.')
			return true;
		return false;
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
    	private int row;
    	private int column;
    	
    	public Cell(int _r,int _c) {
    		this.row =_r;
    		this.column = _c;
    	}
    	
    	@Override
    	public String toString() {
    		// TODO Auto-generated method stub
    		return this.row+" "+this.column;
    	}
    }
}
