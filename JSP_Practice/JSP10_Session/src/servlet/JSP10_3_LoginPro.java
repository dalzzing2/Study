package servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class JSP10_3_LoginPro
 */
@WebServlet("/JSP10_3_LoginPro")
public class JSP10_3_LoginPro extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JSP10_3_LoginPro() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// 파라미터 데이터를 추출
		String user_id = request.getParameter("user_id");
		String user_pw = request.getParameter("user_pw");
		
		// 로그인 처리
		if("abc".equals(user_id) && "123".equals(user_pw)){
			// 사용자 정보를 세션에 저장
			HttpSession session = request.getSession();
			session.setAttribute("user_name", "홍길동");
			// index.jsp로 이동한다.
			response.sendRedirect("JSP10_3_Index.jsp");
		} else {
			// 로그인 실패시 Login.jsp로 이동
			response.sendRedirect("JSP10_3_Login.jsp");
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
