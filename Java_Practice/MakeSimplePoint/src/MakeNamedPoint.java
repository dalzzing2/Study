/************************************************************
 * MakeNamedPoint.java
 * 
 * 2���� ���� ���� ������ϴ� ���α׷�
 ************************************************************/

import java.util.Scanner;

/**
 * 2���� ��ǥ ���� ���� ��Ÿ���� Ŭ���� NamedPoint�� �̿��Ͽ�
 * 2���� ��ǥ�� �ϳ� �Է¹ް� ����ϴ� ���α׷�
 */
public class MakeNamedPoint
{
    public static void main(String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        NamedPoint p = readNamedPoint(scan, 
                "���� �̸��� ��ǥ x, y�� �Է��ϼ���.");
        System.out.printf("�Էµ� �� = %s%n", p.toString());
    }
    private static NamedPoint readNamedPoint(Scanner scan, String prompt) 
    {
        String name;
        int x, y;
        System.out.print(prompt + " ");
        name = scan.next();
        x = scan.nextInt();
        y = scan.nextInt();
        NamedPoint p = new NamedPoint(name, x, y);
        return p;
    }
}
