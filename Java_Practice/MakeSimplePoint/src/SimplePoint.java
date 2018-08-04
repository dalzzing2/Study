/**
 * 2���� ��ǥ ���� ���� ��Ÿ���� Ŭ���� Point����
 * toString �޼ҵ带 ������ Ŭ����
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
