/** DMOJ -Numeros de la suerte 
 * 
 * Temáticas: DFS recursivo + Busqueda Binaria 
 *  
 * Idea: Con un dfs voy construyendo todos los posibles numeros los 
 * cuales almacenos en una lista que posteriormente ordeno de creciente
 * para dado un valor X con una busqueda binaria busco el menor numero 
 * presente en la coleccion que sea mayor igal que X 
 */ 

//package JO;

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
    private final int MAX_N = 10010; 	
    private final int MAX_TREE = (MAX_N << 2); 	
    private final char SYMBOL = '@'; 	
    private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1 }; 	
    private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1 }; 	
    
    private long[] cards = { 1, 10, 100, 1000, 10000 }; 	
    
    private long MOD = 10000; 	
    
    public void solve() throws Exception { 		
				List<Long> numbers = new ArrayList<Long>();
        generateNumbers(0,0,0,0L,numbers);
        Collections.sort(numbers);
        
        long x = nextLong();
        out.println(searchNeighborns(x,numbers));
        
    }
    
    public long searchNeighborns(long x,List<Long> numbers){
        long answer = numbers.get(numbers.size()-1);
        int inicio = 0, fin = numbers.size()-1,pivot;
        
        while (inicio <= fin){
            pivot = (inicio+fin)/2;
            if(numbers.get(pivot)<x) inicio=pivot+1;
            else{
                answer = Math.min(answer,numbers.get(pivot));
                fin=pivot-1;
            }
        }
        
        return answer;
    }
    
    public void generateNumbers(int _deep, int _nSeven, int _nFour, long _number, List<Long> numbers){
        
        if(_deep<=10){
        	if( _nSeven==_nFour && _nSeven>0)
            numbers.add(_number);
        
        	if(_nSeven+1<=5) generateNumbers(_deep+1,_nSeven+1,_nFour,_number*10+7,numbers);
          if(_nFour+1<=5) generateNumbers(_deep+1,_nSeven,_nFour+1,_number*10+4,numbers);  
        }

    }
    
    Main() throws Exception { 		
        
        /* 		 
         * Esta entrada se debe activar cuando se hace una ejercicio de lectura hasta 		 
         * fin de fichero copiar la entrada en un fichero "Input.txt" y comentar el otro 		 
         * in . A la hor de enviar comentar este y descomentar el otro 		 */ 		
         // in = new BufferedReader(new FileReader("Input.txt")); 		
         // out = new PrintWriter(new FileWriter("Output.txt")); 		
        in = new BufferedReader(new InputStreamReader(System.in)); 		
        out = new PrintWriter(System.out); 		
        eat(""); 		
        solve(); 		
        in.close(); 		
        out.close(); 	
    } 	
    
    private void eat(String str) { st = new StringTokenizer(str); } 	
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
    public static void main(String[] args) throws Exception { new Main();} 	
    
}