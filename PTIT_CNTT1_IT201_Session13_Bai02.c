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
void printStack(Stack s)
{
   printf("stack = {\n");
   printf("\t elements: [");
   for (int i=0;i<=s.top;i++)
   {
      printf("%d,",s.elements[i]);
   }
   printf("],\n");
   printf("\t top: %d,\n",s.top);
   printf("\t cap: %d,\n",s.cap);
   printf("}\n");
}
int main(){
   Stack myStack=createStack(5);
   printf("Nhap phan tu: \n");
   for (int i=0;i<5;i++)
   {
      int x;
      printf("Phan tu %d: ",i+1);
      scanf("%d",&x);
      push(&myStack,x);
   }
   printStack(myStack);
   return 0;
}