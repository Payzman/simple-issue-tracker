file(GLOB_RECURSE sources ./*.cpp)
add_executable(issue-tracker ${sources})
set_target_properties(issue-tracker PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_compile_options(issue-tracker PRIVATE -Wall -Wextra)

list(REMOVE_ITEM sources main.cpp)
add_library(issuetrackerlib STATIC ${sources})
set_target_properties(issuetrackerlib PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
