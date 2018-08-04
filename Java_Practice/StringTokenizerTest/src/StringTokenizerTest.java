import java.util.Scanner;
import java.util.StringTokenizer;


public class StringTokenizerTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		
		while ( scanner.hasNext() ){
			String line = scanner.nextLine();
			StringTokenizer stz = new StringTokenizer(line);
			
			System.out.println( stz.countTokens() );
			while ( stz.countTokens() > 0 ){
				String token = stz.nextToken();
				System.out.println(token);
			}
		}
	}

}
