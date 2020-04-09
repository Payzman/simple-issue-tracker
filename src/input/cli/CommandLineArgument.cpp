#include "input/cli/CommandLineArgument.hpp"

CommandLineArgument::CommandLineArgument(std::string argument)
    : _argument(argument) {}

bool operator==(const CommandLineArgument &lhs,
                const CommandLineArgument &rhs) {
  return lhs._argument == rhs._argument;
}
