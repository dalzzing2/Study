import java.util.HashMap;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Interpreter2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		HashMap<String, Double> env = new HashMap<String, Double>();
		while (scanner.hasNext()) {
			String line = scanner.nextLine();
			StringTokenizer stz = new StringTokenizer(line);
			// double result = evalExpr(env, 0, "+", stz);
			// System.out.println("Evalute " + line + " to" + result);

			evalStmt(env, stz);
		}
	}

	// evalStmt
	private static void evalStmt(HashMap<String, Double> env,
			StringTokenizer stz) {
		Scanner scan = new Scanner(System.in);
		double result = 0;

		if (stz.countTokens() == 0) {
			System.err.println("tokens not available");
		} else {
			String token = stz.nextToken();

			if (token.equals("READ")) {
				String letter = stz.nextToken();
				if (Character.isLetter(letter.charAt(0))) { // 입력문
					System.out.println("Input double number : ");
					double input = scan.nextDouble();
					env.put(letter, input);
					System.out.println("READ token result : " + letter + " = "
							+ input);
				}
			} else if (token.equals("PRINT")) { // 출력문
				result = evalExpr(env, 0, "+", stz);
				System.out.println("PRINT token result : " + result);
			} else if (Character.isLetter(token.charAt(0))) { // 할당문
				String equals = stz.nextToken();
				if (equals.equals("=")) {
					result = evalExpr(env, 0, "+", stz);
				}
				env.put(token, result);
				System.out.println("ASSIGN token(letter) result : " + token
						+ " = " + result);
			} else if (Character.isDigit(token.charAt(0))) {
				double operand1 = 0;
				String operator1 = "+";

				if (stz.countTokens() == 0) {
					double operand2 = evalOperand(env, token);
					result = evalExpr(operand1, operator1, operand2);
				} else if (stz.countTokens() >= 2) {
					double operand2 = evalOperand(env, token);
					String operator2 = stz.nextToken();
					if (precedence(operator1) > precedence(operator2)) {
						double d = evalExpr(operand1, operator1, operand2);
						result = evalExpr(env, d, operator2, stz);
					} else if (precedence(operator1) < precedence(operator2)) {
						double d = evalExpr(env, operand2, operator2, stz);
						result = evalExpr(operand1, operator1, d);
					} else {
						if (associativity(operator1) == Associativity.LeftToRight) {
							double d = evalExpr(operand1, operator1, operand2);
							result = evalExpr(env, d, operator2, stz);
						} else {
							double d = evalExpr(env, operand2, operator2, stz);
							result = evalExpr(operand1, operator1, d);
						}
					}
				} else
					System.err.println("Tokens not available");
				System.out.println("ASSIGN token(digit) result : " + result);
			}
		}
	}

	// evalExpr
	public static double evalExpr(double operand1, String operator,
			double operand2) {
		double result = 0;

		switch (operator.charAt(0)) {
		case '+':
			result = operand1 + operand2;
			break;
		case '-':
			result = operand1 - operand2;
			break;
		case '*':
			result = operand1 * operand2;
			break;
		case '/':
			result = operand1 / operand2;
			break;
		default:
			System.err.println("Unsupported operator : " + operator);
		}
		return result;
	}

	private static double evalExpr(HashMap<String, Double> env,
			double operand1, String operator1, StringTokenizer stz) {
		double result = 0;

		if (stz.countTokens() == 0) {
			System.err.println("Tokens not available");
		} else if (stz.countTokens() == 1) {
			String token = stz.nextToken();
			double operand2 = evalOperand(env, token);
			result = evalExpr(operand1, operator1, operand2);
		} else if (stz.countTokens() >= 3) {
			String tokenOperand2 = stz.nextToken();
			double operand2 = evalOperand(env, tokenOperand2);
			String operator2 = stz.nextToken();

			if (precedence(operator1) > precedence(operator2)) {
				double d = evalExpr(operand1, operator1, operand2);
				result = evalExpr(env, d, operator2, stz);
			} else if (precedence(operator1) < precedence(operator2)) {
				double d = evalExpr(env, operand2, operator2, stz);
				result = evalExpr(operand1, operator1, d);
			} else {
				if (associativity(operator1) == Associativity.LeftToRight) {
					double d = evalExpr(operand1, operator1, operand2);
					result = evalExpr(env, d, operator2, stz);
				} /*
				 * else { double d = evalExpr(env, operand2, operator2, stz);
				 * result = evalExpr(operand1, operator1, d); }
				 */
			}
		} else {
			System.err.println("Something wrong:");
			while (stz.hasMoreElements()) {
				System.err.println(stz.nextToken() + " ");
			}
			System.err.println();
		}
		return result;
	}

	// evalOperand
	public static double evalOperand(HashMap<String, Double> env, String operand) {
		double result = 0;

		if (Character.isLetter(operand.charAt(0))) {
			Double d = env.get(operand);

			if (d == null) {
				System.err.println("Undefined variable aa: " + operand);
			} else {
				result = d;
			}
		} else {
			result = new Double(operand);
		}
		return result;
	}

	public static int precedence(String operator) {
		switch (operator.charAt(0)) {
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 4;
		default:
			System.err.println("Unsupported operator: " + operator);
			return 0;

		}
	}

	enum Associativity {
		LeftToRight, RightToLeft;
	}

	public static Associativity associativity(String operator) {
		switch (operator.charAt(0)) {
		case '+':
		case '-':
		case '*':
		case '/':
			return Associativity.LeftToRight;
		case '=':
			return Associativity.RightToLeft;
		default:
			System.err.println("Unsupported operator: " + operator);
			return Associativity.LeftToRight;
		}
	}
}