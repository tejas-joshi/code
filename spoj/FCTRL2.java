import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;


public class Main 
{
	public static void main(String[] args) throws IOException 
	{
		List< BigInteger > list = new ArrayList<BigInteger>();
		list.add(new BigInteger("1"));
		
		for(int i=1;i<=100;i++)
		{
			BigInteger t = new BigInteger("1");
			t = list.get(i-1);	
			list.add(t); 	
			list.set(i,list.get(i).multiply(BigInteger.valueOf(i+1)));
		}		
		
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String strT = bufferedReader.readLine();
        int t = Integer.parseInt(strT);
		while((t--)!=0)
		{
			strT = bufferedReader.readLine();
			int n = Integer.parseInt(strT);
			System.out.println(list.get(n-1));
		}
	}

}
