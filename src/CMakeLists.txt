add_library(edge_detection STATIC
    EdgeDetector.cpp
    SobelOperator.cpp
    PrewittOperator.cpp
)

target_include_directories(edge_detection PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(edge_detection PUBLIC ${OpenCV_LIBS})

add_executable(edge_detection_app main.cpp)
target_link_libraries(edge_detection_app PRIVATE edge_detection ${OpenCV_LIBS}) 