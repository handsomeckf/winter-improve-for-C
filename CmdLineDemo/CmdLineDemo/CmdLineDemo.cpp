//文件名:exp2-1.cpp
#include <stdio.h>
#include <malloc.h>
#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
#define MAXNUM  100
#define OK 0
#define ERROR -1
int flag = 0;//全局变量用于链表查找函数的状态判断
int i = 1;//用于链表查找函数计数
typedef struct {
	string name;
	
}ElemType;
typedef struct {
	ElemType  stu[MAXNUM];
	int length;
}SqList;
typedef struct Lnode{
	ElemType stu;
	Lnode* next;
}Lnode;
typedef struct {
	Lnode  *firststu;
	int length;
}LinkList;
typedef struct Dnode {
	Dnode* pre;
	Dnode* next;
	ElemType data;
}Dnode;
typedef struct Stack {
	ElemType stu[MAXNUM];
	int top;
}ST;
typedef struct SNode {
	SNode* next;
	ElemType data;
}SNode;
typedef struct LStack{
	SNode* head;
	SNode* tail;
}LS;

void text2(SqList* class3stu);
void text3(SqList* class3stu);
void text4(SqList* class3stu);
void test2();
void test();
void text5();
void manu4();
void manu5();
void manu6();
void manu7();
int  InitSqList(SqList* list)//顺序表初始化
{
	int i;
	list->length = 0;
	for (i = 0; i < MAXNUM; i++)
		list->stu[i].name ="";
	return OK;
}
Lnode* Linklist_Find(Lnode*phead,ElemType x) //链表寻找，用于插入函数，找到要插入的节点
{
	int i = 1;
	if (phead == NULL) {
		return NULL;
	}
	else {
		Lnode* cur=phead;
		//cur = phead;
		while (cur) {
			if (cur->stu.name == x.name) {
				return cur;
			}
			else {
				cur = cur->next;
				i++;
			}
		}
			return NULL;
	}
}
Lnode* Linklist_Find2(Lnode* phead, ElemType x) //链表寻找，仅为查找作用为之前寻找函数的修改
{
	if (phead == NULL) {
		return NULL;
	}
	else {
		Lnode* cur = new Lnode;
		cur = phead;
		while (cur) {
			if (cur->stu.name == x.name&&cur->next!=NULL) {
				printf("%d个是\n", i); flag = 1;
				return cur;
			}
			else {
				cur = cur->next;
				i++;
			}
		}
		if (flag == 0) {
			printf("没有找打你所需要的\n");
			return NULL;
			i = 1;
		}
		return NULL;
	}
}
void Delect_Linklist(Lnode** phead) //链表删除
{
	ElemType x;
	printf("请输入想要删除同学的名字");
	cin >> x.name;
	if (*phead == NULL) { return; }
	else if ((*phead)->next == NULL&&(*phead)->stu.name==x.name) {
		free(*phead);
		*phead = NULL;
	}
	else {
		Lnode* cur = *phead;
		Lnode* pre=NULL;
		while (cur->stu.name != x.name&&cur->next!=NULL) {
			pre = cur;
			cur = cur->next;
		}
		if (cur) {
			pre->next = cur->next;
			free(cur);
			return;
		}
		else if (cur == NULL && pre) {
			pre = NULL;
			free(cur);
			return;
		}
		else if (cur == NULL && cur->stu.name != x.name) {
			printf("没有找到呀");
			return;
		}
	}
}
void Linklist_Insert(Lnode** phead, ElemType x) //链表插入
{
	if (*phead == NULL) { return; }
	Lnode* temp8 = *phead;
	ElemType temp9;
	printf("请输入想要插入的位置（学生姓名，插入在此学生之前）");
	cin >> temp9.name;
	temp8 = Linklist_Find(*phead, temp9);
	if (temp8) {
		Lnode* newnode = new Lnode;
		newnode->next = NULL;
		newnode->stu = x;
		Lnode* cur=*phead;
		while (cur->next != temp8) {
			cur = cur->next;
		}
		cur->next = newnode;
		newnode->next = temp8;
	}
}
void Print2(Lnode* phead) //链表打印
{
	Lnode* cur = phead;
	int i = 1;
	while (cur != NULL) {
		printf("%d号是%s\n", i++, cur->stu.name.c_str());
		cur = cur->next;
	}
}
void Input2(Lnode** phead) //链表输入
{
	ifstream s("name.text");
	Lnode* temp= new Lnode;
	int i = 0;
	while (s>>temp->stu.name) { 
		Lnode* newnode = new Lnode;
		newnode->next = NULL;
		if (*phead == NULL) {
			newnode->stu.name= temp->stu.name;
			*phead = newnode;
		}
		else {
			Lnode* tail = *phead;
			while (tail->next != NULL) {
				tail = tail->next;
			}
			newnode->stu.name = temp->stu.name;
			tail->next = newnode;
		}
		
	}
}
void Input3(Lnode** phead) //链表输入
{
	ifstream s("name1.txt");
	Lnode* temp = new Lnode;
	int i = 0;
	while (s >> temp->stu.name) {
		Lnode* newnode = new Lnode;
		newnode->next = NULL;
		if (*phead == NULL) {
			newnode->stu.name = temp->stu.name;
			*phead = newnode;
		}
		else {
			Lnode* tail = *phead;
			while (tail->next != NULL) {
				tail = tail->next;
			}
			newnode->stu.name = temp->stu.name;
			tail->next = newnode;
		}

	}
}
void Input4(Lnode** phead) //链表输入
{
	ifstream s("name2.txt");
	Lnode* temp = new Lnode;
	int i = 0;
	while (s >> temp->stu.name) {
		Lnode* newnode = new Lnode;
		newnode->next = NULL;
		if (*phead == NULL) {
			newnode->stu.name = temp->stu.name;
			*phead = newnode;
		}
		else {
			Lnode* tail = *phead;
			while (tail->next != NULL) {
				tail = tail->next;
			}
			newnode->stu.name = temp->stu.name;
			tail->next = newnode;
		}

	}
}
void Input5(Lnode** phead) //链表输入
{
	ifstream s("name.text");
	Lnode* temp= new Lnode;
	int i = 0;
	while (s>>temp->stu.name) { 
		Lnode* newnode = new Lnode;
		newnode->next = NULL;
		if (*phead == NULL) {
			newnode->stu.name= temp->stu.name;
			*phead = newnode;
		}
		else {
			Lnode* tail = *phead;
			while (tail->next != NULL) {
				tail = tail->next;
			}
			newnode->stu.name = temp->stu.name;
			tail->next = newnode;
		}
		
	}
}
void Input6(LS* stack) //链表输入
{
	ifstream s("name.text");
	SNode* temp = new SNode;
	while (s >> temp->data.name) {
		SNode* newnode = new SNode;
		newnode->next = NULL;
		if (stack->head==NULL&&stack->tail==NULL) {
			newnode->data.name = temp->data.name;
			stack->head = stack->tail = newnode;
		}
		else {
			newnode->data.name = temp->data.name;
			stack->tail->next = newnode;
			stack->tail = newnode;
		}

	}
}
void Input7(LS* stack) //链表输入
{
	ifstream s("name.text");
	SNode* temp = new SNode;
	while (s >> temp->data.name) {
		SNode* newnode = new SNode;
		newnode->next = NULL;
		if (stack->head == NULL && stack->tail == NULL) {
			newnode->data.name = temp->data.name;
			stack->head = stack->tail = newnode;
		}
		else {
			newnode->data.name = temp->data.name;
			stack->tail->next = newnode;
			newnode->next = stack->head;
			stack->tail = newnode;
		}

	}
}
void LSPush(LS* stack) {
	
	printf("请输入要插入的名字(按q结束输入)\n");
	while (1) {
		SNode* newnode = new SNode;
		newnode->next = NULL;
		std::cin >> newnode->data.name;
		if (newnode->data.name == "q") { break; }
		stack->tail->next = newnode;
		stack->tail = newnode;
	}
}
void LSPush2(LS* stack) {

	printf("请输入要插入的名字(按q结束输入)\n");
	while (1) {
		SNode* newnode = new SNode;
		newnode->next = stack->head;
		std::cin >> newnode->data.name;
		if (newnode->data.name == "q") { break; }
		stack->tail->next = newnode;
		stack->tail = newnode;
	}
}
void LSPop(LS* stack) {
	SNode* cur=stack->head;
	while (cur->next != stack->tail) {
		cur = cur->next;
	}
	free(stack->tail);
	stack->tail = cur;
}
void LSPoprint(LS* stack, int x) {
	while (x--) {
		printf("%s\n", stack->tail->data.name.c_str());
		LSPop(stack);
	}
}
void LSPrint(LS* stack) {
	
	SNode* mem = stack->tail;
	while (1) {
		SNode* cur = stack->head;
		printf("%s\n", stack->tail->data.name.c_str());
		while (cur->next != stack->tail) {
			cur = cur->next;
		}
		stack->tail = cur;
		if (stack->tail == stack->head) { break; }
	}
	printf("%s\n", stack->head->data.name.c_str());
	stack->tail = mem;
}
void QueuePush(LS* stack) {
	printf("输入想要插入的名字，按q结束");
	while (1) {
		SNode* newnode = new SNode;
		newnode->next = NULL;
		std::cin >> newnode->data.name;
		if (newnode->data.name == "q") {
			break;
		}
		stack->tail->next = newnode;	
		stack->tail = newnode;
	}
}
void QueuePop(LS* stack, int x) {
	while (x--) {
		printf("%s\n\n", stack->head->data.name.c_str());
		stack->head = stack->head->next;
	}
}
void QueuePop2(LS* stack, int x) {
	while (x--) {
		printf("%s\n\n", stack->head->data.name.c_str());
		stack->head = stack->head->next;
		stack->tail->next = stack->head;
	}
}
void QueuePrint(LS* stack) {
	SNode* cur = stack->head;
	 do{
		printf("%s\n", cur->data.name.c_str());
		cur = cur->next;
	 } while (cur != stack->tail->next);
}
void QueuePrint2(LS* stack) {
	SNode* cur = stack->head;
	 do{
		printf("%s\n", cur->data.name.c_str());
		cur = cur->next;
	 } while (cur != stack->head);
}
void DnodeInit(Dnode** phead) {
	*phead = new Dnode;
	(*phead)->next = (*phead)->pre = NULL;
}
void InputD(Dnode** phead) //双链表输入
{
	ifstream s("name.text");
	Dnode* temp = new Dnode;
	while (s >> temp->data.name) {
		Dnode* newnode = new Dnode;
		newnode->next = NULL;
		newnode->pre = NULL;
		if ((*phead) == NULL) {
			newnode->data.name = temp->data.name;
			*phead = newnode;
		}
		else {
			Dnode* tail = *phead;
			while (tail->next != NULL) {
				tail = tail->next;
			}
			newnode->data.name = temp->data.name;
			tail->next = newnode;
			newnode->pre = tail;
		}

	}
}
void InputD2(Dnode** phead) {
	ifstream s("name.text");
	Dnode* temp = new Dnode;
	while (s >> temp->data.name) {
		Dnode* newnode = new Dnode;
		newnode->next = NULL;
		newnode->pre = NULL;
		if ((*phead) == NULL) {
			newnode->data.name = temp->data.name;
			newnode->next = newnode;
			newnode->pre = newnode;
			*phead = newnode;
		}
		else {
			Dnode* tail = *phead;
			while (tail->next != *phead) {
				tail = tail->next;
			}
			newnode->data.name = temp->data.name;
			tail->next = newnode;
			newnode->pre = tail;
			newnode->next = *phead;
			(*phead)->pre = newnode;
		}

	}
}
void InputStack(ST* stack) {
	ifstream s("name.text");
	int i = 0;
	while (s >> stack->stu[i++].name) {
	};
	stack->top = i-1;
}
void PopStack(ST* stack) {
	(stack)->top--;	
}
ElemType StackTop(ST* stack) {
	return stack->stu[stack->top - 1];
}
void PrintStack2(ST* stack,int x) {
	while (stack->top > 0&&x>0)
	{
		printf("%s\n", stack->stu[stack->top - 1].name.c_str());
		PopStack(stack);
		x--;
	}
}
void PrintStack(ST* stack) {
	int x = stack->top;
		while (stack->top > 0)
	{	
		printf("%s\n", stack->stu[stack->top - 1].name.c_str());
		PopStack(stack);
	}	
		stack->top = x;
}
void PushStack(ST* stack,ElemType x) {
	stack->stu[stack->top].name = x.name;
	stack->top++;
}
void PushS(ST* stack) //顺序表栈入栈
{
	ElemType temp;
	printf("please type the name and q to leave\n");
	while (1) {
	std::cin >> temp.name;
	if (temp.name == "q") { break; }
	PushStack(stack, temp);
	}
}
void PrintD(Dnode* phead) {
	Dnode* cur = phead;
	while (cur) {
		printf("%s\n", cur->data.name.c_str());
		cur = cur->next;
	}

}
void PrintD2(Dnode* phead) {
	Dnode* cur = phead;
	int flag = 1;
	while (cur->next!=phead) {
		printf("%s\n", cur->data.name.c_str());
		cur = cur->next;
		
	}
}
void _text1(Lnode**phead) //插入函数
{
	ElemType temp10;
			printf("请输入想要插入的学生名字\n");
			cin >> temp10.name;
			Linklist_Insert(phead, temp10);

}
void _text2(Lnode**phead)//查询函数
{
	ElemType temp7;
	printf("请输入想要查询的学生名字\n");
	cin >> temp7.name;
	Lnode* tempNode;//找到所查询学生名字的第一个位置
	tempNode = Linklist_Find2(*phead, temp7);
	while (tempNode) //运用循环寻找之后是否还有此名字
	{
		tempNode = Linklist_Find2(tempNode->next, temp7);
	}
}
void _text3(Lnode** phead) //插入函数
{
	Delect_Linklist(phead);
	return;
}
void Print(SqList* class3stu) //顺序表打印
{
	for (int i = 0; i < class3stu->length - 1; i++) {
		printf("%d号是%s\n", i + 1, class3stu->stu[i].name.c_str());
	}
}
int InsertSqList(SqList* list, int pos, ElemType ele)//顺序表插入
{
	int  i, j;
	if (pos == 0 && (list->length == 0))
	{
		list->stu[pos] = ele;
		list->length++;
		return OK;
	}
	if (pos<0 || pos>list->length || (list->length == MAXNUM))
		return ERROR;
	if (pos == list->length) {
		list->stu[pos] = ele;
		list->length++;
	}
	else {
		for (i = list->length - 1; i >= pos; i--)
		{
			list->stu[i + 1] = list->stu[i];

		}
		list->stu[pos] = ele; list->length++;
	}
	return OK;
}
void Input(SqList* list) //顺序表从文件中读取
{
	ifstream s("name.text");
	int i = 0;
	while (s >> list->stu[i++].name) {
	};
	list->length = i;
}
void text1(SqList* class3stu) //顺序表文件中读取并打印
{
	InitSqList(class3stu);
	Input(class3stu);
	Print(class3stu);
}
void text2(SqList* class3stu) //顺序表插入函数
{
	int pos = 0;
	printf("请输入想要插入的位置");
	std::cin >> pos;
	ElemType temp3;
	printf("请输入想要插入的人名");
	std::cin >> temp3.name;
	InsertSqList(class3stu, pos - 1, temp3);
	printf("插入成功\n");
}
void text3(SqList* class3stu) //顺序表查找函数
{
	int i = 0; string temp4;
	printf("请输入想要查找同学的拼音");
	std::cin >> temp4;
	for (; i <= class3stu->length - 1; i++) {
		if (temp4 == class3stu->stu[i].name) {
			printf("第%d个是这位学生\n", i + 1);
			return;
		}
	}
	printf("没有找到这位同学(T T)\n");
}
void text4(SqList* class3stu) //顺序表删除函数
{
	int pos = 0;
	printf("请输入想要删除同学的序号");
	std::cin >> pos;
	for (int i = pos - 1; i < class3stu->length; i++) {
		class3stu->stu[i] = class3stu->stu[i + 1];
	}
	class3stu->length--;
	printf("删除成功\n");
}
void BubbleSortLinkList(Lnode** phead)											//二重指针用于改变远指针的指向
{
	Lnode* temp = *phead;
	int length = 1;
	while (temp) {
		temp = temp->next; length++;
	}																			//计算出函数长度用于后续冒泡排序
	for (int i = 0; i < length; i++)											//外层循环，还需在之前加一个处理小于三四个元素的处理更好 
	{
		Lnode* cur = *phead;
		Lnode* next = (*phead)->next;
		Lnode* etr = next->next;
		Lnode* pre = cur;														//以上四个指针用于排序
		for (int j = 1; j < length - i; j++)									//内层循环
		{
			if (cur == pre)														
			{
				if (cur->stu.name >= next->stu.name) {
					next->next = cur;											//改变链表结构
					cur->next = etr;
					*phead = next;												
					pre = next;													//改变四个指针的指向，使四个指针都下沉
					next = etr;
					etr = etr->next;
				}
				else {
					pre = cur;													//不改变结构直接下沉
					cur = next;
					next = etr;
					etr = etr->next;
				}
			}
			else {
				if ((cur->stu.name >= next->stu.name)&&etr) {
					next->next = cur;
					cur->next = etr;
					pre->next = next;											//改变链表
																				//下沉
					pre = next;
					next = etr;
					etr = etr->next;
				}
				if ((cur->stu.name <= next->stu.name) && etr) {
					pre = cur;
					cur = next;
					next = etr;
					etr = etr->next;

				}
				if (etr == NULL) {
					if (cur->stu.name >= next->stu.name) {
						pre->next = next;										//尾部处理
						next->next = cur;
						cur->next = NULL;
					}
				}

			}
		}
	}
}
Lnode*mergeTwoLists(Lnode* l1,Lnode* l2)									//改变原有排序的合并
 {
	Lnode* cur = l1;
	 Lnode* cur1 = l2;
	 Lnode* head = NULL;
	 Lnode* tail = NULL;
	while (cur && cur1) {
		if (head == NULL)													//应对首次进入需改变头指针的情况
		{
			if (cur->stu.name >= cur1->stu.name) {							
				if (cur->stu.name == cur1->stu.name)						//等于的时候将两个指针一同下沉用于排重
				{
					head = cur1; cur1 = cur1->next;						
					cur = cur->next;
				}
				else { head = cur1;  cur1 = cur1->next; }
			}
			else {
				head = cur; cur = cur->next;
			}
			tail = head;
		}
		else {
			if (cur->stu.name >= cur1->stu.name) {
				if (cur->stu.name == cur1->stu.name)							//应对排重
				{
					if (tail->next == cur1) 
					{ cur = cur->next; }
					else 
					{ cur1 = cur1->next; }
				}
				else {
					tail->next = cur1;											//无需排重直接下沉
					tail = tail->next;
					cur1 = cur1->next;
				}
			}
			else {
				tail->next = cur;
				tail = tail->next;
				cur = cur->next;
			}
		}
	}
	if (head == NULL && l1 == NULL) {
		return l2;
	}
	if (head == NULL && l2 == NULL) {
		return l1;
	}
	if (cur == NULL)														//合并后链表剩余则直接接入
	{
		tail->next = cur1;
	}
	else {
		tail->next = cur;													//同上，合并后直接接入
	}
	return head;
}
void mergeTwoLists2(Lnode* l1, Lnode* l2, Lnode** l3)					//新建链合并
{
	//Lnode* head = *l3;
	Lnode* cur1 = l1;
	Lnode* cur2 = l2;
	while (cur1 && cur2) {
		Lnode* temp1 = new Lnode;										//暂放，防止原链表被损坏
		Lnode* temp2 = new Lnode;
		temp1 = cur1;
		temp2 = cur2;
		if (*l3 == NULL) {												//改变头指针
			Lnode* newnode = new Lnode;									//创建新链表
			newnode->next = NULL;
			if (cur1->stu.name >= cur2->stu.name) {
				if (cur1->stu.name == cur2->stu.name)					//相同时，同时下称用于排重 
				{
					newnode->stu.name = cur1->stu.name;
					cur2 = cur2->next;
					cur1 = cur1->next;
					*l3 = newnode;
				}
				else {
					newnode->stu.name = cur2->stu.name;
					cur2 = cur2->next;
					*l3 = newnode;
				}
			}
			else {
				newnode->stu.name = cur1->stu.name;
				cur1 = cur1->next;
				*l3 = newnode;
			}
		}
		else {
			Lnode* newnode = new Lnode;
			newnode->next = NULL;
			Lnode* tail = *l3;									//此时已经不为头部插入，直接尾插即可
			while (tail->next) {
				tail = tail->next;
			}													//找尾
			if (cur1->stu.name >= cur2->stu.name) {
				if (cur1->stu.name == cur2->stu.name)			//排重 
				{
					newnode->stu.name = cur1->stu.name;
					cur2 = cur2->next;
					cur1 = cur1->next;
					tail->next = newnode;
				}
				else {
					newnode->stu.name = cur2->stu.name;
					cur2 = cur2->next;
					tail->next = newnode;
				}
			}
			else {
				newnode->stu.name = cur1->stu.name;
				cur1 = cur1->next;
				tail->next = newnode;
			}
		}
	}
	if (cur1 == NULL)								//有链表剩余时直接尾插
	{
		while (cur2) {
			Lnode* newnode = new Lnode;
			Lnode* tail = *l3;
			newnode->next = NULL;
			while (tail->next) {
				tail = tail->next;
			}
			newnode->stu.name = cur2->stu.name;
			cur2 = cur2->next;
			tail->next = newnode;
		}
	}
	else {
		while (cur1) {									//同上
			Lnode* newnode = new Lnode;
			Lnode* tail = *l3;
			newnode->next = NULL;
			while (tail->next) {
				tail = tail->next;
			}
			newnode->stu.name = cur1->stu.name;
			cur1 = cur1->next;
			tail->next = newnode;
		}
	}
}
void cutsame(Lnode* phead){
	Lnode* cur = phead;
	Lnode* next = cur->next;
	while (cur&&next) {
		if (cur->stu.name == next->stu.name) {
			cur->next = next->next;
			next->next = NULL;
			cur = cur->next;
			next = cur->next;
		}
		cur = next;
		next = next->next;
	}
}
void manu()//顺序表界面
{
	SqList* class3stu;
	class3stu = new SqList;
	char temp;
	temp = '0';
	while (1)
	{
		if (temp == '0' || temp == '1' || temp == '2' || temp == '3' || temp == '4'||temp=='5')
		{
		printf("---------Menu is as following--------\n");
		printf(" press 1 return to input name from name.txt\n");
		printf(" press 2 return to insert name\n");
		printf(" press 3 return to lookup name \n");
		printf(" press 4 return to print all name \n");
		printf(" press 5 return to delete name\n");
		printf("press q to quit\n");
		}

		temp = getchar();//从键盘上输入一个数字后回车，getchar会返回两次，一次是数字，一次是'\n',所以要做上面的处理。
	
		switch (temp)
		{
		case '1':	text1(class3stu); printf("以上为打印名单\n"); 
			// add your code 
			break;
		case '2':text2(class3stu);
			break;
		case '3':text3(class3stu);
			// add your code 
			break;
		case '4':Print(class3stu);
			// add your code
			break;
		case '5':text4(class3stu); 
			break;
		case 'q':
			return;
		default:
			break;
		}

	}

	return;
}
void manu2() //链表界面
{
	LinkList* phead = new LinkList;
	phead->firststu = NULL;
	char temp;
	temp = '0';
	while (1)
	{
		if (temp == '0' || temp == '1' || temp == '2' || temp == '3' || temp == '4'||temp=='5'||temp=='6'||temp=='7' || temp == '8')
		{
		printf("---------Menu is as following--------\n");
		printf(" press 1 to input name from name.txt\n");
		printf(" press 2 to insert name\n");
		printf(" press 3 to lookup name \n");
		printf(" press 4 to print all name \n");
		printf(" press 5 to delete name\n");
		printf(" press 6 to merge two Linklist by mod1\n");
		printf(" press 7 to merge two Linklist by mod2\n");
		printf(" press 8 to cut the same names\n");
		printf("*****操作合并的两个名单为name1和name2，可在文档中编辑*****\n");
		printf("press q to quit\n");
		}

		temp = getchar();//从键盘上输入一个数字后回车，getchar会返回两次，一次是数字，一次是'\n',所以要做上面的处理。
	
		switch (temp)
		{
		case '1':	Input2(&(phead)->firststu); Print2(phead->firststu); printf("以上为打印名单\n");
			// add your code 
			break;
		case '2':
			_text1(&phead->firststu);
			break;
		case '3':i = 1; _text2(&phead->firststu);
			// add your code 
			break;
		case '4':Print2(phead->firststu);
			// add your code
			break;
		case '5':Delect_Linklist(&phead->firststu);
			break;
		case '6':test();
			break;
		case '7':test2();
			break;
		case'8':text5();
		case 'q':
			return;
		default:
			break;
		}

	}
	return;
}
void manu3() //主界面函数
{
	char temp;
	temp = '0';
	while (1)
	{
		if (temp == '0' || temp == '1' || temp == '2' || temp == '3' || temp == '4' || temp == '5' || temp == '6')
		{
			printf("---------Menu is as following--------\n");
			printf(" press 1 to use mode Linklist\n");
			printf(" press 2 to use mode Sqlist\n");
			printf(" press 3 to use mode Stack with sequlist\n");
			printf(" press 4 to use mode Stack with linklist\n");
			printf(" press 5 to use mode Queue with linklist\n");
			printf(" press 6 to use mode Queue with circulate\n");
			printf("press q to quit\n");
		}

		temp = getchar();//从键盘上输入一个数字后回车，getchar会返回两次，一次是数字，一次是'\n',所以要做上面的处理。

		switch (temp)
		{
		case '1':	manu2();
			break;
		case '2':
			manu();
			break;
		case'3':
			manu4();
			break;
		case'4':manu5();
			break;
		case'5':manu6();
			break;
		case'6':manu7();
			break;
		case'q':
			return;
		default:
			break;
		}
	}
}
void manu4() //栈界面函数
{
	char temp;
	int num = 0;
	ST *stu=new ST;
	temp = '0';
	while (1)
	{
		if (temp == '0' || temp == '1' || temp == '2'||temp=='3'||temp=='4')
		{
			printf("---------Menu is as following--------\n");
			printf(" press 1 to input name from text\n");
			printf(" press 2 to push\n");
			printf("press 3 to pop\n");
			printf("press 4 to print\n");
			printf("press q to quite\n");
		}

		temp = getchar();//从键盘上输入一个数字后回车，getchar会返回两次，一次是数字，一次是'\n',所以要做上面的处理。

		switch (temp)
		{
		case '1':	InputStack(stu); printf("input sucessfully\n");
			break;
		case '2':
			PushS(stu); printf("push sucessfully\n");
			break;
		case '3':
			printf("how much you want to pop?\n");
			scanf("%d", &num);
			PrintStack2(stu, num);
			break;
		case '4':
			PrintStack(stu);
			break;
		case'q':
			return;
		default:
			break;
		}
	}
}
void manu5() //栈界面函数
{
	char temp;
	LS LStack;
	int num = 0;
	LStack.head = LStack.tail = NULL;
	temp = '0';
	while (1)
	{
		if (temp == '0' || temp == '1' || temp == '2' || temp == '3' || temp == '4')
		{
			printf("---------Menu is as following--------\n");
			printf(" press 1 to input name from text\n");
			printf(" press 2 to push\n");
			printf("press 3 to pop\n");
			printf("press 4 to print\n");
			printf("press q to quite\n");
		}

		temp = getchar();//从键盘上输入一个数字后回车，getchar会返回两次，一次是数字，一次是'\n',所以要做上面的处理。

		switch (temp)
		{
		case '1':Input6(&LStack);	 printf("input sucessfully\n");
			break;
		case '2':
			LSPush(&LStack); printf("push sucessfully\n");
			break;
		case '3':
			printf("how much you want to pop?\n");
			scanf("%d", &num);
			LSPoprint(&LStack, num);
			break;
		case '4':
			LSPrint(&LStack);
			break;
		case'q':
			return;
		default:
			break;
		}
	}
}
void manu6() //队列界面函数
{
	char temp;
	LS LStack;
	int num = 0;
	LStack.head = LStack.tail = NULL;
	temp = '0';
	while (1)
	{
		if (temp == '0' || temp == '1' || temp == '2' || temp == '3' || temp == '4')
		{
			printf("---------Menu is as following--------\n");
			printf(" press 1 to input name from text\n");
			printf(" press 2 to push\n");
			printf("press 3 to pop\n");
			printf("press 4 to print\n");
			printf("press q to quite\n");
		}

		temp = getchar();//从键盘上输入一个数字后回车，getchar会返回两次，一次是数字，一次是'\n',所以要做上面的处理。

		switch (temp)
		{
		case '1':Input6(&LStack);	 printf("input sucessfully\n");
			break;
		case '2':
			QueuePush(&LStack); printf("push sucessfully\n");
			break;
		case '3':
			printf("how much you want to pop?\n");
			scanf("%d", &num);
			QueuePop2(&LStack, num);
			break;
		case '4':
			QueuePrint(&LStack);
			break;
		case'q':
			return;
		default:
			break;
		}
	}
}
void manu7() //队列界面函数
{
	char temp;
	LS LStack;
	int num = 0;
	LStack.head = LStack.tail = NULL;
	temp = '0';
	while (1)
	{
		if (temp == '0' || temp == '1' || temp == '2' || temp == '3' || temp == '4')
		{
			printf("---------Menu is as following--------\n");
			printf(" press 1 to input name from text\n");
			printf(" press 2 to push\n");
			printf("press 3 to pop\n");
			printf("press 4 to print\n");
			printf("press q to quite\n");
		}

		temp = getchar();//从键盘上输入一个数字后回车，getchar会返回两次，一次是数字，一次是'\n',所以要做上面的处理。

		switch (temp)
		{
		case '1':Input7(&LStack);	 printf("input sucessfully\n");
			break;
		case '2':
			LSPush2(&LStack); printf("push sucessfully\n");
			break;
		case '3':
			printf("how much you want to pop?\n");
			scanf("%d", &num);
			QueuePop2(&LStack, num);
			break;
		case '4':
			QueuePrint2(&LStack);
			break;
		case'q':
			return;
		default:
			break;
		}
	}
}
void test() {
	LinkList* phead1 = new LinkList;
	phead1->firststu = NULL;
	LinkList* phead4 = new LinkList;
	phead4->firststu = NULL;
	LinkList* phead2 = new LinkList;
	phead2->firststu = NULL;
	Lnode* phead3 = NULL;
	Input3(&(phead1)->firststu); Print2(phead1->firststu); printf("以上为第一组输入的名单\n\n");
	Input4(&(phead2)->firststu); Print2(phead2->firststu); printf("以上为第二组输入的名单\n\n");
	BubbleSortLinkList(&(phead1)->firststu); Print2(phead1->firststu); printf("以上为排序后的第一组名单\n\n");
	BubbleSortLinkList(&(phead2)->firststu); Print2(phead2->firststu); printf("以上为排序后的第二组名单\n\n");
	cutsame(phead1->firststu); Print2(phead1->firststu); printf("以上为排重后的第二组名单\n\n");
	cutsame(phead2->firststu); Print2(phead2->firststu); printf("以上为排重后的第二组名单\n\n");
	//phead3 = mergeTwoLists(phead1->firststu, phead2->firststu);
	mergeTwoLists2(phead1->firststu, phead2->firststu, &(phead4)->firststu);
	Print2(phead4->firststu); printf("以上为合并后的名单\n\n");
	return;
}
void test2() {
	LinkList* phead1 = new LinkList;
	phead1->firststu = NULL;
	LinkList* phead2 = new LinkList;
	phead2->firststu = NULL;
	Lnode* phead3 = NULL;
	Input3(&(phead1)->firststu); Print2(phead1->firststu); printf("以上为第一组输入的名单\n\n");
	Input4(&(phead2)->firststu); Print2(phead2->firststu); printf("以上为第二组输入的名单\n\n");
	BubbleSortLinkList(&(phead1)->firststu); Print2(phead1->firststu); printf("以上为排序后的第一组名单\n\n");
	BubbleSortLinkList(&(phead2)->firststu); Print2(phead2->firststu); printf("以上为排序后的第二组名单\n\n");
	cutsame(phead1->firststu);Print2(phead1->firststu); printf("以上为排重后的第一组名单\n\n");
	cutsame(phead2->firststu); Print2(phead2->firststu); printf("以上为排重后的第二组名单\n\n");
	phead3 = mergeTwoLists(phead1->firststu, phead2->firststu);
	//mergeTwoLists2(phead1->firststu, phead2->firststu, &(phead4)->firststu);
	Print2(phead3); printf("以上为合并后的名单\n\n");
	return;
}
void text3() {
	Dnode* stu=NULL;
	//DnodeInit(&stu);
	InputD2(&stu);
	PrintD2(stu);
}
void text4() {
	ST *stu=new ST;
	InputStack(stu);
	PrintStack(stu);
	int num = 0;
	scanf("%d", &num);
	PrintStack2(stu, num);
	PushS(stu);
	PrintStack(stu);
}
void text5() {
	printf("we take the file 'name.text' for example\n press any key to continue\n ");
	getchar();
	getchar();
	LinkList* phead1 = new LinkList;
	phead1->firststu = NULL;
	Input3(&(phead1)->firststu); Print2(phead1->firststu); printf("以上为输入的名单\n\n");
	BubbleSortLinkList(&(phead1)->firststu); Print2(phead1->firststu); printf("以上为排序后的名单\n\n");
	cutsame(phead1->firststu); Print2(phead1->firststu); printf("以上为排重后的第一组名单\n\n");
}
void text6() {
	LS LStack;
	LStack.head = LStack.tail = NULL;
	Input6(&LStack);
	QueuePush(&LStack);
	QueuePop(&LStack,3);
	QueuePrint(&LStack);
}
int main() {
	
	manu3();
}