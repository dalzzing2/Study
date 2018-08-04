
// prj_01View.cpp : Cprj_01View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "prj_01.h"
#endif

#include "prj_01Doc.h"
#include "prj_01View.h"
#include "LRParsing.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cprj_01View

IMPLEMENT_DYNCREATE(Cprj_01View, CScrollView)

BEGIN_MESSAGE_MAP(Cprj_01View, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cprj_01View ����/�Ҹ�

Cprj_01View::Cprj_01View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	
	sizeTotal.cx = sizeTotal.cy =100;
}

Cprj_01View::~Cprj_01View()
{
}

BOOL Cprj_01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// Cprj_01View �׸���

void Cprj_01View::OnDraw(CDC* pDC)
{
	Cprj_01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	if(pDoc->read_flag==1){
		LRParsing par;
		int n = par.parsetree_mfc(pDoc->readFP, pDC, &sizeTotal);
		if(n!=0){
			CString str;
			str.Format("ERR code %d : ������ ��߳��ϴ�.", n);
			pDC->DrawText(str, CRect(20,20,1000,40), DT_LEFT);
			AfxMessageBox(str);
		}
	}
	SetScrollSizes(MM_TEXT, sizeTotal);
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}

void Cprj_01View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Cprj_01View �μ�

BOOL Cprj_01View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void Cprj_01View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void Cprj_01View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// Cprj_01View ����

#ifdef _DEBUG
void Cprj_01View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Cprj_01View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Cprj_01Doc* Cprj_01View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cprj_01Doc)));
	return (Cprj_01Doc*)m_pDocument;
}
#endif //_DEBUG


// Cprj_01View �޽��� ó����
