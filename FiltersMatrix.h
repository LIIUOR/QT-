#pragma once 
#include <QImage>
#include <cmath>
#include <qcolor.h>
#include <qimage.h>
#include <qminmax.h>
#include <vector>
#include <optional>
std::vector<std::vector<double>> matrixForBlur={
            {1.f/16,2.f/16,1.f/16},
            {2.f/16,4.f/16,2.f/16},
            {1.f/16,2.f/16,1.f/16}        
};
std::vector<std::vector<double>> matrixForSharpen={
    {-1,-1,-1},
    {-1,9,-1},
    {-1,-1,-1}
};
std::vector<std::vector<double>> matrixForEdgeDetectionX={
    {-1,0,1},
    {-2,0,2},
    {-1,0,1}
};
std::vector<std::vector<double>> matrixForEdgeDetectionY={
    {-1,-2,-1},
    {0,0,0},
    {1,2,1}
};
std::vector<std::vector<double>> matrixForEmboss={
    {-2,-1,0},
    {-1,1,1},
    {0,1,2}
};
std::vector<std::vector<double>> matrixForLaplacian={
    {0,1,0},
    {1,-4,1},
    {0,1,0}
};
void ApplyMatrix(int& i,int& j,const QImage& image,int& newR,int& newG,int& newB,int& newR1,int& newG1,int& newB1,std::vector<std::vector<double>>& matrix,std::optional<std::vector<std::vector<double>>> matrix2=std::nullopt){
    for(int x=-1;x<2;++x){
        for(int y=-1;y<2;++y){
            QColor color=image.pixelColor(i+x,j+y);
            newR += color.red()*matrix[x+1][y+1];
            newG += color.green()*matrix[x+1][y+1];
            newB += color.blue()*matrix[x+1][y+1];
            if(matrix2.has_value()){
                newR1+=color.red()* (*matrix2)[x+1][y+1];
                newG1+=color.green()* matrix2.value()[x+1][y+1];
                newB1+=color.blue()* matrix2.value()[x+1][y+1];
            }
        }
    }
};
void NormalizeRGB(int& newR,int& newG,int& newB){
    newR=qBound(0, newR, 255);
    newG=qBound(0, newG, 255);
    newB=qBound(0, newB, 255);
};
namespace FiltersLoop{
    //? попробовать соединить два ЛУПА(для матриц и просто картинок)
    QImage LoopForImage(const QImage& image,std::optional<QColor(*)(const QColor&)> func=std::nullopt,std::optional<std::vector<std::vector<double>>> matrix=std::nullopt,std::optional<std::vector<std::vector<double>>> matrix2=std::nullopt){
        QImage newImage{image.width(),image.height(),QImage::Format_RGB888};
        if(func.has_value()){
            for(int x=0;x<image.width();++x){
                for(int y=0;y<image.height();++y){
                    QColor currColor=newImage.pixelColor(x, y);
                    QColor newColor=(*func)(currColor);
                    newImage.setPixelColor(x, y,newColor);
                }
            }
            return newImage;
        }
        for(int i=1;i<image.width()-1;++i){
            for(int j=1;j<image.height()-1;++j){
                int newR=0,newG=0,newB=0;
                int newR1=0,newG1=0,newB1=0;
                ////отдельная функция от
                ApplyMatrix(i,j,image,newR,newG,newB,newR1,newG1,newB1,*matrix,matrix2);
                ////до
                if(!matrix2.has_value()){
                    ////нормализация
                    NormalizeRGB(newR,newG,newB);
                    ////
                }else{
                    newR+=sqrt(pow(newR,2)+pow(newR1,2));
                    newG+=sqrt(pow(newG,2)+pow(newG1,2));
                    newB+=sqrt(pow(newB,2)+pow(newB1,2));
                    ////нормализация
                    NormalizeRGB(newR,newG,newB);
                    ////
                }
                newImage.setPixelColor(i, j,QColor {newR,newG,newB});
            }
        }
        return newImage;
    }
};