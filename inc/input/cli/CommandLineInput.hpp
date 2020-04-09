#ifndef COMMANDLINEINPUT_H
#define COMMANDLINEINPUT_H
#include <vector>

#include "command/CreateDatabaseCommand.hpp"
#include "command/NullCommand.hpp"
#include "input/IInput.hpp"
#include "input/cli/CommandLineArgument.hpp"

/**
 * Input implementation for command line inputs. Uses the command line arguments
 * to determine the appropiate command.
 */
class CommandLineInput : public IInput {
public:
  /** Constructor. */
  CommandLineInput(std::vector<std::string> arguments);
  std::unique_ptr<ICommand> getCommand();

private:
  static const CommandLineArgument CREATE;
  CommandLineArgument _argument;
};

#endif
