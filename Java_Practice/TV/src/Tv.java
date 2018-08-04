
public class Tv {
	public static void main(String[] args){
		Tvmanagement tv1, tv2;
		//볼륨 0 , 전원 오프상태, 화면 없음
		tv1 = new Tvmanagement("삼성티비", 0, "전원꺼짐", 0);
		System.out.println(tv1);
		
		tv1.power_control(1);
		System.out.println(tv1);
		
		tv1.vol_control(1);
		System.out.println(tv1);
		
		tv1.vol_control(1);
		System.out.println(tv1);
		
		tv1.vol_control(-1);
		System.out.println(tv1);
		
		tv1.screen_control(1);
		System.out.println(tv1);
		
		tv1.vol_control(1);
		System.out.println(tv1);
		
		tv1.screen_control(1);
		System.out.println(tv1);
		
		tv1.screen_control(-1);
		System.out.println(tv1);
		
		tv1.power_control(0);
		System.out.println(tv1);
	}
}

class Tvmanagement{
	private String name;
	private int volume=0;
	private int on_off=0;
	private int channel=0;
	private String power_state;
	
	public Tvmanagement(String manufacture, int vol, String p_s, int screen){
		name = manufacture;
		volume = vol;
		power_state = p_s;
		channel = screen;
	}
	
	// 전원 on_off 는 0(전원꺼짐)과  0이 아닌값(전원켜짐)으로 구성
	public String power_control(int power){
		on_off = power;
		if(on_off==0)
			power_state = "전원꺼짐";
		else
			power_state = "전원켜짐";
		return power_state;
	}
	// 1과 -1값으로 구성
	public int vol_control(int vol){
		volume = volume + vol;
		return volume;
	}
	// 1과 -1값으로 구성
	public int screen_control(int screen){
		channel = channel + screen;
		return channel;
	}
	public String toString(){
		return (name+ "제품 상태 -> 전원 : " +power_state+ ", 볼륨 : " +volume+ ", 채널" +channel);
	}
}