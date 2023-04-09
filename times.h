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
	int kalc(time_t get, time_t nado); // Розщет розрива часу в днях між датами
public:
	bool adds_time = false; //Установлені дати платежу ?
	std::string to_str(time_t get); //Перевести час в гарний вигляд
	time_t get(); //Получить час (від користувача)
	void set(char set); //Установка дат платежу
	int pros(int type, time_t get); // Вичислить просрочку платежу
};

