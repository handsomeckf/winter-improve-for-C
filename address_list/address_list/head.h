#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>
typedef struct list {
	char name[20];
	char sex[5];
	int age;
	char address[50];
	char tel[20];
}list;

typedef struct total {
	list *contest;
	int num;
	int capacity;
}total; 
void manu();

void Init(total* head);

void insert(total* head);

void search(total* head);

void delet(total* head);

void show(total* head);

void modify(total* head);

void order(total* head);