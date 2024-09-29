#include <stdio.h>

int main()
{
  int count=0;
  int n,search_key,arr[10],i,space;
  count++;
  int found=0;
  count++;
  space=(10+6)*sizeof(int);
  
  printf("Enter the number of elements :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {   
      count++;
      printf("Enter the element :");
      count++;
      scanf("%d",&arr[i]);
  }
  count++;
  printf("Enter the element to be searched :");
  scanf("%d",&search_key);
  for(i=0;i<n;i++)
  {
      if(arr[i] == search_key)
      {
          found=1;
          count++;
      }
    
  }
  count++;
  if(found==1)
  {
      printf("%d is present in array",search_key);
  }
  else if(found==0)
  {
      printf("%d is not present in array",search_key);
  }
  printf("\nTime complexity : %d",count);
  printf("\nSpace Complexity: %d\n ",space);
  return 0;
  
}

