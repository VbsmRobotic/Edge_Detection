add_executable(edge_detection_tests test_main.cpp)
target_link_libraries(edge_detection_tests PRIVATE edge_detection ${OpenCV_LIBS})
add_test(NAME EdgeDetectionTests COMMAND edge_detection_tests) 