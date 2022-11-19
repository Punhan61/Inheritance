#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//#define WRITE_TO_FILE
//#define READ_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	std::ofstream fout;                  // 1) Создаем поток
	fout.open("File.txt", std::ios::app);// 2) Открываем поток
	//std::ios::app - append,не переписывает,а дописывает в конец файла

	fout << "Hello Files" << endl;       // 3) Пишем в поток
	fout.close();                        // 4) Закрываем поток

	system("notepad File.txt");          // Функция system() запускаем любую программу к которой есть PATH(путь) В Windows 
#endif // WRITE_TO_FILE

#ifdef READ_TO_FILE
	ifstream fin("File.txt");
	if (fin.is_open())
	{
		// Будем читать файл
		const int SIZE = 256;
		char buffer[SIZE] = {};
		while (!fin.eof())
		{
			//fin >> buffer;
			fin.getline(buffer, SIZE);
			cout << buffer << endl;
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
#endif // READ_TO_FILE
	char number[10] = {};
	char src_filename[_MAX_FNAME] = {};//_MAX_FNAME - это встроеная константа.которая
	//содержит максимально возможную длинну файла
	char wal_filename[_MAX_FNAME] = {};
	char dhcpd_filename[_MAX_FNAME] = {};
	// src(source) - файл источник,из кторого изначально берутся MAC и IP адреса
	// dst(destination) - это конечеый файл, в котором столбики будут поменяны местами

	cout << "Введите номер аудитории: "; cin >> number;
	// По введенному номеру аудитории формируем имена файлов,как исходного,так и конечного:

	strcat(src_filename, number);
	strcat(src_filename, " RAW.txt");
	// strcat(dst,src); // содержимое строки src добавляет в конец dst
	// strcat - выполняет коткатенацию строку
	//к первой строке (filename) добавляет вторую строку (" RAW.txt");	
	strcat(wal_filename, number);
	strcat(wal_filename, " ready.txt");

	strcat(dhcpd_filename, number);
	strcat(dhcpd_filename, ".dhcpd");

	cout << "Source filename:" << src_filename << endl;
	cout << "WAL filename:" << wal_filename << endl;
	cout << "DHCPD filename:" << dhcpd_filename << endl;

	const int IP_SIZE = 16;
	const int MAC_SIZE = 18;

	char sz_ip_buffer[IP_SIZE] = {};
	char sz_mac_buffer[MAC_SIZE] = {};

	std::ofstream fout(wal_filename);
	std::ifstream fin(src_filename);

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			cout << sz_mac_buffer << "\t\t" << sz_ip_buffer << endl;
			fout << sz_mac_buffer << "\t\t" << sz_ip_buffer << endl;
		}
		//fin.close();  //Будем еще раз читать файл,только позже
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}

	fout.close();
	char sz_command[_MAX_FNAME] = "start notepad ";
	strcat(sz_command, wal_filename);
	system(sz_command);

	/////////////////////////////////////////////////////////////////////////////////

	// Возвращаемся в начало файла
	fin.clear();
	fin.seekg(0);
	cout << fin.tellg() << endl;
	fout.open(dhcpd_filename);
	if (fin.is_open())
	{
		for (int i = 1; !fin.eof(); i++)
		{
			fin >> sz_ip_buffer >> sz_mac_buffer;
			if (sz_ip_buffer[0] == 0 || sz_mac_buffer[0] == 0)continue;
			for (int i = 0; sz_mac_buffer[i]; i++)
			{
				if (sz_mac_buffer[i] == '-')sz_mac_buffer[i] = '-';
			}
			cout << "host " << number << "-" << i << endl;
			cout << "{\n";
			cout << "\thardware ethernet\t" << sz_mac_buffer << ";\n";
			cout << "\tfixsed-address\t\t" << sz_ip_buffer << ";\n";
			cout << "}\n"; cout << number << "-" << i << endl;
			cout << endl;

			fout << "host " << number << "-" << i << endl;
			fout << "{\n";
			fout << "\thardware ethernet\t" << sz_mac_buffer << ";\n";
			fout << "\tfixsed-address\t\t" << sz_ip_buffer << ";\n";
			fout << "}\n";
		}
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}

	strcpy(sz_command + strlen("start notepad "), dhcpd_filename);
	system(sz_command);
	// strcpy(dst,src);  //string copy
	// strcpy() копирует строку src в строку dst
}