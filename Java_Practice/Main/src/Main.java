import java.awt.Graphics;
import javax.swing.JApplet;

public class Main extends JApplet{
	public void init(){
		resize(1200, 720);
	}
	
	public void paint(Graphics g){
		TurtleGraphics tg = new TurtleGraphics(600, 300, 0, g);
		
		//Rectangle.draw(tg);
		//Pentagon.draw(tg);
		//Octagon.draw(tg);
		Tree.draw(tg);
	}
}
