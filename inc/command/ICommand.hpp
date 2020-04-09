#ifndef ICOMMAND_H
#define ICOMMAND_H

/**
 * Interface for any type of command that can be run on the issue tracker.
 */
class ICommand {
public:
  /** Destructor. */
  virtual ~ICommand() = 0;
};

#endif
