package servlet;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import bean.MemberBean;
import db.MemberDAO;

/**
 * Servlet implementation class JoinProServlet
 */
@WebServlet("/JoinProServlet")
public class JoinProServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JoinProServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// 파라미터 데이터 추출
		String user_name = request.getParameter("user_name");
		String user_id = request.getParameter("user_id");
		String user_pw = request.getParameter("user_pw");
		// 파라미터 데이터를 빈 객체에 담는다.
		MemberBean member_bean = new MemberBean();
		member_bean.setUser_name(user_name);
		member_bean.setUser_id(user_id);
		member_bean.setUser_pw(user_pw);
		// 데이터 베이스에 회원 정보를 추가한다.
		try{
			MemberDAO.add_user(member_bean);
		}catch(Exception e){
			e.printStackTrace();
		}
		// 완료 페이지를 보기 위한 서블릿을 요청
		String site = "login_complate.samsung";
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
