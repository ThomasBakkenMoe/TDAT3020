#include "utility.h"
#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  is_capital_of_norway((const char *)data, size);
  return 0;
}
