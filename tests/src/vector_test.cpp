#include "testing.hpp"


TEST(Vector, default_constructor) {
  std::vector<int> a;
  ft::vector<int> b;

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";
  ASSERT_EQ(a.data(), a.data()) << "data";
}

TEST(Vector, count_constructor_with_zero_size) {
  const size_t count = 0;

  std::vector<int> a(count);
  ft::vector<int> b(count);

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";
}

TEST(Vector, count_constructor_with_default_value) {
  const size_t count = 10;

  std::vector<int> a(count);
  ft::vector<int> b(count);

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";

  for (size_t i = 0; i < a.size(); ++i)
    ASSERT_EQ(a[i], b[i]);
}

TEST(Vector, count_constructor_with_custom_value) {
  const size_t count = 10;
  const int custom_value = 10000;

  std::vector<int> a(count, custom_value);
  ft::vector<int> b(count, custom_value);

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";

  for (size_t i = 0; i < a.size(); ++i)
    ASSERT_EQ(a[i], b[i]);
}
