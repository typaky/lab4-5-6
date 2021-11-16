#include <iostream>

using namespace std;

class Date {
protected:
	int day, month, year;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
public:
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int _day, int _month, int _year) {
		day = _day;
		month = _month;
		year = _year;
	}

	~Date() {};


	friend ostream& operator<<(ostream& out,Date& ob);
	Date operator+(Date& ob);
	Date operator-(Date& ob);
	Date operator++(int _day);
	Date operator--(int _day);
	Date operator+(int day);
	Date operator-(int day);
	
};

Date Date::operator--(int _day) {
	Date temp;
	temp.day = day-1;
	temp.month = month;
	temp.year = year;
	
		if (temp.month == 2 or temp.month == 4 or temp.month == 1 or temp.month == 6 or temp.month == 11 or temp.month == 8 or temp.month == 9) {
			if (temp.day < 1) {
				temp.day += 31;
				temp.month--;
			}
		}
		else if (temp.month == 3) {
			if (temp.day < 1) {
				temp.day += 28;
				temp.month--;
			}
		}
		else {
			if (temp.day < 1) {
				temp.day += 30;
				temp.month;
			}
		}
	
	while (temp.month < 1) {
		temp.year--;
		temp.month + 12;
	}
	return temp;
}

Date Date::operator++(int _day) {
	Date temp;
	temp.day = day+1;
	temp.month = month;
	temp.year = year;
		if (temp.month == 1 or temp.month == 3 or temp.month == 12 or temp.month == 5 or temp.month == 10 or temp.month == 7 or temp.month == 8) {
			if (temp.day > 31) {
				temp.day = 1;
				temp.month++;
			}
		}
		else if (temp.month == 2) {
			if (temp.day > 28) {
				temp.day = 1;
				temp.month++;
			}
		}
		else {
			if (temp.day > 30) {
				temp.day = 1;
				temp.month++;
			}
		}
	
	while (temp.month > 12) {
		temp.month - 12;
		temp.year++;
	}
	return temp;
}

Date Date::operator+(int _day) {
	Date temp;
	temp.day = day + _day;
	temp.month = month;
	temp.year = year;
		if (temp.month == 1 or temp.month == 3 or temp.month == 12 or temp.month == 5 or temp.month == 10 or temp.month == 7 or temp.month == 8) {
			if (temp.day > 31) {
				temp.day -= 31;
				temp.month++;
			}
		}
		else if (temp.month == 2) {
			if (temp.day > 28) {
				temp.day -= 28;
				temp.month++;
			}
		}
		else {
			if (temp.day > 30) {
				temp.day -= 30;
				temp.month++;
			}
		}
	while (temp.month > 12) {
		temp.month -= 12;
		temp.year++;
	}
	return temp;
}

Date Date::operator-(int _day) {
	Date temp;
	temp.day = day - _day;
	temp.month = month;
	temp.year = year;

		if (temp.month == 2 or temp.month == 4 or temp.month == 1 or temp.month == 6 or temp.month == 11 or temp.month == 8 or temp.month == 9) {
			if (temp.day < 1) {
				temp.day += 31;
				temp.month--;
			}
		}
		else if (temp.month == 3) {
			if (temp.day < 1) {
				temp.day += 28;
				temp.month--;
			}
		}
		else {
			if (temp.day < 1) {
				temp.day += 30;
				temp.month--;
			}
		}
	
	while (temp.month < 1) {
		temp.year--;
		temp.month += 12;
	}
	return temp;
}

Date Date::operator+(Date& ob) {
	Date temp;

	temp.month = month + ob.month;
	temp.day = day + ob.day;
		if (temp.month == 1 or temp.month == 3 or temp.month == 12 or temp.month == 5 or temp.month == 10 or temp.month == 7 or temp.month == 8) {
			if (temp.day > 31) {
				temp.day -= 31;
				temp.month++;
			}
		}
		else if (temp.month == 2) {
			if (temp.day > 28) {
				temp.day -= 28;
				temp.month++;
			}
		}
		else {
			if (temp.day > 30) {
				temp.day -= 30;
				temp.month++;
			}
		}
	while (temp.month > 12) {
		temp.month -= 12;
		temp.year++;
	}
	temp.year += year + ob.year;
	return temp;
}

Date Date::operator-(Date& ob) {
	Date temp;
	temp.month = month - ob.month;
	temp.day = day - ob.day;
	while (temp.day > 31 or temp.day < 1) {
		if (temp.month == 2 or temp.month == 4 or temp.month == 1 or temp.month == 6 or temp.month == 11 or temp.month == 8 or temp.month == 9) {
			if (temp.day < 1) {
				temp.day += 31;
				temp.month--;
			}
		}
		else if (temp.month == 3) {
			if (temp.day > 28) {
				temp.day += 28;
				temp.month--;
			}
		}
		else {
			if (temp.day < 1) {
				temp.day += 30;
				temp.month--;
			}
		}
	}
	while (temp.month < 1) {
		temp.year--;
		temp.month += 12;
	}
	temp.year = year - ob.year;
	return temp;
}

ostream& operator<<(ostream& out, Date& ob){

	return out << ob.day << "." << ob.month<<"."<< ob.year;
}

int main() {
	Date	start(1, 2, 2010), constructing(29, 0, 0);
	Date end = start + constructing;


	cout << "Дата начала строительства: " << start << endl;
	cout << "Время строительства: " << constructing << endl;
	cout << "Дата сдачи объекта(Дата+Дата): " << end << endl;
	end = start - constructing;
	cout << "Дата начала строительства объекта(Дата-Дата): " << end << endl;
	end = start + 29;
	cout << "Дата сдачи объекта(Дата+Int): " << end << endl;	
	end = end - 29;
	cout << "Дата начала строительства объекта(Дата-Int): " << end << endl;
	end = start++;
	cout << "Дата сдачи объекта(Дата++): " << end << endl;
	end = end--;
	cout << "Дата начала строительства объекта(Дата--): " << end << endl;
	return 0;
}