#include "data.h"
#include "iomanip"

void data::add(info* get) {
	current = new info;
	current->number_bud = get->number_bud;
	current->number_kv = get->number_kv;
	current->name = get->name;
	current->type = get->type;
	current->date = get->date;
	current->summa = get->summa;
	current->penya = get->penya;
	current->pros = get->pros;

	current->next = head;
	head = current;
	delete get;
}
info* data::input() {
	int type;
	int date_type;
	info *r = new info;
	std::cout << "Номер будинку: "; std::cin >> r->number_bud;
	std::cout << "Номер квартири: "; std::cin >> r->number_kv;
	std::cout << "Прізвище власника: "; std::cin >> r->name;
	/* тип платежу */
	do {
		std::cout << "1 - Квартплата" << std::endl;
		std::cout << "2 - Газ" << std::endl;
		std::cout << "3 - Вода" << std::endl;
		std::cout << "4 - Електроенергія" << std::endl;
		std::cout << "Тип платежу: "; std::cin >> type;
		switch (type) {
		case 1:
			r->type = "Квартплата";
			break;
		case 2:
			r->type = "Газ";
			break;
		case 3:
			r->type = "Вода";
			break;
		case 4:
			r->type = "Електроенергія";
			break;
		}

	} while (!(type >= 1 and type <= 4));
	/* Дата платежу */
	do {
		std::cout << "1 - Установить поточну" << std::endl;
		std::cout << "2 - Встановити свою" << std::endl;
		std::cout << "Дата платежу: "; std::cin >> date_type;
		switch (date_type) {
		case 1:
			r->date = time(0); //Поточна дата
			break;
		case 2:
			r->date = obj_time.get();
			break;
		}
	} while (!(date_type == 1 or date_type == 2));

	std::cout << "Сума: "; std::cin >> r->summa;
	
	r->pros = obj_time.pros(type, r->date);
	r->penya = get_penya(r) * r->pros; 
	return(r);
}
void data::print() {
	if (head != NULL) {
		do {
			print(current); // Виведення за елементом!
			current = current->next;
		} while (current != NULL);
		current = head;
	}
}
void data::print(info *get) {
	std::cout << std::endl;
	if (get != NULL) {	
		std::cout << "Номер будинку: " << get->number_bud << std::endl;
		std::cout << "Номер квартири: " << get->number_kv << std::endl;
		std::cout << "Прізвище власника: " << get->name << std::endl;
		std::cout << "Тип платежу: " << get->type << std::endl;
		std::cout << "Дата платежу: " << obj_time.to_str(get->date);
		std::cout << "Сума платежу: " << get->summa << " грн." << std::endl;
		std::cout << "Пеня: " << get->penya << " грн." << std::endl;
		std::cout << "Пророчка: " << get->pros << " дн." << std::endl;
	}
	else {
		std::cout << "Переданий на показ елемент пустий! " << std::endl;
	}
}
void data::print(int get) {
	if (head != NULL) {
		for (int i = 1; i < get; i++) {
			current = current->next;
		}
		print(current); //Виведення елементу
		current = head;
	}
}

int data::count() {
	int c = 0;
	if (head != NULL) {
		do {
			c++;
			current = current->next;
		} while (current != NULL);
		current = head;
	}
	return(c);
}
void data::view() {
	int str_m = count(); // Макс стр
	int str_c = 1; //Текущая
	int selector;
	if (str_m != 0) {
		do {

			system("cls");
			print(str_c);
			std::cout << std::endl << std::endl;

			std::cout << std::setw(10) << "1 - След. |" << std::setw(10) << "2 - Пред. | " << std::setw(10) << "3 - Вхід |" << std::endl;
			std::cout << "-> "; std::cin >> selector;
			switch (selector) {
			case 1:
				if (str_c == str_m) {
					str_c = 1;
				}
				else str_c++;
				break;
			case 2:
				if (str_c - 1 == 0) {
					str_c = str_m;
				}
				else str_c--;
				break;
			}
		} while (selector != 3);
	}
}
/*(mode)
* 'n' - Номер будинку (num)
* 't' - За типом платежу (type [str])
* 'd' - Датою платежу (time_t)
*/

void data::search(char mode, int num, std::string type, time_t date) {
	int counter = 0;
	system("cls");
	std::cout << "Пошук за ";
	switch (mode) { // Декод
	case 'n':
		std::cout << "(Номером будинку): " << num << std::endl;
		break;
	case 't':
		std::cout << "(Типом платежу): " << type << std::endl;
		break;
	case 'd':
		std::cout << "(Датою платежу)" << std::endl;
		break;
	}
	//bool checker = false;
	if (head != NULL) {
		current = head;
		do {
			counter++;
			switch (mode) {
			case 'n':
				if (current->number_bud == num) {
					std::cout << std::endl << std::endl << "Номер в списку: [" << counter << "]" << std::endl;
					print(current);
				}
				break;
			case 't':
				if (current->type == type) {
					std::cout << std::endl << std::endl << "Номер в списку: [" << counter << "]" << std::endl;
					print(current);
				}
				break;
			case 'd':
				if (current->date >= date) {
					std::cout << std::endl << std::endl << "Номер в списку: [" << counter << "]" << std::endl;
					print(current);
				}
				break;
			}
			current = current->next;
			//checker = false;
		} while (current != NULL);
		current = head;
		system("pause");
	}
}
void data::paste(int pos, info* get) {
	if (pos != 1) {
		//if (pos == count()) pos++; // END ?
		for (int i = 1; i < pos - 1; i++) {
			current = current->next;
		}
		get->next = current->next;
		current->next = get;
	}
	else {
		get->next = head;
		head = get;
	}
	current = head;
}
void data::del(int pos) {
	if (pos != 1) {
		info* buffer = new info;
		for (int i = 1; i < pos - 1; i++) {
			current = current->next;
		}
		if (current->next->next != NULL) {
			buffer = current->next->next;
			delete current->next;
			current->next = buffer;
		}
		else { // Кінечний
			delete current->next;
			current->next = NULL;
		}
	}
	else {
		if (current != NULL) {
			//Первий
			current = head;
			head = current->next;
			delete current;
		}
	}
	current = head;
}
float data::get_penya(info* get) {
	return ((get->summa) * (proc_penya / 100));
}