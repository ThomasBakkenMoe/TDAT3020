#include "utility.h"
#include <assert.h>
#include <string.h>

int main() {
  char *city = "";
  assert(is_capital_of_norway(city, strlen(city)) == false);

  city = "Trondheim";
  assert(is_capital_of_norway(city, strlen(city)) == false);

  city = "Oslo";
  assert(is_capital_of_norway(city, strlen(city)) == true);
}
