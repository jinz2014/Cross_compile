        /* My naive random number generator */
        unsigned short myrand()  
        {
          static unsigned short next = 1;
          next = (next << 7) + next;
          //printf("next = %d\n", next >> 7);
          return (next >> 7);
        }

        /* This file contains a collection of sorting routines */

        typedef int ElementType;

        void
        Swap( ElementType *Lhs, ElementType *Rhs )
        {
            ElementType Tmp = *Lhs;
            *Lhs = *Rhs;
            *Rhs = Tmp;
        }

/* START: fig7_2.txt */
        void
        InsertionSort( ElementType A[ ], int N )
        {
            int j, P;
            ElementType Tmp;

/* 1*/      for( P = 1; P < N; P++ )
            {
/* 2*/          Tmp = A[ P ];
/* 3*/          for( j = P; j > 0 && A[ j - 1 ] > Tmp; j-- )
/* 4*/              A[ j ] = A[ j - 1 ];
/* 5*/          A[ j ] = Tmp;
            }
        }
/* END */

/* START: fig7_4.txt */
        void
        Shellsort( ElementType A[ ], int N )
        {
            int i, j, Increment;
            ElementType Tmp;

/* 1*/      for( Increment = N / 2; Increment > 0; Increment /= 2 )
/* 2*/          for( i = Increment; i < N; i++ )
                {
/* 3*/              Tmp = A[ i ];
/* 4*/              for( j = i; j >= Increment; j -= Increment )
/* 5*/                  if( Tmp < A[ j - Increment ] )
/* 6*/                      A[ j ] = A[ j - Increment ];
                        else
/* 7*/                      break;
/* 8*/              A[ j ] = Tmp;
                }
        }
/* END */

/* START: fig7_8.txt */

        #define LeftChild( i )  ( 2 * ( i ) + 1 )

        void
        PercDown( ElementType A[ ], int i, int N )
        {
            int Child;
            ElementType Tmp;

/* 1*/      for( Tmp = A[ i ]; LeftChild( i ) < N; i = Child )
            {
/* 2*/          Child = LeftChild( i );
/* 3*/          if( Child != N - 1 && A[ Child + 1 ] > A[ Child ] )
/* 4*/              Child++;
/* 5*/          if( Tmp < A[ Child ] )
/* 6*/              A[ i ] = A[ Child ];
                else
/* 7*/              break;
            }
/* 8*/      A[ i ] =Tmp;
        }

        void
        Heapsort( ElementType A[ ], int N )
        {
            int i;

/* 1*/      for( i = N / 2; i >= 0; i-- )  /* BuildHeap */
/* 2*/          PercDown( A, i, N );
/* 3*/      for( i = N - 1; i > 0; i-- )
            {
/* 4*/          Swap( &A[ 0 ], &A[ i ] );  /* DeleteMax */
/* 5*/          PercDown( A, 0, i );
            }
        }
/* END */

/* START: fig7_10.txt
        // Lpos = start of left half, Rpos = start of right half 

        void
        Merge( ElementType A[ ], ElementType TmpArray[ ],
                        int Lpos, int Rpos, int RightEnd )
        {
            int i, LeftEnd, NumElements, TmpPos;

            LeftEnd = Rpos - 1;
            TmpPos = Lpos;
            NumElements = RightEnd - Lpos + 1;

            // main loop
            while( Lpos <= LeftEnd && Rpos <= RightEnd )
                if( A[ Lpos ] <= A[ Rpos ] )
                    TmpArray[ TmpPos++ ] = A[ Lpos++ ];
                else
                    TmpArray[ TmpPos++ ] = A[ Rpos++ ];

            while( Lpos <= LeftEnd )  // Copy rest of first half
                TmpArray[ TmpPos++ ] = A[ Lpos++ ];
            while( Rpos <= RightEnd ) // Copy rest of second half
                TmpArray[ TmpPos++ ] = A[ Rpos++ ];

            // Copy TmpArray back 
            for( i = 0; i < NumElements; i++, RightEnd-- )
                A[ RightEnd ] = TmpArray[ RightEnd ];
        }

        void
        MSort( ElementType A[ ], ElementType TmpArray[ ],
                        int Left, int Right )
        {
            int Center;

            if( Left < Right )
            {
                Center = ( Left + Right ) / 2;
                MSort( A, TmpArray, Left, Center );
                MSort( A, TmpArray, Center + 1, Right );
                Merge( A, TmpArray, Left, Center + 1, Right );
            }
        }

        void
        Mergesort( ElementType A[ ], int N )
        {
            ElementType *TmpArray;

            TmpArray = malloc( N * sizeof( ElementType ) );
            if( TmpArray != NULL )
            {
                MSort( A, TmpArray, 0, N - 1 );
                free( TmpArray );
            }
        }
END */


/* START: fig7_13.txt */
        /* Return median of Left, Center, and Right */
        /* Order these and hide the pivot */

        ElementType
        Median3( ElementType A[ ], int Left, int Right )
        {
            int Center = ( Left + Right ) / 2;

            if( A[ Left ] > A[ Center ] )
                Swap( &A[ Left ], &A[ Center ] );
            if( A[ Left ] > A[ Right ] )
                Swap( &A[ Left ], &A[ Right ] );
            if( A[ Center ] > A[ Right ] )
                Swap( &A[ Center ], &A[ Right ] );

            /* Invariant: A[ Left ] <= A[ Center ] <= A[ Right ] */

            Swap( &A[ Center ], &A[ Right - 1 ] );  /* Hide pivot */
            return A[ Right - 1 ];                /* Return pivot */
        }
/* END */

/* START: fig7_14.txt */
        #define Cutoff ( 3 )

        void
        Qsort( ElementType A[ ], int Left, int Right )
        {
            int i, j;
            ElementType Pivot;

/* 1*/      if( Left + Cutoff <= Right )
            {
/* 2*/          Pivot = Median3( A, Left, Right );
/* 3*/          i = Left; j = Right - 1;
/* 4*/          for( ; ; )
                {
/* 5*/              while( A[ ++i ] < Pivot ){ }
/* 6*/              while( A[ --j ] > Pivot ){ }
/* 7*/              if( i < j )
/* 8*/                  Swap( &A[ i ], &A[ j ] );
                    else
/* 9*/                  break;
                }
/*10*/          Swap( &A[ i ], &A[ Right - 1 ] );  /* Restore pivot */

/*11*/          Qsort( A, Left, i - 1 );
/*12*/          Qsort( A, i + 1, Right );
            }
            else  /* Do an insertion sort on the subarray */
/*13*/          InsertionSort( A + Left, Right - Left + 1 );
        }
/* END */


/* START: fig7_12.txt */
        void
        Quicksort( ElementType A[ ], int N )
        {
            Qsort( A, 0, N - 1 );
        }
/* END */


        /* ROUTINES TO TEST THE SORTS */

        void
        Permute( ElementType A[ ], int N )
        {
            int i;

            for( i = 0; i < N; i++ )
                A[ i ] = i;
            for( i = 1; i < N; i++ )
                Swap( &A[ i ], &A[ myrand() ] );
        }

        int
        Checksort( ElementType A[ ], int N )
        {
            int i;
            for( i = 0; i < N; i++ )
                if( A[ i ] != i )
                    //printf("Sort Fails\n");
                    return 1;
            return 0;
            //printf("Check completed\n");
        }

        void
        Copy( ElementType Lhs[ ], const ElementType Rhs[ ], int N )
        {
            int i;
            for( i = 0; i < N; i++ )
                Lhs[ i ] = Rhs[ i ];
        }

        #define MaxSize 32
        int Arr1[ MaxSize ];
        int Arr2[ MaxSize ];

        int main( )
        {
            int i;
            int sort1, sort2, sort3, sort4;

            for( i = 0; i < 2; i++ )
            {
                Permute( Arr2, MaxSize );
                Copy( Arr1, Arr2, MaxSize );
                InsertionSort( Arr1, MaxSize );
                sort1 = Checksort( Arr1, MaxSize );
                if (sort1) return 1;

                Copy( Arr1, Arr2, MaxSize );
                Shellsort( Arr1, MaxSize );
                sort2 = Checksort( Arr1, MaxSize );
                if (sort2) return 1;

                Copy( Arr1, Arr2, MaxSize );
                Heapsort( Arr1, MaxSize );
                sort3 = Checksort( Arr1, MaxSize );
                if (sort3) return 1;

                //Copy( Arr1, Arr2, MaxSize );
                //Mergesort( Arr1, MaxSize );
                //sort4 = Checksort( Arr1, MaxSize );
                //if (sort4) return 1;

                Copy( Arr1, Arr2, MaxSize );
                Quicksort( Arr1, MaxSize );
                sort4 = Checksort( Arr1, MaxSize );
                if (sort4) return 1;
            }

            return 0;
        }

