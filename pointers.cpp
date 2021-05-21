#include <iostream>

void fill_array(int* value_array, int n)
{
    for(int i=0;i<n;++i)
    {
        value_array[i]=i;
    }
}

void print_all(const int* pointer, int n)
{
    for(int i=0;i<n;++i)
    {
        std::cout<<*pointer<<std::endl;
        pointer++;
        // *pointer=100; // Throws error because we can not change the contents of const int* pointer points to.
    }
}

struct product
{
    int weight;
    double price;
};

int main(void)
{   
    int n=10;
    int value=5;
    int value_array[n];
    int* pointer=&value;
    
    std::cout<<pointer<<std::endl;
    std::cout<<&value<<std::endl;
    std::cout<<*pointer<<std::endl;
    std::cout<<value<<std::endl;

    fill_array(value_array,n);
    for(int i=0;i<n;++i)
    {
        std::cout<<value_array[i]<<std::endl;
    }

    // Type pointed to p is const.
    int x;
    int y=10;
    const int *p=&y;
    x = *p;
    std::cout<<x<<std::endl;
    std::cout<<p<<std::endl;
    *p++;
    std::cout<<p<<std::endl;
    p=&x;
    x=20;
    std::cout<<p<<std::endl;
    std::cout<<&x<<std::endl;
    std::cout<<*p<<std::endl;
    std::cout<<x<<std::endl;
    // *p=x; // Throws error as we are modifying the content of what p points to.

    // int value_array2[]={1,2,3};
    // p=&value_array2;
    print_all(value_array, n);

    int asdf; // non const int
    int* p1=&asdf; // non const pointer pointing to non const int
    const int* p2=&asdf; //non const pointer pointing to const int 
    int const* p2b=&asdf; //non const pointer pointing to const int 
    int* const p3=&asdf; //const pointer pointing to non const int 
    const int* const p4=&asdf; //const pointer poniting to const int

    long N=10000000000000;
    float* foo = new (std::nothrow) float[N];
    if (foo==nullptr)
        std::cout<<"Not enough memory"<<std::endl;

    N=10000;
    foo = new (std::nothrow) float[N];
    if (foo==nullptr)
        std::cout<<"Not enough memory"<<std::endl;

    delete[] foo;

    product apples;
    apples.weight=10;
    apples.price=100.0;
    std::cout<<apples.price<<std::endl;
    product* apple_pointer=&apples;
    std::cout<<apple_pointer->price<<std::endl;

    enum colors_t {black, blue, green};
    colors_t myColor=blue;
    if (myColor==blue)
        myColor=green;
    std::cout<<myColor<<std::endl;

    enum class Colors {black,blue,green};
    Colors mycolor;
    mycolor=Colors::green;

    enum class EyeColor : char {brown, blue, green};

    return 0;
}