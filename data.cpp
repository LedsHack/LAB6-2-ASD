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
	std::cout << "����� �������: "; std::cin >> r->number_bud;
	std::cout << "����� ��������: "; std::cin >> r->number_kv;
	std::cout << "������� ��������: "; std::cin >> r->name;
	/* ��� ������� */
	do {
		std::cout << "1 - ����������" << std::endl;
		std::cout << "2 - ���" << std::endl;
		std::cout << "3 - ����" << std::endl;
		std::cout << "4 - �������������" << std::endl;
		std::cout << "��� �������: "; std::cin >> type;
		switch (type) {
		case 1:
			r->type = "����������";
			break;
		case 2:
			r->type = "���";
			break;
		case 3:
			r->type = "����";
			break;
		case 4:
			r->type = "�������������";
			break;
		}

	} while (!(type >= 1 and type <= 4));
	/* ���� ������� */
	do {
		std::cout << "1 - ���������� �������" << std::endl;
		std::cout << "2 - ���������� ����" << std::endl;
		std::cout << "���� �������: "; std::cin >> date_type;
		switch (date_type) {
		case 1:
			r->date = time(0); //������� ����
			break;
		case 2:
			r->date = obj_time.get();
			break;
		}
	} while (!(date_type == 1 or date_type == 2));

	std::cout << "����: "; std::cin >> r->summa;
	
	r->pros = obj_time.pros(type, r->date);
	r->penya = get_penya(r) * r->pros; 
	return(r);
}
void data::print() {
	if (head != NULL) {
		do {
			print(current); // ��������� �� ���������!
			current = current->next;
		} while (current != NULL);
		current = head;
	}
}
void data::print(info *get) {
	std::cout << std::endl;
	if (get != NULL) {	
		std::cout << "����� �������: " << get->number_bud << std::endl;
		std::cout << "����� ��������: " << get->number_kv << std::endl;
		std::cout << "������� ��������: " << get->name << std::endl;
		std::cout << "��� �������: " << get->type << std::endl;
		std::cout << "���� �������: " << obj_time.to_str(get->date);
		std::cout << "���� �������: " << get->summa << " ���." << std::endl;
		std::cout << "����: " << get->penya << " ���." << std::endl;
		std::cout << "��������: " << get->pros << " ��." << std::endl;
	}
	else {
		std::cout << "��������� �� ����� ������� ������! " << std::endl;
	}
}
void data::print(int get) {
	if (head != NULL) {
		for (int i = 1; i < get; i++) {
			current = current->next;
		}
		print(current); //��������� ��������
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
	int str_m = count(); // ���� ���
	int str_c = 1; //�������
	int selector;
	if (str_m != 0) {
		do {

			system("cls");
			print(str_c);
			std::cout << std::endl << std::endl;

			std::cout << std::setw(10) << "1 - ����. |" << std::setw(10) << "2 - ����. | " << std::setw(10) << "3 - ���� |" << std::endl;
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
* 'n' - ����� ������� (num)
* 't' - �� ����� ������� (type [str])
* 'd' - ����� ������� (time_t)
*/

void data::search(char mode, int num, std::string type, time_t date) {
	int counter = 0;
	system("cls");
	std::cout << "����� �� ";
	switch (mode) { // �����
	case 'n':
		std::cout << "(������� �������): " << num << std::endl;
		break;
	case 't':
		std::cout << "(����� �������): " << type << std::endl;
		break;
	case 'd':
		std::cout << "(����� �������)" << std::endl;
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
					std::cout << std::endl << std::endl << "����� � ������: [" << counter << "]" << std::endl;
					print(current);
				}
				break;
			case 't':
				if (current->type == type) {
					std::cout << std::endl << std::endl << "����� � ������: [" << counter << "]" << std::endl;
					print(current);
				}
				break;
			case 'd':
				if (current->date >= date) {
					std::cout << std::endl << std::endl << "����� � ������: [" << counter << "]" << std::endl;
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
		else { // ʳ������
			delete current->next;
			current->next = NULL;
		}
	}
	else {
		if (current != NULL) {
			//������
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