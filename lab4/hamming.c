#include <stdio.h>
#include <math.h>
int j;

int findr(int k)
{
	int r=1;

while(1)
{
	int a= pow(2,r);
   if(a>=k+r+1)
   {
   	int j=r;
   	
   	break;
   }
   r++;
   
}
return j;
}



void main()
 {
	
	int data[100],data1[100],m,r[8],c[8],i;
	printf("enter the number of bits you want to take as input from sender\n");
	scanf("%d",&m);
	data1[0]=2;
	printf("enter the data only 1 or 0\n");
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&data[i]);
	}
	for (int i = 0,j=7; i < m,j>=0; ++i,j--)
	{
		data[j]=data[i];
	}

	int rval=findr(m);
	r[0]=data[0]^data[1]^data[3]^data[4]^data[6];
	r[1]=data[0]^data[2]^data[3]^data[5]^data[6];
	r[2]=data[1]^data[2]^data[3]^data[7];
	r[3]=data[4]^data[5]^data[6]^data[7];
	for (int i = 1,j=0,k=0; i < m+rval,j<rval; ++i)
	{
			if(i==pow(2,j))
			{
				data1[i]=r[j];
				j++;
			}
			else
			{
				data1[i]=data[k];
				k++;
			}
	}
		
	/*if(data1[3]==0)
	{
		data1[3]=data[0]=1;
	}
	else
		data1[3]=data[0]=0;*/
	
//recever side

	c[0]=0^data[1]^data[3]^data[4]^data[6]^r[0];
	c[1]=0^data[2]^data[3]^data[5]^data[6]^r[1];
	c[2]=data[1]^data[2]^data[3]^data[7]^r[2];
	c[3]=data[4]^data[5]^data[6]^data[7]^r[3];
for (int i = 3; i >=0; i--)
{
	printf("%d",c[i] );
}
printf("\n");
return 0;
}
	




	/*
	printf("this works for message of 4bits in size \nenter message bit one by one:  ");
	scanf("%d%d%d%d",&data[0],&data[1],&data[2],&data[4]);
	data[6]=data[0]^data[2]^data[4];
	data[5]=data[0]^data[1]^data[4];
	data[3]=data[0]^data[1]^data[2];
	printf("\nthe encoded bits are given below: \n");
	for (i=0;i<7;i++) {
		printf("%d ",data[i]);
	}
	printf("\nenter the received data bits one by one: ");
	for (i=0;i<7;i++) {
		scanf("%d",&rec[i]);
	}
	c1=rec[6]^rec[4]^rec[2]^rec[0];
	c2=rec[5]^rec[4]^rec[1]^rec[0];
	c3=rec[3]^rec[2]^rec[1]^rec[0];
	c=c3*4+c2*2+c1 ;
	if(c==0) {
		printf("\ncongratulations there is no error: ");
	} else {
		printf("\nerron on the postion: %d\nthe correct message is \n",c);
		if(rec[7-c]==0)
		 			rec[7-c]=1; else
		 			rec[7-c]=0;
		for (i=0;i<7;i++) {
			printf("%d ",rec[i]);
		}
	}
	getch();
}*/
