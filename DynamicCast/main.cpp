#include<iostream>
using namespace std;

#define delimiter  "\n-----------------------------------------------------\n"

class Family
{
	string last_name;
	string first_name;
	string age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	const string& get_age()const
	{
		return age;
	}
	void get_last_name(string& last_name)
	{
		this->first_name = last_name;
	}
	// Constructor
	Family(const string& last_name,const string& first_name, const string& age)
	{
		this->last_name = last_name;
		this->first_name = first_name;
		this->age = age;
	}
	~Family()
	{

	}
	// Methods
	void print()const
	{
		cout << last_name << " " << first_name << " " << age<<" y.o" << endl;
	}
};

class Family_mambers:Family
{
	string family_mambers;
public:
	const string& get_family_mambers()const
	{
		return family_mambers;
	}
	
	void set_family_mambers(const string& family_mambers)
	{
		this->family_mambers = family_mambers;
	}
	
	// Constructor
	Family_mambers(const string& last_name, const string& first_name, const string& age,
		const string& family_mambers):Family(last_name,first_name,age)
	{
		set_family_mambers(family_mambers);
	}
	~Family_mambers()
	{

	}
	//Methods
	void print()const
	{
		Family::print();
		cout << family_mambers <<  endl;
	}
};

//#define FAMILY

void main()
{
	setlocale(LC_ALL, "");
#ifdef FAMILY
	Family data("Last name", "First name", "Age");
	data.print();
	cout << delimiter << endl;

	Family_mambers father("Makhmudov", "Punakhan", "35", "Father");
	father.print();
	cout << delimiter << endl;

	Family_mambers mather("Akhmedova", "Ulker", "32", "Mather");
	mather.print();
	cout << delimiter << endl;

	Family_mambers child_1("Makhmudov", "Timur", "10", "son");
	child_1.print();
	cout << delimiter << endl;

	Family_mambers child_2("Makhmudov", "Deniz", "3", "son");
	child_2.print();
#endif // FAMILY

	Family* group[] =
	{
		new Family("Makhmudov", "Punakhan", "35"),
		new Family_mambers("Makhmudov", "Punakhan", "35", "Father")
	};

}