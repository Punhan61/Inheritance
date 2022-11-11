#include<iostream>
using namespace std;

#define delimiter "\n--------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const string& last_name, const string& first_name,unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name,first_name,age

class Human
{
	string last_name;
	string first_name;
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
	Human(HUMAN_TAKE_PARAMETERS) :
		last_name(last_name), first_name(first_name), age(age)
	{
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	// Methods
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет\n";
	}
};

ostream& operator<<(ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << " y.o";
}

#define STUDENT_TAKE_PARAMETERS const string& specialty, const string& group, double rating, double attendence
#define STUDENT_GIVE_PARAMETERS specialty,group,rating,attendence

class Student :public Human
{
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

	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(last_name, first_name, age)
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
	void print()const
	{
		Human::print();
		cout << specialty << " " << group << " " << rating << " " << attendence << endl;
	}

};

ostream& operator<<(ostream& os, const Student& obj)
{
	return os << obj.get_specialty() << " " << obj.get_group() << " " << obj.get_rating() << " " << obj.get_attendence();
}

class Teacher :public Human
{
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
	void set_experience(unsigned int axperience)
	{
		this->experience = experience;
	}

	//Constructors

	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		this->experience = experience;
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	// Methods

	void print()const
	{
		Human::print();
		cout << specialty << " " << experience << endl;
	}
};

ostream& operator<<(ostream& os, const Teacher& obj)
{
	return os << obj.get_specialty() << " " << obj.get_experiance();
}

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
	Undergrad(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const string& topic) :
		Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_topic(topic);
		cout << "GConstructor:\t" << this << endl;
	}
	~Undergrad()
	{
		cout << "DDestructor:\t" << this << endl;
	}

	// Methods
	void print()const
	{
		Student::print();
		cout << "Тема дипломной работы: " << topic << endl;
	}
};

ostream& operator<<(ostream& os, const Undergrad& obj)
{
	return os << obj.get_topic();
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

	// Generalisation(UpCast - преобразование снизу вверх)
	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "ww_220", 90, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Undergrad("Makhmudov", "Punkhan", 35,"Software developer","PV_224",95,80,"OOP Polymorphism"),
		new Student("Vercetti","Tomas",30,"Criminalistica","Vice",98,99),
		new Teacher("Diaz","Ricardo",50,"Weapons distribution",15),
		new Teacher("Einstein","Albert",143,"Astronomy",120)
	};

	// Specialisation - Уточнение (DowsCast - преобразование сверху вниз)
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		//group[i]->print();
		//cout << *group[i] << endl;
		cout << typeid(*group[i]).name() << endl;
		if (typeid(*group[i]) == typeid(Student))cout << *dynamic_cast<Student*>(group[i]);
		if (typeid(*group[i]) == typeid(Undergrad))cout << *dynamic_cast<Undergrad*>(group[i]);
		if(typeid(*group[i])==typeid(Teacher))cout<<*dynamic_cast<Teacher*>(group[i]);
		cout << delimiter << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}