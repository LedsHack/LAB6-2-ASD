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
	
	bool add_time = false; //Добавлено ли дати для платежів 
	float proc_penya = 0; //Процент пені

	void add(info* get); //Додавання готового елементу
	info* input(); //Отримання данних елементу

	void print(); //Виведення (все)
	void print(int get); //Виведення за номером
	void print(info* get); //Виведення за елементом
	void view(); //Перегляд (Книга)

	void paste(int pos, info* get); // Вставка в позицію (Перед)
	void del(int pos); // Видалення елементу за позицією

	int count(); //Отримання к-л елементів (з 1)

	void search(char mode, int num, std::string type, time_t date); //Пошук елемента

	float get_penya(info* get); // Розрахунок пені
};

