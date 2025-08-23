#include <iostream>
#include "string"
#include "vector"
#include <stdlib.h>
#include <time.h>
using namespace std;

bool validDay(int day) {
	return day > 0 && day < 32;
}

bool validMonth(int month) {
	return month > 0 && month < 12;
}

bool validYear(int year) {
	return year > 0 && year <= 2023;
}

int genRand(int from, int to) {
	return from + rand() % (to - from + 1);
}

enum RoomType
{
	OnePerson = 1,
	TwoPerson,
	ThreePerson,
	Lux,
	Appartments
};

union Unsing {
	unsigned int day : 4;
	unsigned int month : 5;
};

struct Date2
{
	Unsing day;
	Unsing month;
	int year;
};

struct HotelClient2
{
	string passport;
	int roomNumber;
	string roomType;
	Date2 arrive;
	Date2 leave;
	int year;
};

struct Passport {
	string name;
	string surname;
};

string names[5] = { "Andrey","Kostya","Katya","Zhenya","Vanya" };
vector<HotelClient2> clients2;

void enter_new2() {

	int n;

	cout << "Введите количество записей" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		HotelClient2 container;
		int roomType = genRand(1, 5);
		container.passport = names[genRand(0, 4)];
		container.roomNumber = genRand(1, 400);
		container.arrive.day.day = genRand(1, 31);
		container.arrive.month.month = genRand(1, 12);
		container.arrive.year = genRand(2000, 2023);
		container.leave.day.day = genRand(1, 31);
		container.leave.month.month = genRand(1, 12);
		container.leave.year = genRand(2000, 2023);

		switch (roomType)
		{
		case OnePerson: container.roomType = "One Person"; break;
		case TwoPerson: container.roomType = "Two Person"; break;
		case ThreePerson: container.roomType = "Three Person"; break;
		case Lux: container.roomType = "Lux"; break;
		case Appartments: container.roomType = "Appartments"; break;
		}
		if (container.arrive.year < container.leave.year) {
			clients2.push_back(container);
		}
	}
}

void out2()
{

	for (int i = 0; i < clients2.size(); i++)
	{

		cout << "Номер выводимой строки: " << i + 1 << endl;
		cout << "Паспортные данные:";
		cout << clients2[i].passport;
		cout << endl;
		cout << "Номер:";
		cout << clients2[i].roomNumber;
		cout << endl;
		cout << "Дата заселения" << endl;
		clients2[i].arrive.day.day > 9 ? cout << clients2[i].arrive.day.day << "." : cout << "0" << clients2[i].arrive.day.day << ".";
		clients2[i].arrive.month.month > 9 ? cout << clients2[i].arrive.month.month : cout << "0" << clients2[i].arrive.month.month;
		cout << endl;
		cout << "Дата выселения" << endl;
		clients2[i].leave.day.day > 9 ? cout << clients2[i].leave.day.day << "." : cout << "0" << clients2[i].leave.day.day << ".";
		clients2[i].leave.month.month > 9 ? cout << clients2[i].leave.month.month : cout << "0" << clients2[i].leave.month.month;
		cout << endl;
		cout << "Вид номера:";
		cout << clients2[i].roomType;
		cout << endl;

		cout << endl;
	}

}

void search2()
{
	cout << "введите фамилию ";
	string surname;
	cin >> surname;

	for (int i = 0; i < clients2.size(); i++)
	{
		if (clients2[i].passport.compare(surname) == 0) {
			cout << "Номер выводимой строки: " << i + 1 << endl;
			cout << "Паспротные данные:";
			cout << clients2[i].passport;
			cout << endl;
			cout << "Номер:";
			cout << clients2[i].roomNumber;
			cout << endl;
			cout << "Дата заселения" << endl;
			clients2[i].arrive.day.day > 9 ? cout << clients2[i].arrive.day.day : cout << "0" << clients2[i].arrive.day.day;
			clients2[i].arrive.month.month > 9 ? cout << clients2[i].arrive.month.month : cout << "0" << clients2[i].arrive.month.month;
			cout << clients2[i].arrive.year;
			cout << endl;
			cout << "Дата выселения" << endl;
			clients2[i].leave.day.day > 9 ? cout << clients2[i].leave.day.day : cout << "0" << clients2[i].leave.day.day;
			clients2[i].leave.month.month > 9 ? cout << clients2[i].leave.month.month : cout << "0" << clients2[i].leave.month.month;
			cout << clients2[i].leave.year;
			cout << endl;
			cout << "Вид номера:";
			cout << clients2[i].roomType;
			cout << endl;
		}
	}
}

void osn2()
{
	int choice;
	cout << "Введите:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для поиска информации" << endl;
	cout << "4-для выхода" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:  enter_new2();	break;
	case 2:  out2();  break;
	case 3:  search2();  break;
	}

	if (choice != 4) {
		osn2();
	}
}


void main() {
	setlocale(LC_CTYPE, "Russian");
	srand(time(NULL));

	osn2();
}