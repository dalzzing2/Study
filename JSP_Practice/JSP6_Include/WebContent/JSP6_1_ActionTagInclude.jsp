<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>액션 태그를 이용한 다른 jsp를 포함하기</title>
</head>
<body>
	<%--
		include 액션 태그를 이용하면 다른 JSP 파일의
		내용을 포함 시킬 수 있다.
		포함되는 내용은 다른 JSP가 실행되어 만들어진
		응답 결과가가 포함된다.
		다른 JSP파일에 만들어 놓은 변수나 메서드, 기타
		자바 코드는 포함되지 않기 때문에 사용할 수 
		없다.
	 --%>
	 이 부분은 JSP6_1_ActionTagInclude.jsp 부분입니다<br/>
	 <hr/>
	 <jsp:include page="JSP6_1_Sub.jsp"/>
	 <hr/>
	 이 부분은 JSP6_1_ActionTagInclude.jsp 부분입니다<br/>
</body>
</html>
















