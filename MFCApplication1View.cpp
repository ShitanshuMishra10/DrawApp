
// MFCApplication1View.cpp : implementation of the CMFCApplication1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_RECTBUTTON,OnRectButtonClicked)
	ON_BN_CLICKED(IDC_CIRCLEBUTTON, OnCircleButtonClicked)
	ON_BN_CLICKED(IDC_LINEBUTTON, OnLineButtonClicked)
	ON_BN_CLICKED(IDC_TRIANGLEBUTTON, OnTriangleButtonClicked)
	ON_BN_CLICKED(IDC_SAVEBUTTON, OnSaveButtonClicked)
	ON_BN_CLICKED(IDC_OPENBUTTON, OnOpenButtonClicked)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication1View construction/destruction

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: add construction code here
}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View drawing

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	if (pDoc->getDraw())
	{
		DrawAllShapes(pDC);
		if(!pDoc->getFirst())
		DrawTempShape(pDC);
	}
}


// CMFCApplication1View printing


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

void CMFCApplication1View::OnRectButtonClicked()
{
	buttonId = IDC_RECTBUTTON;
	GetDocument()->setDraw(true);
	GetDocument()->setFirst(true);
}

void CMFCApplication1View::OnCircleButtonClicked()
{
	buttonId = IDC_CIRCLEBUTTON;
	GetDocument()->setDraw(true);
	GetDocument()->setFirst(true);
}

void CMFCApplication1View::OnLineButtonClicked()
{
	buttonId = IDC_LINEBUTTON;
	GetDocument()->setDraw(true);
	GetDocument()->setFirst(true);
}

void CMFCApplication1View::OnTriangleButtonClicked()
{
	buttonId = IDC_TRIANGLEBUTTON;
	GetDocument()->setDraw(true);
	GetDocument()->setFirst(true);
}



void CMFCApplication1View::OnSaveButtonClicked()
{
	CFileDialog dlg(FALSE, L".dat", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, L"Data Files (*.dat)|*.dat|All Files (*.*)|*.*||");

	if (dlg.DoModal() == IDOK)
	{
		CString pathName = dlg.GetPathName();
											 
		CFile file;
		if (file.Open(pathName, CFile::modeCreate | CFile::modeWrite))
		{
			CArchive archive(&file, CArchive::store);  
													 
			GetDocument()->Serialize(archive);

			archive.Close();
			file.Close();
		}
	}
}

void CMFCApplication1View::OnOpenButtonClicked()
{
	CFileDialog dlg(TRUE, L".dat", NULL, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, L"Data Files (*.dat)|*.dat|All Files (*.*)|*.*||");

	if (dlg.DoModal() == IDOK)
	{
		CString pathName = dlg.GetPathName();

		CFile file;
		if (file.Open(pathName, CFile::modeRead | CFile::shareDenyWrite))
		{
			CArchive archive(&file, CArchive::load);  
													  
			GetDocument()->Serialize(archive);

			archive.Close();
			file.Close();
		}
	}
}


// CMFCApplication1View diagnostics

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

void CMFCApplication1View::DrawAllShapes(CDC * pDC)
{
	ShapeXY** shapes = ((GetDocument())->allShapes).getAllShapes();
	for (int i = 0;i < ((GetDocument())->allShapes).getCounter();i++)
	{
		ShapeXY* shape = shapes[i];
		int x1, y1, x2, y2;

		x1 = shape->getStartPoint()->getX();
		y1 = shape->getStartPoint()->getY();
		x2 = shape->getEndPoint()->getX();
		y2 = shape->getEndPoint()->getY();

		switch (shape->getType())
		{
		case 1 :
			pDC->Rectangle(x1, y1, x2, y2);
			break;
		case 2:
			pDC->Ellipse(x1, y1, x2, y2);
			break;
		case 3:
			pDC->MoveTo(x1, y1);
			pDC->LineTo(x2, y2);
			break;
		case 4:
			pDC->MoveTo(x1, y1);
			pDC->LineTo(x1, y2);
			pDC->LineTo(x2, y2);
			pDC->LineTo(x1, y1);
			break;
		}

	}
}

void CMFCApplication1View::DrawTempShape(CDC * pDC)
{
	int x1, y1, x2, y2;

	x1 = firstPoint.getX();
	y1 = firstPoint.getY();

	x2 = tempX;
	y2 = tempY;

	switch (buttonId)
	{
	case IDC_RECTBUTTON: 
		pDC->Rectangle(x1, y1, x2, y2); 
		break;

	case IDC_CIRCLEBUTTON:
		pDC->Ellipse(x1, y1, x2, y2);
		break;

	case IDC_LINEBUTTON:
		pDC->MoveTo(x1, y1);
		pDC->LineTo(x2, y2);
		break;

	case IDC_TRIANGLEBUTTON:
		pDC->MoveTo(x1, y1);
		pDC->LineTo(x1, y2);
		pDC->LineTo(x2, y2);
		pDC->LineTo(x1, y1);
		break;
	}

}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View message handlers


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	lBtnDown = true;
	
	if (GetDocument()->getDraw() && GetDocument()->getFirst())
	{
		firstPoint.setPoint(point.x, point.y);
		GetDocument()->setFirst(false);
	}

	CView::OnLButtonDown(nFlags, point);
}

void CMFCApplication1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	lBtnDown = false;
	if (GetDocument()->getDraw() && !GetDocument()->getFirst())
	{
		secondPoint.setPoint(point.x, point.y);
		GetDocument()->setFirst(true);

		switch (buttonId)
		{
		case IDC_RECTBUTTON:
			((GetDocument())->allShapes).Add(new RectXY(firstPoint.getX(),firstPoint.getY(), secondPoint.getX(),secondPoint.getY()));
			break;

		case IDC_CIRCLEBUTTON:
			((GetDocument())->allShapes).Add(new CircleXY(firstPoint.getX(), firstPoint.getY(), secondPoint.getX(), secondPoint.getY()));
			break;

		case IDC_LINEBUTTON:
			((GetDocument())->allShapes).Add(new LineXY(firstPoint.getX(), firstPoint.getY(), secondPoint.getX(), secondPoint.getY()));
			break;

		case IDC_TRIANGLEBUTTON:
			((GetDocument())->allShapes).Add(new TriangleXY(firstPoint.getX(), firstPoint.getY(), secondPoint.getX(), secondPoint.getY()));



		}

	}

	CView::OnLButtonUp(nFlags, point);
}




void CMFCApplication1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	bool draw = GetDocument()->getDraw();
	bool first = GetDocument()->getFirst();
	if (lBtnDown && draw && !first)
	{
		tempX = point.x; tempY = point.y;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}


int CMFCApplication1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	rectButton.Create(L"Rectangle", BS_PUSHBUTTON, CRect(50, 10, 150, 50), this, IDC_RECTBUTTON);
	circleButton.Create(L"Circle", BS_PUSHBUTTON, CRect(200, 10, 300, 50), this, IDC_CIRCLEBUTTON);
	lineButton.Create(L"Line", BS_PUSHBUTTON, CRect(350, 10, 450, 50), this, IDC_LINEBUTTON);
	triangleButton.Create(L"Triangle", BS_PUSHBUTTON, CRect(500, 10, 600, 50), this, IDC_TRIANGLEBUTTON);
	saveButton.Create(L"Save", BS_PUSHBUTTON, CRect(650, 10, 750, 50), this, IDC_SAVEBUTTON);
	openButton.Create(L"Open", BS_PUSHBUTTON, CRect(800, 10, 900, 50), this, IDC_OPENBUTTON);

	rectButton.ShowWindow(SW_SHOW);
	circleButton.ShowWindow(SW_SHOW);
	lineButton.ShowWindow(SW_SHOW);
	triangleButton.ShowWindow(SW_SHOW);
	saveButton.ShowWindow(SW_SHOW);
	openButton.ShowWindow(SW_SHOW);

	return 0;
}

