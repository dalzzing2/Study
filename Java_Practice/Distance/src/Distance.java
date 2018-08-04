/************************************************************
 * Distance.java
 * 
 * 2차원 평면 상의 두 점 사이의 거리를 구하는 프로그램
 ************************************************************/

import java.util.Scanner;

/**
 * 2차원 평면 상의 두 점의 좌표 x1, y1, x2, y2를 입력 받아서
 * 두 점 사이의 거리를 피타고라스 정리에 의해 구한다.
 */
public class Distance 
{
    public static void main(String[] args) 
    {
        int x1, y1, x2, y2;
        double dist;
        Scanner scan = new Scanner(System.in);
        System.out.print("첫 번째 점의 좌표 (x, y)를 입력하세요. ");
        x1 = scan.nextInt();
        y1 = scan.nextInt();
        System.out.print("두 번째 점의 좌표 (x, y)를 입력하세요. ");
        x2 = scan.nextInt();
        y2 = scan.nextInt();
        dist = result(x1, y1, x2, y2);
        dist = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
        System.out.printf("(%d, %d)와 (%d, %d) 사이의 거리 = %5.2f%n",
                x1, y1, x2, y2, dist);
    }
    public static double result(int x1, int y1, int x2, int y2){
    	double result = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    	return result;
    }
}
