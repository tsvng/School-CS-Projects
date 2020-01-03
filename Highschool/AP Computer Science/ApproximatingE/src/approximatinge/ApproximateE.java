//William Tsang, AP Comp Sci, Mods 6-7
package approximatinge;

import processing.core.PApplet;

public class ApproximateE extends PApplet 
{
	public void setup() 
	{
		size(300,100);
		noLoop();
	}

	public void draw() 
	{
		background(0);
		Random_e e = new Random_e();
		textAlign(CENTER);;
		text("Value of e is " + e.getValue(),width/2,height/2);
	}
	public void mouseClicked()
	{
		redraw();
	}
	class Random_e
	{
		double dValue;
		
		double getValue()
		{
			
			return dValue;
		}
		Random_e()
		{
			
			double sum = 0;
			double times = 0;
			int trials = 0;
			for(int i=0; i < 10000; i++)
			{
					
					sum=sum+Math.random();
					times++;
					if(sum > 1)
					{
						trials++;
						sum = 0;
					}
					
			}
			
	
			dValue=times/trials;
		}
	}
}