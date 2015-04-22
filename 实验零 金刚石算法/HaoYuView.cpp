// HaoYuView.cpp : implementation of the CHaoYuView class
//

#include "stdafx.h"
#include "HaoYu.h"

#include "HaoYuDoc.h"
#include "HaoYuView.h"
#include <math.h>

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

		////////// 通用准备工作 //////////
	//定义矩形
	CRect rect;         
	//获得客户区矩形的大小
	GetClientRect(&rect);                      
	//自定义坐标系
	pDC->SetMapMode(MM_ANISOTROPIC);                    
	//设置窗口比例
	pDC->SetWindowExt(rect.Width(),rect.Height());      
	//设置视区比例，且x轴水平向右，y轴垂直向上
	pDC->SetViewportExt(rect.Width(),-rect.Height());   
	//设置客户区中心为坐标系原点
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	//矩形与客户区重合
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);  

		const int n=40;
	const double r=350;

	int i,j,k;

	const double Pi=3.1415926535897932384626;

	double x[n+1],y[n+1];
	
	double theta=2*Pi/(double)n;
	double angle=0;

	for (i=1;i<n+1;i++){
		angle+=theta;
		x[i]=r*cos(angle);
		y[i]=r*sin(angle);
	}
	
	for (i=0;i<n+1;i++){
		for(j=0;j<n;j++){
			pDC->MoveTo((int)x[i],(int)y[i]);
			pDC->LineTo((int)x[j],(int)y[j]);
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
