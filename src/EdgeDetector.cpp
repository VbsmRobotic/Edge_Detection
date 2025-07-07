#include "edge_detection/EdgeDetector.h"
#include "edge_detection/SobelOperator.h"
#include "edge_detection/PrewittOperator.h"
#include <stdexcept>

namespace edge_detection {

EdgeDetector::EdgeDetector(OperatorType opType) : opType_(opType) {
    createOperator();
}

void EdgeDetector::setOperator(OperatorType opType) {
    opType_ = opType;
    createOperator();
}

cv::Mat EdgeDetector::detectEdges(const cv::Mat& input) const {
    if (!op_) throw std::runtime_error("Edge operator not set");
    return op_->apply(input);
}

std::string EdgeDetector::currentOperatorName() const {
    if (!op_) return "None";
    return op_->name();
}

void EdgeDetector::createOperator() {
    switch (opType_) {
        case OperatorType::Sobel:
            op_ = std::make_unique<SobelOperator>();
            break;
        case OperatorType::Prewitt:
            op_ = std::make_unique<PrewittOperator>();
            break;
        default:
            throw std::invalid_argument("Unknown operator type");
    }
}

} // namespace edge_detection 