#include <iostream>
#include <sstream>
#include <string>
#define PI 3.1415926
//using namespace std;

void switch_a(int a);
void duplicate(int& a, int&b);
void duplicate_no(int a, int b);

template <class U>
U sum(U a, U b)
{
    return a+b;
}

std::string concat(const std::string& string1, const std::string& string2)
{
    return string1+" "+string2;
}

template <class T, int N>
T fixed_multiply(T a)
{
    return a*N;
}

namespace myNamespace
{
    int x = 5;
    int y;
}

void incrementNameSpaceVar()
{
    myNamespace::x++;
}

void inspectArray(int* myArray, int n)
{
    for(int i=0;i<n;++i)
    {
        std::cout<<myArray[i]<<std::endl;
    }
}

int main()
{
    int a;
    decltype(a) b;
    a=5;
    b=10;
    auto c=a+b;
    const float pi = PI;
    std::cout << "Hello " << c << " " << pi << std::endl;
    bool asdf = b==10 ? true : false;
    std::cout << asdf << std::endl;
    a = (b=3, b+2);
    std::cout << a << std::endl;
    std::string mystr = "1234";
    int myint;
    std::stringstream(mystr) >> myint;
    int asdf1 = myint;
    std::cout << asdf1 << std::endl;

    if (a > 0)
    {
        std::cout<<"greater than zero"<<std::endl;
    }
    else if (a < 0)
    {
        std::cout<<"baoooo"<<std::endl;
    }
    else
    {
        std::cout<<"asdfasdfasdf"<<std::endl;
    }

    for (auto c: mystr)
    {
        std::cout<<c<<std::endl;
    }

    a=10;
    switch_a(a);
    a=2;
    switch_a(a);
    a=1;
    switch_a(a);
    
    a=5;
    b=10;
    duplicate(a,b);
    std::cout << "duplicate " << a << " " << b << std::endl;
    duplicate_no(a,b);
    std::cout << "duplicate no " << a << " " << b << std::endl;

    std::string string1="hello my lady";
    std::string string2="hello my darling";
    std::cout << concat(string1, string2) << std::endl;
    std::cout << sum(a, b) << std::endl;
    int af=5.0;
    int bf=10.0;
    std::cout << sum(af, bf) << std::endl;

    std::cout << fixed_multiply<float,10>(5.0) << std::endl;

    int asdf10;
    std::cout << asdf10 << std::endl;
    std::cout << myNamespace::y << std::endl;
    std::cout << myNamespace::x << std::endl;
    incrementNameSpaceVar();
    std::cout << myNamespace::x << std::endl;

    int myArray[] = {1,2,3,4};
    inspectArray(myArray, 4);
    return 0;
}

void duplicate(int& a, int&b)
{
    a*=2;
    b*=2;
}

void duplicate_no(int a, int b)
{
    a*=2;
    b*=2;
}
void switch_a(int a)
{
    switch(a)
    {
        case 1:
            std::cout<<"case 1"<<std::endl;
            break;
        case 2:
            std::cout<<"case 2"<<std::endl;
            break;
        default:
            std::cout<<"default"<<std::endl;
    }
}
