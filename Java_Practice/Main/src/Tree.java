public class Tree {
	public static void draw(TurtleGraphics tg) {
		tg.penUp();

		tree(tg, 6);
		
		tg.penDown();
	}

	private static void tree(TurtleGraphics tg, int depth) {
		tg.forward(depth * 10);
		depth = depth - 1;
		if (depth > 0) {
			double x, y, degree;

			tg.leftTurn(45);

			for (int i = 0; i < 3; i++) {
				x = tg.getX(); // REMEMBER X,Y,DEGREE
				y = tg.getY();
				degree = tg.getDegree();

				tree(tg, depth);

				tg.setX(x); // GOBACK TO THE X,Y,DEGREE
				tg.setY(y);
				tg.setDegree(degree);

				tg.rightTurn(45);
			}
		}
	}
}
