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
import db.BoardDAO;

/**
 * Servlet implementation class MainProServlet
 */
@WebServlet("/MainProServlet")
public class MainProServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public MainProServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		try{
			// 페이지 번호 처리
			String page_num_str = request.getParameter("page_num");
			if(page_num_str == null){
				page_num_str = "1";
			}
			int page_num = Integer.parseInt(page_num_str);
			// 전체 페이지의 개수를 얻어온다.
			int page_cnt = BoardDAO.getPageCount();
			// 페이지 번호가 잘못 들어 왔을 경우에 대한
			// 처리
			if(page_num < 1){
				page_num = 1;
			} else if(page_num > page_cnt){
				page_num = page_cnt;
			}
			// 현재 페이지의 글 데이터를 가져온다.
			ArrayList<BoardBean> list 
				= BoardDAO.getBoardAlldata(page_num);
			// main.jsp에서 사용하는 데이터를 
			// request에 담아준다.
			request.setAttribute("page_num", page_num);
			request.setAttribute("page_cnt", page_cnt);
			request.setAttribute("list", list);
			// 이동한다
			String site = "main.samsung";
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
