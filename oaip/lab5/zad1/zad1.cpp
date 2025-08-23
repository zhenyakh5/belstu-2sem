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

struct Date
{
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 11;
};

struct Passport {
	string name;
	string surname;
};

struct HotelClient
{
	string passport;
	int roomNumber;
	string roomType;
	Date arrive;
	Date leave;
};

string names[5] = { "Andrey","Kostya","Katya","Zhenya","Vanya" };
vector<HotelClient> clients;

void enter_new() {

	int n;
	cout << "Введите количество записей" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		HotelClient container;
		int roomType = genRand(1, 5);
		container.passport = names[genRand(0, 4)];
		container.roomNumber = genRand(1, 400);
		container.arrive.day = genRand(0, 32);
		container.arrive.month = genRand(1, 12);
		container.arrive.year = genRand(2000, 2023);
		container.leave.day = genRand(1, 31);
		container.leave.day = genRand(1, 12);
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
			clients.push_back(container);
		}
	}
}

void out()
{

	for (int i = 0; i < clients.size(); i++)
	{

		cout << "Номер выводимой строки: " << i + 1 << endl;
		cout << "Паспортные данные:";
		cout << clients[i].passport;
		cout << endl;
		cout << "Номер:";
		cout << clients[i].roomNumber;
		cout << endl;
		cout << "Дата заселения" << endl;
		clients[i].arrive.day > 9 ? cout << clients[i].arrive.day : cout << "0" << clients[i].arrive.day;
		clients[i].arrive.month > 9 ? cout << clients[i].arrive.month : cout << "0" << clients[i].arrive.month;
		cout << clients[i].arrive.year;
		cout << endl;
		cout << "Дата выселения" << endl;
		clients[i].leave.day > 9 ? cout << clients[i].leave.day : cout << "0" << clients[i].leave.day;
		clients[i].leave.month > 9 ? cout << clients[i].leave.month : cout << "0" << clients[i].leave.month;
		cout << clients[i].leave.year;
		cout << endl;
		cout << "Тип комнаты: ";
		cout << clients[i].roomType;
		cout << endl;

		cout << endl;
	}

}
void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить" << endl;
	cin >> d;
	clients.erase(clients.begin() + d - 1);
}


void search()
{
	int day, month, year, date;
	cout << "enter date ";
	cin >> date;
	year = date % 10000;
	month = (date % 1000000 - year) / 10000;
	day = date / 1000000;

	if (validDay(day) && validMonth(month) && validYear(year) && date % 100000000) {
		for (int i = 0; i < clients.size(); i++)
		{
			if (clients[i].arrive.day == day && clients[i].arrive.month == month) {
				cout << "Номер выводимой строки: " << i + 1 << endl;
				cout << "Паспротные данные:";
				cout << clients[i].passport;
				cout << endl;
				cout << "Номер:";
				cout << clients[i].roomNumber;
				cout << endl;
				cout << "Дата заселения" << endl;
				clients[i].arrive.day > 9 ? cout << clients[i].arrive.day : cout << "0" << clients[i].arrive.day;
				clients[i].arrive.month > 9 ? cout << clients[i].arrive.month : cout << "0" << clients[i].arrive.month;
				cout << clients[i].arrive.year;
				cout << endl;
				cout << "Дата выселения" << endl;
				clients[i].leave.day > 9 ? cout << clients[i].leave.day : cout << "0" << clients[i].leave.day;
				clients[i].leave.month > 9 ? cout << clients[i].leave.month : cout << "0" << clients[i].leave.month;
				cout << clients[i].leave.year;
				cout << endl;
				cout << "Вид номера:";
				cout << clients[i].roomType;
				cout << endl;
			}
		}
	}
	else {
		cout << "Неверная дата" << endl;
	}



}

void osn1()
{
	int choice;
	cout << "Введите:" << endl;
	cout << "1-для ввода записи" << endl;
	cout << "2-для вывода записи" << endl;
	cout << "3-для удаления" << endl;
	cout << "4-для поиска информации" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:  enter_new();	break;
	case 2:  out();  break;
	case 3:  del();	break;
	case 4:  search();  break;
	}

	if (choice != 5) {
		osn1();
	}
}

void main() {
	setlocale(LC_CTYPE, "Russian");
	srand(time(NULL));

	osn1();
}