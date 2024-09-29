#include<stdio.h>
int main()
{
  int arr[10],n,i,j,temp,min,space,count=0;
  space=(10+7)*sizeof(int);
  printf("Enter the number of elements :");
  scanf("%d",&n);
  printf("Enter the %d elements: \n",n);
  count+=3;
  for(i=0;i<n;i++) {
    printf("Element %d: ", i+1);
    scanf("%d",&arr[i]);
    count++;
  }count++;
  for(i=0;i<n;i++)
  { count++;
    min = i;
    for(j=i+1;j<n;j++)
    {
      if (arr[j]<arr[min])
      { 
        min=j;
        count++;
      }count++;
    }count++;
    temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
    count+=3;
  }count++;
  printf("Sorted list in Ascending Order: \n");
  for(i=0;i<n;i++)
  { printf("%d  ",arr[i]);
    count++;
  }count++;
  printf("\nTime complexity : %d",count);
  printf("\nSpace Complexity: %d\n",space);
  return 0;
}



/*Enter the number of elements :5
Enter the 5 elements: 
Element 1: 67
Element 2: 56
Element 3: 60
Element 4: 23
Element 5: 35
Sorted list in Ascending Order: 
23  35  56  60  67  
Time complexity : 56
Space Complexity: 68
PS D:\JWONLY\S3 LAB THINGS\DS\output> */
