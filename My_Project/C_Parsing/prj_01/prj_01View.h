
// prj_01View.h : Cprj_01View Ŭ������ �������̽�
//

#pragma once


class Cprj_01View : public CScrollView
{
protected: // serialization������ ��������ϴ�.
	Cprj_01View();
	DECLARE_DYNCREATE(Cprj_01View)

// Ư���Դϴ�.
public:
	Cprj_01Doc* GetDocument() const;

// �۾��Դϴ�.
public:
	CSize sizeTotal;

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~Cprj_01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // prj_01View.cpp�� ����� ����
inline Cprj_01Doc* Cprj_01View::GetDocument() const
   { return reinterpret_cast<Cprj_01Doc*>(m_pDocument); }
#endif

