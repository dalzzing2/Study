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
 * Servlet implementation class JSP9_6_IndexPro
 */
@WebServlet("/JSP9_6_IndexPro")
public class JSP9_6_IndexPro extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JSP9_6_IndexPro() {
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
		// 쿠키 정보 가져온다.
		String user_id = box.getCookie("user_id", "utf-8");
		String user_pw = box.getCookie("user_pw", "utf-8");
		String user_name = box.getCookie("user_name", "utf-8");
		// 로그인하지 않은 상태에서 직접 주소를 입력해서 
		// 들어 왔을 경우
		if(user_id == null){
			response.sendRedirect("JSP9_6_CookieLoginMain.jsp");
		} else {
			request.setAttribute("user_name", user_name);
			// 페이지로 이동
			String site = "JSP9_6_Index.jsp";
			RequestDispatcher dis 
					= request.getRequestDispatcher(site);
			dis.forward(request, response);
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
