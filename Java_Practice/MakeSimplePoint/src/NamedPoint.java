/**
 * 2���� ��ǥ ���� ���� ��Ÿ���� Ŭ���� NamedPoint.
 * Point�� �޸� ���� �̸��� �ο��Ǿ� �ִ�.
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

