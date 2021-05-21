#include <iostream>
#include <vector>

class Rectangle
{
    private:
        int width, height;
    public:
        Rectangle();
        Rectangle(int,int);
        void set_values(int,int);
        void get_values(int*);
        int area(void);
};

Rectangle::Rectangle()
{
    width=0;
    height=0;
}

Rectangle::Rectangle(int a, int b)
{
    width=a;
    height=b;
}

void Rectangle::set_values(int a, int b)
{
    width=a;
    height=b;
}

void Rectangle::get_values(int * values)
{
    values[0]=width;
    values[1]=height;
}

int Rectangle::area(void)
{
    return width*height;
}

class Circle
{
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}
        double area()
        {
            return radius*radius*3.14159265;
        }
};

class Cylinder
{
    private:
        Circle base;
        double height;
    public:
        Cylinder(double r, double h) : base(r), height(h) {}
        double volume()
        {
            return base.area()*height;
        }
};

class CVector
{
    public:
        int x,y;
        CVector() {}
        CVector(int a, int b) : x(a), y(b) {}
        CVector operator+ (const CVector&);
        CVector& operator= (const CVector&);
        void set_values(int, int);
        void print_values();
};

CVector CVector::operator+ (const CVector& param)
{
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
}

CVector& CVector::operator= (const CVector& param)
{
    x=param.x;
    y=param.y;
    return *this;
}

void CVector::set_values(int a, int b)
{
    x=a;
    y=b;
    this->print_values();
}

void CVector::print_values()
{
    std::cout<<x<<" "<<y<<std::endl;
}

class CounterClass
{
    public:
        static int n;
        CounterClass () {n++;};
};

// CounterClass::CounterClass()
// {
//     CounterClass::n++;
// }

int CounterClass::n=0;

class MyClass1
{
    public:
        int x;
        MyClass1(int val) : x(val) {}
        int get() {return x;}
};

class MyClass2
{
    public:
        int x;
        MyClass2(int val) : x(val) {}
        int& get() {return x;}
};

class MyClass3
{
    // private:
    //     int x;
    public:
        int x;
        MyClass3(int val) : x(val) {}
        const int& get() const {return x;}
        int& get() {return x;}
};

template <class T>
class MyTemplateClass
{
    private:
        T values[2];
    public:
        MyTemplateClass (T first, T second)
        {
            values[0]=first;
            values[1]=second;
        }
        T getMax();
};

template <class T>
T MyTemplateClass<T>::getMax()
{
    return values[0]>values[1]? values[0] : values[1];
}

template <class T>
class mycontainer
{
    private:
        T element;
    public:
        mycontainer (T arg) {element=arg;}
        T increase () {return ++element;}
};

template <>
class mycontainer <char>
{
    private:
        char element;
    public:
        mycontainer (char arg) {element=arg;}
    char uppercase()
    {
        if ((element>='a')&&(element<='z'))
        {
            element+='A'-'a';
        }
        return element;
    }
};

int main(void)
{
    int* values = new int[2];
    Rectangle rect(2,10);
    std::cout<<rect.area()<<std::endl;
    rect.set_values(5,10);
    rect.get_values(values);
    std::cout<<values[0]<<std::endl;
    delete[] values;
    std::cout<<rect.area()<<std::endl;

    Cylinder cylinder(2, 5);
    std::cout<<cylinder.volume()<<std::endl;
    
    std::vector<int> foo;

    CVector a(1,2);
    CVector b(3,4);
    CVector c;
    c = a + b;
    std::cout<<c.x<<" "<<c.y<<std::endl;
    c.set_values(10,20);
    a=c;
    std::cout<<a.x<<" "<<a.y<<std::endl;

    
    CounterClass counter1;
    CounterClass counter2;
    CounterClass counter3;
    CounterClass counter4;
    std::cout<<CounterClass::n<<std::endl;

    MyClass1 myclass1(10);
    int myclass1_x;
    myclass1_x=myclass1.get();
    std::cout<<myclass1_x<<std::endl;
    myclass1_x=1000;
    std::cout<<myclass1_x<<std::endl;
    std::cout<<myclass1.get()<<std::endl;

    MyClass2 myclass2(10);
    int myclass2_x;
    myclass2.get()=20; //need return of int& to assign 20 to x
    std::cout<<myclass2.get()<<std::endl;

    MyTemplateClass<int> int_template_class(5,10);
    MyTemplateClass<float> float_template_class(5.255,10.99);
    std::cout<<int_template_class.getMax()<<std::endl;
    std::cout<<float_template_class.getMax()<<std::endl;

    mycontainer<int> myint(7);
    mycontainer<char> mychar('j');
    std::cout<<myint.increase()<<std::endl;
    std::cout<<mychar.uppercase()<<std::endl;


    return 0;
}