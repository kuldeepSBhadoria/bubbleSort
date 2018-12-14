#include <stdio.h>
#include <stdlib.h>

int compare (int a, int b)
{
	if(a < b)// just change the compare and see the accending / decending  
		return -1;
	else
	       	return 1;
}

void display(int *p,int x)
{
	int i=0;
	printf("\n Array is : ");
	for(i=0 ; i < x; i++){
		printf(" %d ", *(p+i));
	}
	printf("\n ");
}

void bubblesort(int *p , int size, int (*comp)(int, int))
{
	int round, i , t, flag =0; static int count =0;
	for(round =1; round < size; round++)
	{
		for(i=0; i < size-round; i++)
		{	
			if(comp(*(p+i),*(p+i+1)) > 0)
			{
				flag = 1;
				count++;
				t = *(p+i);
				*(p+i) = *(p+i+1);
				*(p+i+1) = t;
			}
		}
		if(flag ==0)
			return ;
	}
	printf("\n Count %d\n", count);
}

int main()
{
	int *arr =  NULL;
	int arrsize = 0;
	int i =0;
	printf("\n Enter array size you want to sort : ");
	scanf("%d", &arrsize);

	arr = (int *) malloc( arrsize * (sizeof(int *)));
	printf("\n ENter array :  ");
	for( i=0 ; i < arrsize; i++)
	{
		scanf("%d", (arr+i));
	}
	void (*funp_bubblesort)(int *,int, int (*compare)(int , int)) = &bubblesort;
	display(arr, arrsize);
	funp_bubblesort(arr, arrsize, compare);
	display(arr, arrsize);
	
return 0;
}
//end
