import java.util.Iterator;
import java.lang.Iterable;

public abstract class List<T, S> implements Iterable{
	public Iterator iterator(){
		return new ListIterator(this);
	}
	public abstract boolean isNull();
    public abstract boolean isPair();
    public abstract T first();
    public abstract S second();
    public abstract String toString();         
}


class NullList<T, S> extends List {
    public boolean isNull() {
            return true;
    }
    public boolean isPair() {
        return false;
    }
    public T first() {
        return null;
    }

    public S second() {
    	return null;
    }
    public String toString() {
            return "()";
    }
}

class Pair<T, S> extends List{
	private T firstElem;
    private S secondElem;

    public Pair(T firstElem, S secondElem) {
            this.firstElem = firstElem;
            this.secondElem = secondElem;
    }
    public boolean isNull() {
    	return false;
    }
    public boolean isPair() {
    	return true;
    }
    public T first() {
            return firstElem;
    }
    public S second() {
            return secondElem;
    }
    public String toString() {
            return "(" + firstElem + ", " + secondElem.toString() + ")";
    }
}
