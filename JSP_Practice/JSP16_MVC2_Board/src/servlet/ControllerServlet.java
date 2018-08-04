package servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import bean.MemberBean;

/**
 * Servlet implementation class ControllerServlet
 */
@WebServlet("*.samsung")
public class ControllerServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ControllerServlet() {
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
		// 세션 확인 여부를 체크할 변수
		boolean isCheckSession = false;
		// 요청 URL에서 서블릿의 이름을 추출
		String url = request.getRequestURI();
		// 문자열을 / 를 기준으로 잘라낸다.
		String [] sub = url.split("/");
		url = sub[sub.length - 1];
		// ;JSESSIONID 값이 붙을 수도 있기 때문에...
		sub = url.split(";");
		url = sub[0];
		// 요청 이름을 이용해 분기한다.
		String site = null;
		if(url.equals("join_member.samsung")){
			// 회원 가입 입력 화면
			site = "/member/join_member.jsp";
			isCheckSession = false;
		} else if(url.equals("join_pro.samsung")){
			// 회원 가입 처리 서블릿
			site = "JoinProServlet";
			isCheckSession = false;
		} else if(url.equals("login_complate.samsung")){
			// 가입 완료 페이지
			site = "/member/join_complete.jsp";
			isCheckSession = false;
		} else if(url.equals("login_pro.samsung")){
			// 로그인 처리 서블릿
			site = "LoginProServlet";
			isCheckSession = false;
		} else if(url.equals("main_pro.samsung")){
			// 메인 페이지 처리 서블릿
			site = "MainProServlet";
			isCheckSession = true;
		} else if(url.equals("main.samsung")){
			// 게시판 메인 페이지
			site = "/board/main.jsp";
			isCheckSession = true;
		} else if(url.equals("write_board.samsung")){
			// 글 작성 페이지
			site = "/board/write_board.jsp";
			isCheckSession = true;
		} else if(url.equals("write_board_pro.samsung")){
			// 글 작성 처리 서블릿
			site = "WriteBoardProServlet";
			isCheckSession = true;
		} else if(url.equals("read_content_pro.samsung")){
			// 글 내용을 볼 수 있도록 처리하는 서블릿
			site = "ReadContentProServlet";
			isCheckSession = true;
		}
		// 세션 확인 처리
		if(isCheckSession == true){
			// 비 정상적인 접근이라면...
			// 세션에 저장되어 있는 객체를 가지고 온다.
			HttpSession session = request.getSession();
			MemberBean member_bean
				= (MemberBean)session.getAttribute("member_bean");
			// 로그인 여부를 확인
			if(member_bean == null 
					|| member_bean.isLogin() == false){
				site = "index.jsp";
				response.sendRedirect(site);
				// 메서드 수행 종료
				return;
			}
		}
		// 이동
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
