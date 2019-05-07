//NAME:ALOK BHAWANKAR
//ROLL NO.:203143
//BATCH: A3
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node* createll(struct node *head)
{
	char ch;
	do
	{
		struct node *ptr,*temp;
		ptr=(struct node*)malloc(sizeof(struct node*));
		printf("\nEnter the data:\n");
		scanf("%d",&ptr->data);
		if(head->next==NULL)
		{
			head->next=ptr;
			ptr->next=NULL;
			temp=ptr;
		}
		else
		{
			temp->next=ptr;
			temp=ptr;
		}
		printf("\nDo you want to add another node?(y/n)\n");
		scanf(" %c",&ch);
	}
	while(ch=='y');
	return head;
}
void display(struct node *head)
{
	struct node *temp;
	if(head->next==NULL)
	{
		printf("\nList empty!!\n");
	}
	else
	{
		temp=head->next;
		printf("\nList elements:\n");
		while(temp!=NULL)
		{
			printf("%d -> ",temp->data);
			temp=temp->next;
		}
	}
}


struct node* addbet(struct node *head)
{
	int flag,count;
	struct node *temp,*ptr,*nd;
	ptr=(struct node*)malloc(sizeof(struct node*));
	printf("\nAt which position do you want to add the node?\n");
	scanf("%d",&flag);
	printf("\nEnter Data:\n");
	scanf("%d",&ptr->data);
	temp=head->next;
	count=1;
	if(flag==count)
	{
		head->next=ptr;
		ptr->next=temp;
	}
	while(temp!=NULL)
	{
		if(count==flag-1)
		{
			nd=temp->next;
			temp->next=ptr;
			ptr->next=nd;
			break;
		}
		else
		{
			count++;
			temp=temp->next;
		}
	}
	return head;
}
struct node* delbet(struct node *head)
{
	int flag,count;
	struct node *temp,*nd;
	printf("At which position do you want to delete the node?\n");
	scanf("%d",&flag);
	temp=head->next;
	count=1;
	if(flag==count)
	{
		temp=temp->next;
		head->next=temp;
	}
	while(temp!=NULL)
	{
		if(count==flag-1)
		{
			nd=temp->next;
			nd=nd->next;
			temp->next=nd;

			break;
		}
		else
		{
			count++;
			temp=temp->next;
		}
	}
	return head;
}

int len(struct node* head)
{
	int i =0;
	struct node *curr;
	curr=head->next;
	while(curr!=NULL)
		{    i++;
			curr=curr->next;

		}
	return (i);


}

void sllsort(struct node* head){
	struct node *prev,*curr,*temp;
	int i,j,n;
	n=len(head);
	for(i=0;i<n;i++){
		prev=head;
		curr=head->next;
		for(j=0;j<n-1;j++){
			temp=curr->next;
			if(curr->data>temp->data){
				prev->next=temp;
				curr->next=temp->next;
				temp->next=curr;
				prev=temp;
			}
			else{
				prev=curr;
				curr=curr->next;
			}
		}
	}
	display(head);
}

void mergesort(struct node* head1,struct node* head2){
	struct node *curr1,*curr2,*temp;
	curr1=head1->next;
	curr2=head2->next;
	int flag;
	if(curr1->data < curr2->data)
	{
		temp=head1;
		flag=1;
	}
	else
	{
		temp=head2;
		flag=0;
	}
	while(curr1!=NULL && curr2!=NULL){
		if(curr1->data<curr2->data){
			temp->next=curr1;
			temp=curr1;
			curr1=curr1->next;
		}
		else{
			temp->next=curr2;
			temp=curr2;
			curr2=curr2->next;
		}
	}
	if(curr1==NULL)
	temp->next=curr2;

	if(curr2==NULL)
	temp->next=curr1;

	if(flag==1)
	{
		display(head1);
	}
	else
	{
	display(head2);
	}
}

void reverse(struct node *head){
    struct node *p,*q,*r;
    p=NULL;
    q=head->next;
    while(q!=NULL){
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    head->next=p;
}



int main()
{
	int ch;
	struct node *head,*head1;
	head=(struct node*)malloc(sizeof(struct node*));

	head->next=NULL;

	head=createll(head);
	display(head);
	while(ch!=4)
	{
		printf("\n1:Add node\n2:Delete node\n3:Reverse\n5:Sort Linked List\n4.Merge Sort\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:head=addbet(head);
				display(head);
				break;
			case 2:head=delbet(head);
				display(head);
				break;
			case 3:reverse(head);
				display(head);
				break;
			case 5:display(head);
				sllsort(head);

				break;
			case 4:printf("\nEnter 2nd linked list:\n");
			head1=(struct node*)malloc(sizeof(struct node*));
			head1->next=NULL;
			head1=createll(head1);
			display(head);
				display(head1);
				mergesort(head,head1);
				break;
		}
	}



	return 0;
}
/*OUTPUT:

Enter the data:
1

Do you want to add another node?(y/n)
y

Enter the data:
3

Do you want to add another node?(y/n)
y

Enter the data:
5

Do you want to add another node?(y/n)
n

List elements:
1 -> 3 -> 5 -> 
1:Add node
2:Delete node
3:Reverse
5:Sort Linked List
4.Merge Sort
1

At which position do you want to add the node?
1

Enter Data:
0

List elements:
0 -> 1 -> 3 -> 5 -> 
1:Add node
2:Delete node
3:Reverse
5:Sort Linked List
4.Merge Sort
2
At which position do you want to delete the node?
1

List elements:
1 -> 3 -> 5 -> 
1:Add node
2:Delete node
3:Reverse
5:Sort Linked List
4.Merge Sort
3

List elements:
5 -> 3 -> 1 -> 
1:Add node
2:Delete node
3:Reverse
5:Sort Linked List
4.Merge Sort
5

List elements:
5 -> 3 -> 1 -> 
List elements:
1 -> 3 -> 5 -> 
1:Add node
2:Delete node
3:Reverse
5:Sort Linked List
4.Merge Sort
4

Enter 2nd linked list:

Enter the data:
2

Do you want to add another node?(y/n)
y

Enter the data:
4

Do you want to add another node?(y/n)
y

Enter the data:
6

Do you want to add another node?(y/n)
n

List elements:
1 -> 3 -> 5 -> 
List elements:
2 -> 4 -> 6 -> 
List elements:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 
*/

