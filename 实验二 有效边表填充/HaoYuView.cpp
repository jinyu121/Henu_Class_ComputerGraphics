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
	this->counter=0;
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
	pDC->TextOut(100,100,"左键选点，右键确认画图");
	pDC->TextOut(100,120,"尽量去左上角，高度不要超过1024");
	pDC->TextOut(100,140,"改变窗口大小以清除屏幕");
}
class HYEdge{
public:
	int ymin,ymax;
	double x,kk;
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
		if (dy!=0 && dx!=0){
			kk=((double)dx/(double)dy);  // For k is dy/dx
		}else{
			kk=0;
		}
	}
	
};

struct cmp{
	bool operator()(HYEdge a,HYEdge b){
		return (a.x>b.x) || ((a.x==b.x) && (a.kk>b.kk));
	}
};

void CHaoYuView::HYFill(CDC* pDC, int n, CPoint* p,COLORREF color){
	std::priority_queue<HYEdge,std::vector<HYEdge>,cmp> sta[1024];
	int i,j,k,tsta,ttt=0,x,y;
	int maxmax=-10000;
	int minmin=10000;
	for(i=0;i<n;i++){
		maxmax=max(maxmax,p[i].y); // The maxmium of y
		minmin=min(minmin,p[i].y); // The minimium of y
		j=(i+1)%n;
		HYEdge e=HYEdge(p[i],p[j]);
		sta[e.ymin].push(e);
	}
	std::priority_queue<HYEdge,std::vector<HYEdge>,cmp> edgeTable1,edgeTable2;
	for(y=minmin;y<=maxmax;y++){
		int tnnn=sta[y].size();
		while(!sta[y].empty()){
			HYEdge tete=sta[y].top();
			sta[y].pop();
			edgeTable1.push(tete);
		}
		while(!edgeTable1.empty()){
			HYEdge a=edgeTable1.top();
			edgeTable1.pop();
			HYEdge b=edgeTable1.top();
			edgeTable1.pop();
			int ista=(int)(a.x+0.5);
			int ifin=(int)(b.x+0.5);
			for(x=ista;x<ifin;x++){
				pDC->SetPixelV(x,y,RGB(0,0,255));
			}
			a.x=a.x+a.kk;
			b.x=b.x+b.kk;
				edgeTable2.push(a);
				edgeTable2.push(b);
		}
		while(!edgeTable2.empty()){
			HYEdge tete=edgeTable2.top();
			edgeTable2.pop();
			if (tete.ymax<=y+1)
				continue;
			edgeTable1.push(tete);
		}
		if (edgeTable1.empty()){
			break;
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
	this->counter+=1;
	this->pps[this->counter-1]=point;
}

void CHaoYuView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnRButtonDown(nFlags, point);
	CDC* pDC=GetDC();
	HYFill(pDC,this->counter,this->pps,RGB(0,155,0));
	this->counter=0;
}
