#include"head.h"

void manu() {
	printf("*********************************\n");
	printf("************contest**************\n");
	printf("******1.add        2.search******\n");
	printf("******3.delete     4.modify******\n");
	printf("******5.show       6.clear*******\n");
	printf("******7.order             *******\n");
}

void Init(list* head) {
	list* tem = head;
	for (int i = 0; i < 1000; i++) {
		*tem->address = { 0 };
		*tem->name = { 0 };
		*tem->tel = { 0 };
		*tem->sex = { 0 };
		tem->age = 0;
		tem++;
	}
}
void insert(total* head) {
	assert(head);
	if (head->num == 1000) {
		printf("ͨѶ¼����");
		return;
	}
	else {
		do {
			printf("����������>");
		} while (scanf("%s", head->contest[head->num].name)==0);
		printf("�������Ա�>");
		scanf("%s", head->contest[head->num].sex);
		printf("�������ַ>");
		scanf("%s", head->contest[head->num].address);
		printf("����������>");
		scanf("%d", &head->contest[head->num].age);
		printf("������绰>");
		scanf("%s", head->contest[head->num++].tel);
		return;
	}
}

void search(total* head) {
	char tem[20] = {0};
	printf("��������Ҫ�������˵�����>");
		scanf("%s", tem);
		for (int i=0; i < head->num; i++) {
			if (strcmp(tem, head->contest[i].name) == 0) {
				printf("�ҵ��ˣ�ȫ����ϢΪ��\n");
				printf("%-10s%-5s%-10s%-15s%-10s\n", "����", "����", "�Ա�", "�绰", "��ַ");
				printf("%-10s%-5d%-10s%-15s%-10s\n", head->contest[i].name, head->contest[i].age,
					head->contest[i].sex, head->contest[i].tel, head->contest[i].address);
				break;
			}
	}
		printf("û�������Ӵ~");
}

void delet(total* head) {
	char tem[20] = { 0 };
	printf("��������Ҫɾ�����˵�����>");
	scanf("%s", tem);
	for (int i = 0; i < head->num; i++) {
		if (strcmp(tem, head->contest[i].name) == 0) {
			for (; i < head->num-1; i++) {
				head->contest[i] = head->contest[i + 1];
			}
			head->num--;
			printf("ɾ���ɹ�\n");
			break;
		}
	}
}
void show(total* head) {
	printf("%-10s%-5s%-10s%-15s%-10s\n", "����", "����", "�Ա�", "�绰","��ַ");
	for (int i = 0; i < head->num; i++) {
		printf("%-10s%-5d%-10s%-15s%-10s\n", head->contest[i].name, head->contest[i].age,
			head->contest[i].sex, head->contest[i].tel, head->contest[i].address);
	}
}

void modify(total* head) {
	char tem[20] = { 0 };
	printf("��������Ҫ�޸ĵ��˵�����>");
	scanf("%s", tem);
	for (int i = 0; i < head->num; i++) {
		if (strcmp(tem, head->contest[i].name) == 0) {
			int flag = 0;
			printf("1:�޸�������2���޸����䣬3���޸ĵ�ַ��4���޸��Ա�5���޸ĵ绰\n");
			while(1){
				flag == 0 ? printf("Ҫ�޸�ʲô�أ�") : printf("��Ҫ�޸�ʲô��,�������������Ƴ�");
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
	printf("���������������\n");

}