#include <stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;
struct node *tail;

void init()
{
    head=0;
    tail=0;
}

void insert(int val)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->prev=0;

    newNode->next=head;
    if(head!=0) head->prev=newNode;
    else tail=newNode;
    head=newNode;
}

void insertLast(int val)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=0;

    newNode->prev=tail;
    if(head!=0) tail->next=newNode;
    else head=newNode;
    tail=newNode;
}

void print()
{
    struct node *temp=head;
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

//// Complete the following functions and also add them in main function

int length()//The function will return the length of the list
{
    //Write your code here
    int len=1;
    struct node *temp=head;
    while(temp->next !=0){
         temp=temp->next;
        len++;
    }


    printf("Length is :%d\n",len);
    return len;
}

struct node* search(int value) // The function will search the value from the list and return it
{
     struct node *temp;
    temp=head;
    while(temp!=0){
        if(temp->data==value){
            printf("Found this value %d\n",temp->data);
            return temp;
        }
        temp=temp->next;
    }
    printf("Not found\n");
    return 0;

}
void deleteFirst() // The function will delete the last item of the list
{
    //Write your code here

    struct node *temp=head;
    struct node *priv=tail;

    head =head->next;
    head->prev =NULL;
    free(temp);
   /*while(priv->next !=0){

        temp=temp->next;



    }*/

}


void deleteItem(int val) // The function will delete the value from the list, if the value exists in the list
{
    //Write your code here

    {
    struct node *prev=0;
    struct node *temp=head;

    while(temp!=0){
        if(temp->data==val)
            break;
        prev=temp;
        temp=temp->next;
    }
    if(head==0) return 0;
    else if(temp==head){
        head=head->next;
        if(temp->next==0) tail=prev;
        free(temp);
    }
    else{
        prev->next=temp->next;
        if(temp->next==0) tail=prev;
        free(temp);
    }
}
}



int main()
{
    init();
    int op;
    printf("1.insert\n");
    printf("2.insertLast\n");
    printf("3.print\n");
    printf("4.Search\n");
    printf("5.Length\n");
    printf("6.DeleteItem\n");
    printf("7.DeleteFirst\n");
    while(1){
        scanf("%d",&op);
        if(op==1){
            int val;
            scanf("%d",&val);
            insert(val);
        }
        else if(op==2){
            int val;
            scanf("%d",&val);
            insertLast(val);
        }
        else if(op==3){
            print();
        }
        else if(op==4){
                int v;
        scanf("%d",&v);

            search(v);
        }
        else if(op==5){
            length();
        }
        else if (op==6){

            int value;
            scanf("%d",&value);
            deleteItem(value);

        }
        else if (op==7){
            deleteFirst();
        }
    }

}
