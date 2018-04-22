//
//  morphologicalTransformations.cpp
//  Morphological transformations
//
//  Created by Артём Семёнов on 04.04.2018.
//  Copyright © 2018 Артём Семёнов. All rights reserved.
//

#include "morphologicalTransformations.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
using namespace cv;

void morphologicalTransformationsBase::showCurrentVersion() {
    imshow(nameWindow, image); // выводим изображение.
    waitKey(); // ждём нажатия клавиши.
    destroyWindow(nameWindow); // уничтожаем окно.
}

morphologicalTransformationsBase::~morphologicalTransformationsBase() { 
    image.deallocate(); // освобождаем память.
}

morphologicalTransformationsBase::morphologicalTransformationsBase(std::string fileName) { 
    image = imread(fileName, IMREAD_GRAYSCALE); // загрузка изображения в оттенках серого.
    nameWindow = "First image";
}

cv::Mat &morphologicalTransformationsBase::extractImage() { 
    return image; // вернуть ссылку на исходное изображение.
}

void morphologicalTransformationsBase::importImage(cv::Mat& matrix) {
    image = matrix; // засасываем изображение.
}

void morphologicalTransformationsBase::exportToDisk(std::string filePath, cv::Mat &matrix) {
    filePath = filePath + "result.jpg";
    imwrite(filePath, matrix);
}

