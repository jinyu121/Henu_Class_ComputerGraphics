// HaoyuView.cpp : implementation of the CHaoyuView class
//

#include "stdafx.h"
#include "Haoyu.h"

#include "HaoyuDoc.h"
#include "HaoyuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView

IMPLEMENT_DYNCREATE ( CHaoyuView, CView )

BEGIN_MESSAGE_MAP ( CHaoyuView, CView )
    //{{AFX_MSG_MAP(CHaoyuView)
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    //}}AFX_MSG_MAP
    // Standard printing commands
    ON_COMMAND ( ID_FILE_PRINT, CView::OnFilePrint )
    ON_COMMAND ( ID_FILE_PRINT_DIRECT, CView::OnFilePrint )
    ON_COMMAND ( ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView construction/destruction

CHaoyuView::CHaoyuView() {
    // TODO: add construction code here

}

CHaoyuView::~CHaoyuView() {
}

BOOL CHaoyuView::PreCreateWindow ( CREATESTRUCT& cs ) {
    // TODO: Modify the Window class or styles here by modifying
    //  the CREATESTRUCT cs

    return CView::PreCreateWindow ( cs );
}

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView drawing

void CHaoyuView::OnDraw ( CDC* pDC ) {
    CHaoyuDoc* pDoc = GetDocument();
    ASSERT_VALID ( pDoc );
    // TODO: add draw code for native data here
	/*
    ////////// 通用准备工作 //////////
    //定义矩形
    CRect rect;
    //获得客户区矩形的大小
    GetClientRect ( &rect );
    //自定义坐标系
    pDC->SetMapMode ( MM_ANISOTROPIC );
    //设置窗口比例
    pDC->SetWindowExt ( rect.Width(), rect.Height() );
    //设置视区比例，且x轴水平向右，y轴垂直向上
    pDC->SetViewportExt ( rect.Width(), -rect.Height() );
    //设置客户区中心为坐标系原点
    pDC->SetViewportOrg ( rect.Width() / 2, rect.Height() / 2 );
    //矩形与客户区重合
    rect.OffsetRect ( -rect.Width() / 2, -rect.Height() / 2 );
	*/
}

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView printing

BOOL CHaoyuView::OnPreparePrinting ( CPrintInfo* pInfo ) {
    // default preparation
    return DoPreparePrinting ( pInfo );
}

void CHaoyuView::OnBeginPrinting ( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ ) {
    // TODO: add extra initialization before printing
}

void CHaoyuView::OnEndPrinting ( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ ) {
    // TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView diagnostics

#ifdef _DEBUG
void CHaoyuView::AssertValid() const {
    CView::AssertValid();
}

void CHaoyuView::Dump ( CDumpContext& dc ) const {
    CView::Dump ( dc );
}

CHaoyuDoc* CHaoyuView::GetDocument() { // non-debug version is inline
    ASSERT ( m_pDocument->IsKindOf ( RUNTIME_CLASS ( CHaoyuDoc ) ) );
    return ( CHaoyuDoc* ) m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHaoyuView message handlers

void CHaoyuView::OnLButtonDown ( UINT nFlags, CPoint point ) {
    // TODO: Add your message handler code here and/or call default

    CView::OnLButtonDown ( nFlags, point );
    this->FIN = point;

}

void CHaoyuView::OnLButtonUp ( UINT nFlags, CPoint point ) {
    // TODO: Add your message handler code here and/or call default

    CView::OnLButtonUp ( nFlags, point );
    this->STA = point;
    CDC* pDC = GetDC();

    int i, j;
    int tx, ty, tsta, tfin, dx, dy;
    double k = 0, d, dd;
    if ( this->STA.x > this->FIN.x ) {
        CPoint tpoint;
        tpoint = this->STA;
        this->STA = this->FIN;
        this->FIN = tpoint;
    }
    if ( ( this->STA.x == this->FIN.x ) || ( this->STA.y == this->FIN.y ) ) {
        if ( this->STA.x == this->FIN.x ) {
            tsta = min ( this->STA.y, this->FIN.y );
            tfin = max ( this->STA.y, this->FIN.y );
            tx = this->STA.x;
            for ( j = tsta; j < tfin; j++ ) {
                pDC->SetPixelV ( tx, j, RGB ( 0, 0, 0 ) );
            }
        }

        if ( this->STA.y == this->FIN.y ) {
            tsta = this->STA.x;
            tfin = this->FIN.x;
            ty = this->STA.y;
            for ( i = tsta; i < tfin; i++ ) {
                pDC->SetPixelV ( i, ty, RGB ( 0, 0, 0 ) );
            }
        }
    } else {
        dx = this->FIN.x - this->STA.x;
        dy = this->FIN.y - this->STA.y;
        k = ( double ) dy / ( double ) dx;
		if (abs(dx)==abs(dy)){
			tsta = this->STA.x;
            tfin = this->FIN.x;
			ty=ty = this->STA.y;
			int delta;
			delta=(dy<0?-1:1);
			for (i=tsta;i<tfin;i++){
				pDC->SetPixelV ( i, ty, RGB ( 0, 0, 0 ) );
				ty+=delta;
			}
		}else{
			 if ( abs ( dx ) >= abs ( dy ) ) {
            tsta = this->STA.x;
            tfin = this->FIN.x;
            ty = this->STA.y;
			d=0;
            if ( dy > 0 ) {
                for ( i = tsta; i < tfin; i++ ) {
					pDC->SetPixelV(i,ty,RGB ( 255*d, 255*d, 255*d ));
					pDC->SetPixelV(i,ty+1,RGB ( 255*(1-d), 255*(1-d), 255*(1-d) ));
					d=d+k;
					if (d>=1){
						d=d-1;
						ty++;
					}
                }
            } else {
                for ( i = tsta; i < tfin; i++ ) {
					pDC->SetPixelV(i,ty,RGB ( 255*d, 255*d, 255*d ));
					pDC->SetPixelV(i,ty+1,RGB ( 255*(1-d), 255*(1-d), 255*(1-d) ));
					d=d+k;
					if (d<=-1){
						d=d+1;
						ty--;
					}
                }
            }
        } else {
			tsta = this->STA.y;
            tfin = this->FIN.y;
            tx = this->STA.x;
			d=0;
			if ( dy >= 0 ) {
                for ( i = tsta; i < tfin; i++ ) {
					pDC->SetPixelV(tx,i,RGB ( 255*d, 255*d, 255*d ));
					pDC->SetPixelV(tx+1,i,RGB ( 255*(1-d), 255*(1-d), 255*(1-d) ));
					d=d+(1/k);
                    if (d>1){
						d=d-1;
						tx++;
					}
                }
            } else {
                for ( i = tsta; i > tfin; i-- ) {
					pDC->SetPixelV(tx+1,i,RGB ( 255*d, 255*d, 255*d ));
					pDC->SetPixelV(tx,i,RGB ( 255*(1-d), 255*(1-d), 255*(1-d) ));
					d=d+(1/k);
                    if (d<=-1){
						d=d+1;
						tx++;
					}
                }
            }
        }
		}

    }
	//pDC->SetPixelV ( this->FIN.x, this->FIN.y, RGB ( 0, 0, 0 ) );
    ReleaseDC ( pDC );
}
