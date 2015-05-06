/*
Divide in half
A fast way to search a sorted array is to use a binary search. 
The idea is to look at the element in the middle. If the key is 
equal to that, the search is finished. If the key is less than 
the middle element, do a binary search on the first half. 
If it's greater, do a binary search of the second half. 

Performance
The advantage of a binary search over a linear search is astounding 
for large numbers. For an array of a million elements, binary search, O(log N), 
will find the target element with a worst case of only 20 comparisons. 
Linear search, O(N), on average will take 500,000 comparisons to find the element.
Probably the only faster kind of search uses hashing, a topic that isn't covered in these notes. 
This performance comes at a price - the array must be sorted first. Because sorting 
isn't a fast operation, it may not be worth the effort to sort when there are only a few searches. 
*/

#define MAX 128

int binarySearch(int sortedArray[], int first, int last, int key) {
   // function:
   //   Searches sortedArray[first]..sortedArray[last] for key.  
   // returns: index of the matching element if it finds key, 
   //         otherwise  -(index where it could be inserted)-1.
   // parameters:
   //   sortedArray in  array of sorted (ascending) values.
   //   first, last in  lower and upper subscript bounds
   //   key         in  value to search for.
   // returns:
   //   index of key, or -insertion_position -1 if key is not 
   //                 in the array. This value can easily be
   //                 transformed into the position to insert it.
   
   while (first <= last) {
       int mid = (first + last) / 2;  // compute mid point.
       if (key > sortedArray[mid]) 
           first = mid + 1;  // repeat search in top half.
       else if (key < sortedArray[mid]) 
           last = mid - 1; // repeat search in bottom half.
       else
           return mid;     // found it. return position /////
   }
   return -(first + 1);    // failed to find key
}


int main()
{
  int a[MAX];
  int i;
  int index;

  for (i = 0; i < MAX; i++)
    a[i] = i;

  // Cannot find MAX
  index = binarySearch(a, 0, MAX - 1, MAX);

  return 0;
}


