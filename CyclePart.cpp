#include<iostream>
#include<cstring>

using namespace std;
enum Quality
{
    Low =1, Medium , High

};
class CyclePart
{
    char* name;
    double price;
    Quality quality;
public:

//---------------------------------------------------------------------------------------
    void print() const
    {
        cout<<name<<" "<<price<<" "<<quality<<endl;
    }
    CyclePart():name(NULL)
    {
        setName("");
        setPrice(0);
        setQuality(Quality::Low);
    }

    CyclePart(char* _name,double _price,Quality _quality):name(NULL)
    {
        setName(_name);
        setPrice(_price);
        setQuality(_quality);
    }

    CyclePart(const CyclePart& other):name(NULL)
    {
        setName(other.name);
        setPrice(other.price);
        setQuality(other.quality);

    }
    CyclePart& operator=(const CyclePart& other)
    {
        if(this!=&other)
        {
          setName(other.name);
          setPrice(other.price);
          setQuality(other.quality);
        }
        return *this;
    }
    ~CyclePart()
    {
        delete name;
    }

//---------------------------------------------------------------------------------------

    void setName(char* _name)
    {
        delete name;
        name = new char[strlen(_name)+1];
        strcpy(name,_name);
    }
    void setPrice(double _price)
    {
        price=_price;
    }
    void setQuality(Quality _quality)
    {
        quality=_quality;
    }

//---------------------------------------------------------------------------------------

    char* getName()
    {
        return name;
    }
    double getPrice()
    {
        return price;
    }
    Quality getQuality()
    {
        return quality;
    }
    bool operator==(CyclePart& other)
    {
        return strcmp(name,other.getName()) == 0 && price == other.getPrice() && quality == other.getQuality();
    }
//---------------------------------------------------------------------------------------

    void print()
    {
        cout<<getName()<<"  "<<getPrice()<<"  "<<getQuality()<<endl;
    }
};



class Becycle
{

    char* brand;
    CyclePart* parts;
    int _size;
    int _count;
    double _price;
    void addPart(CyclePart part)
    {
        if(_count==_size)
        {
          _size*=2;
          CyclePart* buffer = new CyclePart[_size];
          for(int i=0;i<_count;i++)
            buffer[i]=parts[i];

          delete[] parts;
          parts=buffer;
        }
        parts[_count] = part;
        _count++;
        _price+=part.getPrice();
    }
    void remPart(CyclePart& part)
    {
        for (int i=0; i<_count; i++)
        {
            if (parts[i] == part)
            {
                for (int j = i+1; j<_count; j++)
                {
                    parts[j-1] = parts[j];
                }
                _count--;
                _price -= parts[i].getPrice();
            }
        }
    }
    int countHighQuality()
    {
        int counter = 0;
        for (int i=0;i<_count;i++)
        {
            if(parts[i].getQuality() == Quality::High)
                counter++;
        }
    }
public:
    Becycle(): brand(NULL)
    {
        setBrand("");
        _size=1;
        _count=0;
        _price=0;
        parts=new CyclePart[_size];
    }
    Becycle(char* _brand): brand(NULL)
    {
        setBrand(_brand);
        _size=1;
        _count=0;
        _price=0;
        parts=new CyclePart[_size];
    }
    Becycle(const Becycle& other): brand(NULL), parts(NULL)
    {
        setBrand(other.brand);
        _size=other._size;
        _count=other._count;
        _price=other._price;
        delete[] parts;
        parts = new CyclePart [_size];
        for(int i=0;i<_count;i++)
            parts[i] = other.parts[i];
    }
    Becycle& operator=(const Becycle& other)
    {
        if(this==&other)
        {
        setBrand(other.brand);
        _size=other._size;
        _count=other._count;
        _price=other._price;
        delete[] parts;
        parts = new CyclePart [_size];
        for(int i=0;i<_count;i++)
            parts[i] = other.parts[i];
        }
        return *this;
    }
    ~Becycle()
    {
        delete brand;
        delete parts;
    }



//--------------------------------------------------------------------------------------

    void print()
    {
        cout<<brand<<"  ("<<_count<<"/"<<_size<<") "<<getPrice()<<endl;
         for(int i=0;i<_count;i++)
            parts[i].print();

    }
    double getPrice()
    {
        return _price*1.5;
    }

    Becycle& operator+(const CyclePart& part)
    {
        addPart(part);
        return *this;
    }
    Becycle& operator-(CyclePart& part)
    {
        remPart(part);
        return *this;
    }
    //is the brand same??
    bool operator==(const Becycle& other)
    {
        return strcmp(brand,other.brand)==0;
    }
    //is the price not equal
    bool operator!=(Becycle& other)
    {
        return !(getPrice() == other.getPrice());
    }
    bool operator<(Becycle& other)
    {
        return countHighQuality() < other.countHighQuality();
    }
    bool operator<=(Becycle& other)
    {
        return countHighQuality() <= other.countHighQuality();
    }
    bool operator>(Becycle& other)
    {
        return countHighQuality() > other.countHighQuality();
    }
    bool operator>=(Becycle& other)
    {
        return countHighQuality() >= other.countHighQuality();
    }
    CyclePart* operator[](const char* name)
    {
        for (int i=0;i<_count;i++)
        {
            if( strcmp(name,parts[i].getName()) == 0)
                return parts + i;
        }
        return NULL;
    }
//---------------------------------------------------------------------------------------
    void setBrand(char* _brand)
    {
        delete brand;
        brand = new char[strlen(_brand)+1];
        strcpy(brand,_brand);
    }

};

int main()
{
    CyclePart one("light",6,Quality::Medium);
    CyclePart two("tier",20,Quality::High);
    CyclePart three("seat",5,Quality::Low);

    Becycle bmx("bmx");
    Becycle bmx1("bmx");
    bmx1+one;
    bmx1+two;
    bmx1+two;
    bmx1+two;
    bmx1+two;

    bmx+one;
    bmx+two;
    bmx+three;
    bmx+one;
    bmx+two;
    bmx+one;
    bmx.print();
    bmx - one;
    bmx.print();
    bmx+two;
    bmx+two;
    bmx.print();
    std::cout<<(bmx == bmx1)<<std::endl;
    std::cout<<(bmx != bmx1)<<std::endl;
    std::cout<<(bmx <= bmx1)<<std::endl;
    const char* fName = "tier"; // test for operator[]
    if (bmx[fName])
        bmx[fName]->print() ;
    else
        std::cout<<"No such part"<<std::endl;
    return 0;
}
