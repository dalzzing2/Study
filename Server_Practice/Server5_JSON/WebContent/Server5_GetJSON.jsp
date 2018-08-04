<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.io.*" %>
<%@ page import="java.net.*" %>
<%@ page import="org.json.simple.*" %>
<%@ page import="org.json.simple.parser.*" %>
<%
	// 접속할 페이지의 주소
	String site = "http://localhost:8080/Server5_JSON/"
	            + "Server5_JSONDataLib.jsp";
	URL url = new URL(site);
	// 문자열 데이터를 가져온다.
	InputStream is = url.openStream();
	InputStreamReader isr 
				= new InputStreamReader(is, "utf-8");
	BufferedReader br = new BufferedReader(isr);
	StringBuffer buf = new StringBuffer();
	String str = null;
	do{
		str = br.readLine();
		if(str != null){
			buf.append(str);
		}
	} while(str != null);
	
	String data = buf.toString();
 %>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>JSON 데이터 가져오기</title>
</head>
<body>
	<%
		// JSON 배열 생성([ 로 시작하기 때문)
		JSONParser parser = new JSONParser();
		JSONArray root = (JSONArray)parser.parse(data);
		// 데이터의 개수만큼 반복
		for(int i = 0 ; i < root.size() ; i++){
			// i 번째 JSONObject를 추출
			JSONObject obj = (JSONObject)root.get(i);
			// 각 데이터를 추출
			long board_idx = (Long)obj.get("board_idx");
			String board_subject
						= (String)obj.get("board_subject");
			String board_content
						= (String)obj.get("board_content");
			long board_show
						= (Long)obj.get("board_show");
			String user_id
						= (String)obj.get("user_id");
			out.print("------------------------<br/>");
			out.print(board_idx + "<br/>");
			out.print(board_subject + "<br/>");
			out.print(board_content + "<br/>");
			out.print(board_show + "<br/>");
			out.print(user_id + "<br/>");
		}
	%>

</body>
</html>












