#include <stdio.h>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include <vector>
#include <iostream>
#include "stdafx.h"
using namespace cv;


int main(int argc, _TCHAR* argv[])
{

	//cria estrutura para armazenar extratores - tipo SURF
	cv::Ptr<DescriptorExtractor> extractor = DescriptorExtractor::create("SURF");











	return 0;
}