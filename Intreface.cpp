#include "FiltersMatrix.h"
#include "Filters.h"
#include "Interface.h"
#include<iostream>
#include <optional>
#include <qhashfunctions.h>
enum class UserAction{
    OpenImage,
    SaveImage,
    ShowFilterList,
    ApplyFilters
};
enum class FiltersName{
    Blur,
    Brightness,
    Contrast,
    DetX,
    DetY,
    EdgeDetection,
    Emboss,
    Invert,
    Laplacian,
    Luminosity,
    Posterize,
    Sepia,
    Sharpen,
    Theshold
};
void Interface::callSaveImage(const std::string& fileName) {
    SaveImage(fileName);
}
void Interface::callOpenImage(const std::string& fileName){
    OpenImage(fileName);
}
void Interface::callShowFilterList(){
    std::cout<<"Список фильтров:"<<std::endl;
    ShowFilterList();
}
void Interface::callApplyFilters(const std::string& filterName){
    ApplyFilters(filterName);
    std::cout<<"Фильтр применен"<<std::endl;
}
void Interface::ShowFilterList(){
    std::cout<<static_cast<int>(FiltersName::Blur)<<"Blur"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::Brightness)<<"Brightness"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::Contrast)<<"Contrast"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::DetX)<<"DetX"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::DetY)<<"DetY"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::EdgeDetection)<<"EdgeDetection"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::Emboss)<<"Emboss"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::Invert)<<"Invert"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::Laplacian)<<"Laplacian"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::Luminosity)<<"Luminosity"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::Posterize)<<"Posterize"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::Sepia)<<"Sepia"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::Sharpen)<<"Sharpen"<<std::endl;
    std::cout<<static_cast<int>(FiltersName::Theshold)<<"Threshold"<<std::endl;
}
void Interface::ApplyFilters(const std::string& filterName){
    QImage image1;
    switch (static_cast<FiltersName>(std::stoi(filterName))) {
        case FiltersName::Blur: 
            FiltersLoop::LoopForImage(currentImage,std::nullopt,matrixForBlur); break;
        case FiltersName::Brightness: 
            FiltersLoop::LoopForImage(currentImage,Filters::Brightness); break;
        case FiltersName::Contrast: 
            FiltersLoop::LoopForImage(currentImage,[](const QColor& color){
                return Filters::Contrast(color, 1.5f);
            }); 
            break;
        case FiltersName::DetX: 
            FiltersLoop::LoopForImage(currentImage,std::nullopt,matrixForEdgeDetectionX);
            break;
        case FiltersName::DetY:
            FiltersLoop::LoopForImage(currentImage,std::nullopt,matrixForEdgeDetectionY);
            break;
        case FiltersName::EdgeDetection:
            FiltersLoop::LoopForImage(currentImage,std::nullopt,matrixForEdgeDetectionX,matrixForEdgeDetectionY);
            break;
        case FiltersName::Emboss:
            FiltersLoop::LoopForImage(currentImage,std::nullopt,matrixForEmboss);
            break;
        case FiltersName::Invert: 
            FiltersLoop::LoopForImage(currentImage,Filters::Invert); break;
        case FiltersName::Laplacian:
            FiltersLoop::LoopForImage(currentImage,std::nullopt,matrixForLaplacian);
            break;
        case FiltersName::Luminosity: 
            FiltersLoop::LoopForImage(currentImage,Filters::Luminosity); break;
        case FiltersName::Posterize: 
            FiltersLoop::LoopForImage(currentImage,Filters::Posterize); break;
        case FiltersName::Sepia: 
            FiltersLoop::LoopForImage(currentImage, Filters::Sepia); break;
        case FiltersName::Sharpen: 
            FiltersLoop::LoopForImage(currentImage,std::nullopt,matrixForSharpen);
            break;
        case FiltersName::Theshold: 
            FiltersLoop::LoopForImage(currentImage,[](const QColor& color){
                return Filters::Threshold(color,155);
            });
            break;
        default:
            break;
    }
}
void Interface::OpenImage(const std::string &fileName){
    currentImage.load(QString::fromStdString(fileName));
}
void Interface::SaveImage(const std::string &fileName){
    currentImage.save(QString::fromStdString(fileName));
}
void Interface::ShowMainMenu(){
    std::cout<<"Выберите действие"<<std::endl;
    std::cout<<static_cast<int>(UserAction::OpenImage)<<"Загрузить изображение"<<std::endl;
    std::cout<<static_cast<int>(UserAction::SaveImage)<<"Сохранить изображение"<<std::endl;
    std::cout<<static_cast<int>(UserAction::ShowFilterList)<<"Показать фильтры"<<std::endl;
    std::cout<<static_cast<int>(UserAction::ApplyFilters)<<"Применить фильтр"<<std::endl;
    InputUserInput();
}
void Interface::InputUserInput(){
    std::string userInput;
    std::getline(std::cin,userInput);
    switch(static_cast<UserAction>(std::stoi(userInput))){
        case UserAction::OpenImage:
            std::cout<<"Введите путь до изображения: ";
            std::getline(std::cin,userInput);
            callOpenImage(userInput);
            break;
        case UserAction::SaveImage:
            std::cout<<"Введите путь для сохранения: ";
            std::getline(std::cin,userInput);
            callSaveImage(userInput);
            break;
        case UserAction::ShowFilterList:
            callShowFilterList();
            break;
        case UserAction::ApplyFilters:
            std::cout<<"Введите фильтр для применения: ";
            std::getline(std::cin,userInput);
            Interface::callApplyFilters(userInput);
            break;
        default:
            break;
    }
}