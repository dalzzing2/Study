package servlet;

import java.io.IOException;
import java.net.URLEncoder;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class JSP4_1_Pro
 */
@WebServlet("/JSP4_1_Pro")
public class JSP4_1_Pro extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JSP4_1_Pro() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// 파라미터 디코딩
		request.setCharacterEncoding("utf-8");
		// 파라미터 데이터 추출
		String data1 = request.getParameter("data1");
		String data2 = request.getParameter("data2");
		// 연산 처리
		String data3 = data1 + ", " + data2;
		// Get방식으로 데이터를 보낼때는 
		// 인코딩을 해야한다.
		try{
			data3 = URLEncoder.encode(data3, "utf-8");
		}catch(Exception e){
			e.printStackTrace();
		}
		
		//JSP4_1_Result.jsp로 이동한다.
		response.sendRedirect("JSP4_1_Result.jsp?data3=" + data3);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
