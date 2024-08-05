
#ifndef DRAW_HH
#define DRAW_HH

#include <THStack.h>
#include <TLegend.h>
#include <netinet/in.h>
#include <iostream>
#include <iomanip>
#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>
#include <TTree.h>
#include <TGraph.h>
#include <TApplication.h>
#include <vector>
#include <math.h>


void draw1D(TH1* h){   //一维图

    h->GetYaxis()->CenterTitle();
    h->GetXaxis()->SetTitleFont(22);
    h->GetYaxis()->SetTitleFont(22);
    h->GetXaxis()->SetTitleSize(0.05);
    h->GetYaxis()->SetTitleSize(0.05);
    h->GetXaxis()->SetTitleOffset(1.0);
    h->GetYaxis()->SetTitleOffset(1.0);
    h->GetXaxis()->SetLabelFont(22);
    h->GetYaxis()->SetLabelFont(22);
    h->GetXaxis()->SetLabelSize(0.05);
    h->GetYaxis()->SetLabelSize(0.05);

    h->SetLineWidth(3);
    h->SetStats(0);//不要Stats信息   标准差方差平均值等

    //h->GetXaxis()->SetTitle("");

    h->GetYaxis()->SetMaxDigits(3);
}

void draw2D(TH2F* h){       //二维图
    h->GetXaxis()->CenterTitle();
    h->GetYaxis()->CenterTitle();
    h->GetZaxis()->CenterTitle();
    h->GetXaxis()->SetTitleFont(22);
    h->GetYaxis()->SetTitleFont(22);
    h->GetZaxis()->SetTitleFont(22);
    h->GetXaxis()->SetTitleSize(0.05);
    h->GetYaxis()->SetTitleSize(0.05);
    h->GetZaxis()->SetTitleSize(0.05);
    h->GetXaxis()->SetTitleOffset(1.0);
    h->GetYaxis()->SetTitleOffset(1.0);
    h->GetZaxis()->SetTitleOffset(1.5);
    h->GetXaxis()->SetLabelFont(22);
    h->GetYaxis()->SetLabelFont(22);
    h->GetZaxis()->SetLabelFont(22);
    h->GetXaxis()->SetLabelSize(0.05);
    h->GetYaxis()->SetLabelSize(0.05);
    h->GetZaxis()->SetLabelSize(0.05);
    h->SetStats(0);


    h->SetContour(100); // 设置调色板的数量
    h->SetOption("COLZ"); // 启用彩色轮廓  colz2 有底色
    h->GetZaxis()->SetMaxDigits(2);  

  //  h->GetXaxis()->SetTickLength(h->GetYaxis()->GetTickLength()); //设置y和x轴相等
 
}

void drawTC1D(TCanvas*c1){      //一维画布
    c1->SetFrameLineWidth(3);
    c1->SetBottomMargin(0.14);
    c1->SetLeftMargin(0.14);
    //c1->SetRightMargin(0.14);
    c1->SetGrid();
    gStyle->SetGridWidth(3); // 设置网格线的宽度为3像素
}

void drawTC2D(TCanvas*c1){     //二维画布
    c1->SetFrameLineWidth(3);
    c1->SetBottomMargin(0.16);
    c1->SetLeftMargin(0.16);
    c1->SetRightMargin(0.16);
    // c1->SetFixedAspectRatio();
    // c1->SetGrayscale();
    c1->SetGrid();
    gStyle->SetGridWidth(3); // 设置网格线的宽度为3像素
}

void drawTHStack(THStack *h){   //堆叠图

   
    h->GetXaxis()->SetTitleFont(22);
    h->GetYaxis()->SetTitleFont(22);
    h->GetXaxis()->SetTitleSize(0.05);
    h->GetYaxis()->SetTitleSize(0.05);
    h->GetXaxis()->SetTitleOffset(1.0);
    h->GetYaxis()->SetTitleOffset(1.0);
    h->GetXaxis()->SetLabelFont(22);
    h->GetYaxis()->SetLabelFont(22);
    h->GetXaxis()->SetLabelSize(0.05);
    h->GetYaxis()->SetLabelSize(0.05);

}
void drawTLegend(TLegend* l){    //

    l->SetBorderSize(0);
    l->SetTextSize(0.04);//字体大小
    l->SetFillStyle(0);//不填充背景
    l->SetTextAlign(32);//靠右对齐
    l->SetTextFont(22);//字体
    
}
#endif // DRAW_H