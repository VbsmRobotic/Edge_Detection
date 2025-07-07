#pragma once
#include "EdgeDetector.h"

namespace edge_detection {

class PrewittOperator : public EdgeOperator {
public:
    cv::Mat apply(const cv::Mat& input) const override;
    std::string name() const override { return "Prewitt"; }
};

} // namespace edge_detection 