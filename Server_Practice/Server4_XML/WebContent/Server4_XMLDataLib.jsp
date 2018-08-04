<%@ page contentType="text/xml; charset=utf-8"
    pageEncoding="utf-8"%>
<%@ page import="java.util.*" %>
<%@ page import="java.sql.*" %>
<%@ page import="org.w3c.dom.*" %>
<%@ page import="javax.xml.parsers.*" %>
<%@ page import="javax.xml.transform.dom.*" %>
<%@ page import="javax.xml.transform.stream.*" %>
<%@ page import="javax.xml.transform.*" %>
<%@ page trimDirectiveWhitespaces="true" %>
<%
try{
Class.forName("oracle.jdbc.OracleDriver");
String db_url = "jdbc:oracle:thin:@localhost:1521:orcl";
String db_id = "scott";
String db_pw = "1234";
//데이터 베이스 접속
Connection conn
	= DriverManager.getConnection(db_url, db_id, db_pw);

String sql = "select * from JDBC_MEMBER_TABLE";
// 쿼리 실행
Statement stmt = conn.createStatement();
ResultSet rs = stmt.executeQuery(sql);
// 데이터를 담아 놓을 컬렉션 생성
ArrayList<HashMap<String, String>> list
	= new ArrayList<HashMap<String, String>>();

// 데이터를 추출해서 담아준다.
while(rs.next()){
	// 데이터를 추출한다.
	String user_id = rs.getString("user_id");
	String user_name = rs.getString("user_name");
	String user_pw = rs.getString("user_pw");
	// 데이터를 담는다.
	HashMap<String, String> map
					= new HashMap<String, String>();
	map.put("user_id", user_id);
	map.put("user_name", user_name);
	map.put("user_pw", user_pw);
	
	list.add(map);
}

conn.close();

	DocumentBuilderFactory factory
			= DocumentBuilderFactory.newInstance();
	DocumentBuilder builder
			= factory.newDocumentBuilder();
	Document doc = builder.newDocument();
	
	// ROOT 생성
	Element root = doc.createElement("root");
	doc.appendChild(root);
	// status 태그 생성
	Element status = doc.createElement("status");
	Text status_value = doc.createTextNode("OK");
	status.appendChild(status_value);
	root.appendChild(status);
	// 데이터의 개수만큼 반복
	for(HashMap<String, String> map : list){
		// user_info를 생성
		Element user_info = doc.createElement("user_info");
		root.appendChild(user_info);
		// user_id
		Element user_id = doc.createElement("user_id");
		Text user_id_value 
				= doc.createTextNode(map.get("user_id"));
		user_id.appendChild(user_id_value);
		user_info.appendChild(user_id);
		// user_name
		Element user_name = doc.createElement("user_name");
		Text user_name_value
				= doc.createTextNode(map.get("user_name"));
		user_name.appendChild(user_name_value);
		user_info.appendChild(user_name);
		// user_pw
		Element user_pw = doc.createElement("user_pw");
		Text user_pw_value
				= doc.createTextNode(map.get("user_pw"));
		user_pw.appendChild(user_pw_value);
		user_info.appendChild(user_pw);
	}
	
	TransformerFactory t_factory
				= TransformerFactory.newInstance();
	Transformer trans = t_factory.newTransformer();
	DOMSource source = new DOMSource(doc);
	StreamResult result = new StreamResult(out);
	
	trans.transform(source, result);
	
}catch(Exception e){
	// XML 문서를 만들기위한 도구를 생성
	DocumentBuilderFactory factory
			= DocumentBuilderFactory.newInstance();
	DocumentBuilder builder
			= factory.newDocumentBuilder();
	Document doc = builder.newDocument();
	// root 태그를 만들어준다.
	Element root = doc.createElement("root");
	// root 태그를 doc에 넣어준다.
	doc.appendChild(root);
	// status 태그를 만들어준다.
	Element status = doc.createElement("status");
	Text status_value = doc.createTextNode("FAIL");
	status.appendChild(status_value);
	root.appendChild(status);
	// XML 데이터로 변환하여 출력한다.
	TransformerFactory t_factory
				= TransformerFactory.newInstance();
	Transformer trans = t_factory.newTransformer();
	// 클라언트로 전달할 xml 코드를 생성한다.
	DOMSource source = new DOMSource(doc);
	// 클라이언트로 데이터를 전달할 수 있는 스트림을 생성
	StreamResult result = new StreamResult(out);
	// 클라이언트로 데이터를 전달한다.
	trans.transform(source, result);
}
%>









