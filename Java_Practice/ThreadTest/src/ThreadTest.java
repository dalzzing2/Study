public class ThreadTest {
	public static void main(String[] args) {
		String lock1 = "lock1";
		String lock2 = "lock2";
		String lock3 = "lock3";
		String lock4 = "lock4";
		String lock5 = "lock5";
		
		// a 와 b 는동시시작 불가
		
		// b 와 c 는동시시작 불가
		
		// c 와 d 는동시시작불가
		
		// d 와 e 는 동시시작 불가
		
		// a가 시작되거나 e가 시작되면 두개는 이후 실행 불가
		
		Thread p1 = new ThreadPhilosopher("A", lock1, lock2);
		Thread p2 = new ThreadPhilosopher("B", lock3, lock2);
		Thread p3 = new ThreadPhilosopher("C", lock4, lock3);
		Thread p4 = new ThreadPhilosopher("D", lock5, lock4);
		Thread p5 = new ThreadPhilosopher("E", lock1, lock5);

		p1.start();
		p2.start();
		p3.start();
		p4.start();
		p5.start();
		
		try {
			p1.join();
			p2.join();
			p3.join();
			p4.join();
			p5.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println("Finished...");
	}
}

class ThreadPhilosopher extends Thread {
	String name;
	int counter = 10;
	String left;
	String right;

	ThreadPhilosopher(String name, String left, String right) {
		this.name = name;
		this.left = left;
		this.right = right;
	}
	public void run () {
		while ( counter > 0 ) {
			synchronized (left) {
				System.out.println(name + " got " + left);
				synchronized (right) {
					System.out.println(name + " got " + right);
					counter--;
				}
			}
			System.out.println(name + " released both");
		}
	}
}
