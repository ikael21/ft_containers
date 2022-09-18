#include "testing.hpp"

TEST(Vector, default_constructor) {
  std::vector<std::string> a;
  ft::vector<std::string> b;

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";
  ASSERT_EQ(a.data(), a.data()) << "data";
}

TEST(Vector, count_constructor_with_zero_size) {
  const size_t count = 0;

  std::vector<std::string> a(count);
  ft::vector<std::string> b(count);

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";
}

TEST(Vector, count_constructor_with_default_value) {
  const size_t count = 10;

  std::vector<std::string> a(count);
  ft::vector<std::string> b(count);

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";

  for (size_t i = 0; i < a.size(); ++i)
    ASSERT_EQ(a[i], b[i]);
}

TEST(Vector, count_constructor_with_custom_value) {
  const size_t count = 10;
  const std::string custom_value("custom_value");

  std::vector<std::string> a(count, custom_value);
  ft::vector<std::string> b(count, custom_value);

  ASSERT_EQ(a.size(), b.size()) << "size";
  ASSERT_EQ(a.capacity(), b.capacity()) << "capacity";

  for (size_t i = 0; i < a.size(); ++i)
    ASSERT_EQ(a[i], b[i]);
}
