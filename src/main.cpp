#include "edge_detection/EdgeDetector.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace edge_detection;

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Usage: " << argv[0] << " <input_image> <output_image> <operator: sobel|prewitt>\n";
        return 1;
    }

    std::string inputPath = argv[1];
    std::string outputPath = argv[2];
    std::string opStr = argv[3];

    EdgeDetector::OperatorType opType;
    if (opStr == "sobel") {
        opType = EdgeDetector::OperatorType::Sobel;
    } else if (opStr == "prewitt") {
        opType = EdgeDetector::OperatorType::Prewitt;
    } else {
        std::cerr << "Unknown operator: " << opStr << "\n";
        return 2;
    }

    cv::Mat input = cv::imread(inputPath, cv::IMREAD_GRAYSCALE);
    if (input.empty()) {
        std::cerr << "Failed to load image: " << inputPath << "\n";
        return 3;
    }

    EdgeDetector detector(opType);
    cv::Mat edges = detector.detectEdges(input);
    cv::imwrite(outputPath, edges);
    std::cout << "Edge detection complete using " << detector.currentOperatorName() << ". Output saved to " << outputPath << "\n";
    return 0;
} 