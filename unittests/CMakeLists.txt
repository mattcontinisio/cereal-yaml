file(GLOB TESTS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

# Build all of the non-special tests
foreach(TEST_SOURCE ${TESTS})

  string(REPLACE ".cpp" "" TEST_TARGET "${TEST_SOURCE}")
  set(TEST_TARGET "test_${TEST_TARGET}")

  # Check to see if our target is listed in "SPECIAL_TESTS"
  list(FIND SPECIAL_TESTS "${TEST_SOURCE}" IS_SPECIAL_TEST)

  if(IS_SPECIAL_TEST EQUAL -1)

    add_executable(${TEST_TARGET} ${TEST_SOURCE})
    target_link_libraries(${TEST_TARGET} ${CEREAL_YAML_THREAD_LIBS} yaml-cpp)
    add_test("${TEST_TARGET}" "${TEST_TARGET}")

  endif()

endforeach()

#if(NOT CMAKE_VERSION VERSION_LESS 3.0)
#  add_test(test_cmake_config_module ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake-config-module.cmake)
#endif()
