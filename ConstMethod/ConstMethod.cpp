
#include <iostream>
class Account
{
private:
    double sum;
    const double rate;
public:
    Account(double _rate, double _sum) :rate{ _rate }
    {
        sum = _sum;
    }
    double get_rate()
    {
        std::cout << "non_const\n";
        return rate;;
    }
    double get_rate() const
    {
        std::cout << "const\n";
        return rate;
    }
};
class Fraction
{
    int numerator;
    int denumerator;
public:
    Fraction(int _numerator, int _denumerator)
        :numerator{ _numerator }, denumerator{ _denumerator } 
    {
        int common = nod(_numerator, _denumerator);
        numerator /= common;
        denumerator /= common;
    
    }
    Fraction() :Fraction(1, 1) {}
    int nod(int n, int m)
    {
        if (n % m == 0)
            return m;
        return nod(m, n % m);
    }
    explicit Fraction(int _numerator) :numerator{ _numerator }, denumerator{ 1 } {}
    void Print() const
    {
        printf("%d / %d\n", numerator, denumerator);
    }
    //Fraction operator+(Fraction& obj2)
    //{
    //    return  Fraction(this->numerator * obj2.denumerator 
    //        + obj2.numerator*this->denumerator
    //        , this->denumerator* obj2.denumerator);
    //}
    Fraction operator+(int number) 
    {
        return Fraction(this->numerator + number * this->denumerator
            , this->denumerator);
    }
    int friend getNumerator(const Fraction & obj);//Дружественная функция
    Fraction friend operator+(int number, const Fraction& obj);
    Fraction friend operator-(int number, const Fraction& obj);
    Fraction friend operator+ (const Fraction& obj1, const Fraction& obj2);//Дружественная функция
    bool friend operator==(const Fraction& obj1, const Fraction& obj2);
    bool friend operator!=(const Fraction& obj1, const Fraction& obj2);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& obj);
};
int getNumerator(const Fraction& obj)
{
    return obj.numerator;
}
Fraction operator+(int number, const Fraction& obj)
{
    return Fraction(obj.numerator + number * obj.denumerator
        , obj.denumerator);
}
Fraction operator-(int number, const Fraction& obj)
{
    return Fraction(number * obj.denumerator - obj.numerator
        , obj.denumerator);
}
Fraction operator+(const Fraction& obj1, const Fraction& obj2)
{
        return  Fraction(obj1.numerator * obj2.denumerator 
        + obj2.numerator*obj1.denumerator
        , obj1.denumerator* obj2.denumerator);
}

bool operator==(const Fraction& obj1, const Fraction& obj2)
{
    return obj1.numerator * obj2.denumerator == obj2.numerator * obj1.denumerator;
}

bool operator!=(const Fraction& obj1, const Fraction& obj2)
{
    return !(obj1==obj2);
}

std::ostream& operator<<(std::ostream& out, const Fraction& obj)
{
    return std::cout << "Drob " << obj.numerator << "/" << obj.denumerator << "\n";
}



void PrintFraction(const Fraction& obj) 
{
    obj.Print();
}

class Point 
{
    int x;
    int y;
public:
    Point(int _x, int _y);
    Point& operator++();
    void Print();
    Point& operator--();
    Point& operator++(int);
    Point& operator--(int);
 
    
};

int main()
{
    //Account ac(10, 20);
    //std::cout << ac.get_rate();
    Fraction f1{1,2};
    //f.Print();
    PrintFraction(f1);
    //PrintFraction(10);
    Fraction f2{ 1,2 };
    //f.Print();
    PrintFraction(f2);
    Fraction f3 = f2 + f1;
    f3.Print();
    f3 = f3 + 1;
    f3 = 2 - f3;
    f3.Print();
    Point p(1, 5);
    p.Print();
    (++p).Print();
    std::cout <<(f1 == f2);
    std::cout << f1;

}

Point::Point(int _x, int _y)
{
    x = _x;
    y = _y;

}

Point& Point::operator++()
{
    ++x; ++y; return *this;
}

void Point::Print()
{
    printf("X: %d, Y: %d\n", x, y);
}

Point& Point::operator--()
{
    --x; --y; return *this;
}

Point& Point::operator++(int)
{
    Point *point = new Point(x, y);
    ++(*this);
    return *point;
}

Point& Point::operator--(int)
{
    Point * point = new Point(x, y);
    --(*this);
    return *point;
   
}
