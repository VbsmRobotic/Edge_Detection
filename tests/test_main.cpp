#include "edge_detection/EdgeDetector.h"
#include <opencv2/opencv.hpp>
#include <cassert>
#include <iostream>

using namespace edge_detection;

void test_operator_selection() {
    EdgeDetector detector(EdgeDetector::OperatorType::Sobel);
    assert(detector.currentOperatorName() == "Sobel");
    detector.setOperator(EdgeDetector::OperatorType::Prewitt);
    assert(detector.currentOperatorName() == "Prewitt");
    std::cout << "test_operator_selection passed\n";
}

void test_edge_detection_on_mock() {
    // Create a simple mock image: a white square on black background
    cv::Mat img = cv::Mat::zeros(10, 10, CV_8U);
    cv::rectangle(img, cv::Point(3,3), cv::Point(6,6), cv::Scalar(255), -1);
    EdgeDetector sobel(EdgeDetector::OperatorType::Sobel);
    EdgeDetector prewitt(EdgeDetector::OperatorType::Prewitt);
    cv::Mat sobel_edges = sobel.detectEdges(img);
    cv::Mat prewitt_edges = prewitt.detectEdges(img);
    assert(sobel_edges.size() == img.size());
    assert(prewitt_edges.size() == img.size());
    // Check that there are some nonzero edge pixels
    assert(cv::countNonZero(sobel_edges) > 0);
    assert(cv::countNonZero(prewitt_edges) > 0);
    std::cout << "test_edge_detection_on_mock passed\n";
}

int main() {
    test_operator_selection();
    test_edge_detection_on_mock();
    std::cout << "All tests passed!\n";
    return 0;
} 