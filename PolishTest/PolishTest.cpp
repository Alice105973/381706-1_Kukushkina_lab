#include "gtest.h"
#include "Polish.h"

TEST(Polish, get_priority)
{

  ASSERT_EQ(1, GetPrt(')'));
  ASSERT_EQ(1, GetPrt('('));
  ASSERT_EQ(2, GetPrt('+'));
  ASSERT_EQ(2, GetPrt('-'));
  ASSERT_EQ(3, GetPrt('*'));
  ASSERT_EQ(3, GetPrt('/'));
  ASSERT_ANY_THROW(GetPrt('!'));
}

TEST(Polish, check_is_op)
{
  ASSERT_EQ(1, IsOp(')'));
  ASSERT_EQ(1, IsOp('('));
  ASSERT_EQ(1, IsOp('+'));
  ASSERT_EQ(1, IsOp('-'));
  ASSERT_EQ(1, IsOp('*'));
  ASSERT_EQ(1, IsOp('/'));
  ASSERT_EQ(false, IsOp('4'));
  ASSERT_EQ(false, IsOp('!'));
}

TEST(Polish, math_expression_with_invalid_symbol)
{
  char s[] = "9!8";
  TString A(s);
  TQueue<char> B;
  ASSERT_ANY_THROW(ConvertToPol(A));
}

TEST(Polish, invalid_brackets_num)
{
  char s[] = "(9*8";
  TString A(s);
  TQueue<char> B;
  ASSERT_ANY_THROW(ConvertToPol(A));
}

TEST(Polish, math_expression_begins_with_invalid_symbol)
{
  char s[] = "*9*8";
  TString A(s);
  TQueue<char> B;
  ASSERT_ANY_THROW(ConvertToPol(A));
}

TEST(Polish, queue_begins_with_invalid_symbol)
{
  TQueue<char> B(7);
  B.Put('+');
  B.Put('[');
  B.Put('9');
  B.Put(']');
  B.Put('[');
  B.Put('8');
  B.Put(']');
  ASSERT_ANY_THROW(Rez(B));
}

TEST(Polish, invalid_queue_1)
{
  TQueue<char> B(7);
  B.Put('[');
  B.Put('9');
  B.Put(']');
  B.Put('*');
  B.Put('[');
  B.Put('8');
  B.Put(']');
  ASSERT_ANY_THROW(Rez(B));
}

TEST(Polish, invalid_queue_2)
{
  TQueue<char> B(10);
  B.Put('[');
  B.Put('9');
  B.Put(']');

  B.Put('[');
  B.Put('9');
  B.Put(']');
  
  B.Put('+');

  B.Put('[');
  B.Put('4');
  B.Put(']');
  
  ASSERT_ANY_THROW(Rez(B));
}

TEST(Polish, invalid_queue_3)
{
  TQueue<char> B(7);
  B.Put('[');
  B.Put('9');
  B.Put(']');

  B.Put('[');
  B.Put('9');
  B.Put(']');

  B.Put('&');

  ASSERT_ANY_THROW(Rez(B));
}
