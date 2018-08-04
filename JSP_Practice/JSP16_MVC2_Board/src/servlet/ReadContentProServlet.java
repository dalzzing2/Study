package servlet;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import bean.BoardBean;
import bean.ReplyBean;
import db.BoardDAO;

/**
 * Servlet implementation class ReadContentProServlet
 */
@WebServlet("/ReadContentProServlet")
public class ReadContentProServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ReadContentProServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		try{
			// 파라미터 데이터 추출
			String board_idx_str = request.getParameter("board_idx");
			String page_num_str = request.getParameter("page_num");
			if(page_num_str == null){
				page_num_str = "1";
			}
			int page_num = Integer.parseInt(page_num_str);
			
			
			int board_idx = Integer.parseInt(board_idx_str);
			// 조회수를 증가시킨다.
			BoardDAO.update_board_show(board_idx);
			// 게시글 데이터를 가져온다.
			BoardBean bean = BoardDAO.getBoardContent(board_idx);
			// 댓글 정보를 가져온다.
			ArrayList<ReplyBean> reply_list
							= BoardDAO.getReplyList(board_idx);
			// 전달할 데이터를 request에 담는다.
			request.setAttribute("page_num", page_num);
			request.setAttribute("bean", bean);
			request.setAttribute("reply_list", reply_list);
			// 이동한다.
			String site = "board/read_content.jsp";
			RequestDispatcher dis 
					= request.getRequestDispatcher(site);
			dis.forward(request, response);
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
