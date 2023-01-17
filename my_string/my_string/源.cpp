#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#include<assert.h>
int my_strlen(const char* arr) {
	int i = 0;
	assert(arr);
	while (*arr != '\0') {
		i++;
		arr++;
	}
	return i;
}
int my_strcmp(const char* dest, const char* source) {
	assert(dest && source);
	while (*dest == *source&&*source!='\0'&&*dest!='\0') {
		dest++;
		source++;
	}
	if (*source == '\0' && *dest == '\0') {
		return 0;
	}
	int x = *dest - *source;
	return x;
}
char* my_strcat(char* dest, const char* source) {
	assert(dest && source);
	char* temp = dest;
	while (*dest) {
		dest++;
	};
	while 
		(*dest++ = *source++);
	return temp;
}
char* my_strcpy(char* dest, const char* source) {
	assert(dest && source);
	char* temp = dest;
	while
		(*dest++ = *source++);
	return temp;
}
char* strstr(const char* dest, const char* source) {
	char* d = (char*)dest;
	char* s = (char*)source;
	while (1) {
		while (*dest == *source && *dest != '\0' && *source != '\0') {
			dest++;
			source++;
		}
		if (*source=='\0') {
			return d;
		}
		else if (*dest == '\0')
		{
			return NULL;
		}
		d++;
		source = s;
		dest = d;
 	}
}
void* my_memcpy(void* dest, const void* source,unsigned int count) {
	void* tem = dest;
	for (int i = 0; i < count; i++) {
		*(char*)dest = *(char*)source;
		dest = (char*)dest+1;
		source = (char*)source+1;
	}
	return dest;
}
 void* my_memmove(void* dest,const void* source,unsigned int count) {
	int x = (char*)dest - (char*)source;
	if (x <= 0) {
		for (int i = 0; i < count; i++) {
			*(char*)dest = *(char*)source;
			dest = (char*)dest + 1;
			source = (char*)source + 1;
		}
	}
	else {
		for (int i = 0; i < count; i++) {
			dest = (char*)dest + 1;
			source = (char*)source + 1;
		}
		dest = (char*)dest - 1;
		source = (char*)source - 1;
		for (int i = 0; i < count-1; i++) {
			*(char*)dest = *(char*)source;
        	dest = (char*)dest - 1;
			source = (char*)source - 1;
		}
		*(char*)dest = *(char*)source;
	}
	return dest;
	}
int main() {
	char arr[20] = "wjfdkf";
	/*printf("%d", my_strlen(arr));*/
	//printf("%d\n",my_strcmp("chenkai", "chenka"));
	//printf("%s\n", my_strcat(arr, "ckf"));
	//printf("%s\n", my_strcpy(arr, "ckf"));
	/*printf("%s",strstr(arr, "jfd"));*/
	int arr1[50] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[20] = { 0 };
	//my_memcpy(arr2, arr1, 20);
	void* ret=my_memmove(arr1 + 3, arr1+1, 20);
	for (int i = 0; i < 5; i++) {
		printf("%d", *(int *)ret);
		ret = (int*)ret + 1;
	}
}
