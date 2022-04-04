//DMOJ - Creating Teams
//Add-Hoc + Aritmetica-Algebra
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Vector;
import java.util.BitSet;
import java.util.Collections;
import java.util.Formatter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.regex.*;
import java.util.Calendar;

public class Main {
    
    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;
    
    public void solve() throws IOException 
    {
           String line = in.readLine(); 
           while( line!=null){
               eat(line);
               int M=nextInt();
               int N=nextInt();
               int K=nextInt();
               int T=Math.min(N,M/2);
               int Q=M-2*T,H=N-T;
               while(Q+H<K){
                  T--;
                  Q+=2;
                  H+=1;
               }
               out.printf("%d\n",Math.max(T,0));
               line = in.readLine(); 
           } 
	 }

    Main() throws IOException {
        //in = new BufferedReader(new FileReader("Input.txt"));
        //out = new PrintWriter(new FileWriter("Output.txt"));
       in = new BufferedReader(new InputStreamReader(System.in));
		  out = new PrintWriter(System.out);
        eat("");solve();in.close();out.close();
    }

    private void eat(String str) { st = new StringTokenizer(str);}

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) return null;
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {return Integer.parseInt(next());}

    long nextLong() throws IOException {return Long.parseLong(next());}

    double nextDouble() throws IOException {return Double.parseDouble(next());}

    public static void main(String[] args) throws IOException {new Main();}

}
