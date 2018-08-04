<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.io.*" %>    
<%@ page import="java.net.*" %>    
<%
	// 파일명을 받는다
	// 실제로 구현할 때 데이터베이스에 저장되어 있는 파일이름을 가져온다.
	String file_name = request.getParameter("file_name");
	// 파일이 저장되어 있는 서버상의 위치를 얻어온다.
	String path = application.getRealPath("/upload");
	path = path + "//" + file_name;
	System.out.println(path);
	// 다운로드시 파일 이름 한글 처리
	byte [] file_buf = file_name.getBytes("utf-8");
	file_name = new String(file_buf, "8859_1"); 
	// 파일 전송을 위한 정보 셋팅
	response.setHeader("Content-type", "application/octet-stream;charset=utf-8");
	response.setHeader("Content-type", "attachment; filename=" + file_name);
	// 클라이언트로 전송할 스트림 추출
	ServletOutputStream sos = response.getOutputStream();
	// 파일에서 읽어온 데이터를 담아놓을 배열
	byte [] data_buf = new byte[4096];	
	// 파일에서 데이터를 읽어올 스트림
	FileInputStream fis = new FileInputStream(path);
	// 읽어온 파일의 용량이 -1이면 실패
	int size = 0;
	do {
		// 읽어온다
		size = fis.read(data_buf, 0, data_buf.length);
		if(size != -1){
			// 클라이언트로 전달
			sos.write(data_buf, 0, size);
		}
	}while(size != -1);
	// 스트림을 닫는다.
	sos.flush();
	sos.close();
	fis.close();
%>