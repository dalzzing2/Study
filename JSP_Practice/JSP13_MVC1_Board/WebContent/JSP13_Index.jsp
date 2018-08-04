<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
	// 컨텍스트 경로를 얻어온다.
	String path = request.getContextPath();
	// 로그인 결과를 추출한다.
	String login_result
				= request.getParameter("login_result");
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>로그인 페이지</title>
</head>
<body>
<%  if(login_result != null){ %>
<%  	if(login_result.equals("1")){ %>
	<font color="red">등록되지 않은 아이디 입니다</font>
	<br/>
<%		} else if(login_result.equals("2")){ %>	
	<font color="red">비밀번호가 잘못되었습니다</font>
	<br/>
<%		} %>
<% } %>
	<form action="<%=path%>/member/login_pro.jsp" method="post">
		아이디 : <input type="text" name="user_id"/><br/>
		비밀번호 : <input type="password"
		                  name="user_pw"/><br/>
		<button type="submit">로그인</button>
	</form>
	<a href="<%=path%>/member/join_member.jsp">회원 가입</a>
</body>
</html>









