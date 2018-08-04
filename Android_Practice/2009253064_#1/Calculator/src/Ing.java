
public class Ing {
	private double num=0, res=0;
	private char tempop='E';
	private double tempnum1=0;
	
	private char op;
	public void inputnum(int num){
		this.num = this.num * 10 + num;
	}
	public double outputnum(){
		return this.num;
	}
	public double outputres(){
		return this.res;
	}
	public void inputop(char op){
		this.op = op;
		if(this.op=='+'){
			if(this.tempop == '-'){
				this.res = this.tempnum1 - this.num;
			}
			else if(this.tempop == 'E'){
				this.res = this.num;
			}
			else if(this.tempop == '+'){
				this.res = this.tempnum1 + this.num;
			}
			else if(this.tempop == '*'){
				this.res = this.tempnum1 * this.num;
			}
			else if(this.tempop == '/'){
				this.res = this.tempnum1 / this.num;
			}
			this.tempop = this.op;
			this.tempnum1 = this.res;
			this.num = 0;
		}
		else if(this.op=='-'){
			if(this.tempop == '-'){
				this.res = this.tempnum1 - this.num;
			}
			else if(this.tempop == 'E'){
				this.res = this.num;
			}
			else if(this.tempop == '+'){
				this.res = this.tempnum1 + this.num;
			}
			else if(this.tempop == '*'){
				this.res = this.tempnum1 * this.num;
			}
			else if(this.tempop == '/'){
				this.res = this.tempnum1 / this.num;
			}
			this.tempop = this.op;
			this.tempnum1 = this.res;
			this.num = 0;
		}
		else if(this.op=='*'){
			if(this.tempop == '-'){
				this.res = this.tempnum1 - this.num;
			}
			else if(this.tempop == 'E'){
				this.res = this.num;
			}
			else if(this.tempop == '+'){
				this.res = this.tempnum1 + this.num;
			}
			else if(this.tempop == '*'){
				this.res = this.tempnum1 * this.num;
			}
			else if(this.tempop == '/'){
				this.res = this.tempnum1 / this.num;
			}
			this.tempop = this.op;
			this.tempnum1 = this.res;
			this.num = 0;
		}
		else if(this.op=='/'){
			if(this.tempop == '-'){
				this.res = this.tempnum1 - this.num;
			}
			else if(this.tempop == 'E'){
				this.res = this.num;
			}
			else if(this.tempop == '+'){
				this.res = this.tempnum1 + this.num;
			}
			else if(this.tempop == '*'){
				this.res = this.tempnum1 * this.num;
			}
			else if(this.tempop == '/'){
				this.res = this.tempnum1 / this.num;
			}
			this.tempop = this.op;
			this.tempnum1 = this.res;
			this.num = 0;
		}
		else if(this.op == '='){
			if(this.tempop == '+'){
				this.res = this.res + this.num;
			}
			else if(this.tempop == '-'){
				this.res = this.res - this.num;
			}
			else if(this.tempop  == '*'){
				this.res = this.res * this.num;
			}
			else if(this.tempop == '/'){
				this.res = this.res / this.num;
			}
		}
		else if(this.op == 'C'){
			this.res = 0;
			this.num = 0;
		}
	}
	public char outputop(){
		return this.op;
	}
}
