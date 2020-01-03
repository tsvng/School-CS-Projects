//William Tsang, Google Billboard, AP Comp Sci Mods 6,7
//url of your finished program
package googlebillboard;

import processing.core.PApplet;


public class GoogleBillboard extends PApplet
{
	public final static String e = "2.718281828459045235360287471352662497757247093699959574966967627724076630353547594571382178525166427427466391932003059";
	public void setup()
	{
	noLoop();
	}
	public void draw()
	{
		int start = 2;
		int end = 12;
		for(int i = 0; i < e.length()-11;i++)
		{
			String digits = e.substring(start,end);
			double dNum = Double.parseDouble(digits);
			if(isPrime(dNum) == true)
			{
				System.out.println(dNum);
			}
			start++;
			end++;
		}
	}
	public boolean isPrime(double dNum)
	{
		if ( dNum < 2)
		{
			return false;
		}
		else if( dNum >= 2 && dNum < 4)
		{
			return true;
		}
		else
		{

			for( int i = 2; i <= Math.sqrt(dNum); i++)
			{
				if ( dNum % i == 0)
				{
					return false;
				}

			} 
			return true; 
		}  
	}
}

