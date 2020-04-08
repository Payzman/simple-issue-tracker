file(GLOB_RECURSE test_sources ./*.cpp)
add_executable(Test ${test_sources})
target_compile_options(issue-tracker PRIVATE -Wall -Wextra)
target_link_libraries(Test issuetrackerlib)
