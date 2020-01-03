
import java.util.*;
public class PQuiz {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		while(true){
			String sInput = s.next();
			if(sInput.equals("quit")){
				break;
			}else if(sInput.equals("add")){
				int sum = Integer.parseInt(s.next());
				sum += Integer.parseInt(s.next());
				System.out.println("sum is "+ sum);
			}else if(sInput.equals("subtract")){
				//your code here
			}
		}
		s.close();
	}
}