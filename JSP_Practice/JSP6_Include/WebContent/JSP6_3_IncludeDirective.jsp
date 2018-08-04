<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>include 지시자 사용 예제</title>
</head>
<body>
	여기는 JSP6_3_IncludeDirective.jsp 영역입니다.<br/>
	<%
		// 변수를 선언한다.
		int main_value = 100;
	%>
	----------------------------------------------<br/>
	<%@ include file="JSP6_3_Sub/JSP6_3_Sub.jspf" %>
	----------------------------------------------<br/>
	여기는 JSP6_3_IncludeDirective.jsp 영역입니다.<br/>
	Sub_value : <%=Sub_value%><br/>
</body>
</html>







