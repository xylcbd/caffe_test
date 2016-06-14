#ifndef __SAMPLE_GENETATOR_H__
#define __SAMPLE_GENETATOR_H__

#include <string>
#include <opencv2/opencv.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H

class SampleGenetator 
{
public:
	SampleGenetator(const std::string fontPath,const int textHeight);
    ~SampleGenetator();
	cv::Mat SampleGenetator::genSample(const wchar_t wc, const unsigned char bgColor, const unsigned char fgColor);
private:
    FT_Library library;
    FT_Face face;
};

#endif //__SAMPLE_GENETATOR_H__

