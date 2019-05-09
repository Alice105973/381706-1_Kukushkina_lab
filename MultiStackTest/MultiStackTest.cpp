#include "gtest.h"
#include "MultiStack.h"

TEST(TNewStack, newstack_with_negative_size)
{
  int *a = NULL;
  ASSERT_ANY_THROW(TNewStack<int> S(-1, a));
}
 
TEST(TNewStack, create_newstack)
{
  int *a = NULL;
  ASSERT_NO_THROW(TNewStack<int> S(2, a));
}

TEST(TNewStack, copy_newstack)
{
  int *a = NULL;
  TNewStack<int> S(2, a);
  ASSERT_NO_THROW(TNewStack<int> S1(S));
}

TEST(TNewStack, get_free_mem)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Push(3);
  S.Push(2);
  ASSERT_EQ(3, S.GetFreeMem());
}

TEST(TNewStack, get_top)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Put(3);
  S.Put(2);
  ASSERT_EQ(2, S.GetTop());
}

TEST(TNewStack, get_size)
{
  int *a = NULL;
  TNewStack<int> S(5, a);
  ASSERT_EQ(5, S.GetSize());
}

TEST(TNewStack, set_multistack)
{
  int *a = new int[5];
  int *b = new int[5];
  TNewStack<int> S(5, a);
  S.SetMas(10, b);
  ASSERT_EQ(10, S.GetSize());
}

TEST(TNewStack, set_negative_size_multistack)
{
  int *a = new int[5];
  int *b = new int[5];
  TNewStack<int> S(5, a);
  ASSERT_ANY_THROW(S.SetMas(-1, b));
}

TEST(TNewStack, put_and_get)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Push(3);
  S.Push(2);
  ASSERT_EQ(2, S.Get());
  ASSERT_EQ(3, S.Get());
}

TEST(TMStack, create_mstack)
{
  ASSERT_NO_THROW(TMStack<int> A(5, 25));
}

TEST(TMStack, negative_size_mstack)
{
  ASSERT_ANY_THROW(TMStack<int> A(5, -1));
}

TEST(TMStack, mstack_with_zero_stacks)
{
  ASSERT_ANY_THROW(TMStack<int> A(0, 10));
}

TEST(TMStack, copy_mstack)
{
  TMStack<int> A(5, 25);
  ASSERT_NO_THROW(TMStack<int> B(A));
}

TEST(TMStack, get_size)
{
  TMStack<int> A(5, 25);
  ASSERT_EQ(A.GetSize(), 25);
}

TEST(TMStack, set_element)
{
  TMStack<int> A(5, 25);
  ASSERT_NO_THROW(A.Set(1, 2));
}

TEST(TMStack, full_mstack_set)
{
  TMStack<int> A(2, 4);
  A.Set(0, 1);
  A.Set(0, 2);
  A.Set(1, 3);
  A.Set(1, 4);
  ASSERT_ANY_THROW(A.Set(1,6));
}

TEST(TMStack, negative_index_set)
{
  TMStack<int> A(5, 25);
  ASSERT_ANY_THROW(A.Set(-2, 2));
}

TEST(TMStack, get_element)
{
  TMStack<int> A(5, 25);
  A.Set(2, 43);
  ASSERT_EQ(43, A.Get(2));
}

TEST(TMStack, repack)
{
  TMStack<int> A(2, 6);
  A.Set(0, 1);
  A.Set(0, 2);
  A.Set(0, 3);
  A.Set(1, 3);
  ASSERT_NO_THROW(A.Set(0,10));
  ASSERT_EQ(A.Get(0), 10);
}

TEST(TMStack, negative_index_get)
{
  TMStack<int> A(5, 25);
  A.Set(1, 43);
  ASSERT_ANY_THROW(A.Get(-1));
}

TEST(TMStack, empty_mstack_get)
{
  TMStack<int> A(2, 5);
  ASSERT_ANY_THROW(A.Get(1));
}

TEST(TMStack, output_order)
{
  TMStack <int> A(2, 5);
  A.Set(1, 1);
  A.Set(1, 2);
  A.Set(1, 3);
  ASSERT_EQ(3, A.Get(1));
  ASSERT_EQ(2, A.Get(1));
  ASSERT_EQ(1, A.Get(1));
}

TEST(TMStack, is_empty_true)
{
  TMStack<int> A(5, 25);
  ASSERT_TRUE(A.IsEmpty(1));
}

TEST(TMStack, is_empty_false)
{
  TMStack<int> A(5, 25);
  A.Set(1, 1);
  ASSERT_FALSE(A.IsEmpty(1));
}

TEST(TMStack, is_full_true)
{
  TMStack<int> A(5, 25);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  EXPECT_EQ(1, A.IsFull(1));
}

TEST(TMStack, is_full_false)
{
  TMStack<int> A(5, 25);
  A.Set(1, 43);
  A.Set(1, 43);
  A.Set(1, 43);
  ASSERT_FALSE(A.IsFull(1));
}

TEST(TMStack, is_full_or_empty)
{
  TMStack<int> A(5, 25);
  ASSERT_ANY_THROW(A.IsFull(-1));
  ASSERT_ANY_THROW(A.IsEmpty(-1));
}