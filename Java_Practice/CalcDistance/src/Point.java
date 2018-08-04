import java.util.Scanner;

/**
 * 2���� ��� ���� �� ���� ��Ÿ���� ���� Ŭ���� Point.
 * �� �� ������ �Ÿ��� ���ϱ� ���� �޼ҵ� distanceFrom()�� �����Ͽ���.
 */
public class Point 
{
    private int x, y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public String toString() {
        String buf = "(" + x + ", " + y + ")";
        return buf;
    }
    public int getX() {
        return x;
    }
    public int getY() {
        return y;
    }
    public double distanceFrom(Point q) {
        double dist = Math.sqrt(Math.pow(q.x - x, 2) 
                + Math.pow(q.y - y, 2));
        return dist;
    }
    public static Point readPoint(Scanner scan, String prompt) 
    {
        System.out.print(prompt + " ");
        int x = scan.nextInt();
        int y = scan.nextInt();
        Point p = new Point(x, y);
        return p;
    }
}
