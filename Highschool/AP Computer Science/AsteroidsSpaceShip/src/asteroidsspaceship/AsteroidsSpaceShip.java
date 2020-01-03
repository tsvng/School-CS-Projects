//William Tsang, AsteroidsSpaceShip, AP Comp Sci, Mods 6-7
//Use "w" to accelerate your ship and use the "a" and "d" keys to rotate your ship
//Press "r" for hyperspace
package asteroidsspaceship;

import processing.core.PApplet;


public class AsteroidsSpaceShip extends PApplet {
	Star[] aBunch = new Star[150];
	Spaceship Deema = new Spaceship();
	public void setup() 
	{
		size(800,600);
		for(int i = 0; i < 150; i++)
		{
			aBunch[i] = new Star();
		}
		frameRate = 1;

	}

	public void draw()
	{
		background(0);
		for(int i = 0; i < 150; i++)
		{
			aBunch[i].show();
		}
		//Spaceship Acceeleration And Rotation
		Deema.move();
		if(keyPressed == true && key == 'd')
		{
			Deema.rotate(3);
		}
		else if(keyPressed == true && key == 'a')
		{
			Deema.rotate(-3);
		}
		if(keyPressed == true && key == 'w')
		{
			Deema.accelerate(.5);
		}
		//Hyperspace
		if(keyPressed == true && key == 'r')
		{
			Deema.hyperspace();
		}
		Deema.show();

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
}
