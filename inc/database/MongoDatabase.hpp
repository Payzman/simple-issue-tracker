#ifndef MONGODATABASE_H
#define MONGODATABASE_H
#include "database/IDatabase.hpp"

class MongoDatabase : public IDatabase {
  void close();
  void open();
};

#endif
