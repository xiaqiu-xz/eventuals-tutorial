#include "eventuals/expected.h"
#include "eventuals/then.h"

using namespace eventuals;

Expected::Of<int> SomeFunction(int i) {
  if (i > 100) {
    return Unexpected(std::overflow_error("> 100"));
  } else {
    return i; // return Expected(i);
  }
}

int main(int argc, char** argv) {
  CHECK_EQ("42", *(SomeFunction(42) | Then([](int i) { return std::to_string(i); })));

  return 0;
}
