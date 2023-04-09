#include "times.h"

std::string times::to_str(time_t get) {
	std::string r = asctime(localtime(&get));
	return(r);
}
time_t times::get() {
	int h = 0;
	int m = 0;
	int day;
	int mounth;
	time_t buffer = time(0);
	tm* data = localtime(&buffer);
	int level = 2;
	do {
		switch (level) {
		case 0:
			std::cout << "Годин: "; std::cin >> h;
			if (h >= 0 and h <= 24) level++;
			break;
		case 1:
			std::cout << "Хвилин: "; std::cin >> m;
			if (m >= 0 and m <= 60) level++;
			break;
		case 2:
			std::cout << "День: "; std::cin >> day;
			if (day >= 1 and day <= 31) level++;
			break;
		case 3:
			std::cout << "Місяць: "; std::cin >> mounth;
			if (mounth >= 1 and mounth <= 12) level++;
			break;
		}
	} while (level != 4);
	data->tm_sec = 0;
	data->tm_hour = h;
	data->tm_min = m;
	data->tm_mday = day;
	data->tm_mon = mounth - 1;
	
	return(mktime(data));
	//return(buffer);
}

/*
* k - Кварт плата
* g - Газ
* v - Вода
* e - електро енергія
*/
void times::set(char set) {
	switch (set) {
	case 'k':
		kvart = get();
		break;
	case 'g':
		gaz = get();
		break;
	case 'v':
		voda = get();
		break;
	case 'e':
		elect = get();
		break;
	}
}
/*
* 1 - Квартплата
* 2 - Газ
* 3 - Вода
* 4 - електроенергія
*/
int times::pros(int type, time_t get) {
	switch (type) {
	case 1:
		return(kalc(get, kvart));
		break;
	case 2:
		return(kalc(get, gaz));
		break;
	case 3:
		return(kalc(get, voda));
		break;
	case 4:
		return(kalc(get, elect));
		break;
	}
}
int times::kalc(time_t get, time_t nado) {
	int r = 0;
	tm* nados = localtime(&nado);
	int nado_d = nados->tm_mday;
	int nado_m = nados->tm_mon;
	//delete nados;
 	tm* gets = localtime(&get);
	/*
	std::cout << "DN: " << nado_d << std::endl;
	std::cout << "MN: " << nado_m << std::endl;
	std::cout << std::endl;
	std::cout << "DG: " << gets->tm_mday << std::endl;
	std::cout << "MG: " << gets->tm_mon << std::endl;
	system("pause");
	*/
	if (gets->tm_mon > nado_m) {
		r += (gets->tm_mon - nado_m) * 31;
	}
	if (gets->tm_mday > nado_d) {
		r += gets->tm_mday - nado_d;
	}
	//delete gets;
	return r;
}