//William Tsang, Old MacDonald, AP Comp Sci, Mods 6-7

public class OldMacDonald 
{

	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Farm f = new Farm();
		f.animalSounds();

	}

}
interface Animal
{
	public String getSound();    
	public String getType();
}
class Farm 
{

	private Animal[] aBunchOfAnimals = new Animal[4];
	double dA = Math.random();
	public Farm() 
	{
		aBunchOfAnimals[0] = new NamedCow("cow","Elsie","moo");
		aBunchOfAnimals[1] = new Chick("chick","cluck","cheep");
		aBunchOfAnimals[2] = new Pig("pig","oink");
		aBunchOfAnimals[3] = new Fox("fox","RINGDINGDINGDINGDINGADINGERDING");
	}

	public void animalSounds()
	{
		for (int nI=0; nI < aBunchOfAnimals.length; nI++)
		{
			System.out.println( aBunchOfAnimals[nI].getType() + " goes " + aBunchOfAnimals[nI].getSound());
		}
		System.out.println( "The cow is known as " + ((NamedCow)aBunchOfAnimals[0]).getName() );
	}
}
class Cow implements Animal
{
	private String myType;
	private String mySound;

	public Cow(String type, String sound)
	{
		myType = type;
		mySound = sound;
	}
	public Cow()
	{
		myType = "cow";
		mySound = "moo";
	}
	public String getSound() 
	{ 
		return mySound; 
	}
	public String getType() 
	{ 
		return myType; 
	}
}
class Chick implements Animal
{
	private String myType;
	private String mySound1;
	private String mySound2;

	public Chick(String type, String sound1, String sound2)
	{
		myType = type;
		mySound1 = sound1;
		mySound2 = sound2;
	}
	public Chick()
	{
		myType = "chick";
		mySound1 = "cluck";
		mySound2 = "cheep";
	}

	public String getSound() 
	{ 
		if(Math.random() < .5)
		{
		return mySound1;
		}
		else
		{
		return mySound2;
		}
	}
	public String getType() 
	{ 
		return myType; 
	}
}
class Pig implements Animal
{
	private String myType;
	private String mySound;

	public Pig(String type, String sound)
	{
		myType = type;
		mySound = sound;
	}
	public Pig()
	{
		myType = "pig";
		mySound = "oink";
	}

	public String getSound() 
	{ 
		return mySound; 
	}
	public String getType() 
	{ 
		return myType; 
	}
}
class Fox implements Animal
{
	private String myType;
	private String mySound;

	public Fox(String type, String sound)
	{
		myType = type;
		mySound = sound;
	}
	public Fox()
	{
		myType = "fox";
		mySound = "RINGDINGDINGDINGDINGADINGERDING";
	}

	public String getSound() 
	{ 
		return mySound; 
	}
	public String getType() 
	{ 
		return myType; 
	}
}
class NamedCow extends Cow
{
	private String myName;
	public NamedCow(String type,String name,String sound)
	{
		myName= name;
	}
	public NamedCow()
	{
		myName = "Elsie";
	}
	public String getName()
	{
		return myName;
	}
}





