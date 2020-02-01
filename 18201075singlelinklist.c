#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void init()
{
    head=NULL;
}

void insertItem(int value)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=head;
    head=temp;
}

void print()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

struct node* search(int val)
{
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        if(temp->data==val){
            return temp;
        }
        temp=temp->next;
    }
    return 0;
}

void removeItem(int val)
{
   struct node *temp=head;
   struct node *prev=0;
   while(temp!=0){
        if(temp->data==val) break;
        prev=temp;
        temp=temp->next;
   }
   if(temp==0) return;
   else if(temp==head){
        head=head->next;
        free(temp);
   }
   else{
        prev->next=temp->next;
        free(temp);
   }
}

//// Complete the following functions and also add them in main function

void deleteFirst() // The function will delete the first item of the list
{
    struct node *temp=head;
   struct node *avalue=temp->next;
   head=avalue;
   free(temp);

}
void deleteLast() // The function will delete the last item of the list
{
    struct node *temp = head;
    struct node *prve=0;
    while(temp->next !=0){
        prve=temp;
        temp=temp->next;

    }

    prve->next=temp->next;
    free(temp);

}

void insertLast(int value) // The function will insert the value at the end of the list
{
  struct node *temp =head;
  struct node *newNode;

    newNode=(struct node*)malloc(sizeof(struct node));

        newNode ->data=value;
        newNode ->next=NULL;
        while(temp->next !=0){

           temp= temp->next;

        }
        temp ->next=newNode;

}

struct node* findLargest() // The function will find the largest item of the list and return it
{
    //Write your code here


    struct node *temp;
    int mx,mi;
    temp=head;

    int f=1;

    while(temp !=NULL){

        if(f==1){
            mx=temp->data;
            mi=temp->data;
            f=0;

        }
        else{


        if(mx<temp->data){

            mx=temp->data;
        }
        if (mi>temp->data){

            mi=temp->data;
        }
        }
        temp=temp->next;
    }

    printf("Maximum value is :%d\nminimum value is :%d\n",mx,mi);

}

struct node* findMiddle()

{

 struct  node*pos=head;
 struct node *pos1=head;

 while(pos1 && pos1->next){


    pos=pos->next;
    pos1=pos->next->next;

 }

printf("%d",pos->data);




}


int main()
{
    init();
    int op;
    printf("1.insert\n");
    printf("2.print\n");
    printf("3.search\n");
    printf("4.remove\n");
    printf("5.Delete firstItem\n");
    printf("6.Delete LastItem\n");
    printf("7.Insert LastItem\n");
    printf("8.findMiddle\n");
    printf("9.findLargest\n");
    while(1){
        scanf("%d",&op);
        if(op==1){
            int val;
            scanf("%d",&val);
            insertItem(val);
        }
        else if(op==2){
            print();
        }
        else if(op==3){
            int val;
            scanf("%d",&val);
            struct node *temp=search(val);
            if(temp==0) printf("Not found.\n");
            else printf("Found.\n");
        }
        else if(op==4){
            int val1;
            scanf("%d",&val1);
            removeItem(val1);
        }
        else if(op==5){
        deleteFirst();
        }
        else if(op==6){
        deleteLast();
        }
        else if(op==7){
            int value;
            scanf("%d",&value);
            insertLast(value);
        }
        else if (op==8 ){

            findMiddle();
        }
        else if (op==9){

            findLargest();
        }
    }

}
