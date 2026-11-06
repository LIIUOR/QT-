#pragma once
#include <qimage.h>
#include <string>
class Interface{
public:
    Interface(QImage image):currentImage(image){};
    ~Interface(){};
    void ShowMainMenu();
    void InputUserInput();
    void callShowFilterList();
    void callSaveImage(const std::string& fileName);
    void callOpenImage(const std::string& fileName);
    void callApplyFilters(const std::string& filterName);
private:
    void ShowFilterList();
    void SaveImage(const std::string& fileName);
    void OpenImage(const std::string& fileName);
    void ApplyFilters(const std::string& filterName);
    QImage currentImage;
    QImage currentImage1;
};