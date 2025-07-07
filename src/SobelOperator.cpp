#include "edge_detection/SobelOperator.h"
#include <opencv2/imgproc.hpp>

namespace edge_detection {

cv::Mat SobelOperator::apply(const cv::Mat& input) const {
    cv::Mat grad_x, grad_y, abs_grad_x, abs_grad_y, output;
    cv::Sobel(input, grad_x, CV_16S, 1, 0, 3);
    cv::Sobel(input, grad_y, CV_16S, 0, 1, 3);
    cv::convertScaleAbs(grad_x, abs_grad_x);
    cv::convertScaleAbs(grad_y, abs_grad_y);
    cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, output);
    return output;
}

} // namespace edge_detection 