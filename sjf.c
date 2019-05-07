#include<stdio.h>
#include<stdlib.h>

struct process
{
	int pname,at,bt,wt,tat,n,rt;

}
p[10];

void accept(int);
void sort(int);
void sjfpremt(int);
void display(int);

void accept(int n)
{
int i;
for(i=0;i<n;i++)
{printf("Enter details for process P%d \n",i);
p[i].pname=i;
printf("Enter arrival time:");
scanf("%d",&p[i].at);
printf("Enter burst time:");
scanf("%d",&p[i].bt);
p[i].rt=p[i].bt;
p[i].wt=0;
p[i].tat=0;
}
}

void sort(int n)
{
int c,d;
struct process swap;
for(c=0;c<n-1;c++)
	{
		for(d=c+1;d<n;d++)
		{
			if (p[c].at>p[d].at)			 
			{					
				swap = p[c];			
				p[c]=p[d];
				p[d]=swap;
			}
		}
	}
}

void display(int n)
{
int i;
printf("\n Process \t AT \t BT \t WT \t TAT");
for(i=0;i<n;i++)
{
printf("\n\tP%d\t%d\t%d\t%d\t%d\n",p[i].pname,p[i].at,p[i].bt,p[i].wt,p[i].tat);
}
}

void sjfpremt(int n)
{
int i,time=0,count=0,smallest=0,end=0,total_wt=0,total_tat=0,temp=555,temp2=555;
float avg_wt=0,avg_tat=0;
p[9].rt=9999;

for(time=0;count!=n;time++)
{
smallest =9;
for(i=0;i<n;i++)
{
if(p[i].at<=time && p[i].rt <p[smallest].rt && p[i].rt>0)
{
smallest=i;
}
}



p[smallest].rt--;
printf("%d<--P%d-->",time,p[smallest].pname);

if(p[smallest].rt==0)
{
count++;
end=time+1;
p[smallest].wt=end-p[smallest].at-p[smallest].bt;
p[smallest].tat=end-p[smallest].at;
total_wt=total_wt+p[smallest].wt;
total_tat=total_tat+p[smallest].tat;
}
}

printf("%d",time);
display(n);
avg_wt=total_wt/n;
avg_tat=total_tat/n;
printf("\n\nAverage Waiting Time:\t%f\n",avg_wt);
printf("Average Turnaround Time:\t%f\n",avg_tat);
}

int main()
{
int n;
printf("Enter number of processes:");
scanf("%d",&n);
accept(n);
sort(n);
display(n);
sjfpremt(n);

}




