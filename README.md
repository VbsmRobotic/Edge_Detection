# Edge Detection in C++

This project implements image edge detection using Sobel and Prewitt operators in C++. The user can select the operator at runtime. The project is organized for clarity, testability, and maintainability.

## Features
- Edge detection using Sobel or Prewitt operator
- Simple grayscale image input/output
- Operator selection via command line
- Unit tests for operator logic and image handling
- UML class diagram included

## Directory Structure
- `include/edge_detection/` - Header files
- `src/` - Implementation files and main application
- `tests/` - Unit tests
- `docs/` - Documentation (UML diagram)
- `examples/` - Example images (add your own)

## Build Instructions
This project uses CMake and requires OpenCV.

```
mkdir build
cd build
cmake ..
make
```

## Run the Application
```
./bin/edge_detection_app <input_image> <output_image> <operator: sobel|prewitt>
```
Example:
```
./bin/edge_detection_app ../examples/input.png ../examples/output.png sobel
```

## Run Tests
```
./bin/edge_detection_tests
```

## UML Diagram
See `docs/edge_detection_uml.png` or `docs/edge_detection_uml.drawio` for the class diagram.

## Author
- GitHub: https://github.com/VbsmRobotic/Edge_Detection 