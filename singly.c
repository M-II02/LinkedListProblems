#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *add;
};

struct Node *head=NULL;

//Create LL
struct Node* create(struct Node *head)
{
    struct Node *list1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *list2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *list3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *list4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *list5 = (struct Node*)malloc(sizeof(struct Node));
    list1->data =10;
    list1->add=NULL;
    list1->add=list2;
    list2->data=20;
    list2->add=NULL;
    list2->add=list3;
    list3->data=30;
    list3->add=NULL;
    list3->add=list4;
    list4->data=40;
    list4->add=list5;
    list5->data=50;
    list5->add=NULL;
    head=list1;

    return head;
}

//1.rotate
struct Node* rotateByK(struct Node *head,struct Node* kthOne,int k){
  struct Node *s=kthOne,*temp,*t1;
  temp=s->add;
  s->add=NULL;
  t1=temp;
  while(t1->add!=NULL){
      t1=t1->add;
  }
  t1->add=head;
  head=temp;
  return head;
}

//(K+1)th Node
struct Node* kPlusOnethEnd( struct Node *head,int k)
{
    struct Node *s=head,*p=head;
    while((k+1)>0) {
        s=s->add;
        k--;
    }
    while(s && p && p->add) {
        s=s->add;
        p=p->add;
    }
    return p;
}

//2.Palindrome
 int checkPalindrome(struct Node *head,struct Node* Mid){
   struct Node *l=head,*prev=NULL,*m=Mid,*temp;
   //reversing second half
   while(m!=NULL){
    temp=m->add;
    m->add=prev;
     prev=m;
     m=temp;
   }
   struct Node *r=prev;
   while(r->add!=NULL){
     if(l->data!=r->data){
       return 0;
     }
     l=l->add;
     r=r->add;
   }
   return 1;
 }
 
 //Mid
struct Node* mid(struct Node* head)
{
    struct Node *s,*f;
    s=head,f=head;
    while(s && f && f->add) {
        s=s->add;
        f=f->add->add;
    }
    printf("Mid value is:%d",s->data);
    return s;
}

//3. splitMerge LL
struct Node* SplitMergeLL( struct Node *list1,struct Node *list2, int a,int b )
{
    struct Node *s=list1,*p=list1;
    while(s->add->data!=a)
        s=s->add;
    while(p->add->data!=b)
        p=p->add;
    s->add=list2;
    while(list2->add!=NULL) {
        list2=list2->add;
         /* if(a==b) {
            s->add=list2;
            list2->add=s->add;
        }*/
    }
    list2->add=p->add->add;
    return list1;
}

//nth node from end
struct Node* nthEnd( struct Node *head,int k)
{
    struct Node *s=head,*p=head;
    while(k--) {
        s=s->add;
    }
    while(s && p && p->add) {
        s=s->add;
        p=p->add;
    }
    printf("%d",p->data);
    return p;
}

//Print LL
void print(struct Node *head)
{
    struct Node *t=head;
    while(t!=NULL) {
        printf("\n%d",t->data);
        t=t->add;
    }
}


/*__________________________MAIN PROGRAM_________________________________*/

int main(){
    int a,b,k,choice;
    struct Node *list1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *list2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *kthOne,*Mid,*head;
    while(1) {
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            head=create(head);
            print(head);
            break;
        case 2: printf("\nEnter k:");
            scanf("%d",&k);
            kthOne=kPlusOnethEnd(head,k);
            printf("%d",kthOne->data);
            break;
        case 3: printf("Enter k:");
              scanf("%d",&k);
              head=rotateByK(head,kthOne,k);
              print(head);
              break;
        case 4:
            Mid=mid(head);
            break;
        case 5:
             checkPalindrome(head,Mid);
             break;
        case 6:
            printf("\nEnter a:");
            scanf("%d",&a);
            printf("\nEnter b:");
            scanf("%d",&b);
            head=SplitMergeLL(list1,list2,a,b);
            print(head);
            break;
        case 7:
            printf("\nEnter k:");
            scanf("%d",&k);
            head=nthEnd(head,k);
            break;
        case 8:
            print(head);
            break;
        default:
            exit(1);
        }
    }
    return 0;
}
