#define _CRT_SECURE_NO_WARNINGS 1
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
//    杨氏矩阵
//int main() {
//	int arr[10][10] = { 0 };
//	int row, col;
//	row = 0; col = 0;
//	scanf("%d %d", &row, &col);
//	for (int i = 0; i < col; i++) {
//		for (int j = 0; j < row; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	int search = 0;
//	printf("请输入你要查找的数字");
//	scanf("%d", &search);
//	int r = row-1;
//	int c = 0;
//	while (1) {
//		if (r == col || col == -1) {
//			printf("没有找到");
//			break;
//		}
//		if (arr[c][r] < search) {
//			c++;
//			continue;
//		}
//		else if (arr[c][r] > search) {
//			r--;
//			continue;
//		}
//		else {
//			printf("找到啦！是第%d行第%d列个", c, r);
//			break;
//		}
//	}
//}

//   字符串左旋&判断
void turnleft(char *s, int num) {
	int x = strlen(s);
	if (x == 0) { return; }
	for (int i = 0; i < num; i++) {
		char temp = s[x - 1];
		for (int j = x-2; j>=0; j--) {
			s[j + 1] = s[j];
		}
		s[0] = temp;
	}
}

bool judge(char* s1, char* s2) {
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	if (l1 != l2) {
		return false;
	}
	else {
		if (strcmp(s1, s2)==0) {
			return true;
		}
		else {
			for (int i = 0; i < l1 - 1; i++) {
				turnleft(s1, 1);
				if (strcmp(s1, s2)==0) {
					return true;
				}
				else {
					continue;
				}
			}
		}
	}
	return false;
}

int main() {
	char s[15] = "chen kai feng";
	char s1[15] = "angchen kai f";
	/*while (1) {
		printf("%s",s);
		turnleft(s, 1);
		Sleep(100);
		system("cls");
	}*/
	if (judge(s, s1)) {
		printf("yes");
	}
	else {
		printf("no");
	}

}