/**
 * DMOJ - Vacas Cenadoras.
 * Temáticas: Programación Dinámica + Tabla acumulativa
 *  
 *  Idea: Usar una tabla acumulativa que para cada vaca i llevar cuantas vacas
 *  de cada tipo llevo por la izquierda y por la derecha incluyendo la i. Luego 
 *  por cada par adyacentes de vacas (i;i+1) 
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
		int ncows =nextInt(),answer,turnLeft,turnRigth,type1=0,type2=0;
		Cow [] cows =new Cow[ncows+2];
		cows[0]=new Cow(0);
		cows[ncows+1]=new Cow(0);
		
		for(int i=1;i<=ncows;i++) {
			cows[i]=new Cow(nextInt());
			if(cows[i].type==1) {
				cows[i].type1Left=cows[i-1].type1Left+1;
				cows[i].type2Left=cows[i-1].type2Left;
				type1++;
			}else if(cows[i].type==2) {
				cows[i].type1Left=cows[i-1].type1Left;
				cows[i].type2Left=cows[i-1].type2Left+1;
				type2++;
			}
			cows[i].totalLeft=cows[i-1].totalLeft+1;
		}
		
		for(int i=ncows;i>=1;i--) {
			if(cows[i].type==1) {
				cows[i].type1Rigth=cows[i+1].type1Rigth+1;
				cows[i].type2Rigth=cows[i+1].type2Rigth;
			}else if(cows[i].type==2) {
				cows[i].type1Rigth=cows[i+1].type1Rigth;
				cows[i].type2Rigth=cows[i+1].type2Rigth+1;
			}
			cows[i].totalRigth=cows[i+1].totalRigth+1;
		}
		
		answer =Math.min(type1, type2);
		for(int i=1;i<ncows;i++) {
			turnLeft=cows[i].totalLeft-cows[i].type1Left;
			turnRigth=cows[i+1].totalRigth-cows[i+1].type2Rigth;
			answer=Math.min(answer, turnLeft+turnRigth);
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

	private int nextInt() throws Exception {return Integer.parseInt(next());}

	private long nextLong() throws Exception {return Long.parseLong(next());}

	private double nextDouble() throws Exception {return Double.parseDouble(next());}

	public static void main(String[] args) throws Exception {new Main();}  

	private class Cow{
		public int type1Left;
		public int type2Left;
		public int type1Rigth;
		public int type2Rigth;
		public int totalLeft;
		public int totalRigth;
		public int type;
		
		public Cow(int _type) {
			this.type = _type;
			this.type1Left = 0;
			this.type2Left = 0;
			this.type1Rigth = 0;
			this.type2Rigth = 0;
			this.totalLeft = 0;
			this.totalRigth = 0;
		}
	}
}
