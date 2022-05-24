#include <boost/ut.hpp>
#include <pqrs/cf/set.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;

  "make_empty_cf_set"_test = [] {
    auto set = pqrs::cf::make_empty_cf_set();
    expect(set);
    expect(CFSetGetCount(*set) == 0);
  };

  "make_cf_mutable_set"_test = [] {
    auto set = pqrs::cf::make_cf_mutable_set();
    expect(set);
    expect(CFGetRetainCount(*set) == 1);
    expect(CFSetGetCount(*set) == 0);

    auto string1 = CFSTR("string1");
    auto string2 = CFSTR("string2");

    CFSetAddValue(*set, string1);
    CFSetAddValue(*set, string2);

    expect(CFSetGetCount(*set) == 2);
  };

  return 0;
}
