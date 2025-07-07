# Edge Detection in C++

This project implements image edge detection using Sobel and Prewitt operators in C++. The user can select the operator at runtime. The project is organized for clarity, testability, and maintainability.

## 🚀 Features
- Edge detection using Sobel or Prewitt operator
- Simple grayscale image input/output
- Operator selection via command line
- Unit tests for operator logic and image handling
- UML class diagram included
- Clean, maintainable C++ code following design patterns

## 📁 Project Structure

```
Edge_Detection_ws/
├── include/edge_detection/     # Header files
│   ├── EdgeDetector.h         # Main detector class
│   ├── SobelOperator.h        # Sobel operator interface
│   └── PrewittOperator.h      # Prewitt operator interface
├── src/                       # Implementation files
│   ├── EdgeDetector.cpp       # Main detector implementation
│   ├── SobelOperator.cpp      # Sobel algorithm implementation
│   ├── PrewittOperator.cpp    # Prewitt algorithm implementation
│   └── main.cpp              # Application entry point
├── tests/                     # Unit tests
│   └── test_main.cpp         # Test implementation
├── examples/                  # Sample images and outputs
├── docs/                      # Documentation
│   ├── README.md             # Technical documentation
│   ├── UML_diagram.drawio    # UML diagram (draw.io format)
│   └── UML_Diagram_drawio.png # UML diagram (PNG format)
└── CMakeLists.txt            # Build configuration
```

## 🔧 Build and Usage

### Prerequisites
- C++17 compatible compiler
- OpenCV 4.x
- CMake 3.16+

### Build Commands
```bash
mkdir build && cd build
cmake ..
make
```

### Usage Examples

#### Run Tests
```bash
./tests/edge_detection_tests
```

#### Apply Edge Detection
```bash
# Apply Sobel operator
./src/edge_detection_app input.png output_sobel.png sobel

# Apply Prewitt operator
./src/edge_detection_app input.png output_prewitt.png prewitt
```

#### Command Line Usage
```
./src/edge_detection_app <input_image> <output_image> <operator: sobel|prewitt>
```

**Example:**
```bash
./src/edge_detection_app ../examples/sample_1.png ../examples/output.png sobel
```

## 🧪 Testing

The project includes comprehensive unit tests that cover:
- Operator selection logic
- Image data handling with mock data
- Edge detection accuracy validation

Run tests with:
```bash
./tests/edge_detection_tests
```

## 📊 UML Diagram

The project uses the **Strategy Pattern** for edge detection operators. See the UML diagram for the complete class structure:

- **Draw.io format:** `docs/UML_diagram.drawio`
- **PNG format:** `docs/UML_Diagram_drawio.png`

For detailed technical documentation, see `docs/README.md`.

## 🎯 Design Patterns

- **Strategy Pattern:** Allows runtime switching between different edge detection algorithms
- **Factory Pattern:** Centralized creation of operator objects
- **Polymorphism:** Clean interface for different operator implementations

## 📈 Sample Results

The `examples/` directory contains:
- `sample_1.png` - Simple test image (white rectangle on black background)
- `sample_2.png` - Complex test image (multiple geometric shapes)
- Output images showing edge detection results for both operators

## 🚀 Future Enhancements

Potential improvements include:
- Additional edge detection operators (Canny, Laplacian)
- GUI interface for image processing
- Batch processing capabilities
- Performance optimizations

## 👨‍💻 Author
- **GitHub:** https://github.com/VbsmRobotic/Edge_Detection
- **Repository:** https://github.com/VbsmRobotic/Edge_Detection

## 📄 License
MIT License 