#include "File.h"

bool File::save(data get) {
	bool result = true;
	if (get.head != NULL) {
		std::ofstream fout("data.dat");
		info* current = get.head;
		if (!fout) {
			result = false;
		}
		else {
			do {
				fout <<
					current->number_bud << " " <<
					current->number_kv << " " <<
					current->name << " " <<
					current->type << " " <<
					current->date << " " <<
					current->summa << " " <<
					current->penya << " " <<
					current->pros;

				if (current->next != NULL) fout << " ";

				current = current->next;
			} while (current != NULL);
		}
	    //fout << std::endl; // �� ������� ��� �� � �������� ��� ���������
		fout.close();
	}
	else result = false;
	return(result);
}
data File::read(data get) {
	std::ifstream fin("data.dat");
	if (!fin) {
		std::cout << "������� ��� ������ ����� � �����!" << std::endl;
	}
	else {
		while (!fin.eof()) { //�������� �� ����� ����� ������� true ���� �����
			info* read = new info;
			//	�����
			fin >> read->number_bud;
			fin >> read->number_kv;			
			fin >> read->name;		
			fin >> read->type;		
			fin >> read->date;		
			fin >> read->summa;		    
			fin >> read->penya;			
			fin >> read->pros;
			get.add(read);
		}
		std::cout << "������!" << std::endl;
	}
	fin.close();
	return(get);
}