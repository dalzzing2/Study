package servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class ControllerServlet
 */
@WebServlet("*.bang")
public class ControllerServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ControllerServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// 파라미터 한글 처리
		request.setCharacterEncoding("utf-8");
		// 세션 확인 여부를 체크할 변수
		boolean isCheckSession = false;
		// 요청 URL에서 서블릿의 이름을 추출
		String url = request.getRequestURI();
		// 문자열을 / 를 기준으로 잘라낸다.
		String [] sub = url.split("/");
		url = sub[sub.length - 1];
		// ;JSESSIONID 값이 붙을 수도 있기 때문에...
		sub = url.split(";");
		url = sub[0];
		// 요청 이름을 이용해 분기한다.
		String site = null;
		if(url.equals("login_pro.bang")){
			// 로그인 처리 서블릿
			site = "LoginServlet";
			isCheckSession = false;
		} else if(url.equals("main.bang")){
			// 방목록 글 데이터를 처리하는 서블릿
			site = "BangServlet";
			isCheckSession = true;
		} else if(url.equals("add.bang")){
			// 방명록에 글 데이터를 추가하는 서블릿
			site = "AddBangServlet";
			isCheckSession = true;
		}
		// 세션 확인 처리
		if(isCheckSession == true){
			// 비 정상적인 접근이라면...
			// 세션에 저장되어 있는 객체를 가지고 온다.
			HttpSession session = request.getSession();
			String user_name
				= (String)session.getAttribute("user_name");
			// 로그인 여부를 확인
			if(user_name == null || user_name.equals("")){
				site = "index.jsp";
				response.sendRedirect(site);
				// 메서드 수행 종료
				return;
			}
		}
		// 이동
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
