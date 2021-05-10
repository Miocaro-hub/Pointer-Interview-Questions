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

	char* p = "abcdef"; //"a  b c d e f \0",p中存放的是字符a的地址
	printf("%d\n", sizeof(p)); //4 - 计算指针变量p的大小
	printf("%d\n", sizeof(p+1)); //4 - p中存的是a的地址,p+1得到的是字符b的地址
	printf("%d\n", sizeof(*p)); //1 - *p就是字符串的第一个字符'a'
	printf("%d\n", sizeof(p[0])); //1 - p[0] == *(p+0) == 'a'
	printf("%d\n", sizeof(&p)); //4 - 表示p的地址
	printf("%d\n", sizeof(&p+1)); //4 - 跳过p的地址所占的内存,但本质还是地址
	printf("%d\n", sizeof(&p[0]+1)); //4 - p[0] == 'a',&p[0]表示a的地址,再加1表示b的地址
	printf("\n");
	
	printf("%d\n", strlen(p)); //6 - 从'a'的地址开始数,遇到\0中止
	printf("%d\n", strlen(p + 1)); //5 - 从'b'的地址开始数
	//printf("%d\n", strlen(*p)); //err
	//printf("%d\n", strlen(p[0])); //err
	printf("%d\n", strlen(&p)); //随机值 - &p表示p的地址,从p的地址开始数,\0的位置不确定
	printf("%d\n", strlen(&p + 1)); //随机值
	printf("%d\n", strlen(&p[0] + 1)); //5 - 化简后相当于第二行
	printf("\n");

	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n", sizeof(a)); //48 - sizeof(数组名)计算数组的总大小
	printf("%d\n", sizeof(a[0][0])); //4 - 第一行第一列的元素
	printf("%d\n", sizeof(a[0])); //16 - 将二维数组看成一维数组,a[0]相当于第一行作为一维数组的数组名,sizeof(arr[0])把数组名单独放在sizeof()内,计算的是第一行的大小
	printf("%d\n", sizeof(a[0]+1)); //4 - 只有将数组名单独放在sizeof()内才计算第一行的大小,此时a[0]表示第一行首元素的地址,a[0]+1计算的第一行中第二个元素地址的大小
	printf("%d\n", sizeof(*(a[0]+1))); //
	printf("%d\n", sizeof(a+1)); //
	printf("%d\n", sizeof(*(a+1))); //
	printf("%d\n", sizeof(&a[0]+1)); //
	printf("%d\n", sizeof(*(&a[0] + 1))); //
	printf("%d\n", sizeof(*a)); //
	printf("%d\n", sizeof(a[3])); //
	printf("\n");


	return 0;
}


