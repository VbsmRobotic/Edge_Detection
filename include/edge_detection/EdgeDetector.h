#pragma once
#include <opencv2/opencv.hpp>
#include <memory>
#include <string>

namespace edge_detection {

class EdgeOperator {
public:
    virtual ~EdgeOperator() = default;
    virtual cv::Mat apply(const cv::Mat& input) const = 0;
    virtual std::string name() const = 0;
};

class EdgeDetector {
public:
    enum class OperatorType { Sobel, Prewitt };

    EdgeDetector(OperatorType opType);
    void setOperator(OperatorType opType);
    cv::Mat detectEdges(const cv::Mat& input) const;
    std::string currentOperatorName() const;

private:
    std::unique_ptr<EdgeOperator> op_;
    OperatorType opType_;
    void createOperator();
};

} // namespace edge_detection 