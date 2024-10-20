#include "impls.h"


std::vector<std::vector<cv::Point>> find_contours(const cv::Mat& input) {
    /**
     * 要求：
     * 使用cv::findContours函数，从输入图像（3个通道）中找出所有的最内层轮廓。
     * 将它们保存起来作为函数返回值就行。contours的中文意思就是轮廓。
     * 
     * 提示：
     * 1. 使用cv::imshow来查看输入图像。
     * 2. 使用cv::drawContours来在一张图上绘制轮廓。
     * 3. 直接使用原图一般而言不利于轮廓的寻找，可以做一些简单的处理。
     * 4. findContours函数可以返回轮廓的层次结构，理解层次结构的保存方式并使用它（重点）。
     * 
     * 通过条件：
     * 运行测试点，你找到的轮廓与答案的轮廓一样就行。
     */
    
    std::vector<std::vector<cv::Point>> res;
    // IMPLEMENT YOUR CODE HERE
       cv::Mat threshold, bin;
    cv::cvtColor(input, bin, cv::COLOR_BGR2GRAY);
    cv::threshold(bin, threshold, 20, 255, cv::THRESH_BINARY_INV);
    std::vector<cv::Vec4i> hierarhy;
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(threshold, contours, hierarhy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
    /*
    cv::Mat countour_img = input;
    for (int i = 0; i < contours.size(); i++)
        cv::drawContours(countour_img, contours, i, cv::Scalar(255, 0, 0), 1, 8, hierarhy, 0);
    cv::imshow("threshold", threshold);
    cv::imshow("contours", countour_img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    */
    for (int i = 0; i < contours.size(); i++)
        if (hierarhy[i][2] == -1)
            res.push_back(contours[i]);
    return res;
}