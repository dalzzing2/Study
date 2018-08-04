<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="bean.*" %>
<%@ page import="db.*" %>
<%-- 파라미터의 데이터를 받는다 --%>
<jsp:useBean id="login_bean" class="bean.MemberBean"/>
<jsp:setProperty property="*" name="login_bean"/>
<%
	String path = request.getContextPath();
	// 로그인 결과를 가져온다.
	String login_result 
				= MemberDAO.check_login(login_bean);
	if(login_result.equals("3")){		// 로그인 성공
		// 사용자 정보를 가져온다.
		MemberBean member_bean 
			= MemberDAO.getUserInfo(login_bean.getUser_id());
		// 로그인 값을 설정한다.
		member_bean.setLogin(true);
		// 사용자 정보를 세션에 담는다.
		session.setAttribute("member_bean", member_bean);
		// 게시판 메인 페이지로 이동
		String site = path + "/board/main.jsp";
		response.sendRedirect(site);
	} else {							// 로그인 실패
		// 첫 페이지로 이동
		String site 
			= path + "/JSP13_Index.jsp?login_result=" 
		    + login_result;
		response.sendRedirect(site);
	}
%>











