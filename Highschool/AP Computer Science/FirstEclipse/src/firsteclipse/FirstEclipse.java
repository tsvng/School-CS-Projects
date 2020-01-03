//William T., APCSAA, Mods 6-7
package firsteclipse;

import processing.core.PApplet;


public class FirstEclipse extends PApplet {

	public void setup() {
		size(300,200);
		background(255);
		noFill();
		smooth();
		strokeWeight(7);
	}

	public void draw() {
		//Blue Ring
		stroke(27,131,209);
		ellipse(50,50,85,85);
		
		//Yellow Ring
		stroke(247,247,35);
		ellipse(100,93,85,85);
		
		//Black Ring
		stroke(0,0,0);
		ellipse(150,50,85,85);
		 
		//Green Ring
		stroke(18,167,8);
		ellipse(200,93,85,85);
		 
		//Red Ring
		stroke(206,6,33);
		ellipse(250,50,85,85);

	}
}
