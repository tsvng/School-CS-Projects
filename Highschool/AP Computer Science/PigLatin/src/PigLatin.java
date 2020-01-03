//William Tsang, Pig Latin, AP Comp Sci, Mods 6-7
import java.util.*;

public class PigLatin {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		while(s.hasNext()){
			System.out.print(pigLatin(s.next()) + " ");
		}
	}
	public static int findFirstVowel(String sWord)
	//precondition: sWord is a valid String of length greater than 0.
	//postcondition: returns the position of the first vowel in sWord.  If there are no vowels, returns -1
	{
		for(int i = 0; i < sWord.length();i++)
		{
			if(sWord.charAt(i) == 'a' || sWord.charAt(i) == 'e' || sWord.charAt(i) == 'i' || sWord.charAt(i) == 'o' || sWord.charAt(i) == 'u')
				return i;
		}
		return -1;
	}
	public static int findQU(String sWord)
	{
		if(sWord.charAt(0) == 'q' && sWord.charAt(1) == 'u')
			{
				return 5;
			}
		return -1;
	}
	public static String pigLatin(String sWord)
	//precondition: sWord is a valid String of length greater than 0
	//postcondition: returns the pig latin equivalent of sWord
	{
		//all consonants
		if(findFirstVowel(sWord) == -1)
		{
			return sWord + "ay";
		}
		//starts vowel
		else if(findFirstVowel(sWord) == 0)
		{
			return sWord + "way";
		}
		// starts qu
		else if(findQU(sWord) == 5)
		{
			return sWord.substring(2) + sWord.substring(0,2) + "ay";
		}
		//leading consonants
		else
		{
			return sWord.substring(findFirstVowel(sWord)) + sWord.substring(0,findFirstVowel(sWord)) + "ay";
		}
	}

}
