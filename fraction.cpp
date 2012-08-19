#include "fraction.h"

void getToken(char token[100], char c, int &size);

Fraction::Fraction()
{
    mixed = 0;
    num = 0;
    denom = 1;
    reduce();
}

Fraction::Fraction(int whole)
{
    mixed = 0;
    num = whole;
    denom = 1;
    reduce();
}

Fraction::Fraction(int top, int bottom)
{
    mixed = 0;
    num = top;
    denom = bottom;
    reduce();
}

Fraction::Fraction(int whole, int top, int bottom)
{
    mixed = 0;
    num = whole * bottom + top;
    denom = bottom;
    reduce();
}

Fraction::Fraction(const Fraction& fraction) //copy constructor
{
    copy(fraction);
}

Fraction::~Fraction()
{

}

Fraction& Fraction::operator=(Fraction &other)
{
    if(this == &other)
        return other;
    copy(other);
    return *this;
}

Fraction& Fraction::operator=(Fraction other)
{
    if(this == &other)
        return other;
    copy(other);
    return *this;
}

ostream& operator<<(ostream &out, const Fraction &x)
{
    if(x.denom == 0)
        out << "INFINITY";
    else if(x.denom == 1)
        out << x.num;
    else if(abs(x.num) > x.denom)
        out << x.num/x.denom << " " << x.num%x.denom << "/" << x.denom;
    else if(x.num)
        out << x.num << "/" << x.denom;
    else
        out << "0";
    return out;
}

istream& operator>>(istream &in, Fraction &x)
{
    bool error = false, isNegative = false;
    char token[100];
    int size = 0, number;
    char c;
    in.get(c);
    if(c == '-')
    {
        isNegative = true;
        in.get(c);
    }
    if(isdigit(c))
    {
        while(isdigit(c))
        {
            getToken(token, c, size);
            cin.get(c);
        }
        token[size] = '\0';
        number = atoi(token);
        if(isNegative)
            number = -number;
    }
    else
        error = true;

    if(!error)
    {
        /*
        if(c == '\n')
        {
            x.mixed = 0;
            x.num = number;
            x.denom = 1;
        }
        */
        if(c == '/')
        {
            x.mixed = 0;
            x.num = number;
            in >> x.denom;
            x.reduce();
        }
        else if(c == ' ')
        {
            x.mixed = number;
            char slash;
            in >> x.num >> slash >> x.denom;
            x.num = x.mixed * x.denom + x.num;
            x.reduce();
        }
        else
            error = true;
    }
    if(error)
        cout << "Invalid input." << endl;
    return in;
}

Fraction operator+(const Fraction &x, const Fraction &y)
{
    Fraction answer;
    answer.num = x.num * y.denom + y.num * x.denom;
    answer.denom = x.denom * y.denom;
    answer.reduce();
    return answer;
}

Fraction operator-(const Fraction &x, const Fraction &y)
{
    Fraction answer;
    answer.num = x.num * y.denom - y.num * x.denom;
    answer.denom = x.denom * y.denom;
    answer.reduce();
    return answer;
}

Fraction operator*(const Fraction &x, const Fraction &y)
{
    Fraction answer;
    answer.num = x.num * y.num;
    answer.denom = x.denom * y.denom;
    answer.reduce();
    return answer;
}

Fraction operator/(const Fraction &x, const Fraction &y)
{
    Fraction answer;
    answer.num = x.num * y.denom;
    answer.denom = x.denom * y.num;
    answer.reduce();
    return answer;
}

bool operator>(const Fraction &x, const Fraction &y)
{
    return (x.num*y.denom > x.denom*y.num);
}

bool operator<(const Fraction &x, const Fraction &y)
{
    return (x.num*y.denom < x.denom*y.num);
}

bool operator>=(const Fraction &x, const Fraction &y)
{
    return (x.num*y.denom >= x.denom*y.num);
}

bool operator<=(const Fraction &x, const Fraction &y)
{
    return (x.num*y.denom <= x.denom*y.num);
}

bool operator==(const Fraction &x, const Fraction &y)
{
    return (x.num*y.denom == x.denom*y.num);
}

bool operator!=(const Fraction &x, const Fraction &y)
{
    return (x.num*y.denom != x.denom*y.num);
}

//private functions
void Fraction::reduce()
{
    if(denom)
    {
        int div = gcd(num,denom);
        num /= div;
        denom /= div;
    }
}

int Fraction::gcd(int p, int q)
{
    return (q == 0) ? abs(p) : gcd(q, p%q);
}

void Fraction::copy(const Fraction &other)
{
    num = other.num;
    denom = other.denom;
}
//other function
void getToken(char token[100], char c, int &size)
{
    token[size] = c;
    size++;
}
