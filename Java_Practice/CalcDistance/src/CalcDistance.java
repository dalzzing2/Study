/************************************************************
 * CalcDistance.java
 * 
 * 2차원 두 점 사이의 거리를 계산하는 프로그램
 ************************************************************/

import java.util.Scanner;

/**
 * 2차원 평면 상의 두 점 거리를 측정하기 위한 클래스 CalcDistance.
 * Point 객체와 NamedPoint 객체를 모두 모두 사용하여 
 * 두 종류 점의 네 가지 조합을 모두 점검한다.
 */
public class CalcDistance 
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        Point p = Point.readPoint(scan, 
        		"첫 번째 점의 좌표 x와 y를 입력하세요.");
        Point q = Point.readPoint(scan, 
        		"두 번째 점의 좌표 x와 y를 입력하세요.");
        NamedPoint r = NamedPoint.readNamedPoint(scan, 
        		"세 번째 점의 이름과 좌표 x, y를 입력하세요.");
        NamedPoint s = NamedPoint.readNamedPoint(scan, 
        		"네 번째 점의 이름과 좌표 x, y를 입력하세요.");
        System.out.printf("%s과(와) %s 사이의 거리 = %5.2f%n",
                p.toString(), q.toString(), p.distanceFrom(q));
        System.out.printf("%s과(와) %s 사이의 거리 = %5.2f%n",
                p.toString(), r.toString(), p.distanceFrom(r));
        System.out.printf("%s과(와) %s 사이의 거리 = %5.2f%n",
                r.toString(), q.toString(), r.distanceFrom(q));
        System.out.printf("%s과(와) %s 사이의 거리 = %5.2f%n",
                r.toString(), s.toString(), r.distanceFrom(s));
    }  
}
