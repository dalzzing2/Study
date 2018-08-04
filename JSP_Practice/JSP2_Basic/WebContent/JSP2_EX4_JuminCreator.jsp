<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%--
	주민등록 번호 생성기
 --%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>주민등록 번호 생성기</title>
</head>
<body>
	<%--
		앞의 7자리는 임의로 결정
		마지막 숫자는 계산에의해서 결정
		중간자리는 00000 ~ 99999
	--%>
	<%
		int a1, a2, a3, a4, a5, a6, a7, a8,
		a9, a10, a11, a12, a13;
		// 2015년 10월 21생 남자
		a1 = 1;
		a2 = 5;
		a3 = 1;
		a4 = 0;
		a5 = 2;
		a6 = 1;
		a7 = 3;
		
		for(int i = 0 ; i < 100000 ; i++){
			int temp = i;
			// i를 계산해서 a8 ~ a12까지 결정
			a8 = temp / 10000;
			temp = temp % 10000;
			
			a9 = temp / 1000;
			temp = temp % 1000;
			
			a10 = temp / 100;
			temp = temp % 100;
			
			a11 = temp / 10;
			temp = temp % 10;
			
			a12 = temp;
			
			a13 = (a1 * 2) + (a2 * 3) + (a3 * 4)
				+ (a4 * 5) + (a5 * 6) + (a6 * 7)
				+ (a7 * 8) + (a8 * 9) + (a9 * 2)
				+ (a10 * 3) + (a11 * 4) + (a12 * 5);
			
			a13 = a13 % 11;
			a13 = 11 - a13;
			a13 = a13 % 10;
			
			out.print(a1);
			out.print(a2);
			out.print(a3);
			out.print(a4);
			out.print(a5);
			out.print(a6);
			out.print("-");
			out.print(a7);
			out.print(a8);
			out.print(a9);
			out.print(a10);
			out.print(a11);
			out.print(a12);
			out.print(a13 + "<br/>");
		}
	%>
	
</body>
</html>








