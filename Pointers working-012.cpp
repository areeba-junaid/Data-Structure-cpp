#include<stdio.h>
#include<conio.h>
int main()
{
	int a=55,*p,arr[6]={1,2,3,4,5};
	p=&a;
	printf("\n%d",a);
	printf("\n%u",p);
	printf("\n%u",&p);
	printf("\n%u",&a);
	printf("%u",*(&a));
	printf("\n%d",*p);
	printf("\n%u",arr);
	printf("\n%u",arr[0]);

	return 0;
}
