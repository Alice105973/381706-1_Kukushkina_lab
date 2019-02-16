#include "Vector.h"
#include <gtest.h>

TEST(Vector, negative_size)
{
  ASSERT_ANY_THROW(TVector<int> A(-1));
}

TEST(Vector, copy_vector)
{
  TVector <int> A(2);
  A[0] = 9;
  TVector <int> B(A);

  ASSERT_TRUE(B == A);
}

TEST(Vector, can_get_size)
{
  TVector <int> A(6);
  ASSERT_EQ(6, A.GetSize());
}

TEST(Vector, negative_index)
{
  TVector <int> A(3);
  ASSERT_ANY_THROW(A[-1]);
}

TEST(Vector, out_of_bounds)
{
  TVector <int> A(3);
  ASSERT_ANY_THROW(A[3]);
}

TEST(Vector, index_operator)
{
  TVector <int> A(3);
  A[1] = 6;
  int temp = A[1] - 1;
  ASSERT_EQ(5, temp);
}

TEST(Vector, vectors_compare)
{
  TVector <int> A(3), B(3);
  for (int i = 0; i < A.GetSize(); i++) {
    A[i] = i;
    B[i] = i;
  }
  ASSERT_TRUE(A == B);
}

TEST(Vector, compare_non_equal_vectors)
{
  TVector <int> A(3), B(3);
  for (int i = 0; i < A.GetSize(); i++) {
    A[i] = i;
    B[i] = i + 1;
  }
  ASSERT_FALSE(A == B);
}

TEST(Vector, compare_different_size)
{
  TVector <int> A(3), B(4);
  ASSERT_EQ(A == B, 0);
}

TEST(Vector, non_equal_vectors_false)
{
  TVector <int> A(3), B(3);
  for (int i = 0; i < A.GetSize(); i++) {
    A[i] = i;
    B[i] = i;
  }
  ASSERT_FALSE(A != B);
}

TEST(Vector, non_equal_vectors_true)
{
  TVector <int> A(3), B(3);
  for (int i = 0; i < A.GetSize(); i++) {
    A[i] = i;
    B[i] = i + 1;
  }
  ASSERT_TRUE(A != B);
}

TEST(Vector, non_equal_vectors_with_different_sizes)
{
  TVector <int> A(3), B(4);
  ASSERT_TRUE(A != B);
}

TEST(Vector, compare)
{
  TVector <int> A(3), B(5);
  A = B;
  ASSERT_TRUE(A == B);
}

TEST(Vector, can_add_number)
{
  TVector <int> A(2), B(2);
  A = A + 1;
  B = A + 3;
  ASSERT_FALSE(A == B);
  A = A + 3;
  ASSERT_TRUE(A == B);
}

TEST(Vector, can_sub_number)
{
  TVector <int> A(2), B(2);
  A = A - 1;
  B = A - 3;
  ASSERT_FALSE(A == B);
  A = A - 3;
  ASSERT_TRUE(A == B);
}

TEST(Vector, can_multiply)
{
  TVector <int> A(2);
  A = A + 1;
  A = A * 3; 
  int temp = A[0] + A[1];
  ASSERT_TRUE(temp == 6);
}

TEST(Vector, can_sum_vectors)
{
  TVector <int> A(2), B(2), T(2);
  for (int i = 0; i < A.GetSize(); i++) {
    A[i] = i;
    B[i] = i + 1;
    T[i] = A[i] + B[i];
  }
  ASSERT_TRUE(T == (A + B));
}

TEST(Vector, sum_vectors_with_diff_size)
{
  TVector <int> A(2), B(3);
  ASSERT_ANY_THROW(A + B);
}

TEST(Vector, sub_vectors)
{
  TVector <int> A(2), B(2), T(2);
  for (int i = 0; i < A.GetSize(); i++) {
    A[i] = i;
    B[i] = i + 1;
    T[i] = A[i] - B[i];
  }
  ASSERT_TRUE(T == (A - B));
}

TEST(Vector, sub_vectors_with_diff_size)
{
  TVector <int> A(2), B(3);
  ASSERT_ANY_THROW(A - B);
}

TEST(Vector, mult_vectors)
{
  TVector <int> A(2), B(2);
  int temp = 0;
  for (int i = 0; i < A.GetSize(); i++) {
    A[i] = i;
    B[i] = i + 1;
    temp += i * (i + 1);
  }
  ASSERT_EQ(temp, A*B);
}

TEST(Vector, mult_vectors_with_diff_size)
{
  TVector <int> A(2), B(3);
  ASSERT_ANY_THROW(A*B);
}
