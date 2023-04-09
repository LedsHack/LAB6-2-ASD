#include "menu.h"

menu::menu() {
	do {
		system("cls");
		std::cout << "> Вхідні данні <" << std::endl;
		std::cout << "1 - Загрузка з файла" << std::endl;
		std::cout << "2 - Продовжити без підвантаження" << std::endl;
		std::cout << "3 - Вийти" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		switch (selector) {
		case 1:
			system("cls");
			std::cout << "Зчитання з файлу..." << std::endl;
			obj = file.read(obj);
			system("pause");
			main();
			selector = 1;
			break;
		case 2:
			main();
			selector = 2;
			break;
		}
	} while (selector != 3);
	save();
	system("cls");
	std::cout << "Дякую за використання! " << std::endl;
}
void menu::main() {
	do {
		system("cls");
		std::cout << "> Головне меню <" << std::endl;
		std::cout << "1 - Додавання елементу" << std::endl;
		std::cout << "2 - Видалення елементу" << std::endl;
		std::cout << "3 - Виведення" << std::endl;
		std::cout << "4 - Сортування/Пошук" << std::endl;
		std::cout << "5 - Вихід" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		switch (selector) {
		case 1:
			add();
			selector = 1;
			break;
		case 2:
			del();
			selector = 2;
			break;
		case 3:
			print();
			selector = 3;
			break;
		case 4:
			SearchSort();
			selector = 4;
			break;
		}
	} while (selector != 5);
}
void menu::SearchSort() {
	do {
		system("cls");
		std::cout << "> Пошук/Сортування <" << std::endl;
		std::cout << "1 - Пошук (Номером будинку/Типом платежу/Датою платежу)" << std::endl;
		std::cout << "2 - Сортування.." << std::endl;
		std::cout << "3 - Вихід" << std::endl;
		std::cout << "->"; std::cin >> selector;
		switch (selector) {
		case 1:
			Search();
			selector = 1;
			break;
		case 2:
			//ToDo
			std::cout << "ToDo.." << std::endl;
			system("pause");
			selector = 2;
			break;
		}
	} while (selector != 3);
}
void menu::Search() {
	do {
		int num_s;
		system("cls");
		std::cout << "> Сортування <" << std::endl;
		std::cout << "1 - за номером будинку" << std::endl;
		std::cout << "2 - за типом платежу" << std::endl;
		std::cout << "3 - за датою платежу" << std::endl;
		std::cout << "4 - Вихід" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		switch (selector) {
		case 1:
			system("cls");
			std::cout << "> Пошук за номером будинку <" << std::endl;
			std::cout << "Номер будинку: "; std::cin >> num_s;
			obj.search('n', num_s, "", 0);
			break;
		case 2:
			do {
				system("cls");
				std::cout << "> Пошук за типом платежу <" << std::endl;
				std::cout << "1 - Квартплата" << std::endl;
				std::cout << "2 - Газ" << std::endl;
				std::cout << "3 - Вода" << std::endl;
				std::cout << "4 - Електроенергія" << std::endl;
				std::cout << "5 - Вихід" << std::endl;
				std::cout << "-> "; std::cin >> selector;
				switch (selector) {
				case 1:
					obj.search('t', 0, "Квартплата", 0);
					break;
				case 2:
					obj.search('t', 0, "Газ", 0);
					break;
				case 3:
					obj.search('t', 0, "Вода", 0);
					break;
				case 4:
					obj.search('t', 0, "Електроенергія", 0);
					break;
				}
			} while (selector != 5);
			selector = 2;
			break;
		case 3:
			system("cls");
			std::cout << "> Пошук за типом платежу <" << std::endl;
			obj.search('d', 0, "", obj.obj_time.get());
			//system("pause");
			break;
		}
	} while (selector != 4);
}
void menu::get_date() {
	if (!obj.obj_time.adds_time) {
		system("cls");
		std::cout << "> Дата платежу Квартплати <" << std::endl;
		obj.obj_time.set('k');

		system("cls");
		std::cout << "> Дата платежу Гузу <" << std::endl;
		obj.obj_time.set('g');

		system("cls");
		std::cout << "> Дата платежу Води <" << std::endl;
		obj.obj_time.set('v');

		system("cls");
		std::cout << "> Дата платежу Електроенергії <" << std::endl;
		obj.obj_time.set('e');

		obj.obj_time.adds_time = true;
	}
	if (obj.proc_penya == 0) {
		system("cls");
		std::cout << "> Вкажіть відсоток пені за 1 день <" << std::endl;
		std::cout << "Пеня: "; std::cin >> obj.proc_penya;
	}
}
void menu::add() {
	get_date();
	do {
		float size = obj.count();
		int pos;

		system("cls");
		std::cout << "> Додавання елементу <" << std::endl;
		std::cout << "1 - Додавання в кінець" << std::endl;
		std::cout << "2 - Додавання в початок" << std::endl;
		std::cout << "3 - Додавання в середину" << std::endl;
		std::cout << "4 - Додавання в позицію (До/Після)" << std::endl;
		std::cout << "5 - Вихід" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		switch (selector) {
		case 1:
			system("cls");
			std::cout << " > Додавання в кінець < " << std::endl;
			//get_date();
			obj.paste(obj.count() + 1, obj.input()); // Оскільки вставка перед вказаним то +1
			break;
		case 2:
			system("cls");
			std::cout << " > Додавання в початок < " << std::endl;
			//get_date();
			obj.add(obj.input());
			break;
		case 3:
			system("cls");
			std::cout << " > Додавання в середину < " << std::endl;
			//get_date();
			obj.paste(round(size / 2), obj.input());
			break;
		case 4:
			do {
				system("cls");
				std::cout << "1 - Додавання 'До'" << std::endl;
				std::cout << "2 - Додавання 'Після'" << std::endl;
				std::cout << "-> "; std::cin >> selector;
			} while (selector != 1 and selector != 2);

			do {
				system("cls");
				std::cout << "> Вставка";
				if (selector == 1) std::cout << " (До) <" << std::endl;
				else std::cout << " (Після) <" << std::endl;
				std::cout << "Введіть елемент [1-" << size << "]:"; std::cin >> pos;
			} while (!(pos > 0 and pos <= size));
			
			if (selector == 2) pos++; //Правка бо вставля перед
			//get_date();
			obj.paste(pos, obj.input());

			selector = 4;
			break;
		}
	} while (selector != 5);
}
void menu::print() {
	do {
		int size = obj.count();
		int get;

		system("cls");
		std::cout << "> Виведення <" << std::endl;
		std::cout << "1 - Всіх елементів" << std::endl;
		std::cout << "2 - Виведення елемента за номером" << std::endl;
		std::cout << "3 - Переглянути еленти (книга)" << std::endl;
		std::cout << "4 - Вихід" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		switch (selector) {
		case 1:
			system("cls");
			std::cout << "> Виведення всіх елементів <" << std::endl;
			obj.print();
			system("pause");
			break;
		case 2:
			do {
				system("cls");
				std::cout << "1 - Вивести за номером (1/" << size << ")" << std::endl;
				std::cout << "2 - Вихід" << std::endl;
				std::cout << "-> "; std::cin >> selector;
				if (selector == 1) {
					do {
						system("cls");
						std::cout << "> Виведення за номером (1/" << size << ") <" << std::endl;
						std::cout << "Номер: "; std::cin >> get;
					} while (!(get >= 1 and size >= get));
					obj.print(get);
					system("pause");
				}
			} while (selector != 2);
			//selector = 2;
			break;
		case 3:
			obj.view();
			break;
		}
	} while (selector != 4);
}

void menu::save() {
	do {
		system("cls"); 
		std::cout << "> Зберегти зміни ? <" << std::endl;
		std::cout << "1 - Зберегти в файл" << std::endl;
		std::cout << "2 - Вийти без збереження" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		if (selector == 1) {
			system("cls");
			if (file.save(obj)) {
				std::cout << "Файл збережено!" << std::endl;
			}
			else {
				std::cout << "Помилка при збереженні файлу" << std::endl;
			}
			system("pause");
		}
	} while (!(selector == 1 or selector == 2));
}
void menu::del() {
	do {
		float len;
		
		system("cls");
		std::cout << "> Видалення елементу <" << std::endl;
		std::cout << "1 - Видалення з початку" << std::endl;
		std::cout << "2 - Видалення з кінця" << std::endl;
		std::cout << "3 - Видалення з середини" << std::endl;
		std::cout << "4 - Вихід" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		switch (selector) {
		case 1:
			obj.del(1);
			break;
		case 2:
			obj.del(obj.count());
			break;
		case 3:
			len = obj.count();
			obj.del(round(len / 2));
			break;
		}
	} while (selector != 4);
}