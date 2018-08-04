public class ListTest{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<Integer, List> l1 = new NullList<Integer, List>();
		List<Integer, List> l2 = new Pair<Integer, List>(3, l1);
		List<Integer, List> l3 = new Pair<Integer, List>(2, l2);

		for(Object o : l3){
			int i = (Integer)o;
			System.out.print(i+" ");
		}
	}
}
