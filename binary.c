#include <stdio.h>
int main()
{
  int i,left,right,mid,n,search,array[10],count=0,space;
  space=(8+10)*sizeof(int);

  printf("Enter number of elements: ");
  scanf("%d", &n);
  count++;

  printf("Enter the %d numbers: \n", n);

  for(i = 0; i < n; i++) {
    printf("Element %d: ", i+1);
    scanf("%d", &array[i]);
    count++;
  }
  count++;

  printf("Enter value to find: ");
  scanf("%d", &search);
  count++;

  left = 0;
  right = n - 1;
  mid = (left+right)/2;
  count++;

  while (left <= right) {
    count++;
    if (array[mid] < search){
      left = mid + 1;
      count++;
    }
    else if (array[mid] == search) {
      printf("%d found at location %d.\n", search, mid+1);
      count++;
      break;
    }
    else {
      right = mid - 1;
      count++;
    }
    mid = (left + right)/2;
    count++;
  }
  count++;
  if (left > right) {
    printf("Not found! %d isn't present in the list", search);
  }
  count++;
  printf("\nTime complexity : %d",count);
  printf("\nSpace Complexity: %d",space);
  return 0;
}
