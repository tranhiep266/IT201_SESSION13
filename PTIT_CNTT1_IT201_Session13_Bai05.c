#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
typedef struct
{
   int elements[MAX];
   int top;
   int cap;
}Stack;
Stack createStack(int cap)
{
   Stack s;
   s.top=-1;
   s.cap=cap;
   return s;
}
void push(Stack* s,int value)
{
   if (s->top < s->cap-1)
   {
      s->top++;
      s->elements[s->top]=value;
   }else
   {
      printf("Stack Overflow\n");
   }
}
int pop(Stack* s)
{
   if (s->top==-1)
   {
      printf("Stack Underflow\n");
      return -1;
   }else
   {
      int value=s->elements[s->top];
      s->top--;
      return value;
   }
}

void reverseArray(int arr[],int n,Stack* s)
{
   for (int i=0;i<n;i++)
   {
      arr[i]=pop(s);
   }
}

int main(){
   Stack myStack=createStack(5);
   int arr[5];
   printf("Nhap phan tu: \n");
   for (int i=0;i<5;i++)
   {
      int x;
      printf("Phan tu %d: ",i+1);
      scanf("%d",&x);
      push(&myStack,x);
   }
   reverseArray(arr,5,&myStack);
   for (int i=0;i<5;i++)
   {
      printf("%d,",arr[i]);
   }
   return 0;
}