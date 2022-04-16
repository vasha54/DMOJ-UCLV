/*
DMOJ - Tenería.
Tematica: Ordenamiento y busqueda

Idea Basica: Ver si una colección se puede expresar como un subconjunto de la otra colección.
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
    private final int MAX_N = 1000001;
    private final int MAX_TREE = (MAX_N << 2);
    
    private int [] movX = { 0, 0, 1, -1};
    private int [] movY = {-1, 1, 0,  0};
    private long [] cards ={1,10,100,1000,10000};
    private long MOD =1000000009;
    
   
    public void solve() throws Exception {
    
        int N=nextInt(),pN=0;
        int M=nextInt(),pM=0;
        
        long [] store =new long[N];
        long [] protocol =new long[M];
        
        for(int i=0;i<N;i++) store[i]=nextLong();
        for(int i=0;i<M;i++) protocol[i]=nextLong();
        
        Arrays.sort(store);
        Arrays.sort(protocol);
        
        boolean is =true;
        
        while(pN<N && pM<M && is){
            if(store[pN] == protocol[pM]){
                pM++;
                pN++;
            }else if(store[pN] < protocol[pM]){
                pN++;
            }else{
                is = false;
            }
        }
        
        if(pM<M) is=false;
        
        out.printf((is==true?"Yes\n":"No\n"));
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
