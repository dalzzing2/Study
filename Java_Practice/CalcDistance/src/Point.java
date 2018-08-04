import java.util.Scanner;

/**
 * 2차원 평면 상의 한 점을 나타내기 위한 클래스 Point.
 * 두 점 사이의 거리를 구하기 위한 메소드 distanceFrom()을 구현하였다.
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
