#pragma once
#include <stdbool.h>
#include <stddef.h>

bool is_capital_of_norway(const char *city, size_t size) {
  return size >= 3 && city[0] == 'O' && city[1] == 's' && city[2] == 'l' && city[3] == 'o';
}
