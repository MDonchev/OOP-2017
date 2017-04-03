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

//---------------------------------------------------------------------------------------

    void print()
    {
        cout<<getName()<<"  "<<getPrice()<<"  "<<getQuality()<<endl;
    }
};



class Becycle{

char* brand;
CyclePart* parts;
int _size;
int _count;
double _price;


public:
    Becycle()
    {
        setBrand("");
        _size=1;
        _count=0;
        _price=0;
        parts=new CyclePart[_size];
    }
    Becycle(char* _brand)
    {
        setBrand(_brand);
        _size=1;
        _count=0;
        _price=0;
        parts=new CyclePart[_size];
    }
    Becycle(const Becycle& other)
    {
        setBrand(other.brand);
        _size=other._size;
        _count=other._count;
        _price=other._price;
        for(int i=0;i<other._count;i++)
            addPart(other.parts[i]);
    }
    Becycle& operator=(const Becycle& other)
    {
        if(this==&other)
        {
        setBrand(other.brand);
        _size=other._size;
        _count=other._count;
        _price=other._price;
        for(int i=0;i<other._count;i++)
            addPart(other.parts[i]);
        }
        return *this;
    }
    ~Becycle()
    {
        delete brand;
        delete parts;
    }



//---------------------------------------------------------------------------------------


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

    bmx.addPart(one);
    bmx.addPart(two);
    bmx.addPart(three);
    bmx.print();

    return 0;
}
