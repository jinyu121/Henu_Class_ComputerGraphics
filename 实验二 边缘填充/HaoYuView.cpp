// HaoYuView.cpp : implementation of the CHaoYuView class
//

#include "stdafx.h"
#include "HaoYu.h"

#include "HaoYuDoc.h"
#include "HaoYuView.h"
#include <queue>

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
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
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
	// TODO: add draw code for native data here
	
	int p1_n=7;
	CPoint p1[]={
			CPoint(70,80),
			CPoint(30,120),
			CPoint(10,70),
			CPoint(30,10),
			CPoint(60,50),
			CPoint(80,10),
			CPoint(120,90)
	};
	
	HYFill(pDC,p1_n,p1,RGB(0,155,0));
	
	int p2_n=4;
	CPoint p2[]={
			CPoint(100,100),
			CPoint(100,200),
			CPoint(200,200),
			CPoint(200,100),
	};

	HYFill(pDC,p2_n,p2,RGB(0,0,255));
	
}
class HYEdge{
public:
	int ymin,ymax;
	double x,k;
	//int next;
	HYEdge(){}
	HYEdge(CPoint c1,CPoint c2){
		ymin=min(c1.y,c2.y);
		ymax=max(c1.y,c2.y);
		double dx=c2.x-c1.x;
		double dy=c2.y-c1.y;
		if (ymin==c1.y){
			x=c1.x;		
		}else{
			x=c2.x;
		}
		if (dx!=0){
			k=((double)dy/(double)dx);
		}else{
			k=0;
		}
	}
	
};


void CHaoYuView::HYFill(CDC* pDC, int n, CPoint* p,COLORREF color){
	int i,j,k,sta;
	double x=0;
	for(i=0;i<n;i++){
		j=(i+1)%n;
		HYEdge e=HYEdge(p[i],p[j]);
		x=e.x;
		// For each line
		for (j=e.ymin;j<e.ymax;j++){
			// For each point
			for (k=(int)(e.x+0.5);k<=1024;k++){
				if (pDC->GetPixel(k,j)==RGB(255,255,255) ){
					pDC->SetPixelV(k,j,color);
				}else{
					pDC->SetPixelV(k,j,RGB(255,255,255));
				}
			}
			e.x=e.x+e.k;
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
