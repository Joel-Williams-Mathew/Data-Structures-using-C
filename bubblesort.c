#include <stdio.h>
void main()
  {
  int arr[10],i,n,j,temp,count=0,space;
  printf("Enter the number of elements :");
  scanf("%d",&n);
  space=(6+10)*sizeof(int);
  printf("Enter the %d elements\n",n);
  count+=3;
  for (i=0;i<n;i++) {
    printf("Element %d: ", i+1);
    scanf("%d",&arr[i]);
    count++;
  }count++;
  for (i=0;i<n-1;i++)
  { 
    for(j=0;j<n-i-1;j++)
    { 
      if (arr[j]>arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        count+=3;
      }count++;
    }count++;
  }count++;
  printf("Sorted list in Ascending Order: \n");
  for(i=0;i<n;i++)
  { printf("%d  ",arr[i]);
    count++;
  }count++;
  printf("\nTime complexity : %d",count);
  printf("\nSpace Complexity: %d\n",space);
}




/*Enter the number of elements :5
Enter the 5 elements
Element 1: 78
Element 2: 23
Element 3: 60
Element 4: 1
Element 5: 43
Sorted list in Ascending Order: 
1  23  43  60  78  
Time complexity : 51
Space Complexity: 64
PS D:\JWONLY\S3 LAB THINGS\DS\output> */


  
