#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE
#define READ_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	std::ofstream fout;            // 1) ������� �����
	fout.open("File.txt", std::ios::app);         // 2) ��������� �����
	//std::ios::app - append,�� ������������,� ���������� � ����� �����

	fout << "Hello Files" << endl; // 3) ����� � �����
	fout.close();                  // 4) ��������� �����

	system("notepad File.txt"); // ������� system() ��������� ����� ��������� � ������� ���� PATH(����)  
#endif // WRITE_TO_FILE

	ifstream fin("File.txt");
	if (fin.is_open())
	{
		// ����� ������ ����
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
}
