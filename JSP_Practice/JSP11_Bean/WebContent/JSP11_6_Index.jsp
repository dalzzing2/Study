<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%-- 세션으로 부터 객체를 추출 --%>
<jsp:useBean id="login_bean" 
             class="bean.JSP11_6_LoginBean"
             scope="session"/>
<%-- 로그인을 하지 않았다면 login.jsp로 이동 --%>
<%
	if(login_bean.isLogin() == false){
		response.sendRedirect("JSP11_6_Login.jsp");
	}
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>로그인 완료</title>
</head>
<body>
	<jsp:getProperty property="user_name" 
	                 name="login_bean"/>
	님 반갑습니다
</body>
</html>




