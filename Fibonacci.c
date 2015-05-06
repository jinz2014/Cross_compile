int Fib1( int N )
{
    if( N <= 1 )
        return 1;
    else
        return Fib1( N - 1 ) + Fib1( N - 2 );
}

int Fib2( int N )
{
    int i, Last, NextToLast, Answer;

    if( N <= 1 )
        return 1;

    Last = NextToLast = 1;
    for( i = 2; i <= N; i++ )
    {
        Answer = Last + NextToLast;
        NextToLast = Last;
        Last = Answer;
    }

    return Answer;
}

int main()
{
  int fib1, fib2;

  fib1 = Fib1( 7 );
  fib2 = Fib2( 7 );

  if (fib1 != fib2)
    return 1;
  else
    return 0;
}
