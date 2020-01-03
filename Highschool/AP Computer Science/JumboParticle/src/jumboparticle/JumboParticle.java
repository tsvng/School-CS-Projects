//William Tsang, Jumbo Particle, AP Comp Sci, Mods 6-7
package jumboparticle;

import processing.core.PApplet;


public class JumboParticle extends PApplet 
{
	public final static int NUM_STARS = 250;
	Point field[] = new Point[NUM_STARS];
	interface Point
	{
		public void move();
		public void show();
	}
	public void setup()
	{

		size(600,600);
		for(int i = 0; i < NUM_STARS; i++)
		{
			field[i] = new Particle();
			field[NUM_STARS - 2] = new Jumbo();
			field[NUM_STARS - 1] = new TheOddOne();
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
	
		}

	}
	class Particle implements Point
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
		public void move()
		{
			x = x + (Math.cos(angle)*speed);
			y = y + (Math.sin(angle)*speed);
			angle = angle + .03;
		}
		public void show()
		{
			stroke(r,g,b);
			fill(r,g,b);
			ellipse((float)x,(float)y,10,10);
		}
	}
	class TheOddOne implements Point
	{
		 double x,y,speed,angle;
		 int r,g,b;
		TheOddOne()
		{
			x = 300;
			y = 300;
			speed = Math.random()*10;
			angle = Math.random()*(2*Math.PI);
			r = (int)(Math.random()*256);
			g = (int)(Math.random()*256);
			b = (int)(Math.random()*256);

		}
		public void move()
		{
			x = x + (Math.cos(angle)*speed);
			y = y + (Math.sin(angle)*speed);
			angle = angle - .03;
		}
		public void show()
		{
			stroke(r,g,b);
			fill(r,g,b);
			ellipse((float)x,(float)y,30,30);
			fill(0);
			ellipse((float)x,(float)y,15,15);
		}
		
	}
	class Jumbo extends Particle
	{
		public void show()
		{
			ellipse((float)x,(float)y,50,50);
		}
	}
	
}
