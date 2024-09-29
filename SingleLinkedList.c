#include <stdio.h>
#include <stdlib.h>

// VARIABLES //
    //temp = address of newnode
    //link = pointer of every new node
    //item = value
    //data = values address
    //ptr = address of every node that changes dynamically according to the insertion

struct node
{
    int data;
    struct node*link;
}*head,*temp,*ptr,*ptr1,*temp1;

void main()
{
    int n,ch,item,k;
    printf("Enter the size :");
    scanf("%d",&n);
    do
    {
        printf("1) Insert at beginning\n2) Insert at end\n3) Insert at any position\n4) Delete from begining\n5) Detele from end\n6) Delete from any position\n7) Display\n8) Exit\n");
        printf("Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter the item :");
                scanf("%d",&item);
                temp = (struct node*)malloc(sizeof(struct node));
                if(temp==NULL)
                {
                    printf("Memory Underflow, NO insertion");
                }
                else
                {
                    temp->data=item;
                    temp->link=head;
                    head=temp;
                } break;
            }
            case 2:
            {
                struct node *ptr,*temp;
                int item;
                ptr = (struct node*)malloc(sizeof(struct node));
                printf("Enter value :");
                scanf("%d",&item);
                ptr->data = item;
                if(head==NULL)
                {
                    ptr->link=NULL;
                    head=ptr;
                    printf("Node inserted\n");
                }
                else
                {
                    temp=head;
                    while(temp->link!=NULL)
                    {
                        temp=temp->link;
                    }
                    temp->link=ptr;
                    ptr->link=NULL;
                    printf("Node inserted\n");
                }break;
            }
            case 3:
            {
                printf("Enter the item :");
                scanf("%d",&k);
                temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter the item after which value is pto be placed :");
                scanf("%d",&k);
                ptr=head;
                while((ptr->data!=k)&&(ptr->link!=NULL))
                {
                    ptr=ptr->link;
                }
                if(ptr->link==NULL)
                {
                    printf("Search fails");
                }
                else
                {
                    temp->data=ptr->data;
                    temp->link=ptr->link;
                    ptr->link=temp;
                }break;
            }
            case 4:
            {
                struct node *ptr;
                ptr=head;
                head=ptr->link;
                free(ptr);
                printf("Node deleted from the begining\n");
                break;
            }
            case 5:
            {
                struct node *ptr,*ptr1;
                if(head==NULL)
                {
                    printf("List is empty\n");
                }
                else if(head->link==NULL)
                {
                    head=NULL;
                    free(head);
                    printf("Node is deleted\n");
                }
                else
                {
                    ptr=head;
                    while(ptr->link!=NULL)
                    {
                        ptr1=ptr;
                        ptr=ptr->link;
                    }
                    ptr1->link=NULL;
                    free(ptr);
                    printf("Node deleted from the last\n");
                }break;
            }
            case 6:
            {
                struct node *temp;
                temp=head;
                int i,pos;
                printf("Entre the position of the node :");
                scanf("%d",&pos);
                if(pos==1)
                {
                    printf("Element deleted is :%d\n",temp->data);
                    head=head->link;
                    temp->link=NULL;
                    free(temp);
                }
                else
                {
                    for(i=0;i<pos-1;i++)
                    {
                        temp=temp->link;
                        struct node*temp1=temp->link;
                        temp->link=temp->link->link;
                        printf("Element deleted is :%d\n",temp1->data);
                        temp1->link=NULL;
                        free(temp1);
                    }
                }break;
            }
            case 7:
            {
                struct node*ptr;
                ptr=head;
                if(ptr==NULL)
                {
                    printf("Linked List is empty");
                }
                else
                {
                    printf("The elements are :\t");
                    while(ptr!=NULL)
                    {
                        printf("%d\t",ptr->data);
                        ptr=ptr->link;
                    }
                    printf("\n");
                }break;
            }
            case 8:
            {
                printf("Exit\n");
                break;
                default:
                {
                    printf("Invalid choice");
                }
            }
        }

    } while (ch!=8);
    
}