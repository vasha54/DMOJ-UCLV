import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 * DMOJ - N por 17
 * @author vasha
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));
        String line;
        BigInteger pi=new BigInteger("17");
        BigInteger dos=new BigInteger("2");
        BigInteger number;

        while((line=stdin.readLine())!=null){
              number=new BigInteger("0");
              for(int i = line.length()-1; i >=0; i--) {
                  if(line.charAt(i)=='1')
                  number=number.add(dos.pow(line.length()-i-1));
              }
              number=number.multiply(pi);
              for(int i=number.bitLength()-1;i>=0;i--)
                  if(number.testBit(i))
                    System.out.print("1");
                  else
                    System.out.print("0");
              System.out.println();
        }
    }

}