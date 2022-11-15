#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#define delimiter "\n--------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const string& last_name, const string& first_name,unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name,first_name,age

class Human
{
	static const int FULL_NAME_LENGTH = 20;
	static const int AGE_LENGTH = 5;
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}

	// Constructors
	Human(HUMAN_TAKE_PARAMETERS):
		last_name(last_name),first_name(first_name),age(age)
	{
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	// Methods
	virtual ostream& print(ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age << " лет";
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		//ofs << last_name << " " << first_name << " " << age;
		ofs.width(FULL_NAME_LENGTH);
		ofs << std::left;
		ofs << last_name + " " + first_name; 
		ofs.width(AGE_LENGTH);
		ofs << std::right;
		ofs << age;
		return ofs;
	}
	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};

ostream& operator<<(ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	return obj.print(ofs);
}
std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	
	return obj.scan(ifs);
}


#define STUDENT_TAKE_PARAMETERS const string& specialty, const string& group, double rating, double attendence
#define STUDENT_GIVE_PARAMETERS specialty,group,rating,attendence

class Student :public Human
{
	static const int SPECIALTY_LENGTH = 25;
	static const int GROUP_LENGTH = 10;
	static const int RATING_LENGTH = 8;
	static const int ATTENDENCE_LENGTH = 8;
	string specialty;
	string group;
	double rating;
	double attendence;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendence()const
	{
		return attendence;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendence(double attendence)
	{
		this->attendence = attendence;
	}

	// Constructors

	Student(HUMAN_TAKE_PARAMETERS,STUDENT_TAKE_PARAMETERS):Human(last_name,first_name,age)
	{
		this->specialty = specialty;
		this->group = group;
		this->rating = rating;
		this->attendence = attendence;
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	// Methods
	ostream& print(ostream& os)const override
	{
		return Human::print(os) << "," << specialty << " " << group << " " << rating << " " << attendence;
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Human::print(ofs) << " ";
		ofs.width(SPECIALTY_LENGTH);
		ofs << std::left;
		ofs << specialty;
		ofs.width(GROUP_LENGTH);
		ofs << group;
		ofs.width(RATING_LENGTH);
		ofs << std::right;
		ofs << rating;
		ofs.width(ATTENDENCE_LENGTH);
		ofs << attendence;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)override
	{
		Human::scan(ifs);
		const int SIZE = 25;
		char buffer[SIZE]{};
		ifs.read(buffer, SIZE-1);
		for (int i = SIZE - 2; buffer[i] == ' '; i--)buffer[i] = 0;
		while (buffer[0] == ' ')
		{
			for (int i = 0; buffer[i]; i++)buffer[i] = buffer[i + 1];
		}
		specialty = buffer;
		while (specialty[0] == ' ')specialty.erase(0, 1);
		ifs >> group;
		ifs >> rating;
		ifs >> attendence;
		return ifs;
	}
};

class Teacher :public Human
{
	static const int SPECIALTY_LENGTH = 25;
	static const int EXPERIENCE_LENGTH = 5;
	string specialty;
	unsigned int experience;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experiance()const
	{
		return experience;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//Constructors

	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int experience
	):Human(last_name,first_name,age)
	{
		set_specialty(specialty);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	// Methods

	ostream& print(ostream& os)const override
	{
		return Human::print(os)<< "," << specialty << " " << experience;
	}
	std::ofstream& print(ofstream& ofs)const override
	{
		Human::print(ofs) << " ";
		ofs.width(SPECIALTY_LENGTH);
		ofs << std::left;
		ofs << specialty;
		ofs.width(EXPERIENCE_LENGTH);
		ofs << std::right;
		ofs << experience;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)override
	{
		Human::scan(ifs);
		const int SIZE = SPECIALTY_LENGTH;
		char buffer[SIZE]{};
		ifs.read(buffer, SIZE-1);
		for (int i = SIZE - 2; buffer[i] == ' '; i--)buffer[i] = 0;
		while (buffer[0] == ' ')
		{
			for (int i = 0; buffer[i]; i++)buffer[i] = buffer[i + 1];
		}
		specialty = buffer;
		ifs >> experience;
		return ifs;
	}
};

#define GRADUATE_TAKE_PARAMETERS const string& specialty, const string& group, double graduate_work
#define GRADUATE_GIVE_PARAMETERS specialty,group,graduate_work

class Undergrad :public Student
{
	string topic;
public:
	const string& get_topic()const
	{
		return topic;
	}
	void set_topic(const string& topic)
	{
		this->topic = topic;
	}
	
	// Constructors
	Undergrad(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS,const string& topic) :
		Student(HUMAN_GIVE_PARAMETERS,STUDENT_GIVE_PARAMETERS)
	{
		set_topic(topic);
		cout << "GConstructor:\t" << this << endl;
	}
	~Undergrad()
	{
		cout << "DDestructor:\t" << this << endl;
	}

	// Methods
	ostream& print(ostream& os)const override
	{
		return Student::print(os) << ", Тема дипломной работы: " << topic;
	}
	std::ofstream& print(ofstream& ofs)const override
	{
		Student::print(ofs) << " " << topic;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)override
	{
		Student::scan(ifs);
		std::getline(ifs, topic);
		return ifs;
	}
};

Human* HumanFactory(const std::string& type)
{
	// Этот метод создает объекты в динамической памяти:
	if (type.find("Student") != std::string::npos)return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Undergrad") != std::string::npos)return new Undergrad("", "", 0, "", "", 0, 0,"");
	if (type.find("Teacher") != std::string::npos)return new Teacher("", "", 0, "", 0);
}

void print(Human* group[], const int n)
{
	// Specialisation - Уточнение (DownCast - преобразование сверху вниз) 
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}
}
void save(Human* group[],const int n, const std::string& filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		fout.width(15);
		fout << std::left;
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
	}
	fout.close();
	std::string command = "notepad " + filename;
	system(command.c_str());
}
Human** load(const std::string& filename,int& n)
{
	std::ifstream fin(filename);
	// 1)Вычисляем размер массива
	if (fin.is_open())
	{
		std::string buffer;
		for(n=0;!fin.eof();n++)
		{
			std::getline(fin, buffer);
		}
		n--;
	}
	//2) Выделяем память под массив
	Human** group = new Human * [n] {};
	
	//3) Возвращаемся в начало файла,для того чтобы прочитать строки
	// и загрузить их в объекты
	fin.clear();
	fin.seekg(0);
	//cout << fin.tellg() << endl;

	//4) Загружаем объекты из файла
	if (fin.is_open())
	{
		std::string type;
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, type, ':');
			//cout << buffer << endl;
			group[i] = HumanFactory(type);
			fin >> *group[i];
		}
	}

	return group;
}

//#define INHERITANCE 

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human human("Montana", "Antonio", 25);
	human.print();
	cout << delimiter << endl;

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "ww_220", 90, 95);
	stud.print();
	cout << delimiter << endl;

	Teacher professor("White", "Walter", 50, "Chemistry", 20);
	professor.print();
	cout << delimiter << endl;
	Undergrad("Makhmudov", "Punkhan", 35, "Software developer", "PV_224", 95, 80, "OOP Polymorphism");
	grad.print();
#endif // INHERITANCE

	/*Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "ww_220", 90, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Undergrad("Makhmudov", "Punkhan", 35,"Software developer","PV_224",95,80,"OOP Polymorphism"),
		new Student("Vercetti","Tomas",30,"Criminalistica","Vice",98,99),
		new Teacher("Diaz","Ricardo",50,"Weapons distribution",15),
		new Teacher("Einstein","Albert",143,"Astronomy",120)
	};*/
	// Specialisation - Уточнение (DownCast - преобразование сверху вниз)
	/*for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		cout << *group[i] << endl;
		cout << delimiter << endl;
	}*/
	//print(group, sizeof(group) / sizeof(group[0]));
	//save(group, sizeof(group) / sizeof(group[0]), "group.txt");
	
	int n = 0;
	Human** group = load("group.txt", n);
	print(group, n);

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
	
}