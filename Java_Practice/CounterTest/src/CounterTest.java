public class CounterTest {
    public static void main(String[] args) {
    	int lower_bound = 0;
    	int upper_bound = 5;
    	
        Counter c = new Counter();
        Thread t1 = new MyThread( c );
        Thread t2 = new Thread( new MyImplementation( c ) );
        
        // 값이 5보다 크고 0보다 작으면 쓰레드를 중지한다. 값이 지정한 범위 안에 있을경우에는 쓰레드를 실행한다.
        if(c.value() > upper_bound)
    		t1.stop();
        if(c.value() < lower_bound)
        	t2.stop();
        if(c.value() >= lower_bound || c.value() <= upper_bound){
        	t1.start();
            t2.start();
        }
        
        //모든 쓰레드가 중지되면 종료한다.
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