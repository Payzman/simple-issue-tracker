#include "catch.hpp"
#include "command/ICommand.hpp"
#include "input/IInput.hpp"
#include "input/cli/CommandLineArgument.hpp"

/**
 * Denotes a command that does nothing. Can be used for input errors for
 * example.
 */
class NullCommand : public ICommand {};
class CreateDatabaseCommand : public ICommand {};

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

SCENARIO("Testing command line arguments.") {
  GIVEN("A command line input, that a new database should be created.") {
    std::vector<std::string> commandLineArguments = {"new-db", "~/database.db"};
    std::unique_ptr<IInput> input =
        std::make_unique<CommandLineInput>(commandLineArguments);
    WHEN("Getting the resulting command.") {
      std::unique_ptr<ICommand> command = input->getCommand();
      THEN(R"(The resulting command should be of type 
        \"CreateDatabaseCommand\")") {
        REQUIRE(dynamic_cast<CreateDatabaseCommand *>(command.get()) !=
                nullptr);
      }
    }
  }
  GIVEN("A command line input with an unrecognized command.") {
    std::vector<std::string> commandLineArguments = {"yeet"};
    std::unique_ptr<IInput> input =
        std::make_unique<CommandLineInput>(commandLineArguments);
    WHEN("Getting the resulting command.") {
      std::unique_ptr<ICommand> command = input->getCommand();
      THEN("The resulting command should be a NullCommand") {
        REQUIRE(dynamic_cast<NullCommand *>(command.get()) != nullptr);
      }
    }
  }
}
