
// prj_01.h : prj_01 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#ERR "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cprj_01App:
// �� Ŭ������ ������ ���ؼ��� prj_01.cpp�� �����Ͻʽÿ�.
//

class Cprj_01App : public CWinApp
{
public:
	Cprj_01App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cprj_01App theApp;
