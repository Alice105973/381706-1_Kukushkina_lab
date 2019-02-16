#include "Queue.h"
#include <gtest.h>

TEST(Queue, negative_size)
{
  ASSERT_ANY_THROW(TQueue<int> A(-1));
}

TEST(Queue, can_put_and_get)
{
  TQueue <int> A(1);
  A.Enqueue(13);
  ASSERT_EQ(13, A.Dequeue());
}

TEST(Queue, is_full_false)
{
  TQueue <int> A(6);
  ASSERT_FALSE(A.IsFull());
}

TEST(Queue, is_full_true)
{
  TQueue <int> A(1);
  A.Enqueue(5);
  ASSERT_TRUE(A.IsFull());
}

TEST(Queue, is_empty_false)
{
  TQueue <int> A(1);
  A.Enqueue(5);
  ASSERT_FALSE(A.IsEmpty());
}

TEST(Queue, is_empty_true)
{
  TQueue <int> A(1);
  ASSERT_TRUE(A.IsEmpty());
}

TEST(Queue, dequeue_when_queue_is_empty)
{
  TQueue <int> A(1);
  ASSERT_ANY_THROW(A.Dequeue());
}

TEST(Queue, enqueue_when_queue_is_full)
{
  TQueue <int> A(1);
  A.Enqueue(1);
  ASSERT_ANY_THROW(A.Enqueue(2));
}

TEST(Queue, circular_enqueue)
{
  TQueue <int> A(3);
  A.Enqueue(1);
  A.Enqueue(2);
  A.Enqueue(3);
 
  A.Dequeue(); 
  A.Dequeue();

  A.Enqueue(4); 
  A.Enqueue(5);
  A.Dequeue();
  ASSERT_EQ(4, A.Dequeue());
}


TEST(Queue, output_order)
{
  TQueue<int> A(3);
  A.Enqueue(1), A.Enqueue(2), A.Enqueue(3);
  ASSERT_EQ(A.Dequeue(), 1);
  ASSERT_EQ(A.Dequeue(), 2);
  ASSERT_EQ(A.Dequeue(), 3);
}


