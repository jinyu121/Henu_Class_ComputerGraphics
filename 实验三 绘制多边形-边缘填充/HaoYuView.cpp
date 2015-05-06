// HaoYuView.cpp : implementation of the CHaoYuView class
//

#include "stdafx.h"
#include "HaoYu.h"

#include "HaoYuDoc.h"
#include "HaoYuView.h"
#include <queue>
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView

IMPLEMENT_DYNCREATE(CHaoYuView, CView)

BEGIN_MESSAGE_MAP(CHaoYuView, CView)
	//{{AFX_MSG_MAP(CHaoYuView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView construction/destruction

CHaoYuView::CHaoYuView()
{
	// TODO: add construction code here
	this->n=0;
	srand((unsigned)time(NULL));
}

CHaoYuView::~CHaoYuView()
{
}

BOOL CHaoYuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView drawing

void CHaoYuView::OnDraw(CDC* pDC)
{
	CHaoYuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDC->TextOut(50,50,"×ó¼ü´òµãÓÒ¼ü»­Í¼");
}
class HYEdge{
public:
	int ymin,ymax;
	double x,k;
	//int next;
	HYEdge(){}
	HYEdge(CPoint c1,CPoint c2){
		if (c2.y<c1.y){
			CPoint t=c1;
			c1=c2;
			c2=t;
		}
		ymax=c2.y;
		ymin=c1.y;
		x=c1.x;
		double dx=c2.x-c1.x;
		double dy=c2.y-c1.y;
		if (dx!=0){
			k=((double)dx/(double)dy);
		}else{
			k=0;
		}
	}
	
};


void CHaoYuView::HYFill(CDC* pDC, int n, CPoint* p,COLORREF color){
	int maxmax= -100;
	double x;
	for(int i=0;i<n;i++){
		maxmax=max(maxmax,p[i].x);
	}
	for(int iter=0;iter<n;iter++){
		HYEdge e=HYEdge(p[iter],p[(iter+1)%n]);

		for (int y=e.ymin;y<e.ymax;y++){
			for(double x=e.x+e.k*(y-e.ymin);x<maxmax;x++){
				if (pDC->GetPixel((int)x,y)==color){
					pDC->SetPixelV((int)x,y,RGB(255,255,255));
				}else{
					pDC->SetPixelV((int)x,y,color);
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView printing

BOOL CHaoYuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHaoYuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHaoYuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView diagnostics

#ifdef _DEBUG
void CHaoYuView::AssertValid() const
{
	CView::AssertValid();
}

void CHaoYuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHaoYuDoc* CHaoYuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHaoYuDoc)));
	return (CHaoYuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView message handlers

void CHaoYuView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
	this->po[this->n]=point;
	this->n++;
}

void CHaoYuView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnRButtonDown(nFlags, point);
	CDC* pDC;
	pDC=GetDC();
	HYFill(pDC,n,this->po,RGB(rand()%256,rand()%256,rand()%256));
	n=0;
}
