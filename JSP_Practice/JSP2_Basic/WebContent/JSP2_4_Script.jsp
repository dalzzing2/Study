<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%-- 
	선언부
	선언부 내부의 자바 코드는 _jspService 메서드의
	밖(클래스 내부)에 추가된다.
--%>
<%!
	// 클래스의 맴버 변수
	int member_a = 100;
	// 클래스의 맴버 메서드
	public void member_method(){
		System.out.println("member_method");
		// out은 _jspService 메서드의 지역 변수이므로
		// 사용할 수가 없다(출력 불가)
		//out.write("하하하하");
	}
%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Insert title here</title>
</head>
<body>
	<%-- 
		스크립트릿
		자바 코드를 작성하는 부분
		_jspService 메서드 내부로 변환없이 그대로
		들어간다.
		메서드를 만들 수 없다. 
	--%>
	<%
		out.write("스크립트릿 내부입니다<br/>");
	
		for(int i = 0 ; i < 10 ; i++){
			out.write("i : " + i + "<br/>");
		}
		// 지역 중첩 클래스 생성 가능
		class LocalClass{
			public void local_method(){
				try{
					System.out.println("local method");
				}catch(Exception e){
					e.printStackTrace();
				}
			}
		}
		
		LocalClass local = new LocalClass();
		local.local_method();
		// _jspService 메서드 내부로 들어가기 때문에
		// 메서드를 만들어 줄 수 없다.
		// public void local_method2(){
		//	 System.out.println("local method2");
		// }
	%>
	<%--
		표현식은 _jspService 메서드로 들어간다. 
	 --%>
	 <%
	 	int data1 = 100;
	 %>
	 data1 : <%=data1%><br/>
	 <%= 1 + 2 + 3 + 4+5 %><br/>
</body>
</html>










