
// MFCApplication1View.h : interface of the CMFCApplication1View class
//

#pragma once

const UINT IDC_RECTBUTTON{ 101 };
const UINT IDC_CIRCLEBUTTON{ 102 };
const UINT IDC_LINEBUTTON{ 103 };
const UINT IDC_TRIANGLEBUTTON{ 104 };
const UINT IDC_SAVEBUTTON{ 201 };
const UINT IDC_OPENBUTTON{ 202 };

class CMFCApplication1View : public CView
{
protected: // create from serialization only
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

// Attributes
public:
	CMFCApplication1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


private:
	void DrawAllShapes(CDC* pDC);
	void DrawTempShape(CDC* pDC);
	PointXY firstPoint;
	PointXY secondPoint;
	int tempX, tempY;
	int buttonId{ 0 };
	bool lBtnDown{ false };
	//int counter{ 0 };

	CButton rectButton, circleButton, lineButton, triangleButton, openButton, saveButton;

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnRectButtonClicked();
	afx_msg void OnCircleButtonClicked();
	afx_msg void OnLineButtonClicked();
	afx_msg void OnTriangleButtonClicked();
	afx_msg void OnSaveButtonClicked();
	afx_msg void OnOpenButtonClicked();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in MFCApplication1View.cpp
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif

