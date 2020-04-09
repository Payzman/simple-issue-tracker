#include "catch.hpp"
#include "command/CreateDatabaseCommand.hpp"
#include "command/ICommand.hpp"
#include "command/NullCommand.hpp"
#include "input/IInput.hpp"
#include "input/cli/CommandLineInput.hpp"

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
