/*6.编写一个函数接受 3 个参数：一个数组名（内含已排序的整数）、该
数组的元素个数和待查找的整数。如果待查找的整数在数组中，那么该函数
返回 1；如果该数不在数组中，该函数则返回 0。用二分查找法实现。*/

#include <stdio.h>
#define SIZE 10
int Binary_search(int ar[],int n,int search_num);
int main()
{
    int search_num;
    int ar[SIZE]={1,2,3,4,5,6,7,8,9,10};

    printf("输入1个数(q离开):");
    while(scanf("%d",&search_num)==1)
    {
        puts("0代表不在数列，1代表在数列.");
        printf("%d\n",Binary_search(ar,SIZE,search_num));
        printf("再次输入1个数(q离开):");
    }
    puts("再见.");

    return 0;
}

int Binary_search(int ar[],int n,int search_num)
{
    int start=0;
    int end=n-1;
    int mid;

    while(start<=end)
    {
        mid=(start+end) / 2;
        if(search_num < ar[mid])
            end=mid-1;
        else if(search_num > ar[mid])
            start=mid+1;
        else
            return 1;
    }
    return 0;
}




