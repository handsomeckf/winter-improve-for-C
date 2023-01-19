#include"head.h"

void manu() {
	printf("*********************************\n");
	printf("************contest**************\n");
	printf("******1.add        2.search******\n");
	printf("******3.delete     4.modify******\n");
	printf("******5.show       6.clear*******\n");
	printf("******7.order             *******\n");
}
void Check(total* head) {
	if (head->capacity == 0) {
		head->contest = (list*)calloc(2,sizeof(list) );
		head->capacity = 2;
	/*	for (int i = 0; i < 2; i++) {
			head->contest[i].age = 0;
			*(head->contest[i].address) = { 0 };
			*(head->contest[i].name) = { 0 };
			*(head->contest[i].sex) = { 0 };
			*(head->contest[i].tel) = { 0 };
		}*/
	}
	else if(head->capacity==head->num&&head->capacity!=0)
	{	list *tem = (list*)realloc(head->contest,(head->capacity+3)*sizeof(list));
		for (int i = head->capacity; i < head->capacity+2; i++) {
			head->contest[i].age = 0;
			*(head->contest[i].address) = { 0 };
			*(head->contest[i].name) = { 0 };
			*(head->contest[i].sex) = { 0 };
			*(head->contest[i].tel) = { 0 };
		}
		head->capacity += 3;
	}
}
void Init(total* head) {
	head->capacity = 0; 
	head->num = 0;
	Check(head);
}
void insert(total* head) {
	assert(head);
	Check(head);
		do {
			printf("请输入姓名>");
		} while (scanf("%s", head->contest[head->num].name)==0);
		printf("请输入性别>");
		scanf("%s", head->contest[head->num].sex);
		printf("请输入地址>");
		scanf("%s", head->contest[head->num].address);
		printf("请输入年龄>");
		scanf("%d", &head->contest[head->num].age);
		printf("请输入电话>");
		scanf("%s", head->contest[head->num++].tel);
		return;
	}

void search(total* head) {
	char tem[20] = {0};
	int flag = 0;
	printf("请输入想要搜索的人的名字>");
		scanf("%s", tem);
		for (int i=0; i < head->num; i++) {
			if (strcmp(tem, head->contest[i].name) == 0) {
				printf("找到了，全部信息为：\n");
				printf("%-10s%-5s%-10s%-15s%-10s\n", "名字", "年龄", "性别", "电话", "地址");
				printf("%-10s%-5d%-10s%-15s%-10s\n", head->contest[i].name, head->contest[i].age,
					head->contest[i].sex, head->contest[i].tel, head->contest[i].address);
				flag = 1;
				break;
			}
	}
		if(flag==0)
		printf("没有这个人哟~");
}

void delet(total* head) {
	char tem[20] = { 0 };
	printf("请输入想要删除的人的名字>");
	scanf("%s", tem);
	for (int i = 0; i < head->num; i++) {
		if (strcmp(tem, head->contest[i].name) == 0) {
			for (; i < head->num-1; i++) {
				head->contest[i] = head->contest[i + 1];
			}
			head->num--;
			printf("删除成功\n");
			break;
		}
	}
}
void show(total* head) {
	printf("%-10s%-5s%-10s%-15s%-10s\n", "名字", "年龄", "性别", "电话","地址");
	for (int i = 0; i < head->num; i++) {
		printf("%-10s%-5d%-10s%-15s%-10s\n", head->contest[i].name, head->contest[i].age,
			head->contest[i].sex, head->contest[i].tel, head->contest[i].address);
	}
}

void modify(total* head) {
	char tem[20] = { 0 };
	printf("请输入想要修改的人的名字>");
	scanf("%s", tem);
	for (int i = 0; i < head->num; i++) {
		if (strcmp(tem, head->contest[i].name) == 0) {
			int flag = 0;
			printf("1:修改姓名，2：修改年龄，3：修改地址，4：修改性别，5：修改电话\n");
			while(1){
				flag == 0 ? printf("要修改什么呢？") : printf("还要修改什么呢,输入其他数字推出");
				scanf("%d", &flag);
				switch (flag) {
				case 1:scanf("%s", head->contest[i].name); break;
				case 2:scanf("%d", &head->contest[i].age); break;
				case 3:scanf("%s", head->contest[i].address); break;
				case 4:scanf("%s", head->contest[i].sex); break;
				case 5:scanf("%s", head->contest[i].tel); break;
				default:return; 
				}
		}
	}
}
}
 
void order(total* head) {
	for (int i = 0; i < head->num-1; i++) {
		for (int j = 0; j < head->num-1 - i; j++) {
			if (head->contest[j].age > head->contest[j+1].age) {
				list tem = head->contest[j];
				head->contest[j] = head->contest[j + 1];
				head->contest[j + 1] = tem;
			}
		}
	}
	printf("按照年龄排序完毕\n");

}