#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <math.h>
#include<stdlib.h>
//void swap(char* a, char* b) //��������
//{
//	char temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void order(char* rank,int start, int length)//���к����������ֱ�Ϊ����Ҫ���е�Ԫ�����飬��ʼ�����λ�ã�Ԫ�ظ���
//{
//	 if (start == length ) {
//		 if ((rank[1] == 'b') + (rank[2] == 'a')==1
//			 && (rank[1] == 'b') + (rank[3] == 'e')==1
//			 && (rank[0] == 'c') +( rank[1] == 'd')==1 
//			 && (rank[4] == 'c') +( rank[2] == 'd')==1
//			 && (rank[3] == 'e')+( rank[0] == 'a')==1
//			 ) //�ж��߼���ֻҪ�з��ϵľʹ�ӡ����break
//		 {
//			 for (int i = 0; i < 5; i++) {
//				 printf("%d��Ϊ%c\n", i + 1, rank[i]);
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
//		swap(&rank[start], &rank[i]);		//��ÿ��Ԫ�ط���startλ��
//		order(rank, start + 1, length);		//��ÿ��Ԫ��һ�η���start+1��λ����
//		swap(&rank[start], &rank[i]);		//��Ԫ�ػ��أ��Ա��´�ѭ��������
//	}
//}
//int main() {
//	char rank[5] = { 'a','b','c','d','e'};
//	order(rank, 0, 5);
//}
//
//void swap(char* a, char* b) //��������
//{
//	char temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void order(char* rank, int start, int length)//���к����������ֱ�Ϊ����Ҫ���е�Ԫ�����飬��ʼ�����λ�ã�Ԫ�ظ���
//{
//	if (start == length) {
//		if ((rank[0]!='1')+(rank[2]=='1') + (rank[3] == '1') + (rank[3] != '1') == 3) //�ж��߼���ֻҪ�з��ϵľʹ�ӡ����break
//		{
//			for (int i = 0; i < 4; i++) {
//				if (rank[i] == '1') {
//					printf("%c������", i + 'a');
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
//		swap(&rank[start], &rank[i]);		//��ÿ��Ԫ�ط���startλ��
//		order(rank, start + 1, length);		//��ÿ��Ԫ��һ�η���start+1��λ����
//		swap(&rank[start], &rank[i]);		//��Ԫ�ػ��أ��Ա��´�ѭ��������
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
//        printf("������Ҫ��ӡ�������������");
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
int main() {
	int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);

}

