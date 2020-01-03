//William Tsang, AP Comp Sci, Mods 6-7
//Press q to increase the "speed" of rotation
//Press w to decrease the "speed" of rotation
package starfield;

import processing.core.PApplet;


public class Starfield extends PApplet 
{
	public final static int NUM_STARS = 250;
	Particle field[] = new Particle[NUM_STARS];
	public void setup()
	{

		size(600,600);
		for(int i = 0; i < NUM_STARS; i++)
		{
			field[i] = new Particle();
		}
	}

	public void draw()
	{
		noStroke();
		fill(255,255,255,150);
		rect(0,0,width,height);


		for(int i = 0; i < NUM_STARS; i++)
		{

			field[i].move();
			field[i].show();
						if(keyPressed == true && key == 'q')
						{
							field[i].speed = field[i].speed + .03;
						}
						if(keyPressed == true && key == 'w')
						{
							field[i].speed = field[i].speed - .03;
						}
						if(keyPressed == true && key == 'p')
						{
							println(field[1].speed);
						}
			field[i].angle = field[i].angle+0.03;


		}
	}
	class Particle
	{
		double x,y,speed,angle;
		int r,g,b;
		Particle()
		{
			x = 300;
			y = 300;
			speed = Math.random()*50;
			angle = Math.random()*(2*Math.PI);
			r = (int)(Math.random()*256);
			g = (int)(Math.random()*256);
			b = (int)(Math.random()*256);

		}
		void move()
		{
			x = x + (Math.cos(angle)*speed);
			y = y + (Math.sin(angle)*speed);
		}
		void show()
		{
			stroke(r,g,b);
			fill(r,g,b);
			ellipse((float)x,(float)y,10,10);
		}
	}
}
