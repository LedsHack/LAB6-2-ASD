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
	    //fout << std::endl; // Не потрібно так як є проблеми при зчитуванні
		fout.close();
	}
	else result = false;
	return(result);
}
data File::read(data get) {
	std::ifstream fin("data.dat");
	if (!fin) {
		std::cout << "Помилка при читанні даних з файлу!" << std::endl;
	}
	else {
		while (!fin.eof()) { //Перевірка на кінець файлу повертає true якщо кінець
			info* read = new info;
			//	Читаєм
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
		std::cout << "Успішно!" << std::endl;
	}
	fin.close();
	return(get);
}