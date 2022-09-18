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

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";
}

TEST(Vector, count_constructor_with_default_value) {
  const size_t count = 10;

  stl_strings_vector a(count);
  ft_strings_vector  b(count);

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";

  for (size_t i = 0; i < a.size(); ++i)
    ASSERT_EQ(a[i], b[i]);
}

TEST(Vector, count_constructor_with_custom_value) {
  const size_t count = 10;
  const std::string custom_value("custom_value");

  stl_strings_vector a(count, custom_value);
  ft_strings_vector  b(count, custom_value);

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";

  for (size_t i = 0; i < a.size(); ++i)
    ASSERT_EQ(a[i], b[i]);
}
