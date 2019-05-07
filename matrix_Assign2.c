NAME   : Alok Bhawankar
Roll NO.: 203143
DIV    : CSE-A
BATCH  : A3

#include<stdio.h>
void display(int row ,int coloumn ,int a[10][10]);
void cdisplay(int row ,int coloumn,int count ,int b[count+1][3]);
void compact(int row, int coloumn,int a[10][10]);
main()
{
    int row,coloumn,i,j;
    int z;
    int a[10][10];
    int r;
    do{
    printf("select from the following:\n 1.Accept the matrix \n 2.Display the matrix\n3.compact matrix");
    scanf("%d",&r);
    switch(r)
    {
    case 1:
    printf("enter the number of rows you want");
    scanf("%d",&row);					//number of rows you want
    printf("enter the number of coloumns you want");
    scanf("%d",&coloumn);				//number of coloumns you want
    printf("enter the elements in matrix");
    for(i=0;i<row;i++)
    {
        for(j=0;j<coloumn;j++)
        {
            scanf("%d",&a[i][j]);       //scanning the matrix,entering the value in the matrix
        }
    }
    break;
    case 2:
    display(row,coloumn,a);            //displaying the matrix
    break;
    case 3:
    	compact(row,coloumn,a);			//calling compact matrix
    break;

    default:
    printf("invalid argument");

    }
    printf("to continue press 1 or else press 0");
    scanf("%d",&z);
    }while(z==1);

    }

void display(int row ,int coloumn ,int a[10][10])                       //displaying the matrix
{
	int i;
	int j;
	printf("elements in matrix are: ");
	    printf("\n");
	    for(i=0;i<row;i++)
	    {
	       
	        printf("\t");
	        for(j=0;j<coloumn;j++)
	        {
	            printf("%d",a[i][j]);
	            printf("\t");
	        }
	       
	        printf("\n");
	    }

}
void cdisplay(int row ,int coloumn,int count,int b[count+1][3])     //displaying the compact matrix
{
	int i;
	int j;
	printf("matrix is: ");
    printf("\n");
    for(i=0;i<count+1;i++)
    {
        printf("|");
        printf("\t");
        for(j=0;j<3;j++)
        {
            printf("%d",b[i][j]);
            printf("\t");
        }
        printf("|");
        printf("\n");
    }

}
void compact(int row, int coloumn,int a[10][10])
{
	int count=0;
	int p=1;
	int i,j,o;
    for(i=0;i<row;i++)				   //counting the non zero elements in the array
    {
        for(j=0;j<coloumn;j++)
        {
            if(a[i][j]!=0)
            {
                count++;
            }
        }
    }
    printf("%d",count);
    printf("\n");
    int q[count+1][3];
    q[0][0]=row;						//initializing the values of compact matrix
    q[0][1]=coloumn;
    q[0][2]=count;
    for(i=0;i<row;i++)					//putting the non zero value into compact matrix
    {
        for(j=0;j<coloumn;j++ )
        {
            if(a[i][j]!=0)
            {
                q[p][0]=i;
                q[p][1]=j;
                q[p][2]=a[i][j];
                p++;
            }
        }
    }
    printf("the compact matrix is: \n");
    cdisplay(count+1,3,count,q);			//displaying the compact matrix
    printf("\n");
    printf("select from the following:\n1.Simple transpose\n2.Fast transpose");
    scanf("%d",&o);
    switch(o)
    {
    case 1:
    {
    	printf("transpose of sparce matrix is: ");
    	    int f=1;
    	    int g[count+1][3];						//initializing the values of transpose of compact matrix
    	    g[0][0]=q[0][0];
    	    g[0][1]=q[0][1];
    	    g[0][2]=q[0][2];
    	    for(i=0;i<coloumn;i++)					//doing the transpose of compact matrix
    	    {
    	        for( j=1;j<count+1;j++)
    	        {
    	            if(q[j][1]==i)
    	            {
    	                g[f][0]=q[j][1];
    	                g[f][1]=q[j][0];
    	                g[f][2]=q[j][2];
    	                f++;
    	            }
    	        }
    	    }
    	    cdisplay(count+1,3,count,g);		//calling the display function
    	break;
    }
    case 2:
    {
    	printf("fast transpose of sparce matrix is: ");
    	    int s[coloumn];
    	    for(i=0;i<coloumn;i++)				//initializing the array for coloumns with value zero
    	    {
    	        s[i]=0;
    	    }

    	    int t[coloumn];
    	    int r;								//counting how many values are there in that coloumn
    	    for(i=1;i<count+1;i++)
    	    {
    	        r=q[i][1];
    	        s[r]=s[r]+1;

    	    }

    	    t[0]=1;
    	    for(i=1;i<coloumn;i++)				//initializing the position to elements in the coloumn
    	    {
    	        t[i]=t[i-1]+s[i-1];
    	    }

    	    int k[count+1][3];					//initializing the values of transpose of compact matrix
    	        k[0][0]=q[0][0];
    	        k[0][1]=q[0][1];
    	        k[0][2]=q[0][2];
    	   int y;
    	    for(i=1;i<count+1;i++)				//writing the transpose in the matrix
    	    {
    	        y=q[i][1];
    	        k[t[y]][0]=q[i][1];
    	        k[t[y]][1]=q[i][0];
    	        k[t[y]][2]=q[i][2];
    	        t[y]=t[y]+1;
    	    }
    	    cdisplay(count+1,3,count,k);				//calling the display function
    	break;
    }
    default:
    	printf("invalid argument");


    }




}


/* OUTPUT
select from the following:
 1.Accept the matrix 
 2.Display the matrix
3.compact matrix1
enter the number of rows you want3
enter the number of coloumns you want3
enter the elements in matrix
1
2
3
4
0
0
0
6
0
to continue press 1 or else press 01
select from the following:
 1.Accept the matrix 
 2.Display the matrix
3.compact matrix2
elements in matrix are: 
	1	2	3	
	4	0	0	
	0	6	0	
to continue press 1 or else press 01
select from the following:
 1.Accept the matrix 
 2.Display the matrix
3.compact matrix3
5
the compact matrix is: 
matrix is: 
	3	3	5	
	0	0	1	
	0	1	2	
	0	2	3	
	1	0	4
	2	1	6	

select from the following:
1.Simple transpose
2.Fast transpose1
transpose of sparce matrix is: matrix is: 
	3	3	5	
	0	0	1	
	0	1	4	
	1	0	2	
	1	2	6	
	2	0	3	
to continue press 1 or else press 01
select from the following:
 1.Accept the matrix 
 2.Display the matrix
3.compact matrix1
enter the number of rows you want3
enter the number of coloumns you want3
enter the elements in matrix
1
2
3
0
0
0
0
0
9
to continue press 1 or else press 01
select from the following:
 1.Accept the matrix 
 2.Display the matrix
3.compact matrix2
elements in matrix are: 
	1	2	3	
	0	0	0	
	0	0	9	
to continue press 1 or else press 01
select from the following:
 1.Accept the matrix 
 2.Display the matrix
3.compact matrix3
4
the compact matrix is: 
matrix is: 
	3	3	4	
	0	0	1	
	0	1	2	
	0	2	3	
	2	2	9	

select from the following:
1.Simple transpose
2.Fast transpose2
fast transpose of sparce matrix is: matrix is: 
	3	3	4	
	0	0	1	
	1	0	2	
	2	0	3	
	2	2	9	
to continue press 1 or else press 0
*/
