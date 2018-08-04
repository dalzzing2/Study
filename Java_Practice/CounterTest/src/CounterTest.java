public class CounterTest {
    public static void main(String[] args) {
    	int lower_bound = 0;
    	int upper_bound = 5;
    	
        Counter c = new Counter();
        Thread t1 = new MyThread( c );
        Thread t2 = new Thread( new MyImplementation( c ) );
        
        // ���� 5���� ũ�� 0���� ������ �����带 �����Ѵ�. ���� ������ ���� �ȿ� ������쿡�� �����带 �����Ѵ�.
        if(c.value() > upper_bound)
    		t1.stop();
        if(c.value() < lower_bound)
        	t2.stop();
        if(c.value() >= lower_bound || c.value() <= upper_bound){
        	t1.start();
            t2.start();
        }
        
        //��� �����尡 �����Ǹ� �����Ѵ�.
        try {
			t1.join();
			t2.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        
        System.out.println("The counter value: " + c.value());
    }
}

class Counter {
    int c = 0;
    public synchronized void increment() {
        c = c + 1;
        this.notify();
    }

    public synchronized void decrement() {
        if ( c <= 0 ) { 
            try { 
                this.wait(); 
            } catch (InterruptedException e1) { 
                e1.printStackTrace(); 
            } 
        } 
        c = c - 1; 
    } 

    public int value() {
        return c;
    }
} 

class MyThread extends Thread {
    private Counter c;
    public MyThread(Counter c) {
        this.c = c;
    }
    public void run() {
        for (int i=0; i<10; i++) {
            c.increment();
            System.out.println("increament c : " +c.value());
        }
    }
}

class MyImplementation implements Runnable {
    private Counter c;
    public MyImplementation(Counter c) {
        this.c = c;
    }
    public void run() {
        for (int i=0; i<10; i++) {
            c.decrement();
            System.out.println("decreament c : " +c.value());
        }
    }
}