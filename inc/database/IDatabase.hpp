#ifndef IDATABASE_H
#define IDATABASE_H

/**
 * Interface for communicating with different kinds of databases (mongodb,
 * files, ...)
 */
class IDatabase {
public:
  virtual ~IDatabase() = 0;
  virtual void open() = 0;
  virtual void close() = 0;
};

#endif
