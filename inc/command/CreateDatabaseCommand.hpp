#ifndef CREATEDATABASECOMMAND_H
#define CREATEDATABASECOMMAND_H
#include <memory>

#include "command/ICommand.hpp"
#include "database/IDatabase.hpp"

/**
 * Command to create a new database.
 */
class CreateDatabaseCommand : public ICommand {
public:
  CreateDatabaseCommand(std::shared_ptr<IDatabase> database);
  void run();
private:
  std::shared_ptr<IDatabase> _database;
};

#endif
