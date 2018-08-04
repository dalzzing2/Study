
public class Button {
	private int x, y, w, h;
	private String name;
	public Button(){
		x = y = 0;
		w = h = 0;
	}
	public Button(String name, int x, int y, int w, int h){
		this.name = name;
		this.x = x;
		this.y = y;
		this.w = w;
		this.h = h;
	}
	public void draw(){
		System.out.println("¹öÆ° " +name+ " : (" +x+ "," +y+ ") ~ (" +w+ "," +h+ ")");
	}
	
	private ButtonClickListener handler;
	
	public void setHandler(ButtonClickListener handler){
		this.handler = handler;
	}
	/*
	public ButtonClickListener getHandler(){
		System.out.println("aaaaaa");
		return handler;
	}*/
	
	public void Touch(int x, int y){
		if(this.x <= x && x <= this.w && this.y <= y && y <= this.h){
			handler.onClick(this);
		}
	}
}