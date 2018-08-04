import java.util.Scanner;

public class Calculator{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Button btext = new Button("텍스트윈도우", 0, 0, 399, 99);
		Button b0 = new Button("0", 0, 400, 99, 499);
		Button b1 = new Button("1", 0, 300, 99, 399);
		Button b2 = new Button("2", 100, 300, 199, 399);
		Button b3 = new Button("3", 200, 300, 299, 399);
		Button b4 = new Button("4", 0, 200, 99, 299);
		Button b5 = new Button("5", 100, 200, 199, 299);
		Button b6 = new Button("6", 200, 200, 299, 299);
		Button b7 = new Button("7", 0, 100, 99, 199);
		Button b8 = new Button("8", 100, 100, 199, 199);
		Button b9 = new Button("9", 200, 100, 299, 199);
		Button bplus = new Button("+", 300, 100, 399, 199);
		Button bminus = new Button("-", 300, 200, 399, 299);
		Button bmul = new Button("*", 300, 300, 399, 399);
		Button bdiv = new Button("/", 300, 400, 399, 499);
		Button bres = new Button("=", 200, 400, 299, 499);
		Button bcle = new Button("C", 100, 400, 199, 499);
		
		btext.draw();
		
		b7.draw();
		b8.draw();
		b9.draw();
		bplus.draw();
		
		b4.draw();
		b5.draw();
		b6.draw();
		bminus.draw();
		
		b1.draw();
		b2.draw();
		b3.draw();
		bmul.draw();
		
		b0.draw();
		bcle.draw();
		bres.draw();
		bdiv.draw();
		
		Ing cal = new Ing();
		
		ButtonClickListener handlerb0 = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputnum(0);
				System.out.println(cal.outputnum());
			};
		};
		b0.setHandler(handlerb0);
		
		ButtonClickListener handlerb1 = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputnum(1);
				System.out.println(cal.outputnum());
			};
		};
		b1.setHandler(handlerb1);
		
		ButtonClickListener handlerb2 = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputnum(2);
				System.out.println(cal.outputnum());
			};
		};
		b2.setHandler(handlerb2);
		
		ButtonClickListener handlerb3 = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputnum(3);
				System.out.println(cal.outputnum());
			};
		};
		b3.setHandler(handlerb3);
		
		ButtonClickListener handlerb4 = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputnum(4);
				System.out.println(cal.outputnum());
			};
		};
		b4.setHandler(handlerb4);
		
		ButtonClickListener handlerb5 = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputnum(5);
				System.out.println(cal.outputnum());
			};
		};
		b5.setHandler(handlerb5);
		
		ButtonClickListener handlerb6 = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputnum(6);
				System.out.println(cal.outputnum());
			};
		};
		b6.setHandler(handlerb6);
		
		ButtonClickListener handlerb7 = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputnum(7);
				System.out.println(cal.outputnum());
			};
		};
		b7.setHandler(handlerb7);
		
		ButtonClickListener handlerb8 = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputnum(8);
				System.out.println(cal.outputnum());
			};
		};
		b8.setHandler(handlerb8);
		
		ButtonClickListener handlerb9 = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputnum(9);
				System.out.println(cal.outputnum());
			};
		};
		b9.setHandler(handlerb9);
		
		ButtonClickListener handlerbplus = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputop('+');
				System.out.println(cal.outputop());
			};
		};
		bplus.setHandler(handlerbplus);
		
		ButtonClickListener handlerbminus = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputop('-');
				System.out.println(cal.outputop());
			};
		};
		bminus.setHandler(handlerbminus);
		
		ButtonClickListener handlerbmul = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputop('*');
				System.out.println(cal.outputop());
			};
		};
		bmul.setHandler(handlerbmul);
		
		ButtonClickListener handlerbdiv = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputop('/');
				System.out.println(cal.outputop());
			};
		};
		bdiv.setHandler(handlerbdiv);
		
		ButtonClickListener handlerbres = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputop('=');
				System.out.println(cal.outputres());
			};
		};
		bres.setHandler(handlerbres);
		
		ButtonClickListener handlerbcle = new ButtonClickListener(){
			public void onClick(Button b){
				cal.inputop('C');
				System.out.println(cal.outputop());
			};
		};
		bcle.setHandler(handlerbcle);
		
		Button[] arr = {b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, bplus, bminus, bmul, bdiv, bres, bcle};
		Boolean flag = true;
		
		int x, y;
		Scanner scan = new Scanner(System.in);
		while(flag){
			x = scan.nextInt();
			y = scan.nextInt();
			
			for(Button b : arr){
				b.Touch(x, y);
			}
		}
	}
}