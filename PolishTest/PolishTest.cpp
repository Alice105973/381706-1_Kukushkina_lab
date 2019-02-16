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

TEST(Polish, convert_to_pol)
{
  char s[] = "9+8";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);
  ASSERT_EQ(B.Get(), '[');
  ASSERT_EQ(B.Get(), '9');
  ASSERT_EQ(B.Get(), ']');
  ASSERT_EQ(B.Get(), '[');
  ASSERT_EQ(B.Get(), '8');
  ASSERT_EQ(B.Get(), ']');
  ASSERT_EQ(B.Get(), '+');
}

TEST(Polish, sum)
{
  char s[] = "9+8";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);
  EXPECT_EQ(17, Rez(B));
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

TEST(Polish, valid_queue)
{
  TQueue<char> B(7);
  B.Put('[');
  B.Put('9');
  B.Put(']');
  B.Put('[');
  B.Put('8');
  B.Put(']');
  B.Put('+');
  ASSERT_NO_THROW(Rez(B));
  ASSERT_EQ(Rez(B), 17);
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

TEST(Polish, sum_two_digit_numbers) 
{
  char s[] = "43+57";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(100, Rez(B));
}

TEST(Polish, sub) 
{
  char s[] = "9-8";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(1, Rez(B));
}

TEST(Polish, mult)
{
  char s[] = "9*8";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(72, Rez(B));
}

TEST(Polish, mult_3_multipliers) 
{
  char s[] = "9*8*2";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(144, Rez(B));
}

TEST(Polish, correct_brackets_execution) 
{
  char s[] = "(9+8)*2";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);
  EXPECT_EQ(34, Rez(B));
}

TEST(Polish, operations_order) 
{
  char s[] = "9+8*2";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);
  Rez(B);
  EXPECT_EQ(25, Rez(B));
}

TEST(Polish, div)
{
  char s[] = "8/2";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(4, Rez(B));
}

TEST(Polish, operations_order_1) 
{
  char s[] = "(43+57)*43";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(4300, Rez(B));
}

TEST(Polish, operations_order_3)
{
  char s[] = "(43+57)/20";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(5, Rez(B));
}

TEST(Polish, operations_order_4) 
{
  char s[] = "(43+57)/(20+5)";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(4, Rez(B));
}

TEST(Polish, negative_first_num) 
{
  char s[] = "-5+(43+57)/20";
  TString A(s);
  TQueue<char> B;
  B = ConvertToPol(A);

  EXPECT_EQ(0, Rez(B));
}
