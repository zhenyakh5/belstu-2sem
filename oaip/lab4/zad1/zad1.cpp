#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;



struct Specializations
{
	string UniversityName;
	string address;
	string specializaion;
	int concours;
	float payment;
};

vector<Specializations> specializations;
const short N = 20;

string UniversityNames[5] = { "BSTU","BSUIR", "BNTU","BSMU","BSU" };
string Addresses[5] = { "Minsk","Mogilev","Pinsk","Moscow","Olo" };
string SpecializationNames[5] = { "POIT","ISIT","KSIS","MIS","ES" };

int genRand(int from, int to) {
	return from + rand() % (to - from + 1);
}


void enterM()
{
	Specializations container;
	cout << "Название университета: " << '\n';
	cin >> container.UniversityName;
	cout << "Адресс: " << '\n';
	cin >> container.address;

	cout << "Специальность: " << '\n';
	cin >> container.specializaion;
	cout << "Цена обучения " << '\n';
	cin >> container.payment;
	cout << "Конкурс: " << "\n";
	cin >> container.concours;

	specializations.push_back(container);
	cout << "Создана " << specializations.size() << " Специальность" << endl;


}

void input()
{
	Specializations container;
	container.UniversityName = UniversityNames[genRand(0, 4)];
	container.address = Addresses[genRand(0, 4)];
	container.specializaion = SpecializationNames[genRand(0, 4)];
	container.payment = (float)(genRand(100000, 400000)) / 100;
	container.concours = genRand(200, 400);

	specializations.push_back(container);


	cout << "Создана " << specializations.size() << " Специальность" << endl;
}

void output()
{
	for (int i = 0; i < specializations.size(); i++)
	{
		cout << "Название университета: " << specializations[i].UniversityName << '\n';
		cout << "Адресс: " << specializations[i].address << '\n';
		cout << "Специальность: " << specializations[i].specializaion << '\n';
		printf("Цена обучения %.2f$ \n", specializations[i].payment);
		cout << "Конкурс: " << specializations[i].concours << " points" << "\n\n\n";

	}
}

void search()
{
	string spec;
	cin >> spec;
	for (int i = 0; i < specializations.size(); i++)
	{
		if (specializations[i].specializaion.compare(spec) == 0) {
			cout << "Название университета: " << specializations[i].UniversityName << '\n';
			cout << "Адресс: " << specializations[i].address << '\n';
			cout << "Специальность: " << specializations[i].specializaion << '\n';
			printf("Цена обучения %.2f$ \n", specializations[i].payment);
			cout << "Конкурс: " << specializations[i].concours << " points" << "\n\n\n";
		}
	}
}

void deleteSpec()
{
	string spec;
	cin >> spec;
	for (int i = 0; i < specializations.size(); i++)
	{
		if (specializations[i].specializaion.compare(spec) == 0) {
			specializations.erase(specializations.begin() + i);
		}
	}
	cout << '\n';
}



void ofile()
{

	ofstream file1("information.txt");
	for (int i = 0; i < specializations.size(); i++)
	{

		file1 << "\tСпециальность №" << i + 1 << '\n';

		file1 << "Название университета: ";
		file1 << specializations[i].UniversityName;

		file1 << "\nАдрес: ";
		file1 << specializations[i].address;

		file1 << "\nСпециальность: ";
		file1 << specializations[i].specializaion;

		file1 << "\nКонкурс: ";
		file1 << specializations[i].concours;


		file1 << "\nЦена обучения: ";
		file1 << specializations[i].payment << "\n\n";
	}
	cout << "Специальности записаны в файл" << endl;
}

void ifile()
{
	string strInf;
	ifstream file1("information.txt");
	while (file1)
	{
		getline(file1, strInf);
		cout << strInf << '\n';
	}
}

void main()
{
	setlocale(LC_ALL, "Russian");
	short choose;
	cout << "Выберите, что сделать:\n1 — ввод элементов структуры с клавиатуры;\n2 — вывод элементов стуктуры в консольное окно;"
		"\n3 — удаление заданной структурированной переменной; \n4 — поиск информации; \n5 — запись информации в файл; \n6 — чтение данных из файла; \n7 — выход из программы.\n";
	cin >> choose;

	switch (choose)
	{
	case 0: enterM(); break;
	case 1: input(); break;
	case 2: output(); break;
	case 3: deleteSpec(); break;
	case 4: search(); break;
	case 5: ofile(); break;
	case 6: ifile(); break;
	default: return;
	}

	if (choose != 7) {
		main();
	}
}
