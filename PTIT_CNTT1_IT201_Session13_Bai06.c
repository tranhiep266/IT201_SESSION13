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
int isPalindrome(char str[])
{
   int len=strlen(str);
   if (str[len-1]=='\n')
   {
      str[len-1]='\0';
      len--;
   }
   Stack s;
   createStack(&s,len);
   for (int i=0;i<len;i++)
   {
      push(&s,str[i]);
   }
   for (int i=0;i<len;i++)
   {
      if (str[i]!=pop(&s))
      {
         return 0;
      }
   }
   return 1;
}

int main(){
   char str[100];
   printf("Nhap vao 1 chuoi:");
   fgets(str,sizeof(str),stdin);
   if (isPalindrome(str))
   {
      printf("TRUE\n");
   }else
   {
      printf("FALSE\n");
   }

   return 0;
}