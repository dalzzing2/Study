
public class Tv {
	public static void main(String[] args){
		Tvmanagement tv1, tv2;
		//���� 0 , ���� ��������, ȭ�� ����
		tv1 = new Tvmanagement("�ＺƼ��", 0, "��������", 0);
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
	
	// ���� on_off �� 0(��������)��  0�� �ƴѰ�(��������)���� ����
	public String power_control(int power){
		on_off = power;
		if(on_off==0)
			power_state = "��������";
		else
			power_state = "��������";
		return power_state;
	}
	// 1�� -1������ ����
	public int vol_control(int vol){
		volume = volume + vol;
		return volume;
	}
	// 1�� -1������ ����
	public int screen_control(int screen){
		channel = channel + screen;
		return channel;
	}
	public String toString(){
		return (name+ "��ǰ ���� -> ���� : " +power_state+ ", ���� : " +volume+ ", ä��" +channel);
	}
}