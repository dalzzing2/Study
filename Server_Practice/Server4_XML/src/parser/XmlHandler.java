package parser;

import java.util.ArrayList;

import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import bean.SaxBean;

public class XmlHandler extends DefaultHandler{
	// 데이터를 담아놓을 빈 객체
	SaxBean bean;
	// 문자열 값을 임시로 넣어둘 변수
	String tempStr;
	
	public XmlHandler(SaxBean bean){
		this.bean = bean;
	}
	// 문서의 시작을 만났을 때 호출
	// 파싱 작업에 대한 준비 작업
	@Override
	public void startDocument() throws SAXException {
		// TODO Auto-generated method stub
		super.startDocument();
	}
	// 시작 태그를 만났을 때 호출
	// 시작 태그에 있는 속성 값이 필요할 경우 사용
	@Override
	public void startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
		// TODO Auto-generated method stub
		super.startElement(uri, localName, qName, attributes);
		// 태그 이름으로 분기
		if(qName.equals("school_grade")){
			// 속성 값 추출해서 담아준다.
			String grade = attributes.getValue("grade");
			String class_cnt = attributes.getValue("class_cnt");
			
			bean.attr_grade.add(grade);
			bean.attr_class_cnt.add(class_cnt);
		}
	}
	// 문자열 데이터를 만났을 때 호출
	// 임시 변수에 담아준다.
	@Override
	public void characters(char[] ch, int start, int length) throws SAXException {
		// TODO Auto-generated method stub
		super.characters(ch, start, length);
		tempStr = new String(ch, start, length);
	}
	// 종료 태그를 만났을 때
	// 임시 변수에 담긴 데이터를 원하는 곳에 넣어준다.
	// 태그의 이름은 localName이나 qName으로 들어온다.
	@Override
	public void endElement(String uri, String localName, String qName) throws SAXException {
		// TODO Auto-generated method stub
		super.endElement(uri, localName, qName);
		// 태그 이름으로 분기
		if(qName.equals("school_name")){
			bean.school_name = tempStr;
		} else if(qName.equals("school_addr")){
			bean.school_addr = tempStr;
		} else if(qName.equals("school_cnt")){
			bean.school_cnt = tempStr;
		} else if(qName.equals("class_number")){
			bean.class_number.add(tempStr);
		} else if(qName.equals("class_member_cnt")){
			bean.class_member_cnt.add(tempStr);
		} else if(qName.equals("class_boss_name")){
			bean.class_boss_name.add(tempStr);
		} else if(qName.equals("class_president")){
			bean.class_president.add(tempStr);
		}
	}
	// 문서의 마지막을 만났을 때
	// 파싱 종료
	@Override
	public void endDocument() throws SAXException {
		// TODO Auto-generated method stub
		super.endDocument();
	}
	
	
	
}









