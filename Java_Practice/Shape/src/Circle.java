import java.util.Scanner;


public class Circle implements CircumferenceMeasurable{
	private double x, y, r;
	
	Scanner scan = new Scanner(System.in);

	@Override
	public double circumference() {
		// TODO Auto-generated method stub
		System.out.print("x, y ��ǥ �� ������ r �� �Է��ϼ��� : ");
		
		x = scan.nextDouble();
		y = scan.nextDouble();
		r = scan.nextDouble();

		System.out.println("x : " + x + ", y : " + y + ", r : " + r);
		return 2 * 3.14 * r;
	}
}
