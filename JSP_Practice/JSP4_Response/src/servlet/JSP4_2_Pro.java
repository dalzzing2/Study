package servlet;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class JSP4_2_Pro
 */
@WebServlet("/JSP4_2_Pro")
public class JSP4_2_Pro extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JSP4_2_Pro() {
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
		// 파라미터 추출
		String data1 = request.getParameter("data1");
		String data2 = request.getParameter("data2");
		
		String data3 = data1 + ", " + data2;
		// 다음 페이지로 전달할 데이터를 셋팅
		request.setAttribute("data3", data3);
		// Result.jsp로 이동한다.
		// RequestDispatcher는 새로운 페이지로 요청을 하는
		// 것이 아니라 서버 내부에서 코드의 흐름이 이동한다.
		RequestDispatcher dis 
		  = request.getRequestDispatcher("JSP4_2_Result.jsp");
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
