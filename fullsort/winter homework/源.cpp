#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <math.h>
void swap(char* a, char* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}
void order(char* rank,int start, int length) {
	

	 if (start == length ) {
		 if ((rank[1] == 'b') + (rank[2] == 'a')==1
			 && (rank[1] == 'b') + (rank[3] == 'e')==1
			 && (rank[0] == 'c') +( rank[1] == 'd')==1
			 && (rank[4] == 'c') +( rank[2] == 'd')==1
			 && (rank[3] == 'e')+( rank[0] == 'a')==1
			 ) {
			 for (int i = 0; i < 5; i++) {
				 printf("%dÃûÎª%c\n", i + 1, rank[i]);
			 }
			 return;
		 }
		/* for (int i = 0; i < 5; i++) {
			 printf("%c", rank[i]);
		 }
		 printf("\n");
		return;*/
	}
	for (int i = start; i < length; i++) {		
		swap(&rank[start], &rank[i]);
		order(rank, start + 1, length);
		swap(&rank[start], &rank[i]);
	}
}
int main() {
	char rank[5] = { 'a','b','c','d','e'};
	order(rank, 0, 5);
}

