/**
 * DMOJ - Conteo de Pozos
 * Temáticas: Teoria de Grafos + Componente conexa + DFS
 *  
 *  Idea: 
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
		int rows = nextInt(),pozos;
		int columns =nextInt();
		
		char [][] maps =new char [rows][columns];
		
		for(int i=0;i<rows;i++) {
			maps[i] = next().toCharArray();
		}
		
		pozos=0;
		
		for(int i=0;i<rows;i++) {
			for(int j=0;j<columns;j++) {
				if(maps[i][j]=='W') {
					pozos++;
					dfs(i,j,maps,rows,columns);
				}
			}
		}
		
		out.printf("%d\n", pozos);
	}

	private void dfs(int i, int j, char[][] maps, int rows, int columns) {
		maps[i][j]='.';
		int ni,nj;
		for(int k=0;k<movX.length;k++) {
			ni=i+movY[k];
			nj=j+movX[k];
			if(0<=ni && ni<rows && 0<=nj && nj<columns && maps[ni][nj]=='W') {
				dfs(ni, nj, maps, rows, columns);
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


}
