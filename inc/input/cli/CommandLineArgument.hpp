#ifndef COMMANDLINEARGUMENT_H
#define COMMANDLINEARGUMENT_H
#include <string>

/**
 * Defines a specific command line argument.
 */
class CommandLineArgument {
public:
  /** Constructor. */
  CommandLineArgument(std::string argument);
  /** Equality check... */
  friend bool operator==(const CommandLineArgument &lhs,
                         const CommandLineArgument &rhs);

private:
  std::string _argument;
};

#endif
