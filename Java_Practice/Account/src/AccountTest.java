
public class AccountTest {
	public static void main(String[] args)
	{
		Account account1, account2;
		account1 = new Account("°©", 100, 50000);
		account2 = new Account("À»", 101, 100000);
		
		account1.withdraw(2000);
		account1.deposit(100000);
		System.out.println(account1);
		
		account2.withdraw(50000);
		account2.deposit(200000);
		System.out.println(account2);
	}
}

class Account{
	private long number;
	private long balance;
	private String name;
	
	public Account(String na, long no, long amount){
		name = na;
		number = no;
		balance = amount;
	}
	
	public long deposit(long amount){
		balance = balance + amount;
		return balance;
	}
	public long withdraw(long amount){
		if(amount <= balance)
			balance = balance - amount;
		else
			System.out.println("ÀÜ¾×ºÎÁ·");
		return balance;
	}
	public String toString(){
		return(name+ "°í°´´ÔÀÇ Á¤º¸ : " +number+ "\t ÇöÀçÀÜ¾×" +balance+ " ¿ø");
	}
}