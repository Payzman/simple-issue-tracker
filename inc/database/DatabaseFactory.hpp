#ifndef DATABASEFACTORY_H
#define DATABASEFACTORY_H
#include <memory>

#include "database/IDatabase.hpp"
#include "database/MongoDatabase.hpp"

class DatabaseFactory {
  public:
    std::unique_ptr<IDatabase> getDatabase();
};

#endif
