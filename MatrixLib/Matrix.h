#pragma once
#include "Vector.h"

template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix &A);
  TMatrix(const TVector<TVector<T> > &A);
  virtual ~TMatrix();

  bool operator==(const TMatrix &A) const;
  bool operator!=(const TMatrix &A) const;
  TMatrix& operator=(const TMatrix &A);
  TMatrix operator+(const TMatrix &A);
  TMatrix operator-(const TMatrix &A);
  TMatrix<T> operator*(const TMatrix<T> &A);
  TMatrix<T> operator/(const TMatrix<T> &A);

  friend istream& operator>>(istream &is, TMatrix<T> &A);
  friend ostream& operator<<(ostream &os, const TMatrix<T> &A);
};

template <class T>
TMatrix<T>::TMatrix(int s) :TVector<TVector<T> >(s)
{
  if (s <= 0 || s > 1000)
    throw Exc("Invalid size");
  for (int i = 0; i < s; i++)
    this->vec[i] = TVector<T>(s - i);
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T> &A) :TVector<TVector<T> >(A)
{}

template <class T>
TMatrix<T>::TMatrix(const TVector<TVector<T>> &A) : TVector<TVector<T> >(A)
{}

template <class T>
TMatrix<T>::~TMatrix()
{}

template <class T >
bool TMatrix<T>::operator==(const TMatrix<T> &A) const
{
  return TVector<TVector<T>>::operator==(A);
}

template <class T>
bool TMatrix<T>::operator!=(const TMatrix<T> &A) const
{
  return TVector<TVector<T> >::operator!=(A);
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T> &A)
{
  TVector<TVector<T> >::operator=(A);
  return *this;
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T> &A)
{
  if (this->size == A.size)
    return TVector<TVector<T> >::operator+(A);
  else
    throw Exc("Different sizes");
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T> &A)
{
  if (this->size == A.size)
    return TVector<TVector<T>>::operator-(A);
  else
    throw Exc("Different sizes");
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T> &A)
{
  if (this->size != A.size)
    throw Exc("Different sizes");
  TMatrix <T> rez(this->size);
  for (int i = 0; i < this->size; i++)
    for (int j = i; j < this->size; j++)
    {
      for (int k = i; k <= j; k++)
        rez.vec[i][j - i] += this->vec[i][k - i] * A.vec[k][j - k];
    }
  return rez;
}

template <class T>
TMatrix<T> TMatrix<T>::operator/(const TMatrix<T> &A)
{
  if (this->size != A.size)
    throw Exc("error size operand");
  TMatrix <T> copy(*this);
  TMatrix <T> rez(this->size);
  TMatrix <T> copyT(A);

  for (int i = 0; i < this->size; i++)
    rez[i][0] = 1 / copyT[i][0];

  for (int i = 0; i < this->size - 1; i++)
    for (int j = 1; j < this->size - i; j++)
    {
      if (copyT[i][j] != 0)
      {
        T temp = copyT[i][j];
        rez[i][j] = (-1) * copyT[i][j] * rez[i + j][0];
        for (int k = j, l = 0; k < this->size - i; k++)
          copyT[i][k] = copyT[i][k] - copyT[j][l++] * temp;
      }
    }
  rez = copy * rez;
  return rez;
}


template <class T>
istream& operator>>(istream &in, TMatrix<T> &A)
{
  for (int i = 0; i < A.size; i++)
    in >> A.vec[i];
  return in;
}

template <class T>
ostream & operator<<(ostream &out, const TMatrix<T> &A)
{
  for (int i = 0; i < A.size; i++)
  {
    for (int k = 0; k < i; k++)
      out << "  ";
    out << A.vec[i] << endl;
  }
  return out;
}
