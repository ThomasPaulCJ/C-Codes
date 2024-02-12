#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*addr;
};
struct node*head=NULL; 
int notexit=1;
struct node*createnode(int item);
void insert_beg();
void insert_pos();
void insert_end();
void delete_beg();
void delete_end();
void delete_pos();
void display();
struct node*createnode(int item)
{
    struct node*nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=item;
    return nn;
}
int node_count()
{
    int count=0;
    struct node*temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->addr;
    }
    return count;
}
void insert_beg()
{
    int item;
    struct node*nn;
    printf("enter the item");
    scanf("%d",&item);
    nn=createnode(item);
    if(head==NULL)
    {
        nn->addr=NULL;
        head=nn;
    }
    else
    {
        nn->addr=head;
        head=nn;
    }
}
void insert_pos()
{
    int item,count,pos;
    printf("enter the position");
    scanf("%d",&pos);
    count=node_count();
    if(pos>count)
    {
        printf("enter the valid pos");
    }
    else
    {
      printf("enter the elements");
      scanf("%d",&item);
      struct node*nn;
      nn=createnode(item);
      if(head==NULL)
      {
          nn->addr=NULL;
          head=nn;
      }
      else
      {
          struct node*p=head;
          for(int i=1;i<pos-1;i++)
          {
              p=p->addr;
          }
          nn->addr=p->addr;
          p->addr=nn;
      }
    }
}
void insert_end()
{
    int item;
    struct node*nn;
    printf("enter the elements");
    scanf("%d",&item);
    nn=createnode(item);
    if(head==NULL)
    {
        nn->addr=NULL;
        head==nn;
    }
    else
    {
        struct node*p=head;
        while(p->addr!=NULL)
        {
            p=p->addr;
        }
        p->addr=nn;
        nn->addr=NULL;
    }
}
void delete_beg()
{
    if(head==NULL)
    {
        printf("empty");
    }
    else
    {
        struct node*p=head;
       p= p->addr;
       head=p;
    }
}
void delete_end()
{
    if(head==NULL)
    {
        printf("empty");
    }
    else
    {
        struct node*p=head,*c=head;
        while(p->addr!=NULL)
        {
            c=p;
            p=p->addr;
        }
        c->addr=NULL;
    }
}

void delete_pos()
{
    int count,pos;
    printf("enter the pos");
    scanf("%d",&pos);
    count=node_count();
    if(pos>count)
    {
        printf("invalid pos");
    }
    else
    {
        struct node*p=head,*c=head;
        for(int i=0;i<pos;i++)
        {
            c=p;
            p=p->addr;    
        
        }
        c->addr=p->addr;
    }
}
void display()
{
    if(head==NULL)
    {
        printf("empty");
    }
    else
    {
       struct node*p=head;
       printf("linked list");
       while(p->addr!=NULL)
       {
           printf("%d ",p->data);
           p=p->addr;
       }
       printf("%d ",p->data);
    }
}
int main()
{
    int choice;
    printf("operations");
    printf("\n1.insert_beg\n2.insert_pos\n3.insert_end\n4.delete_beg\n5.delete_end\n6.delete_pos\n7.display\n8.exit");
    while(choice!=8)
    {
        printf("enter the choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert_beg();
                break;
            case 2:
                insert_pos();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                delete_beg();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                delete_pos();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
                break;
            default:
                   printf("invalid"); 
        }
    }
}