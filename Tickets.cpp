#include <iostream>
#include <cstring>


enum Type {NORMAL, GROUP, STUDENT};
class Ticket
{
    private:
        char* title;
        double price;

    protected:
        void setTitle(const char*);
        void setPrice(double);
    public:
        Ticket(const char* = "", double = 0.0);
        Ticket(const Ticket&);
        Ticket& operator=(const Ticket&);
        virtual ~Ticket();

        virtual double getPrice() const;
        virtual Type getType() const;


        const char* getTitle() const
        {
            return this->title;
        }
};
void Ticket::setTitle(const char* _name)
{
    if(!_name) return;
    delete[] title;
    this->title = new char [strlen(_name) + 1];
    strcpy(this->title, _name);
}
void Ticket::setPrice(double _price)
{
    this->price = (_price < 0) ? 0.0 : _price;
}
Ticket::Ticket(const char* _name, double _price): title(NULL)
{
    setTitle(_name);
    setPrice(_price);
}
Ticket::Ticket(const Ticket& other): title(NULL)
{
    setTitle(other.getTitle());
    setPrice(other.getPrice());
}
Ticket& Ticket::operator= (const Ticket& other)
{
    if (this != &other)
    {
        setTitle(other.getTitle());
        setPrice(other.getPrice());
    }
    return *this;
}
Ticket::~Ticket()
{
    delete[] title;
}
double Ticket::getPrice() const
{
    return this->price;
}
Type Ticket::getType() const
{
    return NORMAL;
}

/// Group Ticket

class GroupTicket : public Ticket
{
    public:
        GroupTicket(const char* = "", double = 0.0, int = 4);

        virtual double getPrice() const;
        virtual Type getType() const;

        int getCount() const;
    private:
        int count;
};

GroupTicket::GroupTicket(const char* _title, double _price, int _count) : Ticket(_title,_price)
{
    this->count = (_count < 4) ? 4 : _count;
}
double GroupTicket::getPrice() const
{
    return 0.9*(this->count * Ticket::getPrice());
}
Type GroupTicket::getType() const
{
    return GROUP;
}
int GroupTicket::getCount() const
{
    return this->count;
}


///StudentTicket

class StudentTicket : public Ticket
{
    public:
        StudentTicket(const char* = "", double = 0.0, const char* = "");
        StudentTicket(const StudentTicket&);
        StudentTicket& operator= (const StudentTicket&);
        ~StudentTicket();

        const char* getName() const
        {
            return this->name;
        }

        virtual double getPrice() const;
        virtual Type getType() const;
    private:
        char* name;
        void setName(const char*);
};
void StudentTicket::setName(const char* _name)
{
    if (!_name) return;
    delete[] this->name;
    this->name = new char [strlen(_name) + 1];
    strcpy(this->name, _name);
}
StudentTicket::StudentTicket(const char* _title, double _price, const char* _name) : Ticket(_title,_price), name(NULL)
{
    setName(_name);
}
StudentTicket::StudentTicket(const StudentTicket& other) : Ticket(other), name(NULL)
{
    setName(other.getName());
}
StudentTicket& StudentTicket::operator=(const StudentTicket& other)
{
    if (this != &other)
    {
        Ticket::operator=(other);
        setName(other.getName());
    }
    return *this;
}
StudentTicket::~StudentTicket()
{
    delete[] name;
}
double StudentTicket::getPrice() const
{
    return 0.5*Ticket::getPrice();
}
Type StudentTicket::getType() const
{
    return STUDENT;
}


/// sum of an array with all kind of tickets (Normal, Group, Student)
double getTotalPrice(Ticket** tickets, int n)
{
    double sum = 0;
    for (int i = 0 ;i<n; i++)
        sum+=tickets[i]->getPrice();

    return sum;
}
/// prints how many tickets are there by kind
void countByKind (Ticket** tickets, int n)
{
    const char* helpNames[] = {"Normal Tickets", "Group Tickets", "Student Tickets"};

    int countTickets[3] = {0};

    for (int i = 0; i < n; i++)
    {
        countTickets[tickets[i]->getType()]++; ///getType returns Type, where NORMAL -> 0 , GROUP -> 1, STUDENT -> 2
    }

    for (int i = 0; i < 3; i++)
    {
        std::cout<<helpNames[i]<<": "<<countTickets[i]<<std::endl;
    }
}

int main ()
{
    Ticket** soldTickets = new Ticket*[4];
    soldTickets[0] = new Ticket("Star Wars", 11);
    soldTickets[1] = new GroupTicket("Hobbit", 11, 12);
    soldTickets[2] = new StudentTicket("Star Wars", 11, "Gosho");
    soldTickets[3] = new Ticket("Hobbit", 11);


    std::cout<<"Total Price: "<<getTotalPrice(soldTickets, 4)<<std::endl;
    std::cout<<std::endl;


    std::cout<<"Count by type of tickets:"<<std::endl;
    countByKind(soldTickets,4);


    for (int i = 0; i<4 ;i++)
        delete soldTickets[i];
    delete[] soldTickets;

    return 0;
}

