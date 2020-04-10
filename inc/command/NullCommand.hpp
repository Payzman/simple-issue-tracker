#ifndef NULLCOMMAND_H
#define NULLCOMMAND_H

#include "command/ICommand.hpp"

/**
 * Denotes a command that does nothing. Can be used for input errors for
 * example.
 */
class NullCommand : public ICommand {
public:
  void run() {}
};

#endif
