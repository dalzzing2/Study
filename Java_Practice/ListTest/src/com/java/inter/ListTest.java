package com.java.inter;
public class ListTest{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List l1 = new NullList();
		List l2 = new Pair(3, l1);
		List l3 = new Pair(2, l2);

		for(Object o : l3){
			int i = (Integer)o;
			System.out.print(i+" ");
		}
	}
}
