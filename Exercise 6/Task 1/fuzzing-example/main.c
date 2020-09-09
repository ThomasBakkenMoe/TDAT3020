#include "utility.h"
#include <stdio.h>
#include <string.h>

int main() {
  char *city = "Trondheim";
  printf("%d\n", is_capital_of_norway(city, strlen(city)));

  city = "Oslo";
  printf("%d\n", is_capital_of_norway(city, strlen(city)));
}
