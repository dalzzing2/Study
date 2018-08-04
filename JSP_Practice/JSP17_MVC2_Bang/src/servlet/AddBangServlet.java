package servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import bean.BangBean;
import db.BangDAO;

/**
 * Servlet implementation class AddBangServlet
 */
@WebServlet("/AddBangServlet")
public class AddBangServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AddBangServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// 파라미터 데이터를 추출
		String bang_content
				= request.getParameter("bang_content");
		// 빈 객체에 데이터 셋팅
		BangBean bean = new BangBean();
		HttpSession session = request.getSession();
		String user_name 
			= (String)session.getAttribute("user_name");
		bean.setBang_name(user_name);
		bean.setBang_content(bang_content);
		// 디비에 저장한다.
		try{
			BangDAO.add_bang(bean);
		}catch(Exception e){
			e.printStackTrace();
		}
		//메인 페이지로 이동한다.
		String site = "main.bang";
		response.sendRedirect(site);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
