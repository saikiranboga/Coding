#include<iostream>
using namespace std;
const long long MOD = 1000000007;


template< class T >
class Matrix{
public:
  int m,n;
  T *data;

  Matrix( int m, int n );
  Matrix( const Matrix< T > &matrix );
  
  const Matrix< T > &operator=( const Matrix< T > &A );
  const Matrix< T > operator*( const Matrix< T > &A );
  const Matrix< T > operator^( int P );
  
  ~Matrix();
};

template< class T >
Matrix< T >::Matrix( int m, int n )
{
    this->m = m;
    this->n = n;
    data = new T[m*n];
}

template< class T >
Matrix< T >::Matrix( const Matrix< T > &A )
{
    this->m = A.m;
    this->n = A.n;
    data = new T[m*n];
    for( int i = 0; i < m * n; i++ )
      data[i] = A.data[i];
}

template< class T >
Matrix< T >::~Matrix()
{
  delete [] data;
}

template< class T >
const Matrix< T > &Matrix< T >::operator=( const Matrix< T > &A )
{
  if( &A != this )
    {
      delete [] data;
      m = A.m;
      n = A.n;
      data = new T[m*n];
      for( int i = 0; i < m * n; i++ )
	data[i] = A.data[i];
    }
  return *this;
}

template< class T >
const Matrix< T > Matrix< T >::operator*( const Matrix< T > &A )
{
  Matrix C( m, A.n );
  for( int i = 0; i < m; ++i )
    for( int j = 0; j < A.n; ++j )
      {
	C.data[i*C.n+j]=0;
	for( int k = 0; k < n; ++k )
	  C.data[i*C.n+j] = ((C.data[i*C.n+j])%MOD + (data[i*n+k]*A.data[k*A.n+j])%MOD)%MOD;
      }
  return C;
}

template< class T >
const Matrix< T > Matrix< T >::operator^( int P )
{
  if( P == 1 ) return (*this);
  if( P & 1 ) return (*this)*((*this)^(P-1));
  Matrix B = (*this)^(P/2);
  return B*B;
}

int main()
{
  Matrix<long long int> M(4,4);
  M.data[0] = 1;M.data[1] = 2;M.data[2] = 3;M.data[3] = 1;
  M.data[4] = 1;M.data[5] = 0;M.data[6] = 0;M.data[7] = 0;
  M.data[8] = 0;M.data[9] = 1;M.data[10] = 0;M.data[11] = 0;
  M.data[12] = 0;M.data[13] = 0;M.data[14] = 1;M.data[15] = 0;

  Matrix<long long int> F(4,1);
  F.data[0]=12;
  F.data[1]=5;
  F.data[2]=2;
  F.data[3]=1;
  Matrix<long long int> Res(4,1);
  Matrix<long long int> MN(4,4);
  long long int N;
  while (cin >> N)
    if (N>4){
      MN = M^(N-4);
      Res = MN*F;
      cout << Res.data[0]<< endl;
    }
    else
      cout << F.data[4-N] << endl;
}
