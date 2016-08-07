#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include <vector>

using namespace cv;



//Ler imagens e armazenar

Mat img_1 = imread("C:/cu.jpg",CV_LOAD_IMAGE_GRAYSCALE);
Mat img_2 = imread("C:/cu.jpg",CV_LOAD_IMAGE_GRAYSCALE);

//Ptr faz lista dinâmica do tipo descritor de extratores - SURF
cv::Ptr<DescriptorExtractor> extractor = DescriptorExtractor::create("SURF");

//declara o detector
SurfFeatureDetector detector(500);




