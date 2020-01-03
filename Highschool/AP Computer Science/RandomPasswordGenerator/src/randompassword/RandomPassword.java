
//William Tsang, Random Password Generator, AP Comp Sci Mods 6,7

package randompassword;

import processing.core.PApplet;

public class RandomPassword extends PApplet {
	public void setup()
	{
	  size(500,200);
	  noLoop();
	  textSize(32);
	  textAlign(CENTER);
	  
	}
	public void draw()
	{
	  background(0);
	  String password = "";
	  // Password
	  for(int i = 0; i < 13; i++)
	  {
	  password = password + (char)((int)(Math.random()*94)+33);
	  }
	  background((int)(Math.random()*256),(int)(Math.random()*256),(int)(Math.random()*256));
	  text(password,250,100);
	}
	public void mouseClicked()
	{
	  redraw();
	}
}