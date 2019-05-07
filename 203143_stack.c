//NAME:ALOK BHAWANKAR
//ROLL NO.:203143
//BATCH: A3
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
int top = -1;
char stack[MAX][MAX];
char expression[MAX];
char postfix_expression[MAX];
char prefix_expression[MAX];
int isEmpty()
{
	if(top == -1)
		return 1;
	return 0;
}
int isFull()
{
	if(top == MAX)
		return 1;
	return 0;
}
void push(char item[MAX])
{
	top++;
	strcpy(stack[top], item);
}
void pop(char item[MAX])
{
	strcpy(item, stack[top]);
	top--;
}
void display()
{
	if(!isEmpty())
	{
		int i;
		for(i = top; i >= 0; i--)
		{
			printf("\n%s", stack[i]);
		}
	}
	else
		printf("The stack is empty!");
}
int icp(char op)
{
	switch(op)
	{
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '%':
			return 2;
		case '^':
			return 4;
		case '(':
			return 5;
		default:
			return -1;
	}
}
int isp(char op)
{
	switch(op)
	{
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '%':
			return 2;
		case '^':
			return 3;
		case '(':
			return 0;
		default:
			return -1;
	}
}
int isoperator(char temp)
{
if(temp == '+' ||temp == '-' ||temp == '*' ||temp == '/' ||temp == '^' || temp=='%')
	return 1;
else return 0;
}
void peek(char item[MAX])
{
	strcpy(item, stack[top]);
}
void infixToPostfix()
{
	int i = 0, j=0;
	char term[MAX];
	char temp[MAX];	
	while(expression[i] != '\0')
	{
		if(!isEmpty())
			peek(temp);
		term[0] = expression[i];
		if(isalpha(term[0]))
		{	
			postfix_expression[j] = term[0];
			j++;
		}
		else {
		if(isoperator(term[0]))
		{
			if((icp(term[0]) > isp(temp[0])) || isEmpty())
			{
				push(term);
			}
		}
			else if(term[0] == ')')
			{
				char t[MAX];
				pop(t);
				while(!isEmpty() && t[0]!='(')
				{	
					postfix_expression[j] = t[0];
					j++;
					pop(t);						
				}
			}
			else
			{
				while(!isEmpty() && (icp(term[0]) <= isp(temp[0])))
				{
					postfix_expression[j] = temp[0];
					j++;
					pop(temp);
				}
				push(term);
			}			
		
		}
		i++;
	}
	while(!isEmpty())
	{
		pop(term);
		postfix_expression[j] = term[0];
		j++;
	}
}
void infixToPrefix()
{
	top = -1;
	int i=0;
	char temp1;
	char temp_expression[MAX];
	while(expression[i]!='\0')
	{
		i++;
	}
	i--;
	int j=0;
	while(i>=0)
	{
temp_expression[i] = expression[j];
		j++;
		i--;
	}
	i=0;
	while(temp_expression[i]!='\0')
	{
		temp1 = temp_expression[i];
		if(temp1==')')
			temp_expression[i]='(';
		else if(temp1=='(')
			temp_expression[i]=')';
		i++;
	}

	
	
	i = 0;
	j=0;
	char term[MAX];
	char temp[MAX];	
	while(temp_expression[i] != '\0')
	{
		if(!isEmpty())
			peek(temp);
		term[0] = temp_expression[i];
		if(isalpha(term[0]))
		{	
			prefix_expression[j] = term[0];
			j++;
		}
		else {
		if(isoperator(term[0]))
		{
			if((icp(term[0]) > isp(temp[0])) || isEmpty())
			{
				push(term);
			}
		}
			else if(term[0] == ')')
			{
				char t[MAX];
				pop(t);
				while(!isEmpty() && t[0]!='(')
				{	
					prefix_expression[j] = t[0];
					j++;
					pop(t);						
				}
			}
			else
			{
				while(!isEmpty() && (icp(term[0]) < isp(temp[0])))
				{
					prefix_expression[j] = temp[0];
					j++;
					pop(temp);
				}
				push(term);
			}			
		
		}
		i++;
	}
	while(!isEmpty())
	{
		pop(term);
		prefix_expression[j] = term[0];
		j++;
	}
	
	
	
	
	i=0;
	while(postfix_expression[i]!='\0')
	{
		i++;
	}
	i--;
	j=0;
	while(i>=j)
	{
		temp1 = prefix_expression[i];
		prefix_expression[i] = prefix_expression[j];
		prefix_expression[j] = temp1;
		j++;
		i--;
	}
	printf("\nThe prefix expression is %s",prefix_expression);
}
void prefixToInfix()
{
	top=-1;
	int i=0;
	char temp[MAX],a[MAX] ,b[MAX],result[MAX];
	result[0]='(';
	
	while(postfix_expression[i]!='\0')
	{
		i++;
	}
	i--;
	int j=0;
	char temp1;
	while(i>=j)
	{
		temp1 = prefix_expression[i];
		prefix_expression[i] = prefix_expression[j];
		prefix_expression[j] = temp1;
		j++;
		i--;
	}
	i=0;
	while(prefix_expression[i] != '\0')
	{
		temp[0] = prefix_expression[i];
		if(isalpha(temp[0]))
		{
			push(temp);
		}
		else
		{
			pop(a);
			pop(b);
			strcat(result,b);
			strcat(result,temp);
			strcat(result,a);
			strcat(result,")");
			push(result);
		}
		i++;
	}
	peek(temp);



	i=0;

	while(temp[i]!='\0')
	{
		i++;
	}
	i--;
	j=0;
	while(i>=j)
	{
		temp1 = temp[i];
		temp[i] = temp[j];
		temp[j] = temp1;
		j++;
		i--;
	}




	temp1;
	i=0;
	while(temp[i]!='\0')
	{
		temp1 = temp[i];
		if(temp1==')')
			temp[i]='(';
		else if(temp1=='(')
			temp[i]=')';
		i++;
	}
	//temp[i-1]='\0';
	printf("\nThe prefix to infix expression is %s",temp);
}
void postfixToInfix()
{
	top=-1;
	int i=0;
	char temp[MAX], result[MAX], a[MAX], b[MAX];
	result[0]='(';
	result[1] = '\0';
	while(postfix_expression[i]!='\0')
	{
		temp[0] = postfix_expression[i];
		if(isalpha(temp[0]))
			push(temp);
		else
		{
			pop(b);
			pop(a);
			strcat(result,a);
			strcat(result,temp);
			strcat(result,b);
			strcat(result,")");
			push(result);
		}
	result[0]='(';
	result[1] = '\0';
	i++;
	}
	peek(temp);
	printf("\nPostfix to Infix is %s",temp);
}
void postfixToPrefix()
{
	int i=0,j=0;
	top=-1;
	char temp[MAX], a[MAX], b[MAX], result[MAX];
	while(postfix_expression[i]!='\0')
	{
		temp[0] = postfix_expression[i];
		temp[1] = '\0';
		if(isalpha(temp[0]))
			push(temp);
		else
		{
				
			strcat(result,temp);
			pop(a);
			pop(b);
			strcat(result,b);
			strcat(result,a);
			push(result);
		}
		i++;
		result[0] = '\0';
	}
	peek(result);
	strcpy(prefix_expression,result);
	printf("\nPostfix to prefix %s\n",prefix_expression);
}
void prefixToPostfix()
{
	int i=0,j=0;
	char temp[MAX], a[MAX], b[MAX], result[MAX];
	while(prefix_expression[i]!='\0')
	{
		i++;
	}
	i--;
	while(i>=0)
	{
		temp[0] = prefix_expression[i];
		temp[1] = '\0';
		if(isalpha(temp[0]))
			push(temp);
		else
		{
				
			strcat(result,temp);
			pop(a);
			pop(b);
			strcat(result,b);
			strcat(result,a);
			push(result);
		}
		i--;
		result[0] = '\0';
	}
	peek(result);
	strcpy(postfix_expression,result);
	printf("\nPrefix to postfix  %s",postfix_expression);
}
int main()
{
	int c = 1, choice;
while(c==1)
{
		printf("*****MENU*****\n1.Input the expression\n2.Convert infix to postfix\n3.Convert infix to prefix\n4.Convert prefix to infix\n5.Convert postfix to prefix\n6.Exit\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the expression ");
				scanf("%s",expression);
				break;
			case 2:
				infixToPostfix();
				break;
			case 3:
				infixToPrefix();
				break;
			case 4:
				prefixToInfix();		
				break;
			case 5:
				postfixToPrefix();	
				break;
			case 6:
				c = 0;
				break;
			default:
				printf("Wrong choice");
		}
}

				printf("Enter the expression ");
				scanf("%s",expression);
				infixToPostfix();
				printf("The postfix expression is %s",postfix_expression);
				infixToPrefix();
				prefixToInfix();
				//postfixToInfix();
				postfixToPrefix();
				//prefixToPostfix();

	return 0;
}
/*
OUTPUT:
Enter the expression a+b
The postfix expression is ab+
The prefix expression is +ab
The prefix to infix expression is (a+b)
Postfix to prefix +ab
*/

