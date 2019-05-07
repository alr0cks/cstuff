#include<stdio.h>
struct term
{
	char bit;
	int count;	
};
typedef struct term p;

p pagetable[10];
int frame[3];

void initialize()
{
	for(int i=0;i<10;i++)
	{
		pagetable[i].bit='I';
	}

	for(int i=0;i<3;i++)
	{
		frame[i]=-1;
	}
}			

void fifo(int n)
{
	int string[n];
	int j=0,front=0;
	int p,page_fault=0;
	for(int i=0;i<n;i++)
	{
		printf("enter page number from reference string:");
		scanf("%d",&string[i]);
		if(pagetable[string[i]].bit=='I')
		{	
			if(j<3)
			{
				frame[j]=string[i];
				j++;	
			}
			else
			{
				p=frame[front];
				pagetable[p].bit='I';
				frame[front]=string[i];
				front=(front+1)%3;
			}
			page_fault++;
			pagetable[string[i]].bit='V';
		}
		for(int i=0;i<3;i++)
		{
			printf(" %d ",frame[i]);	
		}		
		printf("\n");
	}
	printf("number of pagefaults= %d",page_fault);
}		

void lru(int n)
{
	int string[n];
	int j=0,front=0;
	int min,t;
	int p,page_fault=0;
	for(int i=0;i<n;i++)
	{
		printf("enter page number :");
		scanf("%d",&string[i]);
		pagetable[string[i]].count=i;
		if(pagetable[string[i]].bit=='I')
		{	
			if(j<3)
			{
				frame[j]=string[i];
				j++;	
			}
			
			else
			{
			 min=99;
			   for(int k=0;k<3;k++)
			   {
			     if(pagetable[frame[k]].count<min)
			      {
				t=k;
				min=pagetable[frame[k]].count;	
			      }
			   }			
			 p=frame[t];
			 pagetable[p].bit='I';
			 frame[t]=string[i];
			}
			
			page_fault++;
			pagetable[string[i]].bit='V';
		}
		
		for(int i=0;i<3;i++)
		{
			printf(" %d ",frame[i]);	
		}		
		printf("\n");
	   }
	printf("number of pagefaults= %d",page_fault);
}

int main()
{
	int n;
	printf("enter number of pages: ");
	scanf("%d",&n);
	initialize();
	printf("----FIFO----\n");
	fifo(n);
	initialize();
	printf("----LRU----\n");
	lru(n);
	return 0;
}
/* OUTPUT
$ gcc paging.c
$ ./a.out
enter number of pages: 12
----FIFO----
enter page number from reference string:2
 2  -1  -1 
enter page number from reference string:3
 2  3  -1 
enter page number from reference string:2
 2  3  -1 
enter page number from reference string:1
 2  3  1 
enter page number from reference string:5
 5  3  1 
enter page number from reference string:2
 5  2  1 
enter page number from reference string:4
 5  2  4 
enter page number from reference string:5
 5  2  4 
enter page number from reference string:3
 3  2  4 
enter page number from reference string:2
 3  2  4 
enter page number from reference string:5
 3  5  4 
enter page number from reference string:2
 3  5  2 
number of pagefaults= 9----LRU----
enter page number :2
 2  -1  -1 
enter page number :3
 2  3  -1 
enter page number :2
 2  3  -1 
enter page number :1
 2  3  1 
enter page number :5
 2  5  1 
enter page number :2
 2  5  1 
enter page number :4
 2  5  4 
enter page number :5
 2  5  4 
enter page number :3
 3  5  4 
enter page number :2
 3  5  2 
enter page number :5
 3  5  2 
enter page number :2
 3  5  2 
number of pagefaults= 7$ 

