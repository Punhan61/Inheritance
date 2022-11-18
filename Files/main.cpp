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
	std::ifstream fin("201 RAW.txt");
	const int size = 256;
	char buffer[size] = {};
	std::ofstream fout("201 newRAW.txt");
	while (fin.getline(buffer,size))
		{
		    fout << buffer << endl;
		}
	
	system("notepad 201 newRAW.txt");
}
