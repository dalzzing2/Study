<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>전송 방식 테스트 예제</title>
</head>
<body>
	<%--
		GET : 1. 사용자가 브라우저에 직접 주소를 입력하고
		        요청한 경우
		      2. a 태그를 이용해 만든 링크를 눌렀을 경우
		      3. form태그의 메서드가 get 인 경우
		POST : 1. form 태그의 메서드가 post 인 경우
		
		GET vs POST
		GET은 파라미터 데이터가 주소 창에 표시가 되고
		POST는 표시가 되지 않는다.
		GET은 255바이트로 제한되어 있지만 POST는
		제한이 없다.
	 --%>
	 <a href="JSP3_1_Method">서블릿 요청</a><br/>
	 <a href="JSP3_1_Method.jsp">JSP 요청</a><br/>
	 <hr/>
	 GET<br/>
	 <form action="JSP3_1_Method" method="get">
	 	<button type="submit">서블릿 GET 요청</button>
	 </form>	 
	 <form action="JSP3_1_Method.jsp" method="get">
	 	<button type="submit">JSP GET 요청</button>
	 </form>
	 <hr/>
	 POST<br/>
	 <form action="JSP3_1_Method" method="post">
	 	<button type="submit">서블릿 POST 요청</button>
	 </form>
	 <form action="JSP3_1_Method.jsp" method="post">
	 	<button type="submit">JSP POST 요청</button>
	 </form>
</body>
</html>










