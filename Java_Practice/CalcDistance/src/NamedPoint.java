import java.util.Scanner;

/**
 * 2차원 좌표 상의 점을 나타내는 클래스 NamedPoint.
 * Point의 서브클래스로 구현하였다.
 */
public class NamedPoint extends Point
{
    private String name;

    public NamedPoint(String name, int x, int y)
    {
        super(x, y);
        this.name = name;
    }
    public String toString()
    {
        String buf = name + super.toString();
        return buf;
    }
    public String getName()
    {
        return name;
    }
    public static NamedPoint readNamedPoint(Scanner scan, String prompt) 
    {
        System.out.print(prompt + " ");
        String name = scan.next();
        int x = scan.nextInt();
        int y = scan.nextInt();
        NamedPoint p = new NamedPoint(name, x, y);
        return p;
    }
}
