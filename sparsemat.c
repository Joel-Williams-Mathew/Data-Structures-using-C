#include <stdio.h>

int main()
{
  int sp[10][10],Tr[10][10],r,c,i,j;
  int k = 1;
  
  printf("Enter the number of rows :");
  scanf("%d",&r);
  
  printf("Enter the number of columns :");
  scanf("%d",&c);
  printf("Enter the element of the sparse matrix :");
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      scanf("%d",&sp[i][j]);
    }
  }
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      if(sp[i][j]!=0)
      {
        Tr[k][0] = i;
        Tr[k][1] = j;
        Tr[k][2] = sp[i][j];
        k++;
      }
    }
  }
  Tr[0][0] = r;
  Tr[0][1] = c;
  Tr[0][2] = k-1;
  
  printf("\nSparse Matrix");
  for(i=0;i<r;i++)
    {printf("\n");
    for(j=0;j<c;j++)
      printf("%d\t",sp[i][j]);
    }
  printf("\nTriplet Representation ");
  printf("\nRow\tColumn\tValue");
  for(i=0;i<k;i++)
  {
    printf("\n%d\t%d\t%d\n",Tr[i][0],Tr[i][1],Tr[i][2]);
  }
}
