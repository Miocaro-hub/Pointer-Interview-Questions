#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//ָ���������������

int main()
{
	//һά����
	//����������Ԫ�ص�ַ
    //��������
	//1.sizeof(������) - ��������ʾ��������
	//2. &������ - ��������ʾ��������
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a)); //sizeof(������) - ������������ܴ�С - ��λ���ֽ�- ���Ϊ16
	printf("%d\n", sizeof(a + 0)); //4 - �����������ʾ��Ԫ�ص�ַ - a+0������Ԫ�صĵ�ַ 
	printf("%d\n", sizeof(*a)); //4 - ��Ԫ�ص�ַ������ - *a������Ԫ��
	printf("%d\n", sizeof(a + 1)); //4 - ��ʾ�ڶ���Ԫ�صĵ�ַ
	printf("%d\n", sizeof(a[1])); //4 - �ڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(&a)); //4 - &aȡ����������ĵ�ַ,��������ĵ�ַ�Ĵ�СҲ��4���ֽ�
	printf("%d\n", sizeof(*&a)); //16 - �൱��&��*����,��sizeof(a)һ��Ч��
	printf("%d\n", sizeof(&a + 1)); //4 - &aȡ���������������,+1������һ������,������һ����ַ
	printf("%d\n", sizeof(&a[0])); //4 - ��Ԫ�صĵ�ַ
	printf("%d\n", sizeof(&a[0] + 1)); //4 - �ڶ���Ԫ�صĵ�ַ
	printf("\n");

	//�ַ�����
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr)); //6 - sizeof(������) - �����������ܴ�С
	printf("%d\n", sizeof(arr+0)); //4  - arr����Ԫ�صĵ�ַ,arr+0������Ԫ�صĵ�ַ
	printf("%d\n", sizeof(*arr)); //1 - ��Ԫ�ص�ַ������,*arr������Ԫ��,��Ԫ���ַ���С��һ���ֽ�
	printf("%d\n", sizeof(arr[1])); //1 - �ڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(&arr)); //4 - &arr������ĵ�ַ,��������ĵ�ַ�Ĵ�СҲ��4���ֽ�
	printf("%d\n", sizeof(&arr+1)); //4 - &arr+1���������������ĵ�ַ,���ʻ��ǵ�ַ
	printf("%d\n", sizeof(&arr[0]+1)); //4 - �ڶ���Ԫ�صĵ�ַ
	printf("\n");

	printf("%d\n", strlen(arr)); //���ֵ - \0��λ�ò�ȷ��,�����ַ����ĳ���Ҳ��ȷ��
	printf("%d\n", strlen(arr + 0)); //������һ����˼,���Ҳ�����ֵ
	//printf("%d\n", strlen(*arr)); //'a'��ascii��ֵΪ97,���������൱�ڰ�97��Ϊ��ַ,Ϊ�Ƿ�����err,strlen��()����,�����������ַ��͵�ָ��(��ַ)
	//printf("%d\n", strlen(arr[1])); //�൱��98��Ϊ��ַ,Ҳ�ǷǷ�����
	printf("%d\n", strlen(&arr)); //���ֵ,ԭ���ǰ����һ��
	printf("%d\n", strlen(&arr+1)); //���ֵ - 6,ԭ��һ��
	printf("%d\n", strlen(&arr[0] + 1)); //���ֵ - 1
	printf("\n");

	char ar[] = "abcdef"; //(a b c d e f \0)7��Ԫ��
	printf("%d\n", sizeof(ar)); //7 - sizeof�����������ռ�ռ�Ĵ�С,\0��һ��Ԫ��,��������7��Ԫ��,���Խ��Ϊ7
	printf("%d\n", sizeof(ar + 0)); //4 - ��Ԫ�ص�ַ�Ĵ�С
	printf("%d\n", sizeof(*ar)); //1 - ��Ԫ�ص�ַ������,*ar������Ԫ��,��Ԫ���ַ���С��һ���ֽ�
	printf("%d\n", sizeof(ar[1])); //1 - �ڶ���Ԫ�صĴ�С
	printf("%d\n", sizeof(&ar)); //4 - &ar������ĵ�ַ,��������ĵ�ַ�Ĵ�СҲ��4���ֽ�
	printf("%d\n", sizeof(&ar + 1)); //4 - &ar+1���������������ĵ�ַ,���ʻ��ǵ�ַ
	printf("%d\n", sizeof(&ar[0] + 1)); //4 - &arr[0]+1��ʾ�ڶ���Ԫ�صĵ�ַ
	printf("\n");

	printf("%d\n", strlen(ar)); //6 - �ӵ�һ��Ԫ�صĵ�ַ��ʼ����,����\0��ֹ
	printf("%d\n", strlen(ar + 0)); //����һ��ԭ��һ��
	//printf("%d\n", strlen(*ar)); //�Ƿ�
	//printf("%d\n", strlen(ar[1])); //�Ƿ�
	printf("%d\n", strlen(&ar)); //6 - ����ĵ�ַ - ����ָ��
	printf("%d\n", strlen(&ar + 1)); //���ֵ - &ar+1��������������,������\0��λ���ֲ�ȷ����
	printf("%d\n", strlen(&ar[0] + 1)); //5 - �������еĵڶ���Ԫ�صĵ�ַ����
	printf("\n");
	return 0;
}


