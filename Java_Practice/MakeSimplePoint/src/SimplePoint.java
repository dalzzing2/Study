/**
 * 2차원 좌표 상의 점을 나타내는 클래스 Point에서
 * toString 메소드를 제거한 클래스
 */
public class SimplePoint 
{
    private int x, y;

    public SimplePoint(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
    public String toString()
    {
        String buf = "(" + x + ", " + y + ")";
        return buf;
    }
    public int getX()
    {
        return x;
    }
    public int getY()
    {
        return y;
    }
}
