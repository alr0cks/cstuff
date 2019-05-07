//NAME:- Alok Bhawankar
//ROLL NO.:- 203143
//DIV:- A
//BAtch:A3
#include<stdio.h>

   void main()
	   {
		  int gen[5],data[14],r[5],dn,gn,i,j,cnt,tra[14],res[14],c=0;

		  {//data
		  printf("\n Enter how many data bits:: ");
		  scanf("%d",&dn);
		  printf("\n Enter %d data bits:: ",dn);
		  for(i=0;i<dn;i++)
		   scanf("%d",&data[i]);
		  }

		  {//generator
		  printf("\n Enter the length of generator polynomial:: ");
		  scanf("%d",&gn);
		  printf("\n Enter %d generator bits:: ",gn);
		  for(i=0;i<gn;i++)
		   scanf("%d",&gen[i]);
		  }

		  {//zero bits
		  for(i=dn;i<(gn+dn-1);i++)
		   data[i]=0;
		  printf("\n After adding zero bits:: ");
		  for(i=0;i<(gn+dn-1);i++)
		   printf(" %d ",data[i]);
		  }


		  {//selecting bits from data
		  for(cnt=0;cnt<gn;cnt++)
		   r[cnt]=data[cnt];
		  }

		  { //calculation of remainder  6=^=ex or
		  while(cnt<gn+dn)
		  {
			while(r[0]==0) //shift
			{
			  if(cnt==gn+dn-1)
			   break;
			  for(i=0;i<gn-1;i++)
			   r[i]=r[i+1];
			  r[gn-1]=data[cnt++];
			}
			if(r[0]==0)
			 break;
			for(j=0;j<gn;j++)
			 r[j]=r[j]^gen[j];
		  }
		  }

		  {//crc bits
		  printf("\n\n CRC bits are:: ");
		  for(i=0;i<gn;i++)
		   printf(" %d ",r[i]);
		  }

		   {//adding crc bits in data bits
		   j=0;
		   for(i=dn;i<(gn+dn-1);i++)
			data[i]=r[++j];
		   }




		   printf("\n\n Transmitted data:: ");
		   for(i=0;i<(gn+dn-1);i++)
			printf(" %d ",data[i]);


		   //Receiver side

		   {//received data
		   printf("\n\n Recived data:: ");
		   for(i=0;i<(gn+dn-1);i++)
			scanf("%d",&res[i]);
		   }

		   {//selecting bits from received data
		   for(cnt=0;cnt<gn;cnt++)
			r[cnt]=res[cnt];
		   }

		   {//calculation of remainder
		   while(cnt<gn+dn)
		   {
			 while(r[0]==0)//shift
			 {
			   if(cnt==gn+dn-1)
				break;
			   for(i=0;i<gn-1;i++)
				r[i]=r[i+1];
			   r[gn-1]=res[cnt++];
			 }
			 if(r[0]==0)
			  break;
			 for(j=0;j<gn;j++)
			  r[j]=r[j]^gen[j];
		   }
		   }

		   {//crc bits
		   printf("\n\n CRC bits:: ");
		   for(i=0;i<gn;i++)
			printf(" %d ",r[i]);
		   }

		   {//checking remainder
		   for(i=0;i<gn;i++)
		   if(r[i]==0)
			c++;

		  if(c==gn)
			printf("\n\n correct");
		   else
			printf("\n\n incorrect");
		   }

	}
/*Output:

 Enter how many data bits:: 6

 Enter 6 data bits:: 1
0
0
1
0
0

 Enter the length of generator polynomial:: 4

 Enter 4 generator bits:: 1
1
0
1

 After adding zero bits::  1  0  0  1  0  0  0  0  0 

 CRC bits are::  0  0  0  1 

 Transmitted data::  1  0  0  1  0  0  0  0  1 

 Recived data:: 1
0
0
0
0
0
0
0
1


 CRC bits::  0  0  1  1 

 incorrect
*/
