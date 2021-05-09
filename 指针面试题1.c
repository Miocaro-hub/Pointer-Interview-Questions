#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//指针和数组笔试题详解

int main()
{
	//一维数组
	//数组名是首元素地址
    //两个例外
	//1.sizeof(数组名) - 数组名表示整个数组
	//2. &数组名 - 数组名表示整个数组
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a)); //sizeof(数组名) - 计算的是数组总大小 - 单位是字节- 结果为16
	printf("%d\n", sizeof(a + 0)); //4 - 数组名这里表示首元素地址 - a+0还是首元素的地址 
	printf("%d\n", sizeof(*a)); //4 - 首元素地址解引用 - *a就是首元素
	printf("%d\n", sizeof(a + 1)); //4 - 表示第二个元素的地址
	printf("%d\n", sizeof(a[1])); //4 - 第二个元素的大小
	printf("%d\n", sizeof(&a)); //4 - &a取出的是数组的地址,但是数组的地址的大小也是4个字节
	printf("%d\n", sizeof(*&a)); //16 - 相当于&和*抵消,和sizeof(a)一个效果
	printf("%d\n", sizeof(&a + 1)); //4 - &a取出的是整个数组的,+1跳过了一个数组,但还是一个地址
	printf("%d\n", sizeof(&a[0])); //4 - 首元素的地址
	printf("%d\n", sizeof(&a[0] + 1)); //4 - 第二个元素的地址
	printf("\n");

	//字符数组
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr)); //6 - sizeof(数组名) - 计算的数组的总大小
	printf("%d\n", sizeof(arr+0)); //4  - arr是首元素的地址,arr+0还是首元素的地址
	printf("%d\n", sizeof(*arr)); //1 - 首元素地址解引用,*arr就是首元素,首元素字符大小是一个字节
	printf("%d\n", sizeof(arr[1])); //1 - 第二个元素的大小
	printf("%d\n", sizeof(&arr)); //4 - &arr是数组的地址,但是数组的地址的大小也是4个字节
	printf("%d\n", sizeof(&arr+1)); //4 - &arr+1是跳过整个数组后的地址,本质还是地址
	printf("%d\n", sizeof(&arr[0]+1)); //4 - 第二个元素的地址
	printf("\n");

	printf("%d\n", strlen(arr)); //随机值 - \0的位置不确定,所以字符串的长度也不确定
	printf("%d\n", strlen(arr + 0)); //和上面一个意思,结果也是随机值
	//printf("%d\n", strlen(*arr)); //'a'的ascii码值为97,这种做法相当于把97作为地址,为非法访问err,strlen是()函数,参数必须是字符型的指针(地址)
	//printf("%d\n", strlen(arr[1])); //相当于98作为地址,也是非法访问
	printf("%d\n", strlen(&arr)); //随机值,原理和前两题一样
	printf("%d\n", strlen(&arr+1)); //随机值 - 6,原理一样
	printf("%d\n", strlen(&arr[0] + 1)); //随机值 - 1
	printf("\n");

	char ar[] = "abcdef"; //(a b c d e f \0)7个元素
	printf("%d\n", sizeof(ar)); //7 - sizeof计算的数组所占空间的大小,\0算一个元素,数组里有7个元素,所以结果为7
	printf("%d\n", sizeof(ar + 0)); //4 - 首元素地址的大小
	printf("%d\n", sizeof(*ar)); //1 - 首元素地址解引用,*ar就是首元素,首元素字符大小是一个字节
	printf("%d\n", sizeof(ar[1])); //1 - 第二个元素的大小
	printf("%d\n", sizeof(&ar)); //4 - &ar是数组的地址,但是数组的地址的大小也是4个字节
	printf("%d\n", sizeof(&ar + 1)); //4 - &ar+1是跳过整个数组后的地址,本质还是地址
	printf("%d\n", sizeof(&ar[0] + 1)); //4 - &arr[0]+1表示第二个元素的地址
	printf("\n");

	printf("%d\n", strlen(ar)); //6 - 从第一个元素的地址开始数起,遇到\0中止
	printf("%d\n", strlen(ar + 0)); //和上一行原理一样
	//printf("%d\n", strlen(*ar)); //非法
	//printf("%d\n", strlen(ar[1])); //非法
	printf("%d\n", strlen(&ar)); //6 - 数组的地址 - 数组指针
	printf("%d\n", strlen(&ar + 1)); //随机值 - &ar+1跳过了整个数组,导致了\0的位置又不确定了
	printf("%d\n", strlen(&ar[0] + 1)); //5 - 从数组中的第二个元素的地址数起
	printf("\n");
	return 0;
}


