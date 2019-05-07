#include <stdio.h>
#include <stdlib.h>


struct Process
{
	int at, bt, pid, wt, tat;               
	
};

typedef struct Process pc;

void read_data(pc P[10], int n)
{
	int i;
	for(i = 0; i<n; i++)
	{
		printf("\nEnter the details of the process P%d", i+1);           
		P[i].pid = i+1;
		printf("\nEnter the arrival time of the process\n");
		scanf("%d", &P[i].at);                                     
		printf("\nEnter the burst time of the process\n");
		scanf("%d", &P[i].bt);
		P[i].wt = 0;
		P[i].tat = 0;
	}
}

void display(pc P[10], int n)
{
          int i;
          
          printf("\n\n\tpid\t\tat\t\tbt\t\twt\t\ttat");
          for(i=0;i<n;i++)
          {
          printf("\n\n\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", P[i].pid, P[i].at, P[i].bt, P[i].wt, P[i].tat);       
          }

}

void FCFS(pc P[10], int n)
{
          int i, curr_time, tot_wt, tot_tat;
          float at_wt, av_tat;
          tot_wt = 0;
          tot_tat = 0;
          curr_time = P[0].at;
          printf("\n----GANT CHART----\n");
          printf("%d", curr_time);
          
          for(i=0; i<n; i++)
          {
               printf("[  P%d  ]", P[i].pid);
               curr_time = curr_time + P[i].bt;
               P[i].tat = curr_time - P[i].at;
               P[i].wt = P[i].tat - P[i].wt;
               tot_tat = tot_wt + P[i].tat;
               printf("%d", curr_time);
               if(i<n-1 && curr_time < P[i+1].at)
               {
                    printf("  The processor is in IDLE STATE  ");
                    curr_time = P[i+1].at;
                    printf("%d", curr_time);
               }
          }
          
          printf("\nTabular form output\n");
          display(P,n);
          
          at_wt = (float)tot_wt/n;
          av_tat = (float)tot_tat/n;
          printf("\nAverage waiting time of the process is %f\n", at_wt);
          printf("\nAverage turn around time of the process is %f\n", av_tat);
}

void sort(pc P[10], int n)
{
     int i, j;
     pc t;
     for(i=0; i<n; i++)
     {
          for(j=0; j<n-i-1; j++)
          {
               if(P[j].at > P[j+1].at)
               {
                    t = P[j];
                    P[j] = P[j+1];
                    P[j+1] = t;
               }
          }
     }
               
}
int main(void)
{
     pc P[10];
     int n;
     printf("\nenter the number of process:");
     scanf("%d", &n);
     read_data(P,n);
     sort(P,n);
     display(P,n);
     FCFS(P,n);
     return 0;
}




