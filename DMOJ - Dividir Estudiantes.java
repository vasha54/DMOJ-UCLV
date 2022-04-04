// DMOJ - Dividir Estudiantes

/*
Tematica:Add-Hoc + Algebra aritmetica

Idea Basica: Balancear en tres grupos las cantidades si mezclar los elementos de los grupos que
que no se pueden unir. Se toma entre esos dos grupos el de mayor cantidad si se parte en dos grupos
y con los elementos que pueden estar en cualquier se van agregando uno a uno de forma que se balancee 
la cantidad en cada grupo. 
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
   
    public void solve() throws Exception {
        int cases=nextInt();
        
        while(cases>0){
            int assembler=nextInt();
            int basic =nextInt();
            int cplusplus =nextInt();
            
            int groupA,groupB,groupC;
            
            if(assembler > cplusplus){
                groupA = assembler/2;
                groupB = assembler - groupA;
                groupC = cplusplus;
            }else{
                groupA = cplusplus/2;
                groupB = cplusplus - groupA;
                groupC = assembler;
            }
            
            while(basic>0){
                if(groupA<=groupB && groupA <= groupC){
                   groupA++; 
                }else if(groupB<=groupC && groupB<=groupA){
                    groupB++;
                }else{
                    groupC++;
                }
                basic--;
            }
            out.printf("%d\n",Math.max(groupA,Math.max(groupB,groupC)));
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
