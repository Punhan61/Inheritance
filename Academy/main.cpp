#include<iostream>
using namespace std;

#define delimitr "\n--------------------------------------------\n"

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
	Human(HUMAN_TAKE_PARAMETERS):
		last_name(last_name),first_name(first_name),age(age)
	{
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	// Methods
	void print()const
	{
		cout << last_name << " " << first_name << " " << age << " лет\n";
	}
};

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
	void print()const
	{
		Human::print();
		cout << specialty << " " << group << " " << rating << " " << attendence << endl;
	}

};

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

	void print()const
	{
		Human::print();
		cout << specialty << " " << experience << endl;
	}
};

#define GRADUATE_TAKE_PARAMETERS const string& specialty, const string& group, double graduate_work
#define GRADUATE_GIVE_PARAMETERS specialty,group,graduate_work

class Graduate :public Human
{
	string specialty;
	string group;
	double graduate_work;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_graduate_work()const
	{
		return graduate_work;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	double set_graduate_work(double graduate_work)
	{
		this->graduate_work = graduate_work;
	}

	// Constructors
	Graduate(HUMAN_TAKE_PARAMETERS, GRADUATE_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		this->specialty = specialty;
		this->group = group;
		this->graduate_work = graduate_work;
		cout << "DConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "DDestructor:\t" << this << endl;
	}

	// Methods
	void print()const
	{
		Human::print();
		cout << specialty << " " << group << " " << graduate_work << " points\n";
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human human("Montana", "Antonio", 25);
	human.print();
	cout << delimitr << endl;
	Student stud("Pinkman", "Jessie", 25, "Chemistry", "ww_220", 90, 95);
	stud.print();
	cout << delimitr << endl;
	Teacher professor("White", "Walter", 50, "Chemistry", 20);
	professor.print();
	cout << delimitr << endl;
	Graduate grad("Makhmudov", "Punkhan", 35, "Software developer", "PV_224", 100);
	grad.print();
}