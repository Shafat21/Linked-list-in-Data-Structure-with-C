#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Member{

    char name[40];
    int netWorth;
    struct Member *next;
};

//Display()
void displayLL(struct Member *h)
{
    if(h==NULL)
        printf("\nList is empty\n");
    else
    {
        struct Member *temp = h;
        while(temp != NULL)
        {
            printf("\n%s's Net Worth is %d\n",temp->name,temp->netWorth);
            temp = temp->next;
        }
    }
}

//Size()
int sizeLL(struct Member *h)
{
    int count = 0;
    if(h==NULL)
        printf("\nList is empty\n");
    else
    {
        struct Member *temp = h;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
}

//Search()
int searchLL(struct Member *h,char name[])
{
    struct Member *temp = h;
    while(temp != NULL)
    {
        if(strcmp(temp->name,name)==0)
            return temp -> netWorth;
        else
            temp = temp->next;
    }
    return -1;

}

//Inserting First
void insertFirst(struct Member **h,char name[20],int netWorth)
{
    struct Member *temp;
    temp = (struct Member*)malloc(sizeof(struct Member));

    strcpy(temp -> name,name);
    temp -> netWorth = netWorth;
    temp -> next = *h;
    *h = temp;

}

//Insert node any Position
void insertNode(struct Member **h,char name[],int netWorth,int N)
{
    struct Member *temp = *h,*newN;
    newN = (struct Member*)malloc(sizeof(struct Member));
    strcpy(newN->name,name);
    newN->netWorth = netWorth;

    if(*h==NULL)
    {
        newN->next = NULL;
        *h = newN;
    }
    else if(N==1)
    {
        newN->next = *h;
        *h = newN;
    }

    else
    {
        for(int i=1; i<=N-2; i++)
            temp = temp->next;
    }

    newN->next = temp->next;
    temp->next = newN;
}

//Delete First
void deleteFirst(struct Member **h)
{
    if(*h==NULL)
        printf("\nList is empty\n");

    else
    {
        struct Member *temp ;
        //while(temp != NULL)
            temp = *h;
            *h = temp -> next;
            free(temp);

    }

}

//Delete node any Position
void deleteNode(struct Member **h,int N)
{
    struct Member *temp = *h,*temp2;

    if(*h==NULL)
        printf("\nList is empty\n");
    else if(N==1)
    {
        *h = (*h)->next;
        free(*h);
    }
    else
    {
        for(int i=1; i<=N; i++)
        {
            temp = temp->next;
            }

        temp = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

int main()
{
    struct Member a,b,c,d,e,*head;
    head = &a;
    strcpy(a.name,"Shafat");
    a.netWorth = 10;
    a.next = &b;

    strcpy(b.name,"Ove");
    b.netWorth = 20;
    b.next = &c;

    strcpy(c.name,"Momo");
    c.netWorth = 30;
    c.next = &d;

    strcpy(d.name,"Marjana");
    d.netWorth = 40;
    d.next = &e;

    strcpy(e.name,"Sadia");
    e.netWorth = 50;
    e.next = NULL;

    int choice,size,search;
    system("cls");
    while(1)
    {
        printf("\n****** MENU ******\n");
        printf("1. Display Linked List\n2. Size of All Linked List\n3. Search Linked List\n4. Insert First\n5. Delete First\n6. Insert Node\n7. Delete Node\n8. Insert Last\n9. Delete Last\n10. Exit System\n");
        printf("Enter your choice: ");

        scanf("%d",&choice);

    switch(choice)
    {
            
        case 1 :
            displayLL(head);
        break;

        case 2 :
            size = sizeLL(head);
            printf("%d",size);
        break;

        case 3 :
            search = searchLL(head,"Shafat");
            if(search==1)
                printf("\nNet Worth not found\n");
            else
                printf("\nFound %d\n",search);
        break;

        case 4 :
            insertFirst(&head,"Ove",60);
            displayLL(head);
        break;

        case 5 :
            deleteFirst(&head);
            displayLL(head);
        break;

        case 6 :
            insertNode(&head,"Marjana",70,1);
            displayLL(head);
        break;

        case 7 :
            deleteNode(&head,1);
            displayLL(head);
        break;

        case 8 :
            printf("\nInsert Last : Couldn't Do it\n");
        break;

        case 9 :
            printf("\nDelete Last : Couldn't Do it\n");
        break;

        case 10 :
            exit(0);
        break;

        default :
            printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
}