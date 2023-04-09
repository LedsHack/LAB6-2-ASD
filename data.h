#pragma once
#include "main.h"
#include "times.h"
extern struct info;

class data
{
public:
	info* current;
	info* head = NULL;

	times obj_time;
	
	bool add_time = false; //��������� �� ���� ��� ������� 
	float proc_penya = 0; //������� ���

	void add(info* get); //��������� �������� ��������
	info* input(); //��������� ������ ��������

	void print(); //��������� (���)
	void print(int get); //��������� �� �������
	void print(info* get); //��������� �� ���������
	void view(); //�������� (�����)

	void paste(int pos, info* get); // ������� � ������� (�����)
	void del(int pos); // ��������� �������� �� ��������

	int count(); //��������� �-� �������� (� 1)

	void search(char mode, int num, std::string type, time_t date); //����� ��������

	float get_penya(info* get); // ���������� ���
};

