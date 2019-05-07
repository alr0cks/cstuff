//NAME:- Alok Bhawankar
//ROLL NO.:- 203143
//DIV:- A
//BAtch:A3

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

 Enter your Name: Ammar

 Enter your Phone Number: 987654321

 Enter Price: 299

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 1

 Enter Order Date: 03-01-2019

 Enter your Name: Raj

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
 Name of the Customer: Ammar
 Phone Number: 987654321
 Money to be Received: 299.000000 

 Order ID: 2
 Order Date: 03-01-2019
 Name of the Customer: Raj
 Phone Number: -7002832041
 Money to be Received: 399.000000 

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 1

 Enter Order Date: 03-01-2019

 Enter your Name: Apurva

 Enter your Phone Number: 9574416421

 Enter Price: 185

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 3

 Orders Pending: 

 Order ID: 1
 Order Date: 03-01-2019
 Name of the Customer: Ammar
 Phone Number: 987654321
 Money to be Received: 299.000000 

 Order ID: 2
 Order Date: 03-01-2019
 Name of the Customer: Raj
 Phone Number: -7002832041
 Money to be Received: 399.000000 

 Order ID: 3
 Order Date: 03-01-2019
 Name of the Customer: Apurva
 Phone Number: 1364481759
 Money to be Received: 185.000000 

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 2

 Delivered pizza details: 
 Order ID: 1
 Order Date: 03-01-2019
 Name of the Customer: Ammar
 Phone Number: 987654321
 Money Received: 199.000000 

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 3

 Orders Pending: 

 Order ID: 2
 Order Date: 03-01-2019
 Name of the Customer: RAj
 Phone Number: -7002832041
 Money to be Received: 399.000000 

 Order ID: 3
 Order Date: 03-01-2019
 Name of the Customer: Apurva
 Phone Number: 1364481759
 Money to be Received: 185.000000 

 MENU:  
 1. Order Pizza. 
 2. Deliver Pizza. 
 3. Display all the Orders. 
 4. Exit. 
 Enter your choice: 4

 Thank You for your Visit.
*/
