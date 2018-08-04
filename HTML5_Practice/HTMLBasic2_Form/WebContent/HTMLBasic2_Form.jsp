<%@ page contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>HTML5 Form 요소</title>
</head>
<body>
	<form action="HTMLBasic2_Result.jsp" method="post">
		<%-- 기본 입력(type 속성 생략시 text로 설정) --%>
		<%-- 추가 옵션 : required, placeholder --%>
		<input type="text" name="a1" placeholder="text"
		       required value="abc"/><br/>
		<%-- 여러줄 입력 --%>
		<%-- 절대로 닫는 태그를 밑으로 내리지 마세요 --%>
		<textarea name="a2" placeholder="text area" rows="5" cols="30"></textarea><br/>
		<%-- select --%>
		<select name="a3">
			<option value="1">항목1</option>
			<option value="2">항목2</option>
			<option value="3">항목3</option>
		</select>
		<br/>
		<%-- checkbox --%>
		<fieldset>
		<legend>체크박스</legend>
		<input type="checkbox" name="a4" value="1"/>체크1<br/>
		<input type="checkbox" name="a4" value="2"/>체크2<br/>
		<input type="checkbox" name="a4" value="3"/>체크3<br/>
		</fieldset>
		<br/>
		<fieldset>
		<legend>라디오</legend>
		<input type="radio" name="a5" value="1"/>라디오1<br/>
		<input type="radio" name="a5" value="2"/>라디오2<br/>
		<input type="radio" name="a5" value="3"/>라디오3<br/>
		</fieldset>
		<%-- number --%>
		<%-- 숫자만 입력이 가능 --%>
		<%--
			step : 입력 단위 값 
			max : 최대값
			min : 최소값
		 --%>
		<input type="number" name="a6" placeholder="number"
		       step="2" max="100" min="0"/>
		<br/>
		<%-- email : 유효성 검사 --%>
		<%-- 모바일에서 이메일 입력을 하기위한 키보드 --%>
		<input type="email" name="a7" placeholder="email"/>
		<br/>
		<%-- url : 유효성 검사 --%>
		<%-- 모바일에서 인터넷 주소를 입력하기위한 키보드 --%>
		<input type="url" name="a8" placeholder="url"/>
		<br/>
		<%-- search : 우측에 x 버튼이 표시된다. --%>
		<%-- IE에서는 text를 써도 x 버튼이 표시된다. --%>
		<input type="search" name="a9" placeholder="search"/>
		<br/>
		<%-- color : 모바일에서는 사용 금지 --%>
		<input type="color" name="a10" placeholder="color"/>
		<br/>
		<%-- tel : 유효검사를 하지 않는다. --%>
		<%-- 모바일에서 전화번호 입력을 위한 키보드 표시 --%>
		<input type="tel" name="a11" placeholder="tel"/>
		<br/>
		<%-- 날짜와 시간 --%>
		<%-- IE에서 지원 되지 않는다. --%>
		<input type="time" name="a12" placeholder="time"/>
		<br/>
		<input type="date" name="a13" placeholder="date"/>
		<br/>
		<input type="month" name="a14" placeholder="month"/>
		<br/>
		<input type="week" name="a15" placeholder="week"/>
		<br/>
		<%-- range : 사용하는 것을 권하지 않는다. --%>
		<input type="range" name="a16" max="100" min="1"
		       step="2"/><br/>
		<%-- datalist --%>
		<input type="text" list="data_list" name="a17"/>
		<datalist id="data_list">
			<option label="값1" value="data1"/>
			<option label="값2" value="data2"/>
			<option label="값3" value="data3"/>
		</datalist>
		<br/>
		<%-- keygen --%>
		<keygen name="a18" keytype="rsa"/><br/>
		<%-- hidden : 눈에 보이진 않지만 파라미터로 넘어간다. --%>
		<%-- 정해져 있는 값을 파라미터로 넘길때 사용 --%>
		<input type="hidden" name="a19" value="hidden"/>
		<%-- progress : 진행 률을 표시하기 위해 사용 --%>
		<progress max="100" value="50">
			HTML5가 지원되지 않는 브라우저에서 보여줄 
			화면을 구성한다.
		</progress>
		<%-- 버튼 --%>
		<%-- button : onclick 속성을 이용하여 처리 --%>
		<%-- reset : form 내부의 입력상자를 초기화 --%>
		<%-- submit : action에 설정되어 있는 페이지로 이동 --%>
		<input type="button" value="기본버튼"/>
		<input type="reset" value="리셋버튼"/>
		<input type="submit" value="확인버튼"/>
		<br/>
		<%-- type속성을 생략하면 submit으로 설정된다. --%>		
		<button type="submit">확인버튼</button>
		<button type="button">기본버튼</button>
		<button type="reset">리셋버튼</button>
	</form>
</body>
</html>












