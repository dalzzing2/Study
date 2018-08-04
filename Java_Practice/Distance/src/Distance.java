/************************************************************
 * Distance.java
 * 
 * 2���� ��� ���� �� �� ������ �Ÿ��� ���ϴ� ���α׷�
 ************************************************************/

import java.util.Scanner;

/**
 * 2���� ��� ���� �� ���� ��ǥ x1, y1, x2, y2�� �Է� �޾Ƽ�
 * �� �� ������ �Ÿ��� ��Ÿ��� ������ ���� ���Ѵ�.
 */
public class Distance 
{
    public static void main(String[] args) 
    {
        int x1, y1, x2, y2;
        double dist;
        Scanner scan = new Scanner(System.in);
        System.out.print("ù ��° ���� ��ǥ (x, y)�� �Է��ϼ���. ");
        x1 = scan.nextInt();
        y1 = scan.nextInt();
        System.out.print("�� ��° ���� ��ǥ (x, y)�� �Է��ϼ���. ");
        x2 = scan.nextInt();
        y2 = scan.nextInt();
        dist = result(x1, y1, x2, y2);
        dist = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
        System.out.printf("(%d, %d)�� (%d, %d) ������ �Ÿ� = %5.2f%n",
                x1, y1, x2, y2, dist);
    }
    public static double result(int x1, int y1, int x2, int y2){
    	double result = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    	return result;
    }
}
