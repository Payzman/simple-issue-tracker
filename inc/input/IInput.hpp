#ifndef IINPUT_H
#define IINPUT_H
#include <memory>
#include "command/ICommand.hpp"

/**
 * Interface for any input, i.e. command line / graphical user interface ...
 */
class IInput {
public:
  /** Destructor */
  virtual ~IInput() = 0;
  /**
   * Returns the appropiate command according to the given input.
   *
   * @returns a reference to the command.
   */
  virtual std::unique_ptr<ICommand> getCommand() = 0;
};

#endif
