<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%-- 세션에서 객체를 추출한다 --%>
<jsp:useBean id="member_bean" class="bean.MemberBean"
             scope="session"/>
<%-- 로그인 여부를 확인한다 --%>
<%
	String path = request.getContextPath();

	if(member_bean.isLogin() == false){
		// index.jsp로 이동한다.
		response.sendRedirect(path + "/JSP13_Index.jsp");
	}
%>