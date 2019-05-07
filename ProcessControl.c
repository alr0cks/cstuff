#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{

int arr[20],n,fid,status;
printf("Enter the number of elements in array:");
scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
	  printf("Enter the Elements in Array of %d:\n",n);
	  scanf("%d" , &arr[i]);
	}
fid = fork();
	if(fid==0) //child process
	{
	printf("\nBefore Sorting in Child:\n");
	for(int i=0;i<n;i++)
	{
	printf("%d\t",arr[i]);
	}
	  for(int i=0;i<n;i++) //ascending sort
	   {
	    for(int j=i+1;j<n;j++)
	    {
	    int temp;
	    if(arr[i]>arr[j])
	    {
	    arr[temp]=arr[i];
	    arr[i]=arr[j];
	    arr[j]=arr[temp];
	    }
	    }
	   }
	   printf("\nAfter Sorting in Child:\n");
	   for(int i=n;i>0;i--) //descending show
	   {
	   printf("%d\t",arr[i]);
	   }
	   exit(100);
	   
	}
	else if(fid > 0) //parent process
	{
	printf("\nWating for Child process to end\n");
	wait(&status);
	printf("\nChild Process Closed Sucessfully");
	printf("\nSorting in Parent Process:\n");
	for(int i=0;i<n;i++) //descending sort
	   {
	    for(int j=i+1;j<n;j++)
	    {
	    int temp;
	    if(arr[i]<arr[j])
	    {
	    temp=arr[i];
	    arr[i]=arr[j];
	    arr[j]=temp;
	    }
	    }
	   }
	   
	   for(int i=0;i<n;i++) //ascending show
	   {
	   printf("%d\t",arr[i]);
	   }
	}
	else
	{
	perror("fork failed");
	_exit(2);
	}
	return 0;
	
}
	
