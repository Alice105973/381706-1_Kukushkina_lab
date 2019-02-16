#include "Stack.h"
#include <gtest.h>

TEST(Stack, stack_with_negative_size)
{
  ASSERT_ANY_THROW(TStack <int> A(-1));
}

TEST(Stack, can_put_and_get)
{
  TStack <int> A(1);
  A.Put(3);
  ASSERT_EQ(3, A.Get());
}

TEST(Stack, is_full_false)
{
  TStack <int> A(1);
  ASSERT_FALSE(A.IsFull());
}

TEST(Stack, is_full_true)
{
  TStack <int> A(1);
  A.Put(5);
  ASSERT_TRUE(A.IsFull());
}

TEST(Stack, is_empty_false)
{
  TStack <int> A(1);
  A.Put(5);
  ASSERT_FALSE(A.IsEmpty());
}

TEST(Stack, is_empty_true)
{
  TStack <int> A(1);
  ASSERT_TRUE(A.IsEmpty());
}

TEST(Stack, full_stack_put)
{
  TStack <int> A(1);
  A.Put(2);
  ASSERT_ANY_THROW(A.Put(5));
}

TEST(Stack, empty_stack_get)
{
  TStack <int> A(1);
  ASSERT_ANY_THROW(A.Get());
}

TEST(Stack, compare_true)
{
  TStack <int> A(1), B(1);
  A.Put(1);
  B.Put(1);
  ASSERT_TRUE(A == B);
}

TEST(Stack, compare_false)
{
  TStack <int> A(1), B(1);
  A.Put(1);
  B.Put(2);
  ASSERT_FALSE(A == B);
}

TEST(Stack, different_size_scompare)
{
  TStack <int> A(1), B(3);
  ASSERT_FALSE(A == B);
}

TEST(Stack, different_top_compare)
{
  TStack <int> A(3), B(3);
  A.Put(1);
  B.Put(1), B.Put(2);
  ASSERT_FALSE(A == B);
}

TEST(Stack, non_equal_false)
{
  TStack <int> A(1), B(1);
  A.Put(1);
  B.Put(1);
  ASSERT_FALSE(A != B);
}

TEST(Stack, non_equal_true)
{
  TStack <int> A(1), B(1);
  A.Put(1);
  B.Put(2);
  ASSERT_TRUE(A != B);
}

TEST(Stack, non_equal_different_size)
{
  TStack <int> A(1), B(3);
  ASSERT_TRUE(A != B);
}

TEST(Stack, non_equal_different_top)
{
  TStack <int> A(3), B(3);
  A.Put(1);
  B.Put(1), B.Put(2);
  ASSERT_TRUE(A != B);
}

TEST(Stack, assign)
{
  TStack <int> A(3), B(1);
  A.Put(1), A.Put(2), A.Put(3);
  B = A;
  ASSERT_TRUE(B == A);
}

TEST(Stack, output_order)
{
  TStack <int> A(3);
  A.Put(1), A.Put(2), A.Put(3);
  ASSERT_EQ(A.Get(), 3);
  ASSERT_EQ(A.Get(), 2);
  ASSERT_EQ(A.Get(), 1);
}
