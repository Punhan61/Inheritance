#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE
//#define READ_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	std::ofstream fout;                  // 1) ������� �����
	fout.open("File.txt", std::ios::app);// 2) ��������� �����
	//std::ios::app - append,�� ������������,� ���������� � ����� �����

	fout << "Hello Files" << endl;       // 3) ����� � �����
	fout.close();                        // 4) ��������� �����

	system("notepad File.txt");          // ������� system() ��������� ����� ��������� � ������� ���� PATH(����) � Windows 
#endif // WRITE_TO_FILE

#ifdef READ_TO_FILE
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
#endif // READ_TO_FILE

	std::ofstream fout;
	fout.open("File.txt", std::ios::app);
	fout<<"new Student Pinkman Jessie 25 Chemistry ww_220 90 95"
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Undergrad("Makhmudov", "Punkhan", 35, "Software developer", "PV_224", 95, 80, "OOP Polymorphism"),
		new Student("Vercetti", "Tomas", 30, "Criminalistica", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 15),
		new Teacher("Einstein", "Albert", 143, "Astronomy", 120)"

}
