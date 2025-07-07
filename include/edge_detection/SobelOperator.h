#pragma once
#include "EdgeDetector.h"

namespace edge_detection {

class SobelOperator : public EdgeOperator {
public:
    cv::Mat apply(const cv::Mat& input) const override;
    std::string name() const override { return "Sobel"; }
};

} // namespace edge_detection 