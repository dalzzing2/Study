package servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class JSP3_2_Parameter
 */
@WebServlet("/JSP3_2_Parameter")
public class JSP3_2_Parameter extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JSP3_2_Parameter() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// 파라미터 데이터가 한글로 넘어올 수도 있기
		// 때문에 디코딩을 해준다.
		request.setCharacterEncoding("utf-8");
		// 데이터를 받는다.
		String data1 = request.getParameter("data1");
		String data2 = request.getParameter("data2");
		String [] data3 
				= request.getParameterValues("data3");
		// 출력 타입을 설정
		response.setContentType("text/html; charset=utf-8");
		// 출력을 위한 스트림을 추출
		PrintWriter out = response.getWriter();
		// 출력한다.
		out.print("data1 : " + data1 + "<br/>");
		out.print("data2 : " + data2 + "<br/>");
		
		if(data3 != null){
			for(String str : data3){
				out.print("data3 : " + str + "<br/>");
			}
		}
		out.flush();
		out.close();
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
