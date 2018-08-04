/************************************************************
 * MakeNamedPoint.java
 * 
 * 2차원 상의 점을 입출력하는 프로그램
 ************************************************************/

import java.util.Scanner;

/**
 * 2차원 좌표 상의 점을 나타내는 클래스 NamedPoint를 이용하여
 * 2차원 좌표를 하나 입력받고 출력하는 프로그램
 */
public class MakeNamedPoint
{
    public static void main(String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        NamedPoint p = readNamedPoint(scan, 
                "점의 이름과 좌표 x, y를 입력하세요.");
        System.out.printf("입력된 점 = %s%n", p.toString());
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
