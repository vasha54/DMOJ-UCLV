// DMOJ - Posibilidades de Suma de Secuencia

/*
Tematica: Algebra-Aritmetica

Idea Basica: Contar la cantidad de veces que se puede expresar un numero natural como
suma de numeros concecutivos

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
    private final int MAX_N = 510;
    
    private int [] movX = { 0, 0, 1, -1};
    private int [] movY = {-1, 1, 0,  0};
    private long [] cards ={1,10,100,1000,10000};
   
    public int countConsecutive(int N){
        int count = 0;
        for (int L = 1; L * (L + 1) < 2 * N; L++) {
            double a = (double)((1.0 * N - (L * (L + 1)) / 2) / (L + 1));
            if (a - (int)a == 0.0)
                count++;
        }
        return count;
    } 
   
   
    public void solve() throws Exception {
        int cases = nextInt(),id,x;
        while(cases >0 ){
            id = nextInt();
            x = nextInt();
            out.printf("%d %d\n",id,countConsecutive(x) );
            cases--;
        }
       
    }
    
    Main() throws Exception {
       /*Esta entrada  se debe activar cuando se hace una ejercicio de lectura hasta fin de fichero 
       copiar la entrada en un fichero "Input.txt" y comentar el otro in . A la hor de enviar comentar
       este y descomentar el otro
       */
       //in = new BufferedReader(new FileReader("Input.txt"));
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
