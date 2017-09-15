add_executable(cereal-yaml-example example.cpp)
target_link_libraries(cereal-yaml-example ${CEREAL_YAML_THREAD_LIBS} yaml-cpp)