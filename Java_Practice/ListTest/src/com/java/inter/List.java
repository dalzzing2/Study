package com.java.inter;
import java.util.Iterator;
import java.lang.Iterable;

public abstract class List implements Iterable{
	public Iterator iterator(){
		return new ListIterator(this);
	}
	public abstract boolean isNull();
    public abstract boolean isPair();
    public abstract int first();
    public abstract List second();
    public abstract String toString();         
}


class NullList extends List {
    public boolean isNull() {
            return true;
    }
    public boolean isPair() {
        return false;
    }
    public int first() {
        return 0;
    }

    public List second() {
    	return null;
    }
    public String toString() {
            return "()";
    }
}

class Pair extends List{
	private int firstElem;
    private List secondElem;

    public Pair(int firstElem, List secondElem) {
            this.firstElem = firstElem;
            this.secondElem = secondElem;
    }
    public boolean isNull() {
    	return false;
    }
    public boolean isPair() {
    	return true;
    }
    public int first() {
            return this.firstElem;
    }
    public List second() {
            return this.secondElem;
    }
    public String toString() {
            return "(" + firstElem + ", " + secondElem.toString() + ")";
    }
}
