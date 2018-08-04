<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@page import="com.oreilly.servlet.MultipartRequest"%>
<%@page import="com.oreilly.servlet.multipart.DefaultFileRenamePolicy"%>    
<%
	// 파라미터 한글처리
	request.setCharacterEncoding("utf-8");
	//String data1 = request.getParameter("data1");
	//String data2 = request.getParameter("data2");	
	
	// 파일이 저장될 위치
	String path = application.getRealPath("/upload");
	// 파일의 제한 용량
	int max = 1024 * 1024 * 5; // 5MB
	// 저장 파일의 인코딩 타입
	String enc = "utf-8";
	// 파일이 중복 됬을 경우 이름 변경
	DefaultFileRenamePolicy dfr = new DefaultFileRenamePolicy();
	// 업로드 처리
	MultipartRequest mr = new MultipartRequest(request, path, max, enc, dfr);
	// 파라미터 데이터 추출
	String data1 = mr.getParameter("data1");
	// 원본 파일 명
	String file1 = mr.getOriginalFileName("data2");
	// 서버에서의 파일명을 디비에 저장
	String file2 = mr.getFilesystemName("data2");
%>   
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>업로드 완료</title>
</head>
<body>
	파라미터 : <%=data1%><br/>
	원본 파일 이름 : <%=file1%><br/>
	서버에서의 파일 이름 : <%=file2%><br/>
	
	<a href="Server6_Download.jsp?file_name=<%=file2%>">다운로드</a>
</body>
</html>