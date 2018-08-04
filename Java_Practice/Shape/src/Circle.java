import java.util.Scanner;


public class Circle implements CircumferenceMeasurable{
	private double x, y, r;
	
	Scanner scan = new Scanner(System.in);

	@Override
	public double circumference() {
		// TODO Auto-generated method stub
		System.out.print("x, y 좌표 및 반지름 r 을 입력하세요 : ");
		
		x = scan.nextDouble();
		y = scan.nextDouble();
		r = scan.nextDouble();

		System.out.println("x : " + x + ", y : " + y + ", r : " + r);
		return 2 * 3.14 * r;
	}
}
