//William Tsang, AsteroidsPart4, AP Comp Sci, Mods 6-7
//Press 'r' for hyperspace
// Press the spacebar to shoot
package asteroidspart4;
import java.util.*;
import processing.core.PApplet;


public class AsteroidsPart4 extends PApplet {
	Star[] aBunch = new Star[150];
	Spaceship Deema = new Spaceship();
	Bullet Bill = new Bullet(Deema);
	//Asteroid[] Killem = new Asteroid[10];
	ArrayList <Asteroid> Killem = new ArrayList<Asteroid>();
	ArrayList<Bullet> PewPew = new ArrayList<Bullet>();
	public void setup() 
	{

		size(800,600);
		for(int i = 0; i < 150; i++)
		{
			aBunch[i] = new Star();
		}
		for(int i = 0; i < 10; i++)
		{
			Killem.add(new Asteroid());
		}

	}

	public void draw()
	{
		background(0);
		//Stars
		for(int i = 0; i < 150; i++)
		{
			aBunch[i].show();
		}
		//Asteroids
		for(int i = 0; i < Killem.size(); i++)
		{

			Killem.get(i).move();
			Killem.get(i).show(); 	
		}
		for(int i = 0; i < Killem.size();i++)
		{
			if(dist(Deema.getX(),Deema.getY(),Killem.get(i).getX(),Killem.get(i).getY()) < 20)
			{
				Killem.remove(i);
			}
		}
		for(int i = 0; i < Killem.size();i++)
		{
			if(dist(Deema.getX(),Deema.getY(),Killem.get(i).getX(),Killem.get(i).getY()) < 20)
			{
				Killem.remove(i);
			}
		}
		//Spaceship Acceleration And Rotation
		Deema.move();
		if(keyPressed == true && key == 'd')
		{
			Deema.rotate(5);
		}
		else if(keyPressed == true && key == 'a')
		{
			Deema.rotate(-5);
		}
		if(keyPressed == true && key == 'w')
		{
			Deema.accelerate(.05);
		}
		Deema.show();
		//Bullet
		for(int i = 0; i < PewPew.size(); i++)
		{
			PewPew.get(i).move();
			PewPew.get(i).show();
		}
	}
	public void keyPressed()
	{
		if(key == 'r')
		{
			Deema.hyperspace();
		}
		if(key == ' ')
		{
			PewPew.add(new Bullet(Deema));
		}

	}
	abstract class Floater
	{
		protected int corners;  //the number of corners, a triangular floater has 3
		protected int[] xCorners;
		protected int[] yCorners;
		protected int myColor;
		protected double myCenterX, myCenterY; //holds center coordinates
		protected double myDirectionX, myDirectionY; //holds x and y coordinates of the vector for direction of travel
		protected double myPointDirection; //holds current direction the ship is pointing in degrees

		abstract public void setX(int x);
		abstract public int getX();
		abstract public void setY(int y);
		abstract public int getY();
		abstract public void setDirectionX(double x);
		abstract public double getDirectionX();
		abstract public void setDirectionY(double y);
		abstract public double getDirectionY();
		abstract public void setPointDirection(int degrees);
		abstract public double getPointDirection();

		public void accelerate (double dAmount)
		{  
			//Accelerates the floater in the direction it is pointing
			//(myPointDirection)

			//convert the current direction the floater is pointing to radians
			double dRadians =myPointDirection*(Math.PI/180);

			//change coordinates of direction of travel
			myDirectionX += ((dAmount) * Math.cos(dRadians));
			myDirectionY += ((dAmount) * Math.sin(dRadians));    
		}
		void rotate (int nDegreesOfRotation)
		{  
			//rotates the floater by a given number of degrees
			myPointDirection+=nDegreesOfRotation;
		}
		public void move ()
		{  
			//Moves the floater towards the coordinates

			//myDirectionX and myDirectionY

			//move the floater in the current direction of travel
			myCenterX += myDirectionX;
			myCenterY += myDirectionY;
			//wrap around screen
			if(myCenterX >width){
				myCenterX = 0;
			}
			else if (myCenterX<0){
				myCenterX = width;
			}
			if(myCenterY >height){
				myCenterY = 0;
			}
			else if (myCenterY < 0){
				myCenterY = height;
			}
		}
		public void show ()
		{  
			//Draws the floater at the current position
			noFill();
			stroke(myColor);
			//convert degrees to radians for sin and cos     
			double dRadians = myPointDirection*(Math.PI/180);

			int xRotatedTranslated, yRotatedTranslated;
			beginShape();

			//rotate and translate the coordinates of the floater using current direction	
			for(int nI = 0; nI < corners; nI++)
			{
				xRotatedTranslated = (int)((xCorners[nI]* Math.cos(dRadians)) - (yCorners[nI] * Math.sin(dRadians))+myCenterX);
				yRotatedTranslated = (int)((xCorners[nI]* Math.sin(dRadians)) + (yCorners[nI] * Math.cos(dRadians))+myCenterY); 
				vertex(xRotatedTranslated,yRotatedTranslated);
			}
			endShape(CLOSE);
		}
	}
	class Spaceship extends Floater
	{	
		Spaceship()
		{
			myColor= 255;
			corners = 4;
			xCorners = new int[corners];
			yCorners = new int[corners];
			xCorners[0] = -8;
			yCorners[0] = -8;
			xCorners[1] = 16;
			yCorners[1] = 0;
			xCorners[2] = -8;
			yCorners[2] = 8;
			xCorners[3] = -2;
			yCorners[3] = 0;
			myCenterX = 400;
			myCenterY = 300;
			myDirectionX = 0;
			myDirectionY = 0;
			myPointDirection = 270;
		}

		public void setX(int x)
		{
			myCenterX = x;
		}
		public int getX()
		{
			return (int)myCenterX;
		}
		public void setY(int y)
		{
			myCenterY = y;
		}
		public int getY()
		{
			return (int)myCenterY;
		}
		public void setDirectionX(double x)
		{
			myDirectionX = x;
		}
		public double getDirectionX()
		{
			return myDirectionX;
		}
		public void setDirectionY(double y)
		{
			myDirectionY = y;
		}
		public double getDirectionY()
		{
			return myDirectionY;
		}
		public void setPointDirection(int degrees)
		{
			myPointDirection = degrees;
		}
		public double getPointDirection()
		{
			return (double)myPointDirection;
		}
		public void hyperspace()
		{
			setX((int)(Math.random()*801));
			setY((int)(Math.random()*601));
			setDirectionX(0);
			setDirectionY(0);
			setPointDirection((int)(Math.random()*361));
		}

	}
	class Star
	{
		private int xCoord,yCoord,siz,r,g,b;
		Star()
		{
			xCoord = (int)(Math.random()*801);
			yCoord = (int)(Math.random()*601);
			siz =(int)(Math.random()*6);
			r = (int)(Math.random()*256);
			g = (int)(Math.random()*256);
			b = (int)(Math.random()*256);
		}
		public void show()
		{
			fill(r,g,b);
			stroke(r,g,b);
			ellipse(xCoord,yCoord,siz,siz);  
		}
	}
	class Asteroid extends Floater
	{
		private int rotspeed;
		Asteroid()
		{
			if(Math.random() <.5)
			{
				rotspeed = (int)(Math.random()*5+1);
			}
			else
			{
				rotspeed = -1*(int)(Math.random()*5-1);
			}
			if(Math.random() <.5)
			{
				myDirectionX = Math.random();
			}
			else
			{
				myDirectionX = -1*Math.random();
			}
			if(Math.random() <.5)
			{
				myDirectionY = Math.random();
			}
			else
			{
				myDirectionY = -1*Math.random();
			}
			myColor= 255;
			corners = 6;
			xCorners = new int[corners];
			yCorners = new int[corners];
			xCorners[0] = -11;
			yCorners[0] = -8;
			xCorners[1] = 7;
			yCorners[1] = -8;
			xCorners[2] = 13;
			yCorners[2] = -10;
			xCorners[3] = 6;
			yCorners[3] = 10;
			xCorners[4] = -11;
			yCorners[4] = 8;
			xCorners[5] = -5;
			yCorners[5] = 3;
			myCenterX = Math.random()*801;
			myCenterY = Math.random()*601;
			myPointDirection = 270;
		}
		public void move ()
		{  
			rotate(rotspeed);
			super.move();
		}
		public void setX(int x)
		{
			myCenterX = x;
		}
		public int getX()
		{
			return (int)myCenterX;
		}
		public void setY(int y)
		{
			myCenterY = y;
		}
		public int getY()
		{
			return (int)myCenterY;
		}
		public void setDirectionX(double x)
		{
			myDirectionX = x;
		}
		public double getDirectionX()
		{
			return myDirectionX;
		}
		public void setDirectionY(double y)
		{
			myDirectionY = y;
		}
		public double getDirectionY()
		{
			return myDirectionY;
		}
		public void setPointDirection(int degrees)
		{
			myPointDirection = degrees;
		}
		public double getPointDirection()
		{
			return (double)myPointDirection;
		}
	}
	class Bullet extends Floater
	{
		double dRadians;
		Bullet()
		{
			myColor= 255;
			corners = 3;
			xCorners = new int[corners];
			yCorners = new int[corners];
			xCorners[0] = -2;
			yCorners[0] = -2;
			xCorners[1] = 4;
			yCorners[1] = 0;
			xCorners[2] = -2;
			yCorners[2] = 2;
			myCenterX = 400;
			myCenterY = 300;
			myDirectionX = 0;
			myDirectionY = 0;
			myPointDirection = 270;
		}
		Bullet(Spaceship Killem)
		{
			myColor= 255;
			corners = 3;
			xCorners = new int[corners];
			yCorners = new int[corners];
			xCorners[0] = -2;
			yCorners[0] = -2;
			xCorners[1] = 4;
			yCorners[1] = 0;
			xCorners[2] = -2;
			yCorners[2] = 2;
			myCenterX = Killem.getX();
			myCenterY = Killem.getY();
			myPointDirection = Killem.getPointDirection();
			dRadians = myPointDirection*(Math.PI/180);
			myDirectionX = 5 * Math.cos(dRadians) + Killem.getDirectionX();
			myDirectionY = 5 * Math.sin(dRadians) + Killem.getDirectionY();
		}

		public void setX(int x)
		{
			myCenterX = x;
		}
		public int getX()
		{
			return (int)myCenterX;
		}
		public void setY(int y)
		{
			myCenterY = y;
		}
		public int getY()
		{
			return (int)myCenterY;
		}
		public void setDirectionX(double x)
		{
			myDirectionX = x;
		}
		public double getDirectionX()
		{
			return myDirectionX;
		}
		public void setDirectionY(double y)
		{
			myDirectionY = y;
		}
		public double getDirectionY()
		{
			return myDirectionY;
		}
		public void setPointDirection(int degrees)
		{
			myPointDirection = degrees;
		}
		public double getPointDirection()
		{
			return (double)myPointDirection;
		}
		public void move ()
		{  
			//Moves the floater towards the coordinates

			//myDirectionX and myDirectionY

			//move the floater in the current direction of travel
			myCenterX += myDirectionX;
			myCenterY += myDirectionY;
		
		}
	}
}