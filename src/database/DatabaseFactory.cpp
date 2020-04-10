#include "database/DatabaseFactory.hpp"

std::unique_ptr<IDatabase> DatabaseFactory::getDatabase() {
  return std::make_unique<MongoDatabase>();
}
