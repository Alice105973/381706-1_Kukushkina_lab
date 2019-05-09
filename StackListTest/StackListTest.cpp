#include "gtest.h"
#include "StackList.h"

TEST(TStackList, create_default_stack)
{
  ASSERT_NO_THROW(TStackList<int> A);
}

TEST(TStackList, create_stack)
{
  ASSERT_NO_THROW(TStackList<int> A(3));
}

TEST(TStackList, negative_size_stack)
{
  ASSERT_ANY_THROW(TStackList<int> A(-1));
}

TEST(TStackList, copy_stack)
{
  TStackList<int> S(1);
  ASSERT_NO_THROW(TStackList<int> A(S));
}

TEST(TStackList, get_max_size)
{
  TStackList<int> S(15);
  ASSERT_EQ(S.GetMaxSize(), 15);
}

TEST(TStackList, get_size)
{
  TStackList<int> S(5);
  S.Put(1);
  S.Put(2);
  ASSERT_EQ(S.GetSize(), 2);
}

TEST(TStackList, put)
{
  TStackList<int> A;

  ASSERT_NO_THROW(A.PutBegin(43));
}

TEST(TStackList, put_full_stack)
{
  TStackList<int> S(1);
  S.Put(2);
  ASSERT_ANY_THROW(S.Put(5));
}

TEST(TStackList, get)
{
  TStackList<int> A;
  A.Put(42);
  EXPECT_EQ(42, A.Get());
}

TEST(TStackList, empty_stack_get)
{
  TStackList <int> S(5);
  ASSERT_ANY_THROW(S.Get());
}

TEST(TStackList, is_empty_true)
{
  TStackList<int> S(5);
  ASSERT_TRUE(S.IsEmpty());
}

TEST(TStackList, empty_stack_print)
{
  TStackList<int> S(5);
  ASSERT_ANY_THROW(S.Print());
}

TEST(TStackList, is_empty_false)
{
  TStackList<int> S(1);
  S.Put(5);
  ASSERT_FALSE(S.IsEmpty());
}

TEST(TStackList, output_order)
{
  TStackList<int> S(3);
  S.Put(1), S.Put(2), S.Put(3);
  ASSERT_EQ(S.Get(), 3);
  ASSERT_EQ(S.Get(), 2);
  ASSERT_EQ(S.Get(), 1);
}