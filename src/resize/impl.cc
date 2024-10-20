#include "impls.h"

cv::Mat my_resize(const cv::Mat &input, float scale)
{
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     *
     * 提示：
     * 无。
     *
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
    cv::Mat out = cv::Mat::zeros(new_rows, new_cols, input.type());
    // std::cout << input.type() << std::endl;
    int h = input.rows, w = input.cols;
    for (int x = 0; x < new_rows; x++)
        for (int y = 0; y < new_cols; y++)
        {
            float x0 = x / scale, y0 = y / scale;
            int x1 = static_cast<int>(x0), y1 = static_cast<int>(y0);
            int x2 = std::min(x1 + 1, h - 1), y2 = std::min(y1, w - 1);
            float dx = x0 - x1, dy = y0 - y1;
            cv::Vec3b p1 = input.at<cv::Vec3b>(x1, y1), p2 = input.at<cv::Vec3b>(x1, y2), p3 = input.at<cv::Vec3b>(x2, y1), p4 = input.at<cv::Vec3b>(x2, y2);
            // float p1 = in[convert(x1, y1, h, w)], p2 = in[convert(x1, y2, h, w)], p3 = in[convert(x2, y1, h, w)], p4 = in[convert(x2, y2, h, w)];
            for (int i = 0; i < 3; i++)
                out.at<cv::Vec3b>(x, y)[i] = static_cast<uchar>(p1[i] * (1 - dx) * (1 - dy) + p2[i] * dy * (1 - dx) + p3[i] * (1 - dy) * dx + p4[i] * dx * dy);
            // out.at<cv::Vec3b>(x, y)[i] = static_cast<uchar>((p1[i] + p2[i] + p3[i] + p4[i]) / 4);
            // out[convert(x, y, new_h, new_w)] = p1 * (1 - dx) * (1 - dy) + p2 * dx * (1 - dy) + p3 * (1 - dx) * dy + p4 * dx * dy;
        }
    /*
    cv::imshow("input", input);
    cv::imshow("output", out);
    cv::waitKey(0);
    cv::destroyAllWindows();
    */
    return out;
    return cv::Mat::zeros(new_rows, new_cols, input.type());
}