// RussianCurseDlg.h : header file
//
#include "globalPreDefines.h"
#pragma once


// CRussianCurseDlg dialog
class CRussianCurseDlg : public CDialog
{
// Construction
public:
	CRussianCurseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_RUSSIANCURSE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
		// ----------------------------------------------------------
		// ----------------------- Variables ------------------------
		// ----------------------------------------------------------
	
		#define MAX_LIST_SIZE (20)
		
		int titleSize;
		tNoun Title[MAX_LIST_SIZE];
		
		int whoSize;
		tNoun Who[MAX_LIST_SIZE];

		int whatSize;
		tNoun doWhat[MAX_LIST_SIZE];

		int whereSize;
		tNoun doWhere[MAX_LIST_SIZE];

		int andWhatSize;
		tNoun andWhat[MAX_LIST_SIZE];
		
		int withSize;
		tNoun With[MAX_LIST_SIZE];

		int futureSize;
		tNoun Future[MAX_LIST_SIZE];

		int ultiSize;
		tNoun Ulti[MAX_LIST_SIZE];

		int exclaSize;
		tNoun Excla[MAX_LIST_SIZE];

		int laughSize;
		tNoun Laugh[MAX_LIST_SIZE];

		// Pointers on GUI components
		CButton *pBt;
		CString     curseText;
		
		// Control Variables.
		CComboBox c_who;
		CComboBox c_doWhat;
		CComboBox c_doWhere;
		CComboBox c_andWhat;
		CComboBox c_with;
		CComboBox c_title;
		CComboBox c_future;
		CComboBox c_ulti;
		CComboBox c_excla;
		CComboBox c_laugh;

		// ----------------------------------------------------------
		// ----------------------- Handlers -------------------------
		// ----------------------------------------------------------

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedCurse();
	afx_msg void OnBnClickedRand();

private:
	void ConstructCurse();
	afx_msg void OnCbnComboChange();
};
