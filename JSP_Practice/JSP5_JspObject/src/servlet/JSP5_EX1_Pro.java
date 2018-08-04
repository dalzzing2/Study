package servlet;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class JSP5_EX1_Pro
 */
@WebServlet("/JSP5_EX1_Pro")
public class JSP5_EX1_Pro extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JSP5_EX1_Pro() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// 파라미터 데이터 추출
		String num1 = request.getParameter("num1");
		String num2 = request.getParameter("num2");
		String op = request.getParameter("op");
		// 숫자로 변환
		int number1 = Integer.parseInt(num1);
		int number2 = Integer.parseInt(num2);
		// 연산작업
		int result = 0;
		if(op.equals("1")){
			result = number1 + number2;
		} else if(op.equals("2")){
			result = number1 - number2;
		} else if(op.equals("3")){
			result = number1 * number2;
		} else if(op.equals("4")){
			result = number1 / number2;
		}
		// 결과를 세션에 담는다.
		HttpSession session = request.getSession();
		session.setAttribute("result", result);
		// JSP로 이동한다.
		String site = "JSP5_EX1_Result.jsp";
		RequestDispatcher dis 
				= request.getRequestDispatcher(site);
		dis.forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
