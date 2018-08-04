package servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import util.CookieBox;

/**
 * Servlet implementation class JSP9_6_CookieLogout
 */
@WebServlet("/JSP9_6_CookieLogout")
public class JSP9_6_CookieLogout extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JSP9_6_CookieLogout() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// 쿠키 박스 객체 생성
		CookieBox box = new CookieBox(request, response);
		// 삭제할 쿠키를 셋팅
		box.setCookie("user_id", "", 0, "utf-8");
		box.setCookie("user_pw", "", 0, "utf-8");
		box.setCookie("user_name", "", 0, "utf-8");
		// 첫 페이지로 이동한다.
		response.sendRedirect("JSP9_6_CookieLoginMainServlet");
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
