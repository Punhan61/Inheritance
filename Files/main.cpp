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
	char dst_filename[_MAX_FNAME] = {};
	// src(source) - файл источник,из кторого изначально берутся MAC и IP адреса
	// dst(destination) - это конечеый файл, в котором столбики будут поменяны местами

	cout << "Введите номер аудитории: "; cin >> number;
	// По введенному номеру аудитории формируем имена файлов,как исходного,так и конечного:

	strcat(src_filename, number);
	strcat(src_filename, " RAW.txt"); 
	// strcat(dst,src); // содержимое строки src добавляет в конец 
	// strcat - выполняет коткатенацию строку
	//к первой строке (filename) добавляет вторую строку (" RAW.txt");	
	strcat(dst_filename, number);
	strcat(dst_filename, " 201 newRAW.txt");
	
	const int IP_SIZE = 16;
	const int MAC_SIZE = 18;

	char sz_ip_buffer[IP_SIZE] = {};
	char sz_mac_buffer[MAC_SIZE] = {};

	std::ofstream fout(dst_filename);
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
		fin.close();
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}

	fout.close();
	char sz_command[_MAX_FNAME] = "notepad ";
	strcat(sz_command, dst_filename);
	system(sz_command);

}
