
public class Rectangle {
	public static void draw(TurtleGraphics tg){
		tg.penUp();
		
		tg.forward(100);
		tg.leftTurn(90);
		
		tg.forward(100);
		tg.leftTurn(90);
		
		tg.forward(100);
		tg.leftTurn(90);
		
		tg.forward(100);
		
		tg.penDown();
	}
}
