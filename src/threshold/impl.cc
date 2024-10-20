#include "impls.h"

std::vector<cv::Mat> threshold(const cv::Mat &src, int threshold_value)
{
    /**
     * TODO: 将一个彩色图片转换为二值化图
     *  1. 将 src 转换成灰度图像
     *  2. 阈值化转换为二值化图像
     *  3. 然后将灰度图像和二值图像返回，即 vector<cv::Mat> {gray, dst}
     * HINT: 你可能需要以下函数
     *  1. 灰度图和彩色图之间的转换函数 cv::cvtColor，参数如下
     *     void cv::cvtColor(
     *          InputArray  src,        // 输入的彩色图像
     *          OutputArray dst,        // 输出的灰度图像
     *          int         code,       // 转换的类型 (具体类型可以参考网络资料，或者利用 vscode 的代码提示)
     *          int         dstCn = 0   // 输出图像的通道数
     *    )
     *  2. 图像的二值化函数 cv::threshold，参数如下
     *      void cv::threshold(
     *          InputArray  src,        // 输入的灰度图像
     *          OutputArray dst,        // 输出的二值图像
     *          double      thresh,     // 阈值
     *          double      maxval,     // 最大值
     *          int         type        // 阈值化的类型 (具体类型可以参考网络资料，或者利用 vscode 的代码提示)
     *      )
     *      此函数会将 小于阈值的像素点的值设置为 0，大于阈值的像素点的值设置为 maxval
     */
    cv::Mat gray, dst;

    // TODO: 实现代码
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY, 0);
    cv::threshold(gray, dst, threshold_value, 255, cv::THRESH_BINARY);
    return {gray, dst};
}
