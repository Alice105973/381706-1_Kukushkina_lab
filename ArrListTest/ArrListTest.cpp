#include <gtest.h>
#include "ArrList.h"

TEST(ArrList, can_create_default_list)
{
  ASSERT_NO_THROW(TArrList <int> A());
}

TEST(ArrList, can_create_list_with_specified_size)
{
  ASSERT_NO_THROW(TArrList <int> A(3));
}

TEST(ArrList, can_copy_empty_list)
{
  TArrList <int> A(1);
  A.PutStart(1);
  TArrList <int> B(A);
  ASSERT_EQ(A.GetStart(), B.GetStart());
}

TEST(ArrList, can_copy_list)
{
  TArrList <int> A(3);

  ASSERT_NO_THROW(TArrList <int> B(A));
}

TEST(ArrList, list_with_zero_size)
{
  ASSERT_ANY_THROW(TArrList <int> A(0));
}

TEST(ArrList, list_with_negative_size)
{
  ASSERT_ANY_THROW(TArrList <int> A(-6));
}

TEST(ArrList, can_get_and_put_start)
{
  TArrList <int> A(2);
  A.PutStart(1);
  A.PutStart(2);
  ASSERT_EQ(2, A.GetStart());
  ASSERT_EQ(1, A.GetStart());
}

TEST(ArrList, can_get_and_put_end)
{
  TArrList <int> A(2);
  A.PutEnd(1);
  A.PutEnd(2);
  ASSERT_EQ(2, A.GetEnd());
  ASSERT_EQ(1, A.GetEnd());
}

TEST(ArrList, is_full_false)
{
  TArrList <int> A(1);
  ASSERT_FALSE(A.IsFull());
}

TEST(ArrList, is_full_true)
{
  TArrList <int> A(1);
  A.PutStart(13);
  ASSERT_TRUE(A.IsFull());
}

TEST(ArrList, is_empty_false)
{
  TArrList <int> A(1);
  A.PutStart(13);
  ASSERT_FALSE(A.IsEmpty());
}

TEST(ArrList, is_empty_true)
{
  TArrList <int> A(1);
  ASSERT_TRUE(A.IsEmpty());
}

TEST(ArrList, full_list_put_start)
{
  TArrList <int> A(1);
  A.PutStart(1);
  ASSERT_ANY_THROW(A.PutStart(2));
}

TEST(ArrList, full_list_put_end)
{
  TArrList <int> A(1);
  A.PutStart(13);
  ASSERT_ANY_THROW(A.PutEnd(2));
}

TEST(ArrList, empty_list_get_start)
{
  TArrList <int> A(1);
  ASSERT_ANY_THROW(A.GetStart());
}

TEST(ArrList, empty_list_get_end)
{
  TArrList <int> A(1);
  ASSERT_ANY_THROW(A.GetEnd());
}

TEST(ArrList, output_order)
{
  TArrList <int> A(3);
  A.PutStart(1); 
  A.PutEnd(4);   
  A.PutStart(3); 
  ASSERT_EQ(4, A.GetEnd());      
  ASSERT_EQ(3, A.GetStart());   
  ASSERT_EQ(1, A.GetEnd());
}

TEST(ArrList, empty_list_get)
{
  TArrList <int> A(13);
  ASSERT_ANY_THROW(A.Get(7));
}

TEST(ArrList, full_list_put)
{
  TArrList <int> A(3);
  A.PutEnd(1);
  A.PutEnd(2);
  A.PutEnd(3);

  ASSERT_ANY_THROW(A.Put(1, 6));
}

TEST(ArrList, wrong_put_index)
{
  TArrList <int> A(5);
  A.PutEnd(1);
  A.PutEnd(2);
  A.PutEnd(3);

  ASSERT_ANY_THROW(A.Put(13, 7));
}

TEST(ArrList, wrong_get_index)
{
  TArrList <int> A(3);
  A.PutEnd(1);
  A.PutEnd(2);
  A.PutEnd(3);

  ASSERT_ANY_THROW(A.Get(7));
}

TEST(ArrList, can_get_elem)
{
  TArrList <int> L(3);
  L.PutEnd(1);
  L.PutEnd(2);
  L.PutEnd(3);

  ASSERT_EQ(L.Get(1), 2);
}

TEST(ArrList, can_put_elem)
{
  TArrList <int> L(4);
  L.PutEnd(1);
  L.PutEnd(2);
  L.PutEnd(3);
  L.Put(2, 10);

  ASSERT_EQ(L.Get(1), 2);
  ASSERT_EQ(L.Get(1), 10);
}