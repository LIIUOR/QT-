#pragma once
#include <QImage>
#include <cmath>
namespace Filters{
    QColor Sepia(const QColor& color){
        int newR=qMin(255,static_cast<int> (color.red()*0.393+color.green()*0.769+color.blue()*0.189));
        int newG=qMin(255,static_cast<int> (color.red()*0.349+color.green()*0.686+color.blue()*0.168));
        int newB=qMin(255,static_cast<int> (color.red()*0.272+color.green()*0.534+color.blue()*0.131));
        return QColor(newR,newG,newB);
    }
    QColor Luminosity(const QColor& color){
        int Gray=0.2126*color.red()+0.7152*color.green()+0.0722*color.blue();
        return QColor(Gray,Gray,Gray);
    }
    QColor Brightness(const QColor& color){
        int brightness_offset=-50;
        int newR=qMin(255,qMax(0,color.red()+brightness_offset));
        int newG=qMin(255,qMax(0,color.green()+brightness_offset));
        int newB=qMin(255,qMax(0,color.blue()+brightness_offset));
        return QColor(newR,newG,newB);
    }
    QColor Contrast(const QColor& color,float factor){
        int brightness_offset=50;
        int newR=qMin(255,qMax(0,static_cast<int>(factor*(color.red()-128)+128+brightness_offset)));
        int newG=qMin(255,qMax(0,static_cast<int>(factor*(color.green()-128)+128+brightness_offset)));
        int newB=qMin(255,qMax(0,static_cast<int>(factor*(color.blue()-128)+128+brightness_offset)));
        return QColor(newR,newG,newB);
    }
    QColor Invert(const QColor& color){
        int newR=255-color.red();
        int newG=255-color.green();
        int newB=255-color.blue();
        return QColor(newR,newG,newB);
    }
    QColor Threshold(const QColor& color,int threshold){
        int newR=(color.red()>=threshold)? 255 : 0;
        int newG=(color.green()>=threshold)? 255 : 0;
        int newB=(color.blue()>=threshold)? 255 : 0;
        return QColor(newR,newG,newB);
    }
    QColor Posterize(const QColor& color){
        const int levels=64;
        int newR=qMin(255,static_cast<int>(std::round(color.red()/levels)*levels));
        int newG=qMin(255,static_cast<int>(std::round(color.green()/levels)*levels));
        int newB=qMin(255,static_cast<int>(std::round(color.blue()/levels)*levels));
        return QColor(newR,newG,newB);
    }
};