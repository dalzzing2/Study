package servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import bean.BoardBean;
import bean.MemberBean;
import db.BoardDAO;

/**
 * Servlet implementation class WriteBoardProServlet
 */
@WebServlet("/WriteBoardProServlet")
public class WriteBoardProServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public WriteBoardProServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		try{
			// 파라미터 데이터를 받는다.
			String board_subject 
					= request.getParameter("board_subject");
			String board_content
					= request.getParameter("board_content");
			// 빈 객체에 담아준다.
			BoardBean board_bean = new BoardBean();
			board_bean.setBoard_subject(board_subject);
			board_bean.setBoard_content(board_content);
			// 세션에 있는 사용자 아이디 값을 빈에 넣어준다.
			HttpSession session = request.getSession();
			MemberBean member_bean 
				= (MemberBean)session.getAttribute("member_bean");
			board_bean.setUser_id(member_bean.getUser_id());
			
			// 작성자 아이디를 board_bean에 넣어board_bean.setUser_id(member_bean.getUser_id());
			// 데이터 베이스에 저장
			int max_idx = BoardDAO.add_board(board_bean);
			// 작성한 글을 보기위한 페이지로 이동한다.
			String site =  "read_content_pro.samsung"
					    + "?board_idx=" + max_idx;
			response.sendRedirect(site);
			
		}catch(Exception e){
			e.printStackTrace();
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
