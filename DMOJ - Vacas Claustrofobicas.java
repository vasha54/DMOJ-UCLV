/**
 * DMOJ - Vacas Claustrofóbicas
 * Temáticas: Geometria + Closet Pair Points
 *  
 * Idea: Dado una coleccion de puntos indicar los identificadores de los dos
 * puntos mas cercanos. 
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
		int npoints = nextInt(),X,Y;
		Point [] points =new Point[npoints+10];
		
		for(int i=1;i<=npoints;i++) {
			X = nextInt();
			Y = nextInt();
			points[i] =new Point(i, X, Y);
		}
		
		closestPairWithLineSweep(points, npoints);
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

	private double distance(Point p1, Point p2) {           
		return Math.sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y)); 
	}

	private void closestPairWithLineSweep(Point [] _points, int _npoints) {
		Arrays.sort(_points,1,_npoints+1);
	
		if(_npoints!=0) {
			double dist = Double.MAX_VALUE,distTMP;
			int tBegin = 1 , tEnd = 1 , tot = 1 , ID1=0, ID2=0;
			
			for(int i=2;i<=_npoints;i++){
				while(tot > 0 && 0.0+_points[i].x-_points[tBegin].x > dist){ 
					tBegin++; 
					tot--;
				}
		   
				for(int j=tBegin;j<=tEnd;j++) {
					distTMP = distance(_points[i], _points[j]); 
					if( dist > distTMP ) {
						dist = distTMP;
						ID1= _points[i].id;
						ID2= _points[j].id;
					}
				}
				tEnd++; 
				tot++;
			}
			
			out.printf("%d %d\n", Math.min(ID1, ID2),Math.max(ID1, ID2) );
		}
	}


	private class Point implements Comparable<Point>{

		public int id;
		public double x;
		public double y;

		public Point(int _id, int _x,int _y) {
			this.id =_id;
			this.x =_x;
			this.y =_y;
		}

		@Override
		public int compareTo(Point p1) {
			if(this.x < p1.x) return -1;
			else if (this.x > p1.x) return 1;
			else {
				if(this.y < p1.y) return -1;
				else if(this.y > p1.y) return 1;
				else return 0;
			}
		}
		
		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return "{x:"+this.x+"; y:"+this.y+"; id:"+this.id+"}";
		}
	}
}
