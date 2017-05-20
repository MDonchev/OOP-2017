#include <iostream>
#include <cstring>

using namespace std;


class Date
{
    public:
        Date(int _day, int _month, int _year): day(1), month(1), year(1900)
        {
            this->setDate(_day,_month,_year);
        }
        void setDate(int _day,int _month,int _year)
        {
            if (isValidDate(_day,_month,_year))
            {
                day = _day;
                month = _month;
                year = _year;
            }
        }
        Date(const Date& other) : day(other.getDay()), month(other.getMonth()), year(other.getYear()) {}

        int getDay() const
        {
            return day;
        }
        int getMonth() const
        {
            return month;
        }
        int getYear() const
        {
            return year;
        }


        void print() const
        {
            cout<< day<<"."<<month<<"."<<year<<" ";
        }

    private:
        int day;
        int month;
        int year;
        bool isValidDate(int _day,int _month,int _year)
        {
            if (_year < 1900) return false;
            if (_month < 1 || _month > 12) return false;

            int maxDays;
            bool isLeap = (_year % 400 == 0) || (_year % 100 !=0 && _year % 4 == 0);
            switch(_month)
            {
                case 2: maxDays = 28 + isLeap; break;
                case 4: case 6: case 9: case 11: maxDays = 30; break;
                default: maxDays = 31;
            }
            if (_day < 1 || _day>maxDays) return false;

            return true;
        }
};
class Person
{
    protected:
        char* name;
        char* town;
        Date birthDate;
    public:
        Person(const char* = "", const Date& = Date(1,1,2000), const char* = "");
        Person(const Person&);
        Person& operator= (const Person&);
        ~Person();

        void setName(const char*);
        void setTown(const char*);
        const char* getName() const
        {
            return this->name;
        }
        const char* getTown() const
        {
            return this->town;
        }
        Date getDate() const
        {
            return this->birthDate;
        }

        void print() const;
};
Person::Person(const char* _name, const Date& bd, const char* _town): name(NULL), town(NULL), birthDate(bd)
{
    setName(_name);
    setTown(_town);
}
void Person::setName(const char* _nam)
{
    if (!_nam) return;
    delete[] name;
    this->name = new char [strlen(_nam) + 1];
    strcpy(this->name, _nam);
}
void Person::setTown(const char* _town)
{
    if (!_town) return;
    delete[] town;
    this->town = new char [strlen(_town) + 1];
    strcpy(this->town, _town);
}
Person::Person(const Person& other) : name(NULL), town(NULL), birthDate(other.getDate())
{
    setName(other.getName());
    setTown(other.getTown());
}
Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        this->setName(other.getName());
        this->setTown(other.getTown());
        this->birthDate = other.getDate();
    }
    return *this;
}
Person::~Person()
{
    delete[] name;
    delete[] town;
}
void Person::print() const
{
    cout<<name<<" "<<town<<" ";
    birthDate.print();
}

class Student : public Person
{
    private:
        char* faculty;
        double mark;
    public:
        Student(const char* _name, const Date& _date, const char* _town, const char* _fac, double _mark)
            :Person(_name,_date,_town), mark(_mark), faculty(NULL)
             {
                 setFac(_fac);
             }
        void setFac(const char* fac)
        {
            if (!fac) return;
            delete[] faculty;
            faculty = new char[strlen(fac) + 1];
            strcpy(faculty,fac);
        }
        Student(const Student& other) : Person(other) , faculty(NULL)
        {
            setFac(other.faculty);
            mark = other.mark;
        }
        Student& operator=(const Student& other)
        {
            if (this != &other)
            {
                Person::operator=(other);
                setFac(other.faculty);
                mark = other.mark;
            }
            return *this;
        }
        void print() const
        {
            Person::print();
            cout<<faculty<<" "<<mark<<endl;
        }
};
int main()
{
    Date dt(3,6,2001);
    Date dt1(19,5,1997);
    Person p1("Filip", dt, "Plovdiv");
    p1.print();
    cout<<endl;
    Student s("Stoian", dt1, "Varna", "FMI", 4.50);
    s.print();
    return 0;
}
