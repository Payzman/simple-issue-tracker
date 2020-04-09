#include "input/cli/CommandLineInput.hpp"

const CommandLineArgument CommandLineInput::CREATE =
    CommandLineArgument("new-db");

CommandLineInput::CommandLineInput(std::vector<std::string> arguments)
    : _argument(arguments.front()) {}

std::unique_ptr<ICommand> CommandLineInput::getCommand() {
  if (_argument == CREATE) {
    return std::make_unique<CreateDatabaseCommand>();
  }
  return std::make_unique<NullCommand>();
}
