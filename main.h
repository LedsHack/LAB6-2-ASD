#pragma once
#include <iostream>
#include <stddef.h> // NULL

typedef struct info {
	int number_bud;			//Номер будинку
	int number_kv;			//Номер квартири
	std::string name;		//Прізвище власника
	std::string type;		//Тип платежу
	time_t date;			//Дата платежу
	float summa;		    //Сума платежу
	float penya;			//Процент пені
	int pros;				//На скільки просрочено

	info* next;
};