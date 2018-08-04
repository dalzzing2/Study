package servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import bean.MemberBean;
import db.MemberDAO;

/**
 * Servlet implementation class LoginProServlet
 */
@WebServlet("/LoginProServlet")
public class LoginProServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public LoginProServlet() {
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
		// 빈 객체에 담는다.
		MemberBean login_bean = new MemberBean();
		login_bean.setUser_id(user_id);
		login_bean.setUser_pw(user_pw);
		try{
			// 로그인 결과를 가져온다.
			String login_result 
						= MemberDAO.check_login(login_bean);
			
			if(login_result.equals("3")){	// 로그인 성공
				// 사용자 정보를 가져온다.
				MemberBean member_bean 
					= MemberDAO.getUserInfo(login_bean.getUser_id());
				// 로그인 값을 설정한다.
				member_bean.setLogin(true);
				// 사용자 정보를 세션에 담는다.
				HttpSession session = request.getSession();
				session.setAttribute("member_bean", member_bean);
				// 게시판 메인 페이지로 이동
				String site = "main_pro.samsung";
				response.sendRedirect(site);
			} else {						// 로그인 실패
				// 첫 페이지로 이동
				String site = "index.jsp"
						    + "?login_result=" 
						    + login_result;
				response.sendRedirect(site);
			}
		}catch(Exception e){
			e.printStackTrace();
		}
		
//		
//		
//		
//		
//		if(login_result.equals("3")){		// 로그인 성공
//			// 사용자 정보를 가져온다.
//			MemberBean member_bean 
//				= MemberDAO.getUserInfo(login_bean.getUser_id());
//			// 로그인 값을 설정한다.
//			member_bean.setLogin(true);
//			// 사용자 정보를 세션에 담는다.
//			session.setAttribute("member_bean", member_bean);
//			// 게시판 메인 페이지로 이동
//			String site = path + "/board/main.jsp";
//			response.sendRedirect(site);
//		} else {							// 로그인 실패
//			// 첫 페이지로 이동
//			String site 
//				= path + "/JSP13_Index.jsp?login_result=" 
//			    + login_result;
//			response.sendRedirect(site);
//		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
