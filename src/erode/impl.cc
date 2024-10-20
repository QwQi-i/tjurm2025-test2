#include "impls.h"


std::vector<cv::Mat> erode(const cv::Mat& src_erode, const cv::Mat& src_dilate) {
    /**
     * TODO: 先将图像转换为灰度图像, 然后二值化，然后进行腐蚀操作，具体内容：
     *  1. 将彩色图片 src_erode 转换为灰度图像
     *  2. 将灰度图像进行二值化
     *  3. 将二值化后的两张图片 分别进行 腐蚀 和 膨胀操作
     *  此任务需要你不断调整 erode 和 dilate 函数 的参数，以达到目标效果
     * HINT: 你可能需要以下函数
     *  1. 图像的腐蚀函数 cv::erode，该函数会扩大黑色部分，去除小的白色区域，参数如下
     *      void cv::erode(
     *          InputArray  src,        // 输入的二值图像
     *          OutputArray dst,        // 输出的二值图像
     *          InputArray  kernel,     // 腐蚀的核
     *          Point       anchor = Point(-1,-1), // 锚点
     *          int         iterations = 1,        // 迭代次数
     *          int         borderType = BORDER_CONSTANT, // 边界类型
     *          const Scalar& borderValue = morphologyDefaultBorderValue() // 边界值
     *      )
     *  2. 图像的膨胀函数 cv::dilate，该函数会扩大白色部分，去掉小的的黑色区域，参数如下
     *      void cv::dilate(
     *          InputArray  src,        // 输入的二值图像
     *          OutputArray dst,        // 输出的二值图像
     *          InputArray  kernel,     // 膨胀的核
     *          Point       anchor = Point(-1,-1), // 锚点
     *          int         iterations = 1,        // 迭代次数
     *          int         borderType = BORDER_CONSTANT, // 边界类型
     *          const Scalar& borderValue = morphologyDefaultBorderValue() // 边界值
     *      )
     *  3. 图像的腐蚀和膨胀的核可以使用 cv::getStructuringElement 函数生成，参数如下
     *      cv::Mat cv::getStructuringElement(
     *          int         shape,      // 核的形状 (具体类型可以参考网络资料，或者利用 vscode 的代码提示)
     *          Size        ksize,      // 核的大小
     *          Point       anchor = Point(-1,-1) // 锚点
     *      )
     *       膨胀腐蚀操作的本质是对图像进行卷积(暂时可以理解为在一个像素区域内取平均的意思)操作，
     *      核的大小决定了这个区域的大小
     *   PS: 这里的 二值化函数的参数需要看设置为 thresh = 50, maxval = 255, type = THRESH_BINARY
     *   GOAL:
     *     1. 腐蚀结果图片中，女孩头发里的白点被消除了(类似答案中的样子)
     *     2. dilate 之后的图像中，图中的小脚被消除了(类似答案中的样子)
     *     以上两个检查点需要自己检查，满足条件 则输入 p 通过, 否则输入 f 表示不通过
     */
    cv::Mat dst_erode, dst_dilate;

    // TODO: 在这里实现你的代码
    cv::Mat erode_threshold, erode_gray, dilate_threshold, dilate_gray;
    cv::cvtColor(src_dilate, dilate_gray, cv::COLOR_BGR2GRAY, 0);
    cv::cvtColor(src_erode, erode_gray, cv::COLOR_BGR2GRAY, 0);
    cv::threshold(dilate_gray, dilate_threshold, 50, 255, cv::THRESH_BINARY);
    cv::threshold(erode_gray, erode_threshold, 50, 255, cv::THRESH_BINARY);
    cv::imshow("dilate_gray", dilate_gray);
    cv::imshow("erode_gray", erode_gray);
    cv::imshow("dilate_threshold", dilate_threshold);
    cv::imshow("erode_threshold", erode_threshold);
    cv::waitKey(0);
    cv::destroyAllWindows();
    cv::Size ksize(1, 1);
    cv::Point anchor(-1, -1);
    cv::erode(erode_threshold, dst_erode, cv::getStructuringElement(cv::MORPH_ERODE, ksize, anchor), anchor, 1, cv::BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
    cv::dilate(dilate_threshold, dst_dilate, cv::getStructuringElement(cv::MORPH_DILATE, ksize, anchor), anchor, 1, cv::BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
    return {dst_erode, dst_dilate};
}
