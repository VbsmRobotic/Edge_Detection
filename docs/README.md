# Edge Detection Project - Technical Documentation

## 📊 UML Class Diagram Explanation

The UML diagram shows the **Strategy Pattern** implementation for edge detection operators. Here's a detailed breakdown:

### 🏗️ **Architecture Overview**

#### **1. EdgeOperator Interface (Abstract Base Class)**
```cpp
class EdgeOperator {
    <<interface>>
    +apply(input: cv::Mat) cv::Mat
    +name() string
}
```

**Purpose:** Defines the contract that all edge detection operators must follow.

**Key Points:**
- **`<<interface>>`** - This is an abstract class (pure virtual functions)
- **`apply()`** - Virtual function that takes an input image and returns the edge-detected image
- **`name()`** - Virtual function that returns the operator's name as a string
- **Polymorphism** - Allows different operators to be used interchangeably

#### **2. Concrete Operator Classes**

##### **SobelOperator**
```cpp
class SobelOperator {
    +apply(input: cv::Mat) cv::Mat
    +name() string
}
```
- **Implements** the EdgeOperator interface
- Uses **Sobel kernels** for edge detection
- Better at **noise suppression**
- Produces **sharper, more defined edges**

##### **PrewittOperator**
```cpp
class PrewittOperator {
    +apply(input: cv::Mat) cv::Mat
    +name() string
}
```
- **Implements** the EdgeOperator interface  
- Uses **Prewitt kernels** for edge detection
- More **sensitive to noise**
- Can detect **finer edge details**

#### **3. EdgeDetector (Main Controller Class)**
```cpp
class EdgeDetector {
    +EdgeDetector(opType: OperatorType)
    +setOperator(opType: OperatorType)
    +detectEdges(input: cv::Mat) cv::Mat
    +currentOperatorName() string
    -op_: unique_ptr<EdgeOperator>
    -opType_: OperatorType
    -createOperator()
}
```

**Public Methods:**
- **`EdgeDetector(opType)`** - Constructor that initializes with a specific operator
- **`setOperator(opType)`** - Allows switching between operators at runtime
- **`detectEdges(input)`** - Main method that applies edge detection
- **`currentOperatorName()`** - Returns the name of the currently active operator

**Private Members:**
- **`op_`** - Smart pointer to the current edge operator (polymorphic)
- **`opType_`** - Enum tracking which operator type is selected
- **`createOperator()`** - Factory method that creates the appropriate operator

### 🔗 **Relationships in the Diagram**

#### **1. Inheritance Relationships**
```
EdgeOperator <|.. SobelOperator
EdgeOperator <|.. PrewittOperator
```
- **`<|..`** means "implements" (realization)
- Both `SobelOperator` and `PrewittOperator` inherit from `EdgeOperator`
- This enables **polymorphism** - they can be used interchangeably

#### **2. Composition Relationship**
```
EdgeDetector o-- EdgeOperator
```
- **`o--`** means "composition" (has-a relationship)
- `EdgeDetector` **contains** an `EdgeOperator` object
- The `EdgeDetector` **owns** the operator and controls its lifecycle

## 🎯 **Design Patterns Used**

### **1. Strategy Pattern**
- **Problem:** Need to switch between different edge detection algorithms
- **Solution:** Encapsulate each algorithm in separate classes that implement a common interface
- **Benefits:** 
  - Easy to add new operators (just implement `EdgeOperator`)
  - Runtime operator switching
  - Clean separation of concerns

### **2. Factory Pattern**
- **Problem:** Need to create different operator objects based on user choice
- **Solution:** `createOperator()` method creates the appropriate operator
- **Benefits:** Centralized object creation logic

## 🔄 **How It Works in Practice**

1. **User creates** an `EdgeDetector` with a specific operator type
2. **Factory method** (`createOperator()`) creates the appropriate operator object
3. **User calls** `detectEdges()` with an input image
4. **EdgeDetector delegates** to the current operator's `apply()` method
5. **Operator processes** the image using its specific algorithm
6. **Result is returned** to the user

## 💡 **Key Benefits of This Design**

1. **Extensibility** - Easy to add new operators (Canny, Laplacian, etc.)
2. **Maintainability** - Each operator is isolated and can be modified independently
3. **Testability** - Each component can be tested separately
4. **Flexibility** - Operators can be switched at runtime
5. **Clean Code** - Follows SOLID principles, especially Open/Closed Principle

## 🧪 **Testing Strategy**

### **Unit Tests Coverage**
- **Operator Selection Logic** - Ensures correct operator is applied based on user input
- **Image Data Handling** - Tests with mock data and sample images
- **Edge Detection Accuracy** - Validates that edge detection produces expected results

### **Test Cases**
1. **test_operator_selection()** - Verifies operator switching works correctly
2. **test_edge_detection_on_mock()** - Tests edge detection on synthetic images
3. **Integration Tests** - End-to-end testing with real image files

## 📁 **Project Structure**

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
│   ├── README.md             # This file
│   └── edge_detection_uml.mmd # UML diagram
└── CMakeLists.txt            # Build configuration
```

## 🔧 **Build and Usage**

### **Prerequisites**
- C++17 compatible compiler
- OpenCV 4.x
- CMake 3.16+

### **Build Commands**
```bash
mkdir build && cd build
cmake ..
make
```

### **Usage Examples**
```bash
# Run tests
./tests/edge_detection_tests

# Apply Sobel operator
./src/edge_detection_app input.png output_sobel.png sobel

# Apply Prewitt operator
./src/edge_detection_app input.png output_prewitt.png prewitt
```

## 🚀 **Future Enhancements**

### **Potential New Operators**
- **Canny Edge Detector** - More sophisticated edge detection
- **Laplacian Operator** - Second-order derivative edge detection
- **Roberts Cross Operator** - Simple 2x2 kernel edge detection

### **Additional Features**
- **GUI Interface** - Visual application for image processing
- **Batch Processing** - Process multiple images at once
- **Parameter Tuning** - Adjustable kernel sizes and thresholds
- **Performance Optimization** - GPU acceleration with CUDA

## 📚 **References**

- **OpenCV Documentation** - https://docs.opencv.org/
- **Strategy Pattern** - Design Patterns by Gang of Four
- **C++ Best Practices** - Modern C++ Design Patterns

---

**Author:** VbsmRobotic  
**GitHub:** https://github.com/VbsmRobotic/Edge_Detection  
**License:** MIT 