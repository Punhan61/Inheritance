#include<iostream>
#include<string>
using namespace std;

#define delimiter "\n-------------------------------------------------------\n"
#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name,first_name,age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	// Constructor
	Human(HUMAN_TAKE_PARAMETERS) :
		last_name(last_name), first_name(first_name), age(age)
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
		cout << last_name << " " << first_name << " " << age << " лет.\n";
	}
};

#define STUDENT_TAKE_PARAMETERS const std::string& specialty, const std::string& group, double rating, double attendence
#define STUDENT_GIVE_PARAMETERS specialty, group, rating, attendence

class Student :public Human
{
	std::string specialty;
	std::string group;
	double rating;
	double attendence;
public:
	const std::string& get_specialty()const
	{
		return specialty;
	}
	const std::string& get_group()const
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
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const std::string& group)
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

	// Constructor

	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
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
	std::string specialty;
	unsigned int experiance;
public:
	const std::string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experiance()const
	{
		return experiance;
	}
	void set_specialty(const std::string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experiance(unsigned int experiance)
	{
		this->experiance = experiance;
	}

	//Constructors
	Teacher(HUMAN_TAKE_PARAMETERS, const std::string& specialty, unsigned int experiance) :
		Human(HUMAN_GIVE_PARAMETERS)
	{
		set_specialty(specialty);
		set_experiance(experiance);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;;
	}

	//Methods
	void print()
	{
		Human::print();
		cout << specialty << " " << experiance << endl;
	}
};

class Undergrad :public Student
{
	std::string& topic;
public:
	const std::string& get_topic()const
	{
		return topic;
	}
	void set_topic(const std::string& topic)
	{
		this->topic = topic;
	}

	// Constructor
	Undergrad(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& topic) :
		Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		set_topic(topic);
		cout << "GConstructor:\t" << this << endl;
	}
	~Undergrad()
	{
		cout << "GDestructor:\t" << this << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human human("Montana", "Antonio", 25);
	human.print();
	cout << delimiter << endl;
	Student stud("Pincman", "Jessie", 25, "Chimestry", "ww_220", 90, 95);
	stud.print();
	cout << delimiter << endl;
	Teacher professor("White", "Walter", 50, "Chemistry", 20);
	professor.print();


}