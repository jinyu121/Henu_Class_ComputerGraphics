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

	int p1_n=4;
	CPoint p1[]={ CPoint(0,0), CPoint(0,100), CPoint(100,100), CPoint(100,0), };
	
	HYFill(pDC,p1_n,p1,RGB(255,0,0));

	int p2_n=4;
	CPoint p2[]={ CPoint(100,0), CPoint(100,100), CPoint(200,100), CPoint(200,0), };
	
	HYFill(pDC,p2_n,p2,RGB(0,0,255));

	int p3_n=4;
	CPoint p3[]={ CPoint(0,100), CPoint(0,200), CPoint(100,200), CPoint(100,100), };
	
	HYFill(pDC,p3_n,p3,RGB(0,255,0));

	int p4_n=4;
	CPoint p4[]={ CPoint(100,100), CPoint(100,200),  CPoint(200,200), CPoint(200,100), };
	
	HYFill(pDC,p4_n,p4,RGB(255,255,0));

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
		// One point here!!!
		// if the line's k equals 0, I will not add it into the table.
		// to avoid chrah...
		if (p[i].y==p[j].y)
			continue;
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
				pDC->SetPixelV(x,y,color);
			}
			a.x=a.x+a.kk;
			b.x=b.x+b.kk;
				edgeTable2.push(a);
				edgeTable2.push(b);
		}
		while(!edgeTable2.empty()){
			HYEdge tete=edgeTable2.top();
			edgeTable2.pop();
			if (tete.ymax<=y)
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
