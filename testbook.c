#include<stdio.h>
int main()
{
  struct book{
    int pages;
    float price;
  };
  struct book b1,b2;
  printf("enter the value of pages of book 1:\n");
  scanf("%d",&b1.pages);
  printf("enter the value of price of book 2\n");
  scanf("%f",&b2.price);
  printf("%d\n",b1.pages);
  printf("%d\n",b2.price);
  return 0;
}
