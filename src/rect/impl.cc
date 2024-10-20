#include "impls.h"


std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用findCountours函数找出输入图像（彩色图像）中的矩形轮廓，并且返回它的外接矩形，以及
     * 最小面积外接矩形。所需要的函数自行查找。
     * 
     * 通过条件：
     * 运行测试点，你找到的矩形跟答案一样就行。
    */
    std::pair<cv::Rect, cv::RotatedRect> res;
    // IMPLEMENT YOUR CODE HERE
    cv::imshow("input", input);
    // IMPLEMENT YOUR CODE HERE
    cv::Mat threshold, bin;
    cv::cvtColor(input, bin, cv::COLOR_BGR2GRAY);
    cv::threshold(bin, threshold, 20, 255, cv::THRESH_BINARY_INV | cv::THRESH_OTSU);
    std::vector<cv::Vec4i> hierarhy;
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(threshold, contours, hierarhy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
    /*
    cv::Mat countour_img = input;
    for (int i = 0; i < contours.size(); i++)
        cv::drawContours(countour_img, contours, i, cv::Scalar(255, 0, 0), 1, 8, hierarhy, 0);
    cv::imshow("gray", bin);
    cv::imshow("threshold", threshold);
    cv::imshow("contours", countour_img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    */
    for (int i = 0; i < hierarhy.size(); i++)
        res = std::pair<cv::Rect, cv::RotatedRect>(cv::boundingRect(contours[i]), cv::minAreaRect(contours[i]));
    return res;
}