//NAME:ALOK BHAWANKAR
//ROLL NO.:203143
//BATCH: A3
#include <stdio.h>
#include <stdlib.h>

struct pizza
{
	int orderid;
	char orderdate[20];
	char name[20];
	int mob;
	double price;
};

struct pizza q[20];
int front=-1;
int rear=-1;
int count=0;

void order()
{
	if(rear==19)
		printf("\n Queue is full. Wait for your turn.");
	else
	{
		rear++;
		q[rear].orderid=++count;
		printf("\n Enter Order Date: ");
		scanf("%s", q[rear].orderdate);
		printf("\n Enter your Name: ");
		scanf("%s", q[rear].name);
		printf("\n Enter your Phone Number: ");
		scanf("%d", &q[rear].mob);
		printf("\n Enter Price: ");
		scanf("%lf", &q[rear].price);

	}
}

void deliver()
{
	struct pizza temp;
	if(front==rear)
		printf("\n All pizzas delivered. ");
	else
	{
		front++;
		temp=q[front];
		printf("\n Delivered pizza details: ");
		printf("\n Order ID: %d", temp.orderid);
		printf("\n Order Date: %s", temp.orderdate);
		printf("\n Name of the Customer: %s", temp.name);
		printf("\n Phone Number: %d", temp.mob);
		printf("Money Received: %lf \n", temp.price);
	}
}

void display()
{
	printf("\n Orders Pending: \n");
	for(int i=front+1; i<=rear; i++)
	{
		printf("\n Order ID: %d", q[i].orderid);
		printf("\n Order Date: %s", q[i].orderdate);
		printf("\n Name of the Customer: %s", q[i].name);
		printf("\n Phone Number: %d", q[i].mob);
		printf("\n Money to be Received: %lf \n", q[i].price);
	}
}

int main(void)
{
	int ch, h;
	do
	{
	printf("\n MENU:  ");
	printf("\n 1. Order Pizza. \n 2. Deliver Pizza. \n 3. Display all the Orders. \n 4. Exit. ");
    printf("\n Enter your choice: ");
    scanf("%d", &ch);

    switch(ch)
    {
    case 1: order();
    		h=0;
    		break;

    case 2: deliver();
    		h=0;
    		break;

    case 3: display();
    		h=0;
    		break;

    case 4: printf("\n Thank You for your Visit. ");
    		h=1;
    		break;
    }
	}
	while(h==0);

	return 0;
}


/* 
  OUTPUT:

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 1

 Enter Order Date: 03-01-2019

 Enter your Name: apurva

 Enter your Phone Number: 8669355131

 Enter Price: 199

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 1

 Enter Order Date: 03-01-2019

 Enter your Name: himanshu

 Enter your Phone Number: 7002832041

 Enter Price: 399

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 3

 Orders Pending: 

 Order ID: 1
 Order Date: 03-01-2019
 Name of the Customer: apurva
 Phone Number: 79420539
 Money to be Received: 199.000000 

 Order ID: 2
 Order Date: 03-01-2019
 Name of the Customer: himanshu
 Phone Number: -1587102551
 Money to be Received: 399.000000 

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 1

 Enter Order Date: 03-01-2019

 Enter your Name: kajal

 Enter your Phone Number: 9954416351

 Enter Price: 189

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 3

 Orders Pending: 

 Order ID: 1
 Order Date: 03-01-2019
 Name of the Customer: apurva
 Phone Number: 79420539
 Money to be Received: 199.000000 

 Order ID: 2
 Order Date: 03-01-2019
 Name of the Customer: himanshu
 Phone Number: -1587102551
 Money to be Received: 399.000000 

 Order ID: 3
 Order Date: 03-01-2019
 Name of the Customer: kajal
 Phone Number: 1364481759
 Money to be Received: 189.000000 

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 2

 Delivered pizza details: 
 Order ID: 1
 Order Date: 03-01-2019
 Name of the Customer: apurva
 Phone Number: 79420539Money Received: 199.000000 

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 3

 Orders Pending: 

 Order ID: 2
 Order Date: 03-01-2019
 Name of the Customer: himanshu
 Phone Number: -1587102551
 Money to be Received: 399.000000 

 Order ID: 3
 Order Date: 03-01-2019
 Name of the Customer: kajal
 Phone Number: 1364481759
 Money to be Received: 189.000000 

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 4

 Thank You for your Visit.
*/
/*circular queue 

#include<stdio.h>
#define max 5
int r=-1;
int f=-1;
int q[max];

int isempty()
{
    if(f==r)
        return 0;
    else
        return -1;
}
int isfull()
{
    if(r==max-1)
        return 0;
    else
        return -1;
}

void add(int item)
{

    if((r+1)%max==f)
    {
        printf("queue is full");
    }
    else
    {
         r=(r+1)%max;
    	 q[r]=item;
    }
}
int delete()
{
	int item;
    if(f==r)
    {
    	printf("queue is empty");
    }
    else
    {
    	f=(f+1)%max;
    	item=q[f];
    	return item;
    }

}
void display()
{
    if(f!=r)
    for(int i=f+1;i<=r;i++)
    {
        printf("%d\t",q[i]);
    }
    else
	printf("\nQ is empty");
}
int main()
{
    int ch,x,l2;
    do
    {
        printf("\n1.Add\n2.Delete\n3.Display\n\tEnter Your choice:-");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the item:-");
                    scanf("%d",&x);
                    add(x);
                    printf("r=%d\t f=%d\n",r,f);
                    break;

            case 2: l2=delete();
                    if(l2<0)
                        printf("Q is empty");
                    else
                        printf("\nDeleted item is %d\n:",l2);
                        printf("r=%d\t f=%d\n",r,f);
                        display();
                        break;

            case 3: printf("r=%d\t f=%d\n",r,f);
                    display();
                    break;

        }
    }while(ch!=4);
    return 0;
}*/

