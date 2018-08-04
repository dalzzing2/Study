<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>out을 이용할 출력 예제</title>
</head>
<body>
	<%-- 1 ~ 100까지 숫자 중에 2, 3, 5의 배수 여부를
		표시
	 --%>
	 <% for(int i = 1 ; i <= 100 ; i++){ %>
	 		<%=i%> :
	 		<% if( i % 2 == 0){ %>
	 			2의 배수,
	 		<% } %>
			<% if(i % 3 == 0){ %>
	 			3의 배수,
	 		<% } %>
	 		<% if(i % 5 == 0){ %>
	 			5의 배수
	 		<% } %>
	 		<br/>
	 <% } %>
	 <hr/>
	 <%
	 	for(int i = 1 ; i <= 100 ; i++){
	 		out.print(i + " : ");
	 		if(i % 2 == 0){
	 			out.print("2의 배수,");
	 		} 
	 		if(i % 3 == 0){
	 			out.print("3의 배수,");
	 		}
	 		if(i % 5 == 0){
	 			out.print("5의 배수");
	 		}
	 		out.print("<br/>");
	 	}
	 %>
</body>
</html>







