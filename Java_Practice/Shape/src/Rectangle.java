import java.util.Scanner;


public class Rectangle implements CircumferenceMeasurable{
	private double x1, y1, x2, y2;

	@Override
	public double circumference() {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		System.out.print("x1, y1, x2, y2 좌표를 입력하세요 : ");
		x1 = scan.nextDouble();
		y1 = scan.nextDouble();
		x2 = scan.nextDouble();
		y2 = scan.nextDouble();
		
		double x = x2 - x1, y = y2 - y1;
		if(x < 0)
			x = -x;
		if(y < 0)
			y = -y;
			
		System.out.println("x1 : " + x1 + ", y1 : " + y1 + ", x2 : " + x2 + ", y2 : " + y2);
		return 2*x + 2*y;
	}
}
