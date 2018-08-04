package servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Date;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class JSP1_HelloWorld
 */
@WebServlet("/JSP1_HelloWorld")
public class JSP1_HelloWorld extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public JSP1_HelloWorld() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		// 클라이언트에게 응답 결과의 종류를 전달한다.
		response.setContentType("text/html;charset=utf-8");
		// 클라이언트에게 데이터를 보낼 수 있는 스트림을
		// 추출
		PrintWriter pw = response.getWriter();
		// 클라이언트에게 데이터를 전달한다.
		pw.println("<!DOCTYPE html>");
		pw.println("<html>");
		pw.println("<head>");
		pw.println("<meta charset='utf-8'>");
		pw.println("<title>서블릿 테스트</title>");
		pw.println("</head>");
		pw.println("<body>");
		pw.println("<h1>서블릿 테스트 페이지</h1>");
		// Date import : java.util
		pw.println("<p>" + new Date() + "</p>");
		pw.println("</body>");
		pw.println("</html>");
		
		pw.close();
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}



