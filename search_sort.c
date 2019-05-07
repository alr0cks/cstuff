//Name:Alok BHawankar
//Div:A
//Roll no.:203143
#include<stdio.h>
struct student
{
    char name[10];
    int roll;
    char division;
    float marks;
};
void accept(struct student s1[],int n);
void display(struct student s1[],int n);
void linearsearch(struct student s1[],int n,int a);
void bubblesort(struct student s1[],int n);
void selectionsort(struct student s1[],int n);
void insertionsort(struct student s1[],int n);
int binarysearch(struct student s1[],int last,int first,int a);


main()
{
    int n,a,cond,ch;
    int flag;
        struct student s1[20];
        printf("\nEnter number of students : ");
        scanf("%d", &n);
        do    {
            printf("\n1. Accept\n2. Display \n3. Linear Search\n4. Binary Search\n5.Bubble sort\n6.selection sort\n7.insertion sort\nChoice:");
            scanf("%d",&ch);
            switch(ch)    {
            case 1:    accept(s1,n);
                    break;
            case 2: display(s1,n);
                    break;
            case 3:
                    printf("Enter the roll no.: ");
                        scanf("%d",&a);
                    linearsearch(s1,n,a);

                    break;
            case 4:
                    printf("Enter the roll no.: ");
                        scanf("%d",&a);
                    flag= binarysearch(s1,n,0,a);
                    if(flag==1)
                        printf("\nRecord found.");
                    else
                        printf("\nRecord not found.");
                    break;
            case 5:bubblesort(s1,n);
                    printf("\nSorted");
                    display(s1,n);
                    break;
            case 6:selectionsort(s1,n);
                    printf("\nSorted");
                    display(s1,n);
                    break;
            case 7:insertionsort(s1,n);
                    printf("\nSorted");
                    display(s1,n);
                    break;
            default: printf("\nInvalid Choice");
            }
            printf("\nDo you want to continue? (Y=1/N=0) : ");
            scanf("%d", &cond);
            }while(cond == 1);

}
void accept(struct student s1[],int n)
{
	int i;
	    for(i=0;i<n;i++)
	    {
	        printf("Entry: %d",i+1);
	        printf("\n");
	        printf("Enter roll number:");
	        scanf("%d",&s1[i].roll);
	        printf("Enter name:");
	        scanf("%s",&s1[i].name);
	        printf("Enter division:");
	        scanf("%s",&s1[i].division);
	        printf("\n");


	    }
}
void display(struct student s1[],int n)
{
	  int i;
	    for(i=0;i<n;i++)
	    {
	        printf("Entry: %d",i+1);
	        printf("\n");
	        printf("Roll number: %d",s1[i].roll);
	        printf("\n");
	        printf("Name: %s",s1[i].name);
	        printf("\n");
	        printf("Division: %c",s1[i].division);
	        printf("\n");


	    }
}
void linearsearch(struct student s1[], int n,int a)
{
    int temp=0;
    int i;
    for(i=0;i<n;i++)
    {
        if(s1[i].roll==a)
        {
            printf("entry found at position: %d",i+1);
            temp++;
            break;
        }

    }
    if(temp==0)
    {
        printf("no entry found");
    }


}
void bubblesort(struct student s1[],int n)
{
    int i,j;
    struct student temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(s1[j].roll>s1[j+1].roll)
            {
                temp=s1[j];
                s1[j]=s1[j+1];
                s1[j+1]=temp;


            }
        }

    }


}
void selectionsort(struct student s1[],int n)
{
    int i,j;
    int minpos;
    struct student temp;

    for(i=0;i<n-1;i++)
    {
        minpos=i;
        for(j=i;j<n;j++)
        {
            if(s1[minpos].roll>s1[j].roll)
            {
                minpos=j;


            }
        }
                        temp=s1[i];
                        s1[i]=s1[minpos];
                        s1[minpos]=temp;

    }


}
void insertionsort(struct student s1[],int n)
{
     int i,j;
    int pos;
    struct student temp;

    for(i=0;i<n;i++)
    {
        pos=i;
        while(pos>0 && s1[pos].roll<s1[pos-1].roll)
        {
                                    temp=s1[pos];
                                    s1[pos]=s1[pos-1];
                                    s1[pos-1]=temp;
                                    pos--;
        }


    }


}
int binarysearch(struct student s1[], int last,int first,int a)
{
	insertionsort(s1,last);
    if(last>=first)
    {
        int mid = first+(last-1)/2;
        if(s1[mid].roll==a)
        {
            printf("entry found at position: %d",mid+1);
            return 1;
        }
        if(s1[mid].roll>a)
        {
            binarysearch(s1,mid-1,first,a);
        }
        else
        {
            binarysearch(s1,last,mid+1,a);
        }


    }
    return -1;



}
/*
 * OUTPUT
 *
Enter number of students : 3

1. Accept
2. Display
3. Linear Search
4. Binary Search
5.Bubble sort
6.selection sort
7.insertion sort
Choice:1
Entry: 1
Enter roll number:1
Enter name:alok
Enter division:a

Entry: 2
Enter roll number:3
Enter name:aditya
Enter division:a

Entry: 3
Enter roll number:2
Enter name:aniket
Enter division:a


Do you want to continue? (Y=1/N=0) : 1

1. Accept
2. Display
3. Linear Search
4. Binary Search
5.Bubble sort
6.selection sort
7.insertion sort
Choice:2
Entry: 1
Roll number: 1
Name: alok
Division: a
Entry: 2
Roll number: 3
Name: aditya
Division: a
Entry: 3
Roll number: 2
Name: aniket
Division: a

Do you want to continue? (Y=1/N=0) : 1

1. Accept
2. Display
3. Linear Search
4. Binary Search
5.Bubble sort
6.selection sort
7.insertion sort
Choice:3
Enter the roll no.: 2
entry found at position: 3
Do you want to continue? (Y=1/N=0) : 1

1. Accept
2. Display
3. Linear Search
4. Binary Search
5.Bubble sort
6.selection sort
7.insertion sort
Choice:4
Enter the roll no.: 3
entry found at position: 3
Record not found.
Do you want to continue? (Y=1/N=0) : 1

1. Accept
2. Display
3. Linear Search
4. Binary Search
5.Bubble sort
6.selection sort
7.insertion sort
Choice:5

SortedEntry: 1
Roll number: 1
Name: alok
Division: a
Entry: 2
Roll number: 2
Name: aniket
Division: a
Entry: 3
Roll number: 3
Name: aditya
Division: a

Do you want to continue? (Y=1/N=0) :
*/

 */
