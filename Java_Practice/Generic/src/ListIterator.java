import java.util.Iterator;

public class ListIterator<T, S> implements Iterator{
	private List l;
	
	public ListIterator(List l){
		this.l = l;
	}
	public boolean hasNext(){
		return l.isPair();
	}
	public Object next(){
		if(hasNext()){
			int elem = (Integer)l.first();
			l = (List)l.second();
			return elem;
		}
		else
			return null;
	}
	/*
	 * public ListIterator(List l){
	 * this.l = l;
	 * }
	 * 
	 * public boolean hasNext(){
	 * return l.isPair();
	 * }
	 * 
	 * public Object next(){
	 * int i = l.first();
	 * l = l.second();
	 * return l;
	 * }
	 * 
	 * public void remove(){
	 * }
	 */
}
