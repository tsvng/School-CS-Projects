//William T., AP Comp Sci A A, Mods 6-7
package fourpointedstar;

import processing.core.PApplet;


public class FourPointedStar extends PApplet {
	int startX = 150;
	int startY = 0;
	int endX = 150;
	int endY = 150;
	boolean vertdown = true;
	boolean horiright = true;
	boolean wipe = false;
	public void setup() 
	{
		size(300,300);
		frameRate(30);
		smooth();
		background(0);
	}

	public void draw() 
	{
		//Color
		if (startY == 0)
		{
			stroke(255,0,0);
		}
		if(endX == 0 && startX == 150)
		{
			stroke(0,255,0);
		}
		if (startY == 300)
		{
			stroke(0,0,255);
		}
		if(endX == 300)
		{
			stroke(255,0,255);	
		}

		
		for( int i = 0; i < 1; i++)
		{
			line(startX,startY,endX,endY);
			//Direction
			if (startY <= 0)
			{
				vertdown = true;
			}
			if(endX <=0)
			{
				horiright = true;
			}
			if (startY >= 300)
			{
				vertdown = false;
			}
			if(endX >= 300)
			{
				horiright = false;	
			}


			//Movement Amount
			if (vertdown == true)
			{
				startY = startY + 5;
			}
			if (horiright == true)
			{
				endX = endX + 5;
			}
			if (vertdown == false)
			{
				startY = startY - 5;
			}
			if (horiright == false)
			{
				endX = endX - 5;
			}
			
	
			
			//Clean Sceen
			if(startX == 150 && startY == 0 &&  endX == 150 && endY == 150)
			{
				boolean vertdown = true;
				boolean horiright = true;
				background(0);
				
			}
		}
	}
}


