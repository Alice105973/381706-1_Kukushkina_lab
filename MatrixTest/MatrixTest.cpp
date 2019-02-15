#include "Matrix.h"
#include <gtest.h>

TEST(Matrix, default_matrix)
{
  ASSERT_NO_THROW(TMatrix <int> A());
}

TEST(Matrix, create_matrix)
{
  ASSERT_NO_THROW(TMatrix <int> A(3));
}

TEST(Matrix, matrix_with_zero_size)
{
  ASSERT_ANY_THROW(TMatrix <int> A(0));
}

TEST(Matrix, matrix_with_negative_size)
{
  ASSERT_ANY_THROW(TMatrix <int> A(-1));
}

TEST(Matrix, matrix_with_large_size)
{
  ASSERT_ANY_THROW(TMatrix <int> A(10001));
}

TEST(Matrix, compare_matrix_true)
{
  TMatrix <int> A(3), B(3);
  for (int i = 0; i < A.GetSize(); i++)
    for (int j = 0; j < A.GetSize() - i; j++)
    {
      A[i][j] = i;
      B[i][j] = i;
    }
  ASSERT_TRUE(A == B);
}

TEST(Matrix, compare_matrix_false)
{
  TMatrix <int> A(3), B(3);
  for (int i = 0; i < A.GetSize(); i++)
    for (int j = 0; j < A.GetSize() - i; j++)
    {
      A[i][j] = i;
      B[i][j] = i + 1;
    }
  ASSERT_FALSE(A == B);
}

TEST(Matrix, compare_matrix_with_diff_size)
{
  TMatrix <int> A(2), B(3);
  ASSERT_FALSE(A == B);
}

TEST(Matrix, non-equal_matrix_true)
{
  TMatrix <int> A(3), B(3);
  for (int i = 0; i < A.GetSize(); i++)
    for (int j = 0; j < A.GetSize() - i; j++)
    {
      A[i][j] = i;
      B[i][j] = i + 1;
    }
  ASSERT_TRUE(A != B);
}

TEST(Matrix, non-equal_matrix_false)
{
  TMatrix <int> A(3), B(3);
  for (int i = 0; i < A.GetSize(); i++)
    for (int j = 0; j < A.GetSize() - i; j++)
    {
      A[i][j] = i;
      B[i][j] = i;
    }
  ASSERT_FALSE(A != B);
}

TEST(Matrix, non-equal_matrix_with_diff_size)
{
  TMatrix <int> A(2), B(3);
  ASSERT_TRUE(A != B);
}

TEST(Matrix, assign_matrix)
{
  TMatrix <int> A(3), B(5);
  A = B;
  ASSERT_TRUE(A == B);
}

TEST(Matrix, add_matrix)
{
  TMatrix <int> A(2), B(2), T(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2 - i; j++) {
      A[i][j] = i + j;
      B[i][j] = i + j + 2;
      T[i][j] = A[i][j] + B[i][j];
    }
  ASSERT_TRUE(T == (A + B));
}

TEST(Matrix, add_matrix_with_diff_size)
{
  TMatrix <int> A(2), B(3);
  ASSERT_ANY_THROW(A + B);
}

TEST(Matrix, sub_matrix)
{
  TMatrix <int> A(2), B(2), T(2);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2 - i; j++)
    {
      A[i][j] = i + j;
      B[i][j] = i + j + 2;
      T[i][j] = A[i][j] - B[i][j];
    }
  ASSERT_TRUE(T == (A - B));
}

TEST(Matrix, sub_matrix_with_diff_size)
{
  TMatrix <int> A(2), B(3);
  ASSERT_ANY_THROW(A - B);
}

TEST(Matrix, mult_matrix)
{
  TMatrix <int> A(3), B(3), T(3);
  A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
  A[1][0] = 4; A[1][1] = 5;
  A[2][0] = 6;

  B[0][0] = 3; B[0][1] = 5; B[0][2] = 7;
  B[1][0] = 9; B[1][1] = 11;
  B[2][0] = 13;

  T[0][0] = 3; T[0][1] = 23; T[0][2] = 68;
  T[1][0] = 36; T[1][1] = 109;
  T[2][0] = 78;
  ASSERT_TRUE(T == (A * B));
}

TEST(Matrix, div_matrix)
{
  TMatrix<int> A(3), B(3), T(3);
  int k = 1;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3 - i; j++)
      A[i][j] = k++;

  B[0][0] = 1;
  B[0][1] = 2;
  B[0][2] = 3;
  B[1][0] = 1;
  B[1][1] = 2;
  B[2][0] = 1;

  T[0][0] = 1; T[0][1] = 0; T[0][2] = 0;
  T[1][0] = 4; T[1][1] = -3;
  T[2][0] = 6;
  ASSERT_TRUE(T == (A / B));
}

TEST(Matrix, div_matrix_with_diff_size)
{
  TMatrix <int> A(2), B(3);
  ASSERT_ANY_THROW(A / B);
}

TEST(Matrix, mult_matrix_with_diff_size)
{
  TMatrix <int> A(2), B(3);
  ASSERT_ANY_THROW(A * B);
}