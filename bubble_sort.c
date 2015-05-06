//#include <stdio.h>

void swap(int *a, int base1, int base2)
{
  int temp;
  temp = a[base1];
  a[base1] = a[base2];
  a[base2] = temp;
}

void bubblesort(int *a, int n)
{
  int outerloop = n - 1, innerloop, swapped;
  do
  {
    swapped = 0;
    for (innerloop = 0; innerloop < outerloop; innerloop++)
    {
      if (a[innerloop] > a[innerloop + 1])
      {
        swap(a, innerloop, innerloop + 1);
        swapped = 1;
      }
    }
        outerloop--;
  }
  while (swapped);
}

int main()
{
  int i;
  int a[16];

  // Array initialization
  for (i = 0; i < 16; i++)
    a[i] = 15 - i;

  bubblesort(a, 16);

  //for (i = 0; i < 16; i++)
  //  printf("%d ", a[i]); 

  return 0;
}



