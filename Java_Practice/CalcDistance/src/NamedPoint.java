import java.util.Scanner;

/**
 * 2���� ��ǥ ���� ���� ��Ÿ���� Ŭ���� NamedPoint.
 * Point�� ����Ŭ������ �����Ͽ���.
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
