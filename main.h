#pragma once
#include <iostream>
#include <stddef.h> // NULL

typedef struct info {
	int number_bud;			//����� �������
	int number_kv;			//����� ��������
	std::string name;		//������� ��������
	std::string type;		//��� �������
	time_t date;			//���� �������
	float summa;		    //���� �������
	float penya;			//������� ���
	int pros;				//�� ������ ����������

	info* next;
};