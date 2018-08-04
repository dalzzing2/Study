/************************************************************
 * CalcDistance.java
 * 
 * 2���� �� �� ������ �Ÿ��� ����ϴ� ���α׷�
 ************************************************************/

import java.util.Scanner;

/**
 * 2���� ��� ���� �� �� �Ÿ��� �����ϱ� ���� Ŭ���� CalcDistance.
 * Point ��ü�� NamedPoint ��ü�� ��� ��� ����Ͽ� 
 * �� ���� ���� �� ���� ������ ��� �����Ѵ�.
 */
public class CalcDistance 
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        Point p = Point.readPoint(scan, 
        		"ù ��° ���� ��ǥ x�� y�� �Է��ϼ���.");
        Point q = Point.readPoint(scan, 
        		"�� ��° ���� ��ǥ x�� y�� �Է��ϼ���.");
        NamedPoint r = NamedPoint.readNamedPoint(scan, 
        		"�� ��° ���� �̸��� ��ǥ x, y�� �Է��ϼ���.");
        NamedPoint s = NamedPoint.readNamedPoint(scan, 
        		"�� ��° ���� �̸��� ��ǥ x, y�� �Է��ϼ���.");
        System.out.printf("%s��(��) %s ������ �Ÿ� = %5.2f%n",
                p.toString(), q.toString(), p.distanceFrom(q));
        System.out.printf("%s��(��) %s ������ �Ÿ� = %5.2f%n",
                p.toString(), r.toString(), p.distanceFrom(r));
        System.out.printf("%s��(��) %s ������ �Ÿ� = %5.2f%n",
                r.toString(), q.toString(), r.distanceFrom(q));
        System.out.printf("%s��(��) %s ������ �Ÿ� = %5.2f%n",
                r.toString(), s.toString(), r.distanceFrom(s));
    }  
}
