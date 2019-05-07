
#include<stdio.h>
#include<stdlib.h>

	void accept(char *str)
	{
		printf("Enter string:");
		scanf("%s",str);
	}
	void display(char *str)
	{
		printf("%s\n",str);
	}
	int length(char *s1)
	{
		 int i=0;
		 while(*s1!='\0')
		 {
			 s1++;
			 i++;}
		 return i;
	}
	void copy(char *s1, char *s2)
	{

		 while(*s1!='\0')
	     {
			*s2 = *s1;
			s1++;
			s2++;
	     }
		 *s2='\0';

	}
	void concat(char *s1 ,char *s2)
	{
		int l1 = length(s1);
		int l2 = length(s2);
		int i=0;
		for(i=0;i<l2;i++)
		{
			*(s1 + l1 + i)= *(s2 + i);
		}
			s1[i+l1]='\0';

	}
	void reverse(char *s1 , char *s2)
	{
		int len = length(s1);
		    int i=0;
		    len--;
		    while(len>=0)
		    {
		        s2[i]=s1[len];
		        i++;
		        len--;
		    }
		    s2[i]='\0';
	}
	int compare(char *s1 , char *s2)
	{
	    int i = 0;
	    while(s1[i]==s2[i]&&s1[i]!='\0')
	    {
	        i++;
	    }
	    if(s1[i]==s2[i])
	    {
	        return 1;
	    }
	    else
	    {
	        return 0;
	    }
	}
	void substr(char *s1, char *s2)
	{
	    int count1=0,count2=0,flag;
	while(s1[count1]!='\0')
	{
	count1++;
	}
	while(s2[count2]!='\0')
	{count2++;}
	for(int i=0;i<=count1-count2;i++)
	{
		for(int j =i; j<i+count2;j++)
		{
				flag=1;
				if(s1[j]!=s2[j-i])
				{
					flag=0;
					break;
				}
		}
		if(flag==1)
		break;
	}
		if(flag==1)
			printf("The substring was found \n \n");
		else
			printf("Substring not found \n \n");


	}
	
	int main()
	{
		int ch,len,run,a;
		char str1[20],str2[20];
		do{
        run=0;
		printf("\nMENU\n");
		printf("1)Accept string\n");
		printf("2)Display string\n");
		printf("3)Length of String\n");
		printf("4)Copy String\n");
		printf("5)Concatinate two strings\n");
		printf("6)Reverse 1st string\n");
		printf("7)Compare 2 strings\n");
		printf("8)Check if String is Palindrome\n");
		printf("9)Check if String is Substring\n");
		printf("Enter your option:\n");
		scanf("%d", &ch);

			switch(ch)
		{
		case 1: accept(str1);
				accept(str2);
		break;

		case 2:	
		        printf("The 1st string is:");
		        display(str1);
		        printf("The 2nd string is:");
		        display(str2);
		break;

		case 3:
			    len=length(str1);
				printf("Length of 1st string is: %d",len);
				len=length(str2);
				printf("Length of 2nd string is: %d",len);
		break;

		case 4:
				copy(str1,str2);
				printf("The copied String is %s\n",str2);
		break;

		case 5: concat(str1,str2);
				printf("Concatinated String is: %s",str1);
		break;

		case 6: reverse(str1,str2);
						printf("Reverse String is: %s",str2);
				break;
				
		case 7: 
		        a = compare(str1,str2);
		        if(a==1)
	                 {
	                    printf("Two strings are equal");
	               }
	            else if(a==0)
	             {
	                    printf("Two strings are not equal");
	             }
				break;
				
		case 8: reverse(str1,str2);
		        a=compare(str1,str2);
		        if(a==1)
	                 {
	                    printf("The string is Palindrome");
	               }
	            else if(a==0)
	             {
	                    printf("The string is not Palindrome");
	             }
				break;
		
		case 9: substr(str1,str2);
					
				break;
		}
		
		}
		while(run==0);


	}

