import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class JULKA 
{
	public static void main(String[] args) throws IOException 
	{
		BigInteger two = new BigInteger("2");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i=0;i<10;i++)
		{
	        String str = br.readLine();
			BigInteger total = new BigInteger(str);

			str = br.readLine();
			BigInteger b1 = new BigInteger(str);
			
			if(total.mod(two).intValue()==1)	
			{
				total =  total.divide(two);
				b1 = b1.divide(two);
				System.out.println(total.add(b1.add(BigInteger.ONE)));
				System.out.println(total.subtract(b1));				
			}
			else
			{
				total = total.divide(two);
				b1 = b1.divide(two);
				System.out.println(total.add(b1));
				System.out.println(total.subtract(b1));				
			}
		}
	}
}
