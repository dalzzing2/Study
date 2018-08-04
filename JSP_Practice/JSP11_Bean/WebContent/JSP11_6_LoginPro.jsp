<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="bean.*" %>
<%-- 빈 객체 생성 --%>
<jsp:useBean id="login_bean" 
             class="bean.JSP11_6_LoginBean"
             scope="session"/>
<%-- 파라미터 데이터를 받는다. --%>
<jsp:setProperty name="login_bean" property="*"/>
<%-- 로그인 처리 --%>
<%
	String user_id = login_bean.getUser_id();
	String user_pw = login_bean.getUser_pw();
	if(user_id.equals("abc") && user_pw.equals("123")){
		// 로그인 성공
		login_bean.setLogin(true);
		login_bean.setUser_name("홍길동");
		// 이동
		response.sendRedirect("JSP11_6_Index.jsp");
	} else {
		response.sendRedirect("JSP11_6_Login.jsp");
	}
%>










