#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#include<string.h>
//void swap(char* a, char* b) //交换代码
//{
//	char temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void order(char* rank,int start, int length)//排列函数，参数分别为：需要排列的元素数组，开始放入的位置，元素个数
//{
//	 if (start == length ) {
//		 if ((rank[1] == 'b') + (rank[2] == 'a')==1
//			 && (rank[1] == 'b') + (rank[3] == 'e')==1
//			 && (rank[0] == 'c') +( rank[1] == 'd')==1 
//			 && (rank[4] == 'c') +( rank[2] == 'd')==1
//			 && (rank[3] == 'e')+( rank[0] == 'a')==1
//			 ) //判断逻辑，只要有符合的就打印并且break
//		 {
//			 for (int i = 0; i < 5; i++) {
//				 printf("%d名为%c\n", i + 1, rank[i]);
//			 }
//			 return;
//		 }
//		/* for (int i = 0; i < 5; i++) {
//			 printf("%c", rank[i]);
//		 }
//		 printf("\n");
//		return;*/
//	}
//	for (int i = start; i < length; i++) {		
//		swap(&rank[start], &rank[i]);		//将每个元素放入start位置
//		order(rank, start + 1, length);		//将每个元素一次放入start+1的位置上
//		swap(&rank[start], &rank[i]);		//将元素换回，以便下次循环的排列
//	}
//}
//int main() {
//	char rank[5] = { 'a','b','c','d','e'};
//	order(rank, 0, 5);
//}
//
//void swap(char* a, char* b) //交换代码
//{
//	char temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void order(char* rank, int start, int length)//排列函数，参数分别为：需要排列的元素数组，开始放入的位置，元素个数
//{
//	if (start == length) {
//		if ((rank[0]!='1')+(rank[2]=='1') + (rank[3] == '1') + (rank[3] != '1') == 3) //判断逻辑，只要有符合的就打印并且break
//		{
//			for (int i = 0; i < 4; i++) {
//				if (rank[i] == '1') {
//					printf("%c是凶手", i + 'a');
//				}
//			}
//			exit(0);
//		}
//		/* for (int i = 0; i < 5; i++) {
//			 printf("%c", rank[i]);
//		 }
//		 printf("\n");
//		return;*/
//	}
//	for (int i = start; i < length; i++) {
//		swap(&rank[start], &rank[i]);		//将每个元素放入start位置
//		order(rank, start + 1, length);		//将每个元素一次放入start+1的位置上
//		swap(&rank[start], &rank[i]);		//将元素换回，以便下次循环的排列
//	}
//}
//int main() {
//	char rank[4] = {'1','0','0','0'};
//	order(rank, 0, 4);
//}
//#include <stdio.h>
//int main()
//{
//    int i, j, n = 0;
//    int a[100][100] = { 0 }; 
//    while (n < 1 || n >100)
//    {
//        printf("请输入要打印的杨辉三角行数");
//        scanf("%d", &n);
//    }
//    for (i = 0; i < n; i++)
//        a[i][0] = 1;
//  
//    for (i = 1; i < n; i++)
//        for (j = 1; j <= i; j++)
//            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j <= i; j++)
//            printf("%5d", a[i][j]);
//        printf("\n");
//    }
//    return 0;
//}
//int main() {
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//	}
//}

//int main() {
//	int arr[13] = { 5,5,1,2,3,4,8,1,2,3,4,8,6 };
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0])-1; i++) {
//		for (int j = 0; j < sizeof(arr) / sizeof(arr[0]) - 1 - i; j++) {
//			if (arr[j] > arr[j + 1]) {
//				int tem = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tem;
//			}
//		}
//	}
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i ++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i += 2) {
//		if (arr[i] == arr[i + 1]) {
//			continue;
//		}
//		else {
//			printf("%d ", arr[i]);
//			break;
//		}
//	}
//
//}
char* my_strncat(char* des, const char* source, int num) {
	char* tem = des;
	while (*des != '\0') {
		des++;
	}
	for (int i = 0; i < num; i++) {
		*des++ = *source++;
	}
	*des = '\0';
	return des;
}
char* my_strncpy(char* des, const char* source, int num) {
	char* tem = des;
	for (int i = 0; i < num+1; i++) {
		*des++ = *source++;
	}
	return des;
}
int my_atoi(const char* str) {
	const char* tem = str;
	int count = 0;
	int flag = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (*tem >= '0' && *tem <= '9') {
			count = count * 10 + (*tem-48);
			tem++;
			flag = 1;
		}
		else if(count!=0||flag==1){
			break;
		}
		else {
			tem++;
			continue;
		}
	}
	return count;
}
int main() {
	//char arr[] = "i love you";
	//char arr1[20] = "hello ";
	//my_strncat(arr1, arr, 10);
	//printf("%s", arr1);
	printf("%d", my_atoi("s35771fs0f16"));
}
