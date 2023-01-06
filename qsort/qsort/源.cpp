#define _CRT_SECURE_NO_WARNING 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student {
	int age;
	char name[15];
}stu;
int cmp_int(const void* e1, const void* e2) {
	return *((int*)e1) - *((int*)e2);
}
int cmp_char(const void* e1, const void* e2) {
	return *((char*)e1) - *((char*)e2);
}
int cmp_stu_by_name(const void* e1, const void* e2) {
	return strcmp( ((stu*)e1)->name, ((stu*)e2)->name );
}
int cmp_stu_by_age(const void* e1, const void* e2) {
	return ((stu *)e1)->age - ((stu*)e2)->age;
}
void swap( void* e1, void* e2, int bits)
{
	char temp = 0;
	for (int i = 0; i < bits; i++) {
		temp = *((char*)e1+i);
		*((char*)e1 +i)= *((char*)e2+i);
		*((char*)e2+i) = temp;
	}
}
void Bubble(void* start, int num, int bits, int (*p)(const void* e1, const void* e2)) {
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (p((char*)start + bits * j, (char*)start + bits * (j + 1)) > 0) {
				swap((char*)start + bits * j, (char*)start + bits * (j + 1),bits);
			}
		}
	}
}
int main() {
	int arr[] = { 1,5,8,1,94,51,63,748,135,12,458,44 };
	char arr2[] = { 'a','d','r','f','g','t','c','s' };
	stu arr3[] = { {18,"chenshuai"},{25,"chenkaifeng"},{23,"ahuaige"} };
	Bubble(arr, 12, 4, cmp_int);
	/*qsort(arr2, sizeof(arr2) / sizeof(arr2[0]), sizeof(arr2[0]), cmp_char);
	*/
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d ", arr[i]);
	}
	//printf("\n");
	//for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
	//	printf("%c ", arr2[i]);
	//}
	//printf("\n");
	//qsort(arr3, sizeof(arr3) / sizeof(arr3[1]), sizeof(arr3[1]), cmp_stu_by_age);
	//for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++) {
	//	printf("%d %s ", arr3[i].age, arr3[i].name);
	//}
	//printf("\n");
	//qsort(arr3, sizeof(arr3) / sizeof(arr3[1]), sizeof(arr3[1]), cmp_stu_by_name);
	//for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++) {
	//	printf("%d %s ", arr3[i].age,arr3[i].name);
	//}

}