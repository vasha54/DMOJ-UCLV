/**
 * DMOJ - El Carcelero Borracho 
 * Temáticas: Teoria de Numeros + Cantidad de divisores de un numero + Criba
 *  
 * Idea: Dado un valor N es hallar la cantidad de divisores de cada numero 
 * (incluye al 1 y al mismo numero) en el rango de 1 a N luego aquellos con una 
 * cantidad de impar divisores serán las celdas que quedarán abiertas.
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
    
    private int [] movX = { 0, 0, 1, -1};
    private int [] movY = {-1, 1, 0,  0};
    private long [] cards ={1,10,100,1000,10000};
    private long MOD =1000000009;
    
   
    
    public void solve() throws Exception {
    	boolean [] openCell = new  boolean[MAX_N];
    	Arrays.fill(openCell, true);
    	for(int i=2;i<openCell.length;i++) {
    		for(int j=i;j<openCell.length;j+=i) {
    			openCell[j]=!openCell[j];
    		}
    	}
    	
    	int cases = nextInt();
    	while(cases > 0) {
    		int n = nextInt();
    		int free = 0;
    		for(int i=1;i<=n;i++)
    			free+=(openCell[i]==true? 1:0);
    	    out.printf("%d\n", free);	
    		cases --;
    	}
    }
    
	Main() throws Exception {
       /*Esta entrada  se debe activar cuando se hace una ejercicio de lectura hasta fin de fichero 
       copiar la entrada en un fichero "Input.txt" y comentar el otro in . A la hor de enviar comentar
       este y descomentar el otro
       */
       //in = new BufferedReader(new FileReader("Inpu.txt"));
       //out = new PrintWriter(new FileWriter("Output.txt"));
       in = new BufferedReader(new InputStreamReader(System.in));
	     out = new PrintWriter(System.out);
       eat("");
       solve();
       in.close();
       out.close();
    }

    private void eat(String str) { st = new StringTokenizer(str);}

    String next() throws Exception {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) return null;
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws Exception {return Integer.parseInt(next());}

    long nextLong() throws Exception {return Long.parseLong(next());}

    double nextDouble() throws Exception {return Double.parseDouble(next());}

    public static void main(String[] args) throws Exception {new Main();}

}
