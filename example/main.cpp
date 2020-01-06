#include <iostream>
#include <pqrs/cf/set.hpp>

int main(void) {
  if (auto set_ptr = pqrs::cf::make_cf_mutable_set(0)) {
    CFSetAddValue(*set_ptr, CFSTR("hello"));
    CFSetAddValue(*set_ptr, CFSTR("world"));
  }

  return 0;
}
