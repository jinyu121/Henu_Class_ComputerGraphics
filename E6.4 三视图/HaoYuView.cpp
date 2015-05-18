// HaoYuView.cpp : implementation of the CHaoYuView class
//

#include "stdafx.h"
#include "HaoYu.h"

#include "HaoYuDoc.h"
#include "HaoYuView.h"
#include "HYFace.h"
#include "HYPoint.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define pi 3.1415926535897932384626

/////////////////////////////////////////////////////////////////////////////
// CHaoYuView

IMPLEMENT_DYNCREATE(CHaoYuView, CView)

BEGIN_MESSAGE_MAP(CHaoYuView, CView)
	//{{AFX_MSG_MAP(CHaoYuView)
	ON_COMMAND(HY_BUTTON_3D, OnButton3d)
	ON_COMMAND(HY_BUTTON_LEFT, OnButtonLeft)
	ON_COMMAND(HY_BUTTON_MAIN, OnButtonMain)
	ON_COMMAND(HY_BUTTON_UP, OnButtonUp)
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
	this->poi_num=6;
	this->poi[0]=HYPoint(0,		0,	0);
	this->poi[1]=HYPoint(100,	0,	0);
	this->poi[2]=HYPoint(80,	40,	0);
	this->poi[3]=HYPoint(0,		40,	0);
	this->poi[4]=HYPoint(20,	20,	50);
	this->poi[5]=HYPoint(60,	20,	100);
	this->fac_num=5;
	this->fac[0].num_p=4;	this->fac[0].index[0]=0;	this->fac[0].index[1]=1;	this->fac[0].index[2]=2;	this->fac[0].index[3]=3;	
	this->fac[1].num_p=4;	this->fac[1].index[0]=0;	this->fac[1].index[1]=1;	this->fac[1].index[2]=5;	this->fac[1].index[3]=4;
	this->fac[2].num_p=3;	this->fac[2].index[0]=1;	this->fac[2].index[1]=2;	this->fac[2].index[2]=5;	
	this->fac[3].num_p=4;	this->fac[3].index[0]=2;	this->fac[3].index[1]=3;	this->fac[3].index[2]=4;	this->fac[3].index[3]=5;
	this->fac[4].num_p=3;	this->fac[4].index[0]=3;	this->fac[4].index[1]=0;	this->fac[4].index[2]=4;	
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

void CHaoYuView::OnButton3d() 
{
	this->RedrawWindow();
	CDC* pDC=GetDC();
	CRect rect;      //定义矩形  
	GetClientRect(&rect);       //获得客户区矩形的大小               
	pDC->SetMapMode(MM_ANISOTROPIC);    	//自定义坐标系                
	pDC->SetWindowExt(rect.Width(),rect.Height());   	//设置窗口比例   
	pDC->SetViewportExt(rect.Width(),-rect.Height());   	//设置视区比例，且x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);	//设置客户区中心为坐标系原点
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);  	//矩形与客户区重合
	
	pDC->MoveTo(0,0);
	pDC->LineTo(200,0);
	pDC->TextOut(200,0,"X");
	pDC->MoveTo(0,0);
	pDC->LineTo(0,200);
	pDC->TextOut(0,200,"Y");
	pDC->MoveTo(0,0);
	pDC->LineTo(-150,-150);
	pDC->TextOut(-150,-150,"Z");

	int i,j,k,pot;
	double t[4][4]={{1,0,0,0},
					{0,1,0,0},
					{-cos(pi/4),-sin(pi/4),0,0},
					{0,0,0,1}};
	double ans[6][4];
	memset(ans,0,sizeof(ans));
	for(i=0;i<poi_num;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				ans[i][j]+=(this->poi[i].p[k]*t[k][j]);
			}
		}
	}
	
	for(i=1;i<fac_num;i++){
		pot=this->fac[i].index[0];
		pDC->MoveTo((int)ans[pot][0],(int)ans[pot][1]);
		for(j=0;j<this->fac[i].num_p;j++){
			pot=this->fac[i].index[(j+1)%(this->fac[i].num_p)];
			pDC->LineTo((int)ans[pot][0],(int)ans[pot][1]);
		}
	}

	ReleaseDC ( pDC );
}

void CHaoYuView::OnButtonLeft() 
{
	this->RedrawWindow();
	CDC* pDC=GetDC();
	CRect rect;      //定义矩形  
	GetClientRect(&rect);       //获得客户区矩形的大小               
	pDC->SetMapMode(MM_ANISOTROPIC);    	//自定义坐标系                
	pDC->SetWindowExt(rect.Width(),rect.Height());   	//设置窗口比例   
	pDC->SetViewportExt(rect.Width(),-rect.Height());   	//设置视区比例，且x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);	//设置客户区中心为坐标系原点
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);  	//矩形与客户区重合

	pDC->MoveTo(0,0);
	pDC->LineTo(200,0);
	pDC->TextOut(200,0,"X");
	pDC->MoveTo(0,0);
	pDC->LineTo(0,200);
	pDC->TextOut(0,200,"Z");


	int i,j,k,pot;
	double t[4][4]={{1,0,0,0},
					{0,0,0,0},
					{0,0,1,0},
					{0,0,0,1}};
	double ans[6][4];
	memset(ans,0,sizeof(ans));
	for(i=0;i<poi_num;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				ans[i][j]+=(this->poi[i].p[k]*t[k][j]);
			}
		}
	}
	
	for(i=1;i<fac_num;i++){
		pot=this->fac[i].index[0];
		pDC->MoveTo((int)ans[pot][0],(int)ans[pot][1]);
		for(j=0;j<this->fac[i].num_p;j++){
			pot=this->fac[i].index[(j+1)%(this->fac[i].num_p)];
			pDC->LineTo((int)ans[pot][0],(int)ans[pot][2]);
		}
	}

	ReleaseDC ( pDC );
}

void CHaoYuView::OnButtonMain() 
{
	this->RedrawWindow();
	CDC* pDC=GetDC();
	CRect rect;      //定义矩形  
	GetClientRect(&rect);       //获得客户区矩形的大小               
	pDC->SetMapMode(MM_ANISOTROPIC);    	//自定义坐标系                
	pDC->SetWindowExt(rect.Width(),rect.Height());   	//设置窗口比例   
	pDC->SetViewportExt(rect.Width(),-rect.Height());   	//设置视区比例，且x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);	//设置客户区中心为坐标系原点
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);  	//矩形与客户区重合

	pDC->MoveTo(0,0);
	pDC->LineTo(200,0);
	pDC->TextOut(200,0,"X");
	pDC->MoveTo(0,0);
	pDC->LineTo(0,200);
	pDC->TextOut(0,200,"Z");

	int i,j,k,pot;
	double t[4][4]={{0,0,0,0},
					{0,1,0,0},
					{0,0,1,0},
					{0,0,0,1}};
	double ans[6][4];
	memset(ans,0,sizeof(ans));
	for(i=0;i<poi_num;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				ans[i][j]+=(this->poi[i].p[k]*t[k][j]);
			}
		}
	}
	
	for(i=1;i<fac_num;i++){
		pot=this->fac[i].index[0];
		pDC->MoveTo((int)ans[pot][0],(int)ans[pot][1]);
		for(j=0;j<this->fac[i].num_p;j++){
			pot=this->fac[i].index[(j+1)%(this->fac[i].num_p)];
			pDC->LineTo((int)ans[pot][1],(int)ans[pot][2]);
		}
	}

	ReleaseDC ( pDC );
}

void CHaoYuView::OnButtonUp() 
{
	this->RedrawWindow();
	CDC* pDC=GetDC();
	CRect rect;      //定义矩形  
	GetClientRect(&rect);       //获得客户区矩形的大小               
	pDC->SetMapMode(MM_ANISOTROPIC);    	//自定义坐标系                
	pDC->SetWindowExt(rect.Width(),rect.Height());   	//设置窗口比例   
	pDC->SetViewportExt(rect.Width(),-rect.Height());   	//设置视区比例，且x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);	//设置客户区中心为坐标系原点
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);  	//矩形与客户区重合

	pDC->MoveTo(0,0);
	pDC->LineTo(200,0);
	pDC->TextOut(200,0,"X");
	pDC->MoveTo(0,0);
	pDC->LineTo(0,200);
	pDC->TextOut(0,200,"Y");

	int i,j,k,pot;
	double t[4][4]={{1,0,0,0},
					{0,1,0,0},
					{0,0,0,0},
					{0,0,0,1}};
	double ans[6][4];
	memset(ans,0,sizeof(ans));
	for(i=0;i<poi_num;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				ans[i][j]+=(this->poi[i].p[k]*t[k][j]);
			}
		}
	}
	for(i=1;i<fac_num;i++){
		pot=this->fac[i].index[0];
		pDC->MoveTo((int)ans[pot][0],(int)ans[pot][1]);
		for(j=0;j<this->fac[i].num_p;j++){
			pot=this->fac[i].index[(j+1)%(this->fac[i].num_p)];
			pDC->LineTo((int)ans[pot][0],(int)ans[pot][1]);
		}
	}

	ReleaseDC ( pDC );
}
