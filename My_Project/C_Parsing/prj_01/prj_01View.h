
// prj_01View.h : Cprj_01View 클래스의 인터페이스
//

#pragma once


class Cprj_01View : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	Cprj_01View();
	DECLARE_DYNCREATE(Cprj_01View)

// 특성입니다.
public:
	Cprj_01Doc* GetDocument() const;

// 작업입니다.
public:
	CSize sizeTotal;

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~Cprj_01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // prj_01View.cpp의 디버그 버전
inline Cprj_01Doc* Cprj_01View::GetDocument() const
   { return reinterpret_cast<Cprj_01Doc*>(m_pDocument); }
#endif

