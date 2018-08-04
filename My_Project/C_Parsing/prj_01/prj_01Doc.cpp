
// prj_01Doc.cpp : Cprj_01Doc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "prj_01.h"
#endif

#include "prj_01Doc.h"
#include "prj_01View.h"
#include "MainFrm.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cprj_01Doc

IMPLEMENT_DYNCREATE(Cprj_01Doc, CDocument)

BEGIN_MESSAGE_MAP(Cprj_01Doc, CDocument)
END_MESSAGE_MAP()


// Cprj_01Doc ����/�Ҹ�

Cprj_01Doc::Cprj_01Doc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.
	read_flag = 0;
	//readAll.Format("");
	readFP = NULL;
	//read_fp = fopen("test_example.txt", "r");
}

Cprj_01Doc::~Cprj_01Doc()
{
	if(readFP !=NULL)
		fclose(readFP);
}

BOOL Cprj_01Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// Cprj_01Doc serialization

void Cprj_01Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void Cprj_01Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void Cprj_01Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void Cprj_01Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Cprj_01Doc ����

#ifdef _DEBUG
void Cprj_01Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cprj_01Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cprj_01Doc ���


BOOL Cprj_01Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	Cprj_01View* pView=(Cprj_01View*)((CMainFrame*) AfxGetMainWnd())->GetActiveView();
	/*
	CString ref;
	CFile infile;

	if(infile.Open(lpszPathName, CFile::modeRead))
	{
		CFileStatus fs;
		if(infile.GetStatus(fs) && fs.m_size>0)
		{
			PCHAR pBuf = new CHAR[fs.m_size+10];
			if(pBuf!=NULL)
			{
				for(int i=0; i<fs.m_size;)
					i+=infile.Read((PVOID)&pBuf[i], fs.m_size);
				pBuf[fs.m_size]=NULL;

				USES_CONVERSION;
				readAll = A2W(pBuf);

				delete []pBuf;
			}
		}
		infile.Close();
	}else{
		AfxMessageBox("�Է��� ������ ã���� �����ϴ�.");
	}*/
	if(readFP != NULL)
		fclose(readFP);
	readFP = fopen(lpszPathName, "r");
	read_flag=1;
	pView->Invalidate();
	return TRUE;
}
