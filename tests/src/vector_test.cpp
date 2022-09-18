#include "testing.hpp"

typedef std::vector<std::string> stl_strings_vector;
typedef ft::vector<std::string> ft_strings_vector;

TEST(Vector, default_constructor) {
  stl_strings_vector a;
  ft_strings_vector  b;

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";
  ASSERT_EQ(a.data(), a.data()) << "data";
}

TEST(Vector, count_constructor_with_zero_size) {
  const size_t count = 0;

  stl_strings_vector a(count);
  ft_strings_vector  b(count);

  ASSERT_EQ(a.size(), count) << "size of stl";
  ASSERT_EQ(a.size(), count) << "size of ft";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";
  ASSERT_EQ(a.data(), a.data()) << "data";
}

TEST(Vector, count_constructor_with_default_value) {
  const size_t count = 10;

  stl_strings_vector a(count);
  ft_strings_vector  b(count);

  ASSERT_EQ(a.size(), count) << "size of stl";
  ASSERT_EQ(a.size(), count) << "size of ft";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";

  for (size_t i = 0; i < a.size(); ++i)
    ASSERT_EQ(a[i], b[i]) << "each value";
}

TEST(Vector, count_constructor_with_custom_value) {
  const size_t count = 10;
  const std::string custom_value("custom_value");

  stl_strings_vector a(count, custom_value);
  ft_strings_vector  b(count, custom_value);

  ASSERT_EQ(a.size(), count) << "size of stl";
  ASSERT_EQ(b.size(), count) << "size of ft";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";

  for (size_t i = 0; i < a.size(); ++i)
    ASSERT_EQ(a[i], b[i]) << "each value";
}

TEST(Vector, iterators_constructor) {
  const size_t strings_size = 10;
  std::string strings[strings_size];

  strings[strings_size / 2] = "different string";

  stl_strings_vector a(strings, strings + strings_size);
  ft_strings_vector  b(strings, strings + strings_size);

  ASSERT_EQ(a.size(), strings_size) << "size of stl";
  ASSERT_EQ(b.size(), strings_size) << "size of ft";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";

  for (size_t i = 0; i < a.size(); ++i)
    ASSERT_EQ(a[i], b[i]) << "each value";
}

TEST(Vector, iterators_constructor_with_zero_diff) {
  const std::string* ptr = NULL;

  stl_strings_vector a(ptr, ptr);
  ft_strings_vector  b(ptr, ptr);

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";
  ASSERT_EQ(a.data(), a.data()) << "data";
}
