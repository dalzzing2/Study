package servlet;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import util.CookieBox;

/**
 * Servlet implementation class JSP9_6_CookieLoginMainServlet
 */
@WebServlet("/JSP9_6_CookieLoginMainServlet")
public class JSP9_6_CookieLoginMainServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JSP9_6_CookieLoginMainServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// CookieBox 객체 생성
		CookieBox box = new CookieBox(request, response);
		// user_id란 이름의 쿠키가 있는지 확인한다.
		String user_id = box.getCookie("user_id", "utf-8");
		String user_pw = box.getCookie("user_pw", "utf-8");
		// 정보가 있다면 로그인 처리하는 서블릿으로 이동
		if(user_id != null){
			// 아이디와 비밀번호 정보를 request에 담는다.
			request.setAttribute("user_id", user_id);
			request.setAttribute("user_pw", user_pw);
			
			String site = "JSP9_6_CookieLoginPro";
			RequestDispatcher dis
				= request.getRequestDispatcher(site);
			dis.forward(request, response);
			
		// 정보가 없다면 로그인 정보를 입력하는 JSP로 이동
		} else {
			response.sendRedirect("JSP9_6_CookieLoginMain.jsp");
		}
	}	

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
