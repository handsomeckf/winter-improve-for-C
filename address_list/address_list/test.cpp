#include"head.h"

int main() {
	total* L = new total;	
	Init(L); L->num = 0;

	int flag = 0;
	while (1) {
		manu();
		scanf("%d", &flag);
		switch (flag) {
		case 1:insert(L); break;
		case 2:search(L); break;
		case 3:delet(L); break;
		case 4:modify(L); break;
		case 5:show(L); break;
		case 6:Init(L); L->num = 0; L->capacity = 0; free(L->contest); L = NULL; break;
		case 7:order(L); break;
		default: break;
		}
	

	}
}