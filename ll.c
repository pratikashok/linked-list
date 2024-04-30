#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *first=NULL;
struct node *new,*temp,*prev;
void create_node()
{
    int info;
    new=(struct node *)malloc(sizeof(struct node));
    new->link=NULL;
    printf("Enter the data\n");
    scanf("%d",&info);
    new->info=info;
}
void insert_front()
{
    create_node();
    if(first==NULL)
    {
        first=new;
    }
    else
    {
        new->link=first;
        first=new;
    }
}
void insert_rear()
{
    create_node();
    if(first==NULL)
    {
        first=new;
    }
    else
    {
        temp=first;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=new;
    }
}
void insert_pos(int pos)
{
    int i;
    if(first==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        create_node();
        if(pos==1)
        {
            new->link=first;
            first=new;
        }
        else
        {
            temp=first;
            for(i=1;i<pos;i++)
            {
                prev=temp;
                temp=temp->link;
            }
            prev->link=new;
            new->link=temp;
        }
    }
}
void insert_info(int info)
{
    if(first==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        create_node();
        if(first->info==info)
        {
            new->link=first;
            first=new;
        }
        else
        {
            temp=first;
            while(temp!=NULL&&temp->info!=info)
            {
                prev=temp;
                temp=temp->link;
            }
            if(temp==NULL)
            {
                printf("Information not present\n");
            }
            else
            {
                prev->link=new;
                new->link=temp;
            }
        }
    }
}

void delete_front()
{
    if(first==NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        struct node *temp;
        temp=first;
        first=temp->link;
        printf("%d is deleted\n",temp->info);
        free(temp);
    }
}
void delete_rear()
{
    if(first==NULL)
    {
        printf("The list is empty\n");
    }
    else if(first->link==NULL)
    {
        printf("%d is deleted\n",first->info);
        free(first);
        first=NULL;
    }
    else
    {
        struct node *temp,*prev;
        temp=first;
        while(temp->link!=NULL)
        {
            prev=temp;
            temp=temp->link;
        }
        prev->link=NULL;
        printf("%d is deleted\n",temp->info);
        free(temp);
    }
}
void delete_info(int info)
{
    struct node *temp,*prev;
    if(first==NULL)
    {
        printf("The list is empty\n");
    }
    else if(first->info==info)
    {
        temp=first;
        first=first->link;
        printf("%d is deleted\n",temp->info);
        free(temp);
    }
    else
    {
        temp=first;
        while(temp!=NULL&&temp->info!=info)
        {
            prev=temp;
            temp=temp->link;
        }
        if(temp==NULL)
        {
            printf("Information not present\n");
        }
        else
        {
            prev->link=temp->link;
            printf("%d is deleted\n",*temp);
            free(temp);
        }
    }
}

void delete_pos(int pos)
{
    int i;
    if(first==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        
        if(pos==1)
        {
            temp=first;
            first=first->link;
            free(temp);
        }
        else
        {
            temp=first;
            for(i=1;i<pos;i++)
            {
                prev=temp;
                temp=temp->link;
            }
            prev->link=temp->link;
            free(temp);
        }
    }
}

void display()
{
    struct node *temp;
    if(first==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("contents in the list are\n");
        temp=first;
        while(temp!=NULL)
        {
            printf("%d\t",temp->info);
            temp=temp->link;
        }
    }
}
void main()
{
    int pos,info,choice;
    while(1)
    {
        printf("\n1.Insert at front\n2.Insert at rear\n3.Insert based on position\n4.Insert based on information\n5.Delete at front\n6.Delete at rear\n7.Delete based on info\n8.delete based on position \n9.Display\n10.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert_front();
            break;
            case 2:insert_rear();
            break;
            case 3:printf("Enter the position\n");
                   scanf("%d",&pos);
                   insert_pos(pos);
            break;
            case 4:printf("Enter the information\n");
                    scanf("%d",&info);
                    insert_info(info);
                    break;
            case 5:delete_front();
            break;
            case 6:delete_rear();
            break;
            case 7:printf("Enter the information\n");
                    scanf("%d",&info);
                    delete_info(info);
                    break;
            case 8:printf("enter the position\n");
                    scanf("%d",&pos);
                    delete_pos(pos);
                    break;
            case 9:display();
            break;
            case 10:exit(0);
            break;
            default:printf("Invalid choice\n");
            break;
        }
        display();
    }
}
