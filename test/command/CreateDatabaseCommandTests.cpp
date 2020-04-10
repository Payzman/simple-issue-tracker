#include "catch.hpp"
#include "command/CreateDatabaseCommand.hpp"
#include "command/ICommand.hpp"

class MockedDatabase : public IDatabase {
public:
  void open();
  void close();

  bool exists();

private:
  bool _wasOpened = false;
  bool _wasClosed = false;
};

void MockedDatabase::open() { _wasOpened = true; }

void MockedDatabase::close() { _wasClosed = true; }

bool MockedDatabase::exists() { return _wasOpened && _wasClosed; }

SCENARIO("Creating a new database.") {
  GIVEN("The create database command with a mocked database.") {
    std::shared_ptr<MockedDatabase> database =
        std::make_shared<MockedDatabase>();
    std::unique_ptr<ICommand> command =
        std::make_unique<CreateDatabaseCommand>(database);
    WHEN("Calling the run method.") {
      command->run();
      THEN("The database should have been created.") {
        REQUIRE(database->exists());
      }
    }
  }
}
