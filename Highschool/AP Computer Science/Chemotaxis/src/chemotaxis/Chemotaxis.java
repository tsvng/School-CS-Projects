//W, Chemotaxis, AP Comp Sci mods 6,7
//url of your finished program
package chemotaxis;

import processing.core.PApplet;


public class Chemotaxis extends PApplet
{
	public final static int NUM_PARTS = 10;
	Bacteria[] aBunch = new Bacteria[NUM_PARTS];

	public void setup()
	{
		
		size(640,480);
		fill(255,255,255);
		rect(0,0,width,height);
		fill(255,255,255,10);
		rect(0,0,width,height);
		frameRate(20);

		
		for(int i = 0; i < NUM_PARTS; i++)
		{
			aBunch[i] = new Bacteria();

		}
	}
	public void draw()
	{
		fill(255,255,255,10);
		rect(0,0,width,height);	
		for(int i = 0; i < NUM_PARTS; i++)
		{
			
			aBunch[i].move();
			aBunch[i].show();
		}
		
	}
	class Bacteria 
	{
		int x,y,r,g,b;
		Bacteria()
		{
			x = (width/2) + (int)(Math.random()*101-50);
			y = (height/2) + (int)(Math.random()*101-50);
			r = (int)(Math.random()*256);
			g = (int)(Math.random()*256);
			b = (int)(Math.random()*256);
		}
		
		public void move()
		{
			//Horizontal
			if(Math.random() < .5)
			{
				x = x + (int)(Math.random()*5 + 1);
			}
			else
			{
				x = x - (int)(Math.random()*5 + 1);
			}
			//Vertical
			if(Math.random() < .5)
			{
				y = y + (int)(Math.random()*5 + 1);
			}
			else
			{
				y = y - (int)(Math.random()*5 + 1);
			}
			
		}
		public void show()
		{
		
			noStroke();
			fill(r,g,b,255);
			ellipse(x,y,20,20);
			fill(0);
			ellipse(x,y,5,5);
		}
	}
}

