package bean;

import java.util.ArrayList;

public class SaxBean {
	
	public String school_name;
	public String school_addr;
	public String school_cnt;
	
	public ArrayList<String> attr_grade;
	public ArrayList<String> attr_class_cnt;
	
	public ArrayList<String> class_number;
	public ArrayList<String> class_member_cnt;
	public ArrayList<String> class_boss_name;
	public ArrayList<String> class_president;
		
	public SaxBean(){
		attr_grade = new ArrayList<String>();
		attr_class_cnt = new ArrayList<String>();
		
		class_number = new ArrayList<String>();
		class_member_cnt = new ArrayList<String>();
		class_boss_name = new ArrayList<String>();
		class_president = new ArrayList<String>();
	}
}









