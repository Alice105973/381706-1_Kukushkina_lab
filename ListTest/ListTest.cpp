#include "List.h"
#include <gtest.h>

TEST(Elem, get_data)
{
  TElem<int> e(3, 0);
  ASSERT_EQ(e.GetData(), 3);
}

TEST(Elem, get_next)
{
  TElem<int>* a = 0;
  TElem<int> e(3, a);
  ASSERT_EQ(e.GetNext(), a);
}

TEST(Elem, default_elem)
{
  TElem<int> e;
  ASSERT_EQ(e.GetData(), 0);
}

TEST(Elem, set_data)
{
  TElem<int> e;
  e.SetData(5);
  ASSERT_EQ(e.GetData(), 5);
}

TEST(Elem, set_next)
{
  TElem<int>* a = 0;
  TElem<int> e;
  e.SetNext(a);

  ASSERT_EQ(e.GetNext(), a);
}

TEST(Elem, copy_elem)
{
  TElem<int> e(2, 0);
  TElem<int> e1(e);

  ASSERT_EQ(e.GetNext(), e1.GetNext());
  ASSERT_EQ(e.GetData(), e1.GetData());
}

TEST(List, is_empty_true)
{
  TList<int> list;
  ASSERT_TRUE(list.IsEmpty());
}

TEST(List, is_empty_false)
{
  TList<int> list;
  list.PutBegin(1);
  ASSERT_FALSE(list.IsEmpty());
}

TEST(List, is_full_false)
{
  TList<int> list;
  ASSERT_FALSE(list.IsFull());
}

TEST(List, get_begin)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);

  ASSERT_EQ(list.GetBegin(), 3);
  ASSERT_EQ(list.GetBegin(), 2);
  ASSERT_EQ(list.GetBegin(), 1);
}

TEST(List, get_end)
{
  TList<int> list;
  list.PutBegin(3);
  list.PutBegin(2);

  ASSERT_EQ(list.GetEnd(), 3);
}

TEST(List, create_list)
{
  ASSERT_NO_THROW(TList<int> list);
}

TEST(List, copy_list)
{
  TList<int> list1;
  ASSERT_NO_THROW(TList<int> list(list1));
}

TEST(List, put_begin)
{
  TList<int> list;
  list.PutBegin(3);
  list.PutBegin(2);
  list.PutBegin(1);

  ASSERT_EQ(list.GetBegin(), 1);
  ASSERT_EQ(list.GetBegin(), 2);
  ASSERT_EQ(list.GetBegin(), 3);
}

TEST(List, put_end)
{
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(3);

  ASSERT_EQ(list.GetBegin(), 1);
  ASSERT_EQ(list.GetBegin(), 2);
  ASSERT_EQ(list.GetBegin(), 3);
}

TEST(List, get_size)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);

  ASSERT_EQ(list.GetSize(), 2);
}

TEST(List, get_zero_size)
{
  TList<int> list;

  ASSERT_EQ(list.GetSize(), 0);
}

TEST(List, get_empty_list)
{
  TList<int> list;

  ASSERT_ANY_THROW(list.Get(1));
}

TEST(List, get_invalid_index)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);

  ASSERT_ANY_THROW(list.Get(0));
  ASSERT_ANY_THROW(list.Get(3));
}

TEST(List, get_elem)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);

  ASSERT_EQ(list.Get(1), 2);
}

TEST(List, put_invalid_index)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(1);
  list.PutBegin(1);

  ASSERT_ANY_THROW(list.Put(0, 1));
  ASSERT_ANY_THROW(list.Put(3, 1));
}

TEST(List, put_elem)
{
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(3);
  list.Put(1, 10);

  ASSERT_EQ(list.Get(1), 10);
  ASSERT_EQ(list.Get(1), 2);
}




TEST(List, get_begin_get_empty_list)
{
  TList<int> list;

  ASSERT_ANY_THROW(list.GetBegin());
  ASSERT_ANY_THROW(list.GetEnd());
}

TEST(List, copy_list_1)
{
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(3);
  TList<int> list1(list);

  ASSERT_EQ(list.GetBegin(), list1.GetBegin());
  ASSERT_EQ(list.GetBegin(), list1.GetBegin());
  ASSERT_EQ(list.GetBegin(), list1.GetBegin());
}



