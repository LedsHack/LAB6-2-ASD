#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#pragma warning(disable : 4996)
#pragma once

class times
{
private:
	time_t kvart;
	time_t gaz;
	time_t voda;
	time_t elect;
	int kalc(time_t get, time_t nado); // ������ ������� ���� � ���� �� ������
public:
	bool adds_time = false; //���������� ���� ������� ?
	std::string to_str(time_t get); //��������� ��� � ������ ������
	time_t get(); //�������� ��� (�� �����������)
	void set(char set); //��������� ��� �������
	int pros(int type, time_t get); // ��������� ��������� �������
};

