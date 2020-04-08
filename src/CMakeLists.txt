file(GLOB_RECURSE sources ./*.cpp)
add_executable(issue-tracker ${sources})
target_compile_options(issue-tracker PRIVATE -Wall -Wextra)

list(REMOVE_ITEM sources main.cpp)
add_library(issuetrackerlib STATIC ${sources})
