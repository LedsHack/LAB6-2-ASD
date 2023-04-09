#include "menu.h"

menu::menu() {
	do {
		system("cls");
		std::cout << "> ����� ���� <" << std::endl;
		std::cout << "1 - �������� � �����" << std::endl;
		std::cout << "2 - ���������� ��� ������������" << std::endl;
		std::cout << "3 - �����" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		switch (selector) {
		case 1:
			system("cls");
			std::cout << "�������� � �����..." << std::endl;
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
	std::cout << "����� �� ������������! " << std::endl;
}
void menu::main() {
	do {
		system("cls");
		std::cout << "> ������� ���� <" << std::endl;
		std::cout << "1 - ��������� ��������" << std::endl;
		std::cout << "2 - ��������� ��������" << std::endl;
		std::cout << "3 - ���������" << std::endl;
		std::cout << "4 - ����������/�����" << std::endl;
		std::cout << "5 - �����" << std::endl;
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
		std::cout << "> �����/���������� <" << std::endl;
		std::cout << "1 - ����� (������� �������/����� �������/����� �������)" << std::endl;
		std::cout << "2 - ����������.." << std::endl;
		std::cout << "3 - �����" << std::endl;
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
		std::cout << "> ���������� <" << std::endl;
		std::cout << "1 - �� ������� �������" << std::endl;
		std::cout << "2 - �� ����� �������" << std::endl;
		std::cout << "3 - �� ����� �������" << std::endl;
		std::cout << "4 - �����" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		switch (selector) {
		case 1:
			system("cls");
			std::cout << "> ����� �� ������� ������� <" << std::endl;
			std::cout << "����� �������: "; std::cin >> num_s;
			obj.search('n', num_s, "", 0);
			break;
		case 2:
			do {
				system("cls");
				std::cout << "> ����� �� ����� ������� <" << std::endl;
				std::cout << "1 - ����������" << std::endl;
				std::cout << "2 - ���" << std::endl;
				std::cout << "3 - ����" << std::endl;
				std::cout << "4 - �������������" << std::endl;
				std::cout << "5 - �����" << std::endl;
				std::cout << "-> "; std::cin >> selector;
				switch (selector) {
				case 1:
					obj.search('t', 0, "����������", 0);
					break;
				case 2:
					obj.search('t', 0, "���", 0);
					break;
				case 3:
					obj.search('t', 0, "����", 0);
					break;
				case 4:
					obj.search('t', 0, "�������������", 0);
					break;
				}
			} while (selector != 5);
			selector = 2;
			break;
		case 3:
			system("cls");
			std::cout << "> ����� �� ����� ������� <" << std::endl;
			obj.search('d', 0, "", obj.obj_time.get());
			//system("pause");
			break;
		}
	} while (selector != 4);
}
void menu::get_date() {
	if (!obj.obj_time.adds_time) {
		system("cls");
		std::cout << "> ���� ������� ���������� <" << std::endl;
		obj.obj_time.set('k');

		system("cls");
		std::cout << "> ���� ������� ���� <" << std::endl;
		obj.obj_time.set('g');

		system("cls");
		std::cout << "> ���� ������� ���� <" << std::endl;
		obj.obj_time.set('v');

		system("cls");
		std::cout << "> ���� ������� �����������㳿 <" << std::endl;
		obj.obj_time.set('e');

		obj.obj_time.adds_time = true;
	}
	if (obj.proc_penya == 0) {
		system("cls");
		std::cout << "> ������ ������� ��� �� 1 ���� <" << std::endl;
		std::cout << "����: "; std::cin >> obj.proc_penya;
	}
}
void menu::add() {
	get_date();
	do {
		float size = obj.count();
		int pos;

		system("cls");
		std::cout << "> ��������� �������� <" << std::endl;
		std::cout << "1 - ��������� � �����" << std::endl;
		std::cout << "2 - ��������� � �������" << std::endl;
		std::cout << "3 - ��������� � ��������" << std::endl;
		std::cout << "4 - ��������� � ������� (��/ϳ���)" << std::endl;
		std::cout << "5 - �����" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		switch (selector) {
		case 1:
			system("cls");
			std::cout << " > ��������� � ����� < " << std::endl;
			//get_date();
			obj.paste(obj.count() + 1, obj.input()); // ������� ������� ����� �������� �� +1
			break;
		case 2:
			system("cls");
			std::cout << " > ��������� � ������� < " << std::endl;
			//get_date();
			obj.add(obj.input());
			break;
		case 3:
			system("cls");
			std::cout << " > ��������� � �������� < " << std::endl;
			//get_date();
			obj.paste(round(size / 2), obj.input());
			break;
		case 4:
			do {
				system("cls");
				std::cout << "1 - ��������� '��'" << std::endl;
				std::cout << "2 - ��������� 'ϳ���'" << std::endl;
				std::cout << "-> "; std::cin >> selector;
			} while (selector != 1 and selector != 2);

			do {
				system("cls");
				std::cout << "> �������";
				if (selector == 1) std::cout << " (��) <" << std::endl;
				else std::cout << " (ϳ���) <" << std::endl;
				std::cout << "������ ������� [1-" << size << "]:"; std::cin >> pos;
			} while (!(pos > 0 and pos <= size));
			
			if (selector == 2) pos++; //������ �� ������� �����
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
		std::cout << "> ��������� <" << std::endl;
		std::cout << "1 - ��� ��������" << std::endl;
		std::cout << "2 - ��������� �������� �� �������" << std::endl;
		std::cout << "3 - ����������� ������ (�����)" << std::endl;
		std::cout << "4 - �����" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		switch (selector) {
		case 1:
			system("cls");
			std::cout << "> ��������� ��� �������� <" << std::endl;
			obj.print();
			system("pause");
			break;
		case 2:
			do {
				system("cls");
				std::cout << "1 - ������� �� ������� (1/" << size << ")" << std::endl;
				std::cout << "2 - �����" << std::endl;
				std::cout << "-> "; std::cin >> selector;
				if (selector == 1) {
					do {
						system("cls");
						std::cout << "> ��������� �� ������� (1/" << size << ") <" << std::endl;
						std::cout << "�����: "; std::cin >> get;
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
		std::cout << "> �������� ���� ? <" << std::endl;
		std::cout << "1 - �������� � ����" << std::endl;
		std::cout << "2 - ����� ��� ����������" << std::endl;
		std::cout << "-> "; std::cin >> selector;
		if (selector == 1) {
			system("cls");
			if (file.save(obj)) {
				std::cout << "���� ���������!" << std::endl;
			}
			else {
				std::cout << "������� ��� ��������� �����" << std::endl;
			}
			system("pause");
		}
	} while (!(selector == 1 or selector == 2));
}
void menu::del() {
	do {
		float len;
		
		system("cls");
		std::cout << "> ��������� �������� <" << std::endl;
		std::cout << "1 - ��������� � �������" << std::endl;
		std::cout << "2 - ��������� � ����" << std::endl;
		std::cout << "3 - ��������� � ��������" << std::endl;
		std::cout << "4 - �����" << std::endl;
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