#include "catch.hpp"
#include "input/cli/CommandLineArgument.hpp"

SCENARIO("Test equality operator ==") {
  GIVEN("CommandLineArgument new-db") {
    CommandLineArgument lhs = CommandLineArgument("new-db");
    WHEN("Comparing to command line argument new-db") {
      CommandLineArgument rhs = CommandLineArgument("new-db");
      THEN("They should be equal.") { REQUIRE(lhs == rhs); }
    }
    WHEN("Comparing to command line argument yeet") {
      CommandLineArgument rhs = CommandLineArgument("yeet");
      THEN("They should not be equal") { REQUIRE_FALSE(lhs == rhs); }
    }
  }
}
