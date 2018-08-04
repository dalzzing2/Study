import java.awt.Color;
import java.awt.Graphics;

public class TurtleGraphics {
	private double x;
	private double y;
	private double degree;
	private boolean penup;
	
	private Graphics g;
	
	TurtleGraphics (double x, double y, double degree, Graphics g) {
		this.x = x;
		this.y = y;
		this.degree = degree;
		this.g = g;
		
		penup = true;
	}
	
	public void penUp() {
		penup = true;
	}
	
	public void penDown() {
		penup = false;
	}
	
	public void forward(double steps){
		if(penup == true) {
			g.drawLine((int)this.x, (int)this.y,
					(int)(this.x + steps * Math.sin(this.degree)), (int)(this.y - steps * Math.cos(this.degree)));
			
			x = this.x + steps * Math.sin(this.degree);
			y = this.y - steps * Math.cos(this.degree);
		}
		else {
			x = this.x + steps * Math.sin(this.degree);
			y = this.y - steps * Math.cos(this.degree);
		}
	}
	
	public void backward(double steps){
		forward(-steps);
	}
	
	public void leftTurn(double angle){
		degree = this.degree - Math.toRadians(angle);
	}
	
	public void rightTurn(double angle){
		degree = this.degree + Math.toRadians(angle);
	}
	
	public double getX() { return x; }
	public double getY() { return y; }
	public double getDegree() { return degree; }
	
	public void setX(double x) { this.x = x; }
	public void setY(double y) { this.y = y; }
	public void setDegree(double degree) { this.degree = degree; }
	
}
