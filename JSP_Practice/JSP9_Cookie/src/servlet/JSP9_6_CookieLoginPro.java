package servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import util.CookieBox;

/**
 * Servlet implementation class JSP9_6_CookieLoginPro
 */
@WebServlet("/JSP9_6_CookieLoginPro")
public class JSP9_6_CookieLoginPro extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JSP9_6_CookieLoginPro() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// 사용자 아이디와 비밀번호를 추출한다.
		String user_id = request.getParameter("user_id");
		String user_pw = request.getParameter("user_pw");
		// 파라미터에 데이터가 없으면 속성에서 뽑아낸다.
		if(user_id == null){
			user_id = (String)request.getAttribute("user_id");
			user_pw = (String)request.getAttribute("user_pw");
		}
		// 속성에서도 없다면 아무 문자열이나 넣어준다.
		if(user_id == null){
			user_id = "";
			user_pw = "";
		}
		
		if(user_id.equals("abc") && user_pw.equals("123")){
			// 로그인 성공
			CookieBox box = new CookieBox(request, response);
			box.setCookie("user_id", user_id, 
								365 * 24 * 60 * 60,  "utf-8");
			box.setCookie("user_pw", user_pw, 
								365 * 24 * 60 * 60,  "utf-8");
			box.setCookie("user_name", "홍길동", 
								365 * 24 * 60 * 60,  "utf-8");
			// 로그인 이후 페이지로 이동
			response.sendRedirect("JSP9_6_IndexPro");
		} else {
			// 로그인 실패
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
