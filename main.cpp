//std
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <cstdint>
#include <functional>
#include <thread>
#include <mutex>
#include <memory>
#include <iomanip>
#include <sstream>
#include <map>
#include <clocale>
//own
#include "SampleGenetator.h"
#include "scopeExit.h"
#include "CaffeTest.h"

static const unsigned char bgColor = 0;
static const unsigned char fgColor = 255;

//label:0-?
//content:xxx
static std::map<int, wchar_t> getChineseTable()
{
	static const std::wstring chineseTable = L"��һ�ǲ�����������������������ϴ�Ϊ�͹��ص���˵ʱҪ�ͳ����Ҳ������ܶ����ǵ���������֮������������õ�����Ȼ�����³ɷ��ྭôȥ��ѧ�綼ͬ�ֵ�û�����𿴶���ֻ�����С����Щ������������ǰ������ֻ����ʵ�վ������������볤�ѻ�ʮ��ڹ����ѹ�ʹ������֪ȫ���ֹص���ҵ�⽫���߼����ʺ����ز�����Ӧս��ͷ���������������ʲ���Ȳ����¼����������˹�»��ϻ��ش����ű��ϸ���λ�ζ����γ��Ⱥ�ͨ�̶�ԭ������������Ա��ˮ�����۴�������뼸������ƽϵ�����������Ů�������ܺε������ٱ��Žᷴ��Ŀ̫���ٸн������ӱس����ƹ�����ֱ������ɽ��ָ����ͳ�������������վ���չ���˾��������������ȴ�����ǿ��������Ȩ˼��������ʽɫ·����Ʒס������ݳ̱������Ÿý�����ȡ�����������칲ȷ��ʦ�������Ժ��ʶ���������Ц�ɷ粽���ո�������������ÿ�ó��׼��ַ��������ԪӢʿ֤��ʧת����׼��ʼ���ش�δԶ��̨��Ӱ�����ְ����������������������ż�����ۻ�������ʯ������������뼼��Լʾ����Ϣ�����ƹٻ�Ͼ���֧����Խ�������������д����˹����Ƭʷί��������������ũ��װ���԰ɰ����̸��ͼ����������ҽ��ͻר�Ѻž����ܽ�ע�����������ѡ������������Ʋ�ϣ���ڹ��������Ͷĳ����ά�ﻮ���³�����̬�������ɺ�����Ӫ�ǹ�������־��վ�ϰ������幩Ч��ʩ���������մ���ƾ����ĸ��������Ⱥ��ʰ�����Χ��֯����˫���ͼͲɾ�ɱ�������ܵͳ�����ֹϸԸǧֵ����Ǯ�������������������޴���ְ�ٿ��ַ����ë״������������µ�У�ഴ�پô��ӡ�����Թ�����Ԥ˭��������΢����ͼ�Ѫ������ҩ�ʲ�ҹʡ��ϲ��Դʳ�մ���½ϰ�þ��Ͳƻ��Ÿ��ɻ��׾���ģ�为��ͣľ�������ɲ����޳����Է��������켤��������ݼ����е��ݾ��˼������ڻ���ʹ����Э��ռ������Ƥ��ʤ�����������������������ѹ�����������ִ���ҿ���׷�������꺽�Ź�����������˰���ҷݴ��ձ���ݽŸŶ��ٸ��ؾƵ����л��������������汦���;��˵ܵǻ���������ŷ����Σæ�˰���黵����������������¶����ζҰ����ɳ�������������弪������ϲ��������ɢ����������ȹ�ǹȱ¥���к������󻭰�����������ƿ��Ź�ϯ����л³�������Ҿ�����ʫ�ظϾ�Ʊ������ھɶ�̽��¼Ҷ���總���������ѽ��ͥ���龦���˳��ҡ�л��Ѳ�ν�����������������Ī�����ʴ�ʥ��Ѱ��˯��������ŵ�װ���������ը���彡���Թ��Ƚ������԰ı�α�ץ�ٹ�����������������ѩ����ү��ƪ����ݱ鷲������̹ţ��ֽ��ѵ˽ׯ��˿����ɭ��Ĭ��Ϸ����Ƿ����ɸ���������������̰�����Ū�������ڴ�ӵͽķ������Ȥ������ӭ��������������͸������Ŭ�ݻ���;��������Ѹ��ó��Ψ���ֿ⼣�Ⱦ��ִ���������ΰ�鴨�껺Ǳ���۵���������찣����ֲ������ҳ������֣��������쳼����Ⱦʢŭ��Բ�����ղ������ԳϿ����Ͱ�÷����Ħ��ĩ�˱��Ķ���Ӳ�󽯲��趩�ʳ���ħ���غ�Υ���˻�ҷ���������������Ԯ������վ��ƫ���´��ξ��޶�ǽ��Ϯ���������ɲຫðծ���ڹ����ͯ�̳˹ҽ��ܺ�����Ѷ�泹���ɱ�������ϴ�껼�����ǩ�ɱ�֢������������۲˱շ��쳷��輲Ե���ʶ��̼�����β��͵�����פ���˰��ŵ���޷�����̾�����������վ۾�ǡ�����Ҳ�����Ļӳ��̩�������������ݹ����ĳ��������±���������������������Ż��ֺ��ȵ����ױ���������ƶż�������Ȧ���������ͧ�Գ����Ͼ����������������̧���������������ضܱ����﷦¡��ū��ɥ�۶������ƾ�������ּ����÷ƽ��������ҵ�������Ϥ�ٷ���׳����ɨ����ֳ��ì���ʷ���ʣ��������Һ����������������ü�Ǹ���������ͦ�����Ҽ��������豲���컬ȯ���������������ĺ�֦��īв�������������ƭ���ý���������ϧ�ں���Ծʬ����ʻ�������ݲᴢƮɣ�вҽ��ٲ���Ƶ��ĥ��аײ�����Ѳ�ռ����������ƽ�ȼ����α�������Ļ�Ȱ�����ڽ��Ư���ܶ��������ϸ��׼�������������Ũ�����񸹵��ߴ�����ò�����������������δ������ɸֹ��ķ��̵��پ�ѯ�����ʳ��һ��ο�͢�Ķ�Ǩ��ο��������ԹЬ����ȪӿϽ����ϼ�κ��ף���ºݼ�еҧ�ڳ༷������������������è�������ǣ���������ּ���Ա��ߺ�������ɪ����ѷ���۶���˥ƿ���������ǳ���¬�̹���ң�������븧ǳ�ؾ��꾧��Ͽ��������þ���Ϳ������ú�ܹ�ʪѭů�Ǹ�����ñ����̤��Ԭ������β�����������Ŧ�Ʋ����ͭ�ݿ�Ѻ��Įƣ��ǲ����ȭ��б��ϡ�ݷ����߶����ڻ��̺갩��������ҫŤ̳�ֲ��淥���͹�����Ĺ������ƴ��׽��ˢ���ӹ�Ъ�����鴮�޽ɻ�Ӯ���Ұ����ݴ���βտ�ַ�Ӹ����������լ���ں��������������������ҷ�̰���������������ֹ�ö������˧������������޵������˲����Ӵ��Ӷ���ƥ������ǻ����������糦��������ӥ��������ĵ��ټ��Ǻ���Ѩ��׿����Ĥ��Ƿ������ã��Ѧ���ԥθ�����ʰ����Я������������ǿ��ǰ���ഭ�ֲ�¯������̥���߽�ιɵĽ����ȹ���������Ǭ����ͤϦ���������ѷ�й�˰�ɮ����������Ф��ϼ��ԣ��ժ�����������������轮����η���Ҳ���������ߵɵ�©�ְ�����¹����������̲�޴߳��������͹��Ȳ����ä��ɶ�ͳ���ĨͲ��㰦�Ӹ����ĺ������������������˳��óý�ӯ�̳�˲ӤТ�������±γ���ξ������Ѽ�����������ر���ɩ��̷��ӹǸ֥������̯���Խ��¾���������̴�н�ܳܽ����켢�β�������Ƽ��׬���賫��ݺ�������Ԩ��Ϫ������Ԣ��ɡ�˱�Ų��֬�ѿ�����ʨ�����ο�����������Ƣ�۳ռ�����������ž��ɧ����ճ����İխ�����½�ɲ��â��Ƹ������������ˣ�����ÿ��Ķ��Ѻ�ˤ�����������ͻ���׹ɷ�������´����̰�ԡ�Ļ�����ƨ������׫Х��õ˶����ϥҦï����Գկˡ���ݳ�����̺����۳��÷��ξ뺭ȸѮ˺��֫¢����é����Ҥ��ǫ����ѫ�ν�������ש������Ķ������צ���������̿��գ��£�Ⱦ�����ˬ������ڹ����ݹ�����������ϱ��Ϲԩѻ��������մթի�����ɷĹ�Ͱ���̸���г�ݹ�϶�����ٶ�ù�������ɴȹ�����������ʲ�Ʃ���������������������׵���������ܴ���ն���������ƹ�������²����«ƻж��Կ�굻�����������ĸ�׮����Ȣĭɤ���Է����ϳ������������̾ձ��Ƕ���ӱм�Ϻ���ͺ��Ӵ����Ǵ�����ͱлб���о֭��¿�ྸӶµ������������ɺ���а����������鴱�ܻ߶ò��ع��︿�����������俱�����鳴�ӳ�����������ʿ�ҥį˦������ؤӾ���ⶣ�����������������ʴ��ܽ����ɹ˪���̻��������ױ��Ǧ�������������Ȯ��������ּյ�ļ����ª��ֶŰ��Ө�Ʒ��ʿ�ྥ�����޽�����ť�׹���и�����ȸ�����γ���г��˸��Ȱ���׾��̺ͩɰкçƺ��ɼ������Ӭ�굷���۽��ٻ�����ѿ��̼�����������ȿ���̶�������ή����Ͼ���������ĺ�ý븫������˻������ɾӣ�����ҰӲϷ�����ұ�ӱ�§�����������յ��֨�������ʸ������Ю������ѱ����̱������Ƨ��Ƕ������ɬ�ʱĽ�߶���Ϻ��ơ����Ż��͹Ϩ�Ѱ������Ž����鼬���������Ⱦ���Ʋ�ڷ๶��������ƴ�����ݺ���������������������է������Ϲ�����������®����¶�Ϳ���˨���ð����Ѵ������ƽ����л�����հ­�𵿺��������̭���⿻��ſ�����������Ⱥ������̿Ĳ�դ����Ѭĵ׺���淾�鱹ġ������ֿ�����������������ֲ׵�����������Ĵ�洧ո�Ͽ�Ǣ�ٳ�̵֩����з����̲���ϻå��׶���ܿ����㺷�һ޴׾�ز���޻���������±�ѥ�洯����꽴���ܽ�̦����Ͽ������Ⱦ����Ի��������뻾�����ز��Ѷ��ͱ���ƴ������������������ֺ�尰��˩��ų���š��������ε��ջޱ��������ߴ��Ρ�����ް������������������ݷ㿽��έ�����Ȱ��߱躿�ϵ���˲�ذ���ͺ�����������¸�ܻȿ���բ����������������������ѳ�������������������߳��ٹ贶����ʺ������ǯ�й���Ÿ���Ź��ڽ�ͱ���������Ÿ��ŧ�����ϲ�����ɸ�˱Բ��ض���ӫ������ج��������Ǻ��̴���Ծ�ө��������Ⲻƹ��ձ��ɦ�����ᰪ������ӽ������ƴ����쵪���ߴ���Ϭ��������ê��Ҿ��㾻��������������ȵ��Ģ��п��ᣰ����̳�������ߺ�մ�Φ������̻���׸�ٿ������������Ҹ�����Ӹ�魼������˰�Ȭ������������������߽�������ե����ҿ�̣�����޾���˱�������������Ϻ���ͫư�۳Ӷ���±���޵�����Ѵ���󲳹��ڹ�������﷤���Ͳ�����Ͱ��ü�������������������ԯ����ղ���Ш���������Ҵԧ�տ�����ӻ�Ϸ��ĸ�����źЫҬ��Ţ���ȳպ�����������Ӽ����ǭ���ѽ���ʭ¨���׻���ű���������¦�����԰���᫾�Ѣ����ͮ���Ǻ�����򼶻�����Ǽ�����Ÿ�ӧ����ű�ٿ��������ﴻ�궧��Ŵ�����������������������꼸̻��Ҩ���Ҳ��Ʋt���������������������ա������辿��̲����Ⱥ�黷���ɻ������Ҽ������ϳ����ﱱ��Ա�����ȿ��������í�����ް����������ݩ����";
	std::map<int, wchar_t> result;
	for (int i = 0; i < chineseTable.size();i++)
	{
		result[i] = chineseTable[i];
	}
	return result;
}
static int getRandomValue(const int minValue, const int maxValue)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(minValue,maxValue);
	return dis(gen);
}
struct SampleStyle
{
	std::string font;
	SampleStyle(const std::string& _font) :font(_font){}
};
struct SampleDesc
{
	std::pair<int, wchar_t> txtChar;
	cv::Mat image;
};
static cv::Mat addSaltNoise(const cv::Mat& grayImg)
{
	cv::Mat resultImg = grayImg.clone();
	cv::Mat saltPepperNoise = cv::Mat::zeros(resultImg.rows, resultImg.cols, CV_8UC1);
	cv::randu(saltPepperNoise, 0, 255);
	const cv::Mat black = saltPepperNoise < 10;
	const cv::Mat white = saltPepperNoise > 245;
	resultImg.setTo(255, white);
	resultImg.setTo(0, black);
	return resultImg;
}
static cv::Mat addGaussianNoise(const cv::Mat& grayImg)
{
	cv::Mat resultImg = grayImg.clone();
	cv::Mat noise = cv::Mat::zeros(resultImg.size(), CV_8UC1);
	cv::randn(noise, 8, 30);
	cv::add(resultImg, noise, resultImg);
	return resultImg;
}
static cv::Mat addGaussianSmooth(const cv::Mat& grayImg)
{
	cv::Mat resultImg = grayImg.clone();
	cv::GaussianBlur(resultImg, resultImg, cv::Size(3, 3), 0.1f);
	return resultImg;
}
static cv::Mat horizontalShiftLeft(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(1, 2);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < result.rows; y++)
	{
		unsigned char* lineData = result.data + y*result.cols;
		memcpy(lineData, lineData + shiftDist, result.cols - shiftDist);
		memset(lineData + (result.cols - shiftDist), bgColor, shiftDist);
	}
	return result;
}
static cv::Mat horizontalShiftRight(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(1, 2);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < result.rows; y++)
	{
		unsigned char* lineData = result.data + y*result.cols;
		memcpy(lineData + shiftDist, lineData, result.cols - shiftDist);
		memset(lineData, bgColor, shiftDist);
	}
	return result;
}
static cv::Mat verticalShiftUp(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(1, 2);
	cv::Mat result = grayImg.clone();
	for (int y = 0; y < result.rows - shiftDist; y++)
	{
		const unsigned char* srcLineData = result.data + (y + shiftDist)*result.cols;
		unsigned char* dstLineData = result.data + y*result.cols;
		memcpy(dstLineData, srcLineData, result.cols);
	}
	for (int y = result.rows-shiftDist; y < result.rows; y++)
	{
		unsigned char* dstLineData = result.data + y*result.cols;
		memset(dstLineData, bgColor, result.cols);
	}
	return result;
}
static cv::Mat verticalShiftDown(const cv::Mat& grayImg)
{
	const int shiftDist = getRandomValue(1, 2);
	cv::Mat result = grayImg.clone();
	for (int y = result.rows - shiftDist; y >= shiftDist; y--)
	{
		const unsigned char* srcLineData = result.data + (y - shiftDist)*result.cols;
		unsigned char* dstLineData = result.data + y*result.cols;
		memcpy(dstLineData, srcLineData, result.cols);
	}
	for (int y = 0; y < shiftDist; y++)
	{
		unsigned char* dstLineData = result.data + y*result.cols;
		memset(dstLineData, bgColor, result.cols);
	}
	return result;
}
static cv::Mat addSkew(const cv::Mat& grayImg)
{
	cv::Mat result = grayImg.clone();
	const int degree = getRandomValue(-3, 3);
	const cv::Point center(result.cols / 2, result.rows / 2);
	const cv::Mat rotMatS = cv::getRotationMatrix2D(center, degree, 1.0);
	warpAffine(result, result, rotMatS, result.size(), 1, 0, bgColor);
	return result;
}
static cv::Mat perTransform(const cv::Mat& grayImg)
{
	cv::Mat result = cv::Mat(grayImg.size(), CV_8UC1);
	result.setTo(bgColor);
	const int imgWidth = result.cols;
	const int imgHeight = result.rows;	
	std::vector<cv::Point2f> corners(4);
	corners[0] = cv::Point2f(0, 0);
	corners[1] = cv::Point2f(imgWidth - 1, 0);
	corners[2] = cv::Point2f(0, imgHeight - 1);
	corners[3] = cv::Point2f(imgWidth - 1, imgHeight - 1);
	//TODO : random it
	std::vector<cv::Point2f> corners_trans(4);
	corners_trans[0] = cv::Point2f(0, 0);
	corners_trans[1] = cv::Point2f(imgWidth-1, 0);
	corners_trans[2] = cv::Point2f(0, imgHeight - 1);
	corners_trans[3] = cv::Point2f(imgWidth-1, imgHeight - 1);
	//action
	cv::Mat transform = cv::getPerspectiveTransform(corners, corners_trans);
	std::vector<cv::Point2f> ponits, points_trans;
	for (int i = 0; i < imgHeight; i++)
	{
		for (int j = 0; j < imgWidth; j++)
		{
			ponits.push_back(cv::Point2f(j, i));
		}
	}
	cv::perspectiveTransform(ponits, points_trans, transform);
	int count = 0;
	for (int i = 0; i < imgHeight; i++)
	{
		const unsigned char* p = grayImg.ptr<unsigned char>(i);
		for (int j = 0; j < imgWidth; j++)
		{
			int y = points_trans[count].y;
			int x = points_trans[count].x;
			if (y >= 0 && y < imgHeight)
			{
				unsigned char* t = result.ptr<unsigned char>(y);
				t[x] = p[j];
				count++;
			}
		}
	}
	return result;
}
static std::vector<SampleDesc> genSample(const std::pair<int, wchar_t>& txtChar, const SampleStyle style, const int standardSize, const int singleParm, const int multiParam)
{
	std::vector<SampleDesc> result;
	const int srcSize = 86;
	SampleGenetator paiter(style.font, srcSize);
	//src
	const auto srcImg = paiter.genSample(txtChar.second, bgColor, fgColor);
	//smooth
	cv::Mat smoothedImg;
	cv::GaussianBlur(srcImg, smoothedImg, cv::Size(3, 3), 1.0f);
	//resize
	cv::Mat standardImg;
	if (!smoothedImg.data)
	{
		std::cout << "style : {" << style.font << "}" << std::endl;
		std::cout << "lost char : txtChar = " << txtChar.second << ",width=" << smoothedImg.cols << ",height=" << smoothedImg.rows << std::endl;
		return result;
	}
	else
	{
		cv::resize(smoothedImg, standardImg, cv::Size(standardSize, standardSize), 0.0, 0.0, cv::INTER_AREA);
	}
	//process chain
	//////////////////////////////////////////////////////////////////////////
	using procFuncType = std::function<cv::Mat(const cv::Mat&)>;
	std::vector<procFuncType> procFuncs{
// 		addSaltNoise,
// 		addGaussianNoise,
// 		addGaussianSmooth,
		horizontalShiftLeft,
		horizontalShiftRight,
		verticalShiftUp,
		verticalShiftDown,
		addSkew
		//perTransform
	};
	//////////////////////////////////////////////////////////////////////////
	//standard
	SampleDesc sample;
	sample.txtChar = txtChar;
	sample.image = standardImg;
	result.push_back(sample);
	//////////////////////////////////////////////////////////////////////////
	//single
	const int singleSample = singleParm;
	for (int i = 0; i < singleSample; i++)
	{
		for (auto& func : procFuncs)
		{
			sample.image = func(standardImg);
			result.push_back(sample);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//random
	const int chainSamples = multiParam;
	for (int i = 0; i < chainSamples;i++)
	{
		const int chainLen = 2;
		auto img = standardImg.clone();
		for (int j = 0; j < chainLen; j++)
		{
			const int curIdx = getRandomValue(0, procFuncs.size()-1);
			auto& func = procFuncs[curIdx];
			img = func(img);
		}
		sample.image = img;
		result.push_back(sample);
	}
	return result;
}
//copied from caffe [https://github.com/BVLC/caffe/blob/c7ee2615a8df2dedb408ff9c2c842e5f4f42a310/include/caffe/util/format.hpp]
static inline std::string format_int(int n, int numberOfLeadingZeros = 0) {
	std::ostringstream s;
	s << std::setw(numberOfLeadingZeros) << std::setfill('0') << n;
	return s.str();
}
static void example()
{
	const int srcSize = 86;
	const int standardSize = 32;
	const auto styles = std::vector < SampleStyle > {
		SampleStyle("test/΢��������.ttf"),
			SampleStyle("test/���������μ���.ttf")
	};
	CaffeTester tester;
	const auto success = tester.loadModel(
		R"(D:\databases\ocr_train_data\lenet_train_test_deploy.prototxt)",
		R"(D:\databases\ocr_train_data\model\lenet.caffemodel)",
		R"(D:\databases\ocr_train_data\label.set)"
		);
	assert(success);
	auto chineseTable = getChineseTable();
	int test_count = 0;
	int truth_count = 0;
	while (true)
	{
		const auto idx = getRandomValue(0, chineseTable.size() - 1);
		const auto txtChar = chineseTable[idx];
		const auto samples = genSample(std::make_pair(idx,txtChar), styles[0], standardSize, 1, 1);
		for (const auto& sample : samples)
		{		
			const auto label = tester.recognize(sample.image);
			const auto isSame = sample.txtChar.second == label;
			if (isSame)
			{
				truth_count++;
			}
			test_count++;
			if (test_count >= 1000)
			{
				exit(0);
			}
			std::cout << "current char is " << convertUtf16ToLocal(sample.txtChar.second) << std::endl;
			std::cout << "recognized char is " << convertUtf16ToLocal(label) << std::endl;
			std::cout << "accuracy is : " << ((float)truth_count/(float)test_count) << std::endl;
			std::cout << "------------------------------------" << std::endl;
#if 0
			if (!isSame)
			{
				cv::destroyAllWindows();
				cv::imshow("srcImg", sample.image);
				const auto key = cv::waitKey(0);
				if (key == 27)
				{
					exit(0);
				}
			}
#endif
		}		
	}
}
int main()
{
	setlocale(LC_ALL, "");
	example();
	return 0;
}