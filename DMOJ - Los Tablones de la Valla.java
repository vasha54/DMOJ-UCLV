/**
 * DMOJ - Los Tablones de la Valla
 * Temáticas: Progrmación dinamica. Tabla acumulativa.
 * 
 * Idea: Crear una tabla acumulativa con las alturas de los tablones de la cerca y
 * ver los k tablones concecutivos producen la menor suma. 
 */
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.*;
import java.lang.*;
import java.util.regex.*;

public class Los_Tablones_de_la_Valla {
    
    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;
    private final int MAX_N = 1000001;
    private final int MAX_TREE = (MAX_N << 2);
    private final char SYMBOL = '@';
    
    private int [] movX = { 0, 0, 1, -1};
    private int [] movY = {-1, 1, 0,  0};
    private long [] cards ={1,10,100,1000,10000};
    private long MOD =1000000009;
    
    public void solve() throws Exception {
    	int n =nextInt();
    	int k =nextInt();
    	
    	long heigth;
    	long [] dp =new long [n+1];
    	Arrays.fill(dp, 0);
    	
    	for(int i=1;i<=n;i++) {
    		heigth =nextLong();
    		dp[i]=heigth+dp[i-1];
    	}
    	
    	long maxSumHeigth = Long.MAX_VALUE;
    	int index = -1;
    	
    	for(int i=0;i+k<=n;i++) {
    		if(dp[i+k]-dp[i] < maxSumHeigth) {
    			maxSumHeigth = dp[i+k]-dp[i];
    			index = i+1;
    		}
    	}
    	
    	System.out.printf("%d\n",index);
    }
    
	Los_Tablones_de_la_Valla() throws Exception {
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

    public static void main(String[] args) throws Exception {new Los_Tablones_de_la_Valla();}

}
