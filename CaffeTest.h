#pragma once
//std
#include <string>
#include <sstream>
//3rd
#include "opencv2/opencv.hpp"

inline std::string convertUtf16ToLocal(const wchar_t charTxt)
{
	std::wstring srcData;
	srcData += charTxt;
	char result[2 + 1];
	const int len = wcstombs(result, srcData.c_str(), 2);
	result[2] = '\0';
	return result;
}

template <typename SRC_TYPE,typename DST_TYPE>
DST_TYPE convert(const SRC_TYPE& data)
{
	std::stringstream ss;
	ss << data;
	DST_TYPE result;
	ss >> result;
	return result;
}
class CaffeTester
{
public:
	CaffeTester();
	~CaffeTester();
	bool loadModel(const std::string& deployPath, const std::string& modelPath, const std::string& labelSetFilePath);
	int recognize(const cv::Mat& srcGrayImg);
private:
	void release();
private:
	void* handler = nullptr;
};