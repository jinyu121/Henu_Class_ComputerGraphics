// HaoYuView.cpp : implementation of the CHaoYuView class
//


#include "stdafx.h"
#include "HaoYu.h"

#include "HaoYuDoc.h"
#include "HaoYuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "math.h"



/////////////////////////////////////////////////////////////////////////////
// CHaoYuView

IMPLEMENT_DYNCREATE(CHaoYuView, CView)

BEGIN_MESSAGE_MAP(CHaoYuView, CView)
	//{{AFX_MSG_MAP(CHaoYuView)
	ON_COMMAND(HY_MOVE_X_D, OnMoveXD)
	ON_COMMAND(HY_MOVE_X_U, OnMoveXU)
	ON_COMMAND(HY_MOVE_Y_D, OnMoveYD)
	ON_COMMAND(HY_MOVE_Y_U, OnMoveYU)
	ON_COMMAND(HY_MOVE_Z_D, OnMoveZD)
	ON_COMMAND(HY_MOVE_Z_U, OnMoveZU)
	ON_COMMAND(HY_ROTATE_X_C, OnRotateXC)
	ON_COMMAND(HY_ROTATE_X_R, OnRotateXR)
	ON_COMMAND(HY_ROTATE_Y_C, OnRotateYC)
	ON_COMMAND(HY_ROTATE_Y_R, OnRotateYR)
	ON_COMMAND(HY_ROTATE_Z_C, OnRotateZC)
	ON_COMMAND(HY_ROTATE_Z_R, OnRotateZR)
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
	this->poi[0]=HYPoint(0,0,0);
	this->poi[1]=HYPoint(100,0,0);
	this->poi[2]=HYPoint(100,100,0);
	this->poi[3]=HYPoint(0,100,0);
	this->poi[4]=HYPoint(0,0,100);
	this->poi[5]=HYPoint(100,0,100);
	this->poi[6]=HYPoint(100,100,100);
	this->poi[7]=HYPoint(0,100,100);

	this->fac[0].num_p=4;	this->fac[0].index[0]=0;	this->fac[0].index[1]=1;	this->fac[0].index[2]=2;	this->fac[0].index[3]=3;
	this->fac[1].num_p=4;	this->fac[1].index[0]=4;	this->fac[1].index[1]=5;	this->fac[1].index[2]=6;	this->fac[1].index[3]=7;
	this->fac[2].num_p=4;	this->fac[2].index[0]=1;	this->fac[2].index[1]=2;	this->fac[2].index[2]=6;	this->fac[2].index[3]=5;
	this->fac[3].num_p=4;	this->fac[3].index[0]=0;	this->fac[3].index[1]=3;	this->fac[3].index[2]=7;	this->fac[3].index[3]=4;
	this->fac[4].num_p=4;	this->fac[4].index[0]=2;	this->fac[4].index[1]=3;	this->fac[4].index[2]=7;	this->fac[4].index[3]=6;
	this->fac[5].num_p=4;	this->fac[5].index[0]=0;	this->fac[5].index[1]=4;	this->fac[5].index[2]=5;	this->fac[5].index[3]=1;
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

void CHaoYuView::TransIt(){
	int i,j,k;
	double ans[poi_num][4];
	memset(ans,0,sizeof(ans));
	for(i=0;i<poi_num;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				ans[i][j]+=(this->poi[i].p[k]*this->trans[k][j]);
			}
		}
	}
	for(i=0;i<poi_num;i++){
		for(j=0;j<4;j++){
			this->poi[i].p[j]=ans[i][j];
		}
	}
}

void CHaoYuView::SetTrans(double x11,double x12,double x13,double x14,double x21,double x22,double x23,double x24,double x31,double x32,double x33,double x34,double x41,double x42,double x43,double x44){
	this->trans[0][0]=x11;	this->trans[0][1]=x12;	this->trans[0][2]=x13;	this->trans[0][3]=x14;
	this->trans[1][0]=x21;	this->trans[1][1]=x22;	this->trans[1][2]=x23;	this->trans[1][3]=x24;
	this->trans[2][0]=x31;	this->trans[2][1]=x32;	this->trans[2][2]=x33;	this->trans[2][3]=x34;
	this->trans[3][0]=x41;	this->trans[3][1]=x42;	this->trans[3][2]=x43;	this->trans[3][3]=x44;

}

void CHaoYuView::DrawIt(){
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
	double ans[poi_num][4];
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

void CHaoYuView::BaseMove(double xx,double yy,double zz){
	SetTrans(1,0,0,0,
			0,1,0,0,
			0,0,1,0,
			xx,yy,zz,1);
	TransIt();
}

void CHaoYuView::OnMoveXD() 
{
	BaseMove(-5,0,0);
	DrawIt();
}

void CHaoYuView::OnMoveXU() 
{
	BaseMove(5,0,0);
	DrawIt();
}

void CHaoYuView::OnMoveYD() 
{
	BaseMove(0,-5,0);
	DrawIt();
}

void CHaoYuView::OnMoveYU() 
{
	BaseMove(0,5,0);
	DrawIt();
}

void CHaoYuView::OnMoveZD() 
{
	BaseMove(0,0,-5);
	DrawIt();
}

void CHaoYuView::OnMoveZU() 
{
	BaseMove(0,0,5);
	DrawIt();
}

void CHaoYuView::OnRotateXC() 
{
	double xx=(this->poi[0].p[0]+this->poi[6].p[0])/2;
	double yy=(this->poi[0].p[1]+this->poi[6].p[1])/2;
	double zz=(this->poi[0].p[2]+this->poi[6].p[2])/2;
	BaseMove(-xx,-yy,-zz);
	SetTrans(1,0,0,0,
			0,cos(ang_ang),sin(ang_ang),0,
			0,-sin(ang_ang),cos(ang_ang),0,
			0,0,0,1);
	TransIt();
	BaseMove(xx,yy,zz);

	DrawIt();
}

void CHaoYuView::OnRotateXR() 
{
	double xx=(this->poi[0].p[0]+this->poi[6].p[0])/2;
	double yy=(this->poi[0].p[1]+this->poi[6].p[1])/2;
	double zz=(this->poi[0].p[2]+this->poi[6].p[2])/2;
	BaseMove(-xx,-yy,-zz);
	SetTrans(1,0,0,0,
			0,cos(-ang_ang),sin(-ang_ang),0,
			0,-sin(-ang_ang),cos(-ang_ang),0,
			0,0,0,1);
	TransIt();
	BaseMove(xx,yy,zz);

	DrawIt();
}

void CHaoYuView::OnRotateYC() 
{
	double xx=(this->poi[0].p[0]+this->poi[6].p[0])/2;
	double yy=(this->poi[0].p[1]+this->poi[6].p[1])/2;
	double zz=(this->poi[0].p[2]+this->poi[6].p[2])/2;
	BaseMove(-xx,-yy,-zz);
	SetTrans(cos(ang_ang),0,-sin(ang_ang),0,
			0,1,0,0,
			sin(ang_ang),0,cos(ang_ang),0,
			0,0,0,1);
	TransIt();
	BaseMove(xx,yy,zz);

	DrawIt();
}

void CHaoYuView::OnRotateYR() 
{
	double xx=(this->poi[0].p[0]+this->poi[6].p[0])/2;
	double yy=(this->poi[0].p[1]+this->poi[6].p[1])/2;
	double zz=(this->poi[0].p[2]+this->poi[6].p[2])/2;
	BaseMove(-xx,-yy,-zz);
	SetTrans(cos(-ang_ang),0,-sin(-ang_ang),0,
			0,1,0,0,
			sin(-ang_ang),0,cos(-ang_ang),0,
			0,0,0,1);
	TransIt();
	BaseMove(xx,yy,zz);

	DrawIt();
}

void CHaoYuView::OnRotateZC() 
{
	double xx=(this->poi[0].p[0]+this->poi[6].p[0])/2;
	double yy=(this->poi[0].p[1]+this->poi[6].p[1])/2;
	double zz=(this->poi[0].p[2]+this->poi[6].p[2])/2;
	BaseMove(-xx,-yy,-zz);
	SetTrans(cos(ang_ang),sin(ang_ang),0,0,
			-sin(ang_ang),cos(ang_ang),0,0,
			0,0,1,0,
			0,0,0,1);
	TransIt();
	BaseMove(xx,yy,zz);

	DrawIt();
}

void CHaoYuView::OnRotateZR() 
{
	double xx=(this->poi[0].p[0]+this->poi[6].p[0])/2;
	double yy=(this->poi[0].p[1]+this->poi[6].p[1])/2;
	double zz=(this->poi[0].p[2]+this->poi[6].p[2])/2;
	BaseMove(-xx,-yy,-zz);
	SetTrans(cos(-ang_ang),sin(-ang_ang),0,0,
			-sin(-ang_ang),cos(-ang_ang),0,0,
			0,0,1,0,
			0,0,0,1);
	TransIt();
	BaseMove(xx,yy,zz);

	DrawIt();
}
