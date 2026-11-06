#include <QImage>
#include <qimage.h>
#include "Interface.h"
#include "Intreface.cpp"
int main(int argc, char ** argv){
    QImage image("B9UEKY0.gif");
    Interface app(image);
    app.ShowMainMenu();
    // if(argc>=2){
    //     QImage image(argv[1]);
    //     Filters::LoopForFilters(image,Filters::Sepia);
    //     image.save("Sepia.png");

    //     QImage image1(argv[1]);
    //     Filters::LoopForFilters(image1,Filters::Luminosity);
    //     image1.save("Luminosity.png");

    //     QImage image2(argv[1]);
    //     Filters::LoopForFilters(image2,Filters::Brightness);
    //     image2.save("Brightness.png");

    //     QImage image3(argv[1]);
    //     Filters::LoopForFilters(image3,[](const QColor& color){
    //         return Filters::Contrast(color,1.5f);
    //     });
    //     image3.save("Contrast.png");

    //     QImage image4(argv[1]);
    //     Filters::LoopForFilters(image4,Filters::Invert);
    //     image4.save("Invert.png");


    //     QImage image10(argv[1]);
    //     Filters::LoopForFilters(image10,[](const QColor& color){
    //         return Filters::Threshold(color,155);
    //     });
    //     image10.save("Threshold.png");

    //     QImage image11(argv[1]);
    //     Filters::LoopForFilters(image11,Filters::Posterize);
    //     image11.save("Posterize.png");

        
    //     QImage image12(argv[1]);
    //     QImage image13=FiltersMatrix::LoopForMatrix(image12, matrixForBlur);
    //     image13.save("Blur.png");


    //     QImage image15=FiltersMatrix::LoopForMatrix(image12,matrixForSharpen);
    //     image15.save("Sharpen.png");


    //     QImage image16=FiltersMatrix::LoopForMatrix(image12, matrixForEmboss);
    //     image16.save("Emboss.png");


    //     QImage image17=FiltersMatrix::LoopForMatrix(image12, matrixForLaplacian);
    //     image17.save("Laplacian.png");


    //     QImage image18=FiltersMatrix::LoopForMatrix(image12, matrixForEdgeDetectionX,matrixForEdgeDetectionX);
    //     QImage image19=FiltersMatrix::LoopForMatrix(image12, matrixForEdgeDetectionX);
    //     QImage image20=FiltersMatrix::LoopForMatrix(image12, matrixForEdgeDetectionY);
    //     image19.save("OutputImage/DetX.png");
    //     image20.save("DetY.png");
    //     image18.save("EdgeDetection.png");
    // }
    return 0;
}