#include<stdio.h>
#include<string.h>
char stack[20];
int top,count=0;
void push()
{
top=top+1;
stack[top]='0';
stack[top+1]='\0';
}
int pop()
{
if(top<1)
return(0);
else
{
stack[top]='\0';
top=top-1;
return(1);
}
}
int main()
{
int m,i,j,k,l,a,len;
char input[20],rem_input[20];
printf("Simulation of PDA for n 0's followed by 2n 1's\n");
printf("Enter a string : ");
scanf("%s",input);
l=strlen(input);
j=0;stack[0]='Z';top=0;
printf("Stack\tInput\n");
printf("%s\t%s\n",stack,input);
while(1)
{
len=strlen(input);
while(len>0)
{
if(input[0]=='0')
{
push();
m=0;
for(k=1;k<len;k++)
{
rem_input[m]=input[k];
m=m+1;
}
rem_input[m]='\0';
strcpy(input,rem_input);
printf("%s\t%s\n",stack,input);
}
if(input[0]=='1')
{
count++;
if(count%2==0)
{
a=pop();
if(a==0)
{
printf("String not accepted");
goto b;
}
else
{
m=0;
for(k=1;k<len;k++)
{
rem_input[m]=input[k];
m=m+1;
}
}
rem_input[m]='\0';
strcpy(input,rem_input);
printf("%s\t%s\n",stack,input);
}
else
{
m=0;
for(k=1;k<len;k++)
{
rem_input[m]=input[k];
m=m+1;
}
rem_input[m]='\0';
strcpy(input,rem_input);
printf("%s\t%s\n",stack,input);
}
}
break;
}
j=j+1;
//printf("j = %d\t l = %d\n",j,l);
if(j==l)
{
break;
}
}
if(top>=1)
{
printf("String not accepted");
}
else
{
printf("String accepted");
}
b:
printf(".............");
}