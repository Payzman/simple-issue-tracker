#include "command/CreateDatabaseCommand.hpp"

CreateDatabaseCommand::CreateDatabaseCommand(
    std::shared_ptr<IDatabase> database) {
  _database = database;
}

void CreateDatabaseCommand::run() {
  _database->open();
  _database->close();
}
