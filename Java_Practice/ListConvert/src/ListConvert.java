public class ListConvert {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List list = new Pair(1, new Pair(2, new Pair(3, new NullList())));
		Tree tree1 = new BinTree(new BinTree(new NullTree(), 2, new NullTree()), 1, new BinTree(new NullTree(), 3, new NullTree()));
		Tree tree2 = new BinTree(new BinTree(new BinTree(new NullTree(), 4, new NullTree()), 2, new NullTree()), 1, new BinTree(new NullTree(), 3, new NullTree()));
		
		System.out.print("list.print() ==> "); list.print();
		System.out.print("list.reverse() ==> ");list.reverse().print();
		System.out.print("list.concat() ==> ");list.concat(list).print();
		System.out.println("list.length() ==> " +list.length());
		System.out.println("list.sum() ==> " +list.sum());

		System.out.println("\n\n");
		System.out.println("tree1.sum() ==> " +tree1.sum());
		System.out.println("tree1.count() ==> " +tree1.count());
		System.out.println("tree1.height() ==> " +tree1.height());
		
		System.out.println("\n\n");
		System.out.println("tree2.sum() ==> " +tree2.sum());
		System.out.println("tree2.count() ==> " +tree2.count());
		System.out.println("tree2.height() ==> " +tree2.height());
		
		System.out.println("\n\n");
		System.out.print("preorder\n ===>");tree1.preorder().print();
		System.out.print("inorder\n ===>");tree1.inorder().print();
		System.out.print("postorder\n ===>");tree1.postorder().print();
		System.out.print("preorder\n ===>");tree2.preorder().print();
	}
	
}

abstract class List {
	public abstract boolean isNull();
	public abstract boolean isPair();
	public abstract int first();
	public abstract List second();
	public abstract String toString();
	
	public void print(){
		System.out.print("[");
		
		List l = this;
		
		while(l.isPair()){
				System.out.print(l.first());
				System.out.print(l.second().isNull()?"":",");
				l = l.second();
		}
		System.out.println("]");
	}
	public int length(){
		
		List l = this;
		int count = 0;
		while(l.isPair()){
			count = count + 1;
			l = l.second();
		}
		return count;
	}
	public int sum(){
		
		List l = this;
		int sum = 0;
		while(l.isPair()){
			sum = sum + l.first();
			l = l.second();
		}
		return sum;
	}
	
	public List concat(List l){
		if(this.isNull()){
			return l;
		}
		else{
			return new Pair(this.first(), this.second().concat(l));
		}
	}
	public List reverse(){
		List l = this;
		if(l.isNull())
			return l;
		else
			return l.second().reverse().concat( new Pair( l.first(), new NullList()));
	}
}

class Pair extends List {
	private int firstElem;
	private List secondElem;

	public Pair(int firstElem, List secondElem) {
		this.firstElem = firstElem;
		this.secondElem = secondElem;
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

	@Override
	public boolean isNull() {
		// TODO Auto-generated method stub
		return false;
	}
}

class NullList extends List {
	public boolean isNull() {
		return true;
	}

	public String toString() {
		return "()";
	}

	@Override
	public boolean isPair() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public int first() {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public List second() {
		// TODO Auto-generated method stub
		return null;
	}
}


abstract class Tree {
	public abstract boolean isNull();
	public abstract boolean isBinTree();
	public abstract int value();
	public abstract Tree left();
	public abstract Tree right();
	public abstract String toString();
	
	public int sum(){
		Tree t = this;
		int sum = 0;
		if(t.isBinTree()){
			sum = sum + t.value();
			if(t.left().isBinTree())
				sum = sum + t.left().sum();
			if(t.right().isBinTree())
				sum = sum + t.right().sum();
		}
		return sum;
	}
	public int count(){
		Tree t = this;
		int count = 0;
		
		if(t.isBinTree()){
			if(t.left().isBinTree())
				count = count + t.left().count();
			count = count + 1;
			if(t.right().isBinTree())
				count = count + t.right().count();
		}
		return count;
	}
	public int height(){
		Tree t = this;
		
		int height = 0;
		if(t.isBinTree()){
			height = 1 + ((t.left().height() > t.right().height()) ? t.left() : t.right()).height();
		}
		return height;
	}
	
	public List preorder(){
		if(this.isNull()){
			return new NullList();
		}
		else
		{
			return new Pair(this.value(), new NullList())
			.concat(this.left().preorder())
			.concat(this.right().preorder());
		}
	}
	public List inorder(){
		if(this.isNull()){
			return new NullList();
		}
		else
		{
			return this.left().inorder()
					.concat(new Pair(this.value(), new NullList())
					.concat(this.right().inorder()));
		}
	}
	public List postorder(){
		if(this.isNull()){
			return new NullList();
		}
		else
		{
			return this.left().postorder()
					.concat(this.right().postorder())
					.concat(new Pair(this.value(), new NullList()));
		}
	}
}
class BinTree extends Tree {
	private int value;
	private Tree leftTree;
	private Tree rightTree;
	
	public BinTree(Tree left, int value, Tree right){
		this.leftTree = left;
		this.value = value;
		this.rightTree = right;
	}
	
	public boolean isBinTree(){
		return true;
	}
	public int value(){
		return this.value;
	}
	public Tree left(){
		return this.leftTree;
	}
	public Tree right(){
		return this.rightTree;
	}
	public String toString(){
		return leftTree.value() + "" + value + "" +rightTree.toString();
		
	}
	public boolean isNull() {
		return false;
	}
}
class NullTree extends Tree {
	public boolean isNull(){
		return true;
	}
	public String toString(){
		return "()";
	}
	public boolean isBinTree(){
		return false;
	}
	public Tree left(){
		return null;
	}
	public Tree right(){
		return null;
	}
	public int value(){
		return 0;
	}
}
