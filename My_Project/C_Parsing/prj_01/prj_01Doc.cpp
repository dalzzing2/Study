
// prj_01Doc.cpp : Cprj_01Doc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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


// Cprj_01Doc 생성/소멸

Cprj_01Doc::Cprj_01Doc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
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

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// Cprj_01Doc serialization

void Cprj_01Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void Cprj_01Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
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

// 검색 처리기를 지원합니다.
void Cprj_01Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// Cprj_01Doc 진단

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


// Cprj_01Doc 명령


BOOL Cprj_01Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
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
		AfxMessageBox("입력할 파일을 찾을수 없습니다.");
	}*/
	if(readFP != NULL)
		fclose(readFP);
	readFP = fopen(lpszPathName, "r");
	read_flag=1;
	pView->Invalidate();
	return TRUE;
}
