#include<stdio.h>
#include<conio.h>
#define size 5
void main(){

	int i,j,a[size],temp,count=0;
	clrscr();
	printf("Enter Elements of Array -:\n");
	for(i=0;i<size;i++){
	   scanf("%d",&a[i]);
	}
	clrscr();
	printf("Elements of Array -: ");
	for(i=0;i<5;i++){
	   printf(" %d |",a[i]);
	}

	for(i=0;i<5-1;i++){
	   for(j=0;j<5-i-1;j++){
	      count++;
	      if(a[i] > a[i+1]){
		temp = a[i];
		a[i] = a[i+1];
		a[i+1] = temp;
	      }
	   }
	}

	printf("\n%d Sorted Array -: ",count);
	for(i=0;i<5;i++){
	   printf(" %d |",a[i]);
	}

   getch();
}

