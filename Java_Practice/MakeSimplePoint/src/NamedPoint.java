/**
 * 2차원 좌표 상의 점을 나타내는 클래스 NamedPoint.
 * Point와 달리 점의 이름이 부여되어 있다.
 */
public class NamedPoint extends SimplePoint
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
}

