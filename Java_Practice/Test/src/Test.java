import java.util.Scanner;

/*
public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub	
		Count c = new Count();
		String title = "Playing with java";
		String title1 = new String("Playing");
		
		String comp = "playing with java";
		
		System.out.println(comp.replace("with", "as"));
		System.out.println(comp.substring(1, 6));
		System.out.println(comp.concat(title));
		System.out.println(+title.length()+", "+title1.charAt(3));		
		System.out.println(+title.length()+", "+title1.charAt(3));
		int y = c.ret();
		System.out.println(y);
	}
}

class Count{
	private int x=0;
	public int ret(){
		return x;
	}
}
*/
public class Test {
	public static void main(String[] args) {
		Account accounts[] = {new Account(), new SavingsAccount(), new CheckingAccount()};
		for(Account account : accounts){
			System.out.println(account.toString());
		}
	}
}
class Account{
	protected static int serialAccid=0;
	protected int accid;
	protected double balance;
	
	public Account(){
		accid = ++serialAccid;
		balance = 0;
	}
	public String toString(){
		return "Account"+accInfo();
	}
	protected String accInfo(){
		return "("+accid+": "+balance+")";
	}
}
class SavingsAccount extends Account{
	public SavingsAccount(){
		super();
	}
	public String toString(){
		return "Savings"+accInfo();
	}
}
class CheckingAccount extends Account{
	public CheckingAccount(){
		super();
	}
	public String toString(){
		return "Checking"+accInfo();
	}
}