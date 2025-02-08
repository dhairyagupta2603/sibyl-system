add_executable(sibyl_test sibyl_test.cpp)
target_link_libraries(sibyl_test PRIVATE sibyl_shared)

AddTests(sibyl_test)
