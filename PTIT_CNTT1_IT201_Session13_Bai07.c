#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
   char* data;
   int top;
   int cap;
}Stack;
void createStack(Stack* s,int cap)
{
   s->data=(char*)malloc(sizeof(char)*cap);
   s->top=-1;
   s->cap=cap;
}
void push(Stack* s,char value)
{
   if (s->top < s->cap-1)
   {
      s->data[++(s->top)]=value;
   }
}
char pop(Stack* s)
{
   if (s->top>=0)
   {
      return s->data[(s->top)--];
   }
   return '\0';
}
bool isEmpty(Stack* s)
{
   return s->top == -1;
}
bool isMatching(char open, char close)
{
   return (open == '(' && close == ')') ||
          (open == '[' && close == ']') ||
          (open == '{' && close == '}');
}
bool isValidParentheses(char str[])
{
   int len = strlen(str);
   Stack s;
   createStack(&s, len);

   for (int i = 0; i < len; i++)
   {
      char c = str[i];
      if (c == '(' || c == '[' || c == '{')
      {
         push(&s, c);
      } else if (c == ')' || c == ']' || c == '}') {
         if (isEmpty(&s) || !isMatching(pop(&s), c))
         {
            return false;
         }
      }
   }
   bool valid = isEmpty(&s);
   return valid;
}

int main(){
   char sTr[100];
   printf("Nhap bieu thuc kiem tra: ");
   fgets(sTr, sizeof(sTr), stdin);
   sTr[strcspn(sTr, "\n")] = '\0';

   if (isValidParentheses(sTr))
   {
      printf("TRUE\n");
   } else
   {
      printf("FALSE\n");
   }

   return 0;
}