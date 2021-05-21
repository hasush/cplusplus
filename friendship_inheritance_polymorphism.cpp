#include <iostream>

class Square;

// Friend function.
class Rectangle
{
    private:
        int width, height;
    public:
        // Rectangle ();
        Rectangle () : width(0), height(0) {}
        Rectangle (int w, int h) : width(w), height(h) {}
        int area() {return width*height;}
        friend Rectangle duplicate (const Rectangle&);
        void convert(Square square);
};

// Rectangle::Rectangle()
// {
//     width=0;
//     height=0;
// }

Rectangle duplicate(const Rectangle& param)
{
    Rectangle rect;
    rect.width=param.width;
    rect.height=param.height;
    return rect;
}

// Friend classes.
class Square
{
    friend class Rectangle;
    private:
        int side;
    public:
        Square () : side(0) {}
        Square (int s) : side(s) {}
};

void Rectangle::convert(Square square)
{
    width=square.side;
    height=square.side;
}

// Inheritance between classes.
class Polygon
{
    protected:
        int width,height;
    public:
        Polygon(int w, int h) : width(w), height(h) {}
        void set_values(int w, int h)
        {
            width=w;
            height=h;
        }
        int get_width()
        {
            int width_copy=width;
            return width_copy;
        }
        int get_height()
        {
            int height_copy=height;
            return height_copy;
        };
        // virtual float area() {return 0;}
        virtual float area()=0; // Pure virtual functions makes Polygon abstract base class.
        void printArea()
        {
            std::cout<<this->area()<<std::endl;
        }
};

class Output
{
    public:
        void print_something()
        {
            std::cout<<"something"<<std::endl;
        }
            
};

class Rectangle2 : public Polygon, public Output
{
    public:
        using Polygon::Polygon;
        float area()
        {
            return width*height;
        }
};

class Triangle : public Polygon
{
    public:
        using Polygon::Polygon;
        float area()
        {
            return 0.5*width*height;
        }
};

int main(void)
{
    // Friendship functions and classes.
    Rectangle rect_simple;
    Rectangle rect(5,6);
    Rectangle rect_duplicate = duplicate(rect);
    std::cout<<rect_simple.area()<<std::endl;
    std::cout<<rect_duplicate.area()<<std::endl;
    Square square(5); 
    rect_simple.convert(square);
    std::cout<<rect_simple.area()<<std::endl;
    std::cout<<std::endl;
    
    // Inheritance.
    // If Polygon is abstract base class then can not initialize.
    // Classes that contain atleast one pure virtual function is an abstract base class.
    // Polygon polygon(3,5); 
    Rectangle2 rect2(3,5);
    Triangle triangle(3,5);
    std::cout<<rect2.area()<<std::endl;
    std::cout<<triangle.area()<<std::endl;
    rect2.set_values(4,6);
    triangle.set_values(4,6);
    std::cout<<rect2.area()<<std::endl;
    std::cout<<triangle.area()<<std::endl;
    rect2.print_something();

    // Polymorphism: pointer to a derived base class is type-compatible with a pointer to its base class.
    Polygon* poly_rect;
    Polygon* poly_triangle;
    poly_rect = &rect2;
    poly_triangle = &triangle;
    poly_rect->set_values(100,100);
    poly_triangle->set_values(100,100);
    // std::cout<<poly_rect->area()<<std::endl; // Throws error as Polygon doesn't have area() method. Unless area has been defined as virtual.
    // std::cout<<poly_triangle->area()<<std::endl; // Throws error as Polygon doesn't have area() method. Unless area has been defined as virtual.
    std::cout<<rect2.area()<<std::endl;
    std::cout<<triangle.area()<<std::endl;

    // Virtual members.
    std::cout<<poly_rect->area()<<std::endl; // Throws error as Polygon doesn't have area() method. Unless area has been defined as virtual.
    std::cout<<poly_triangle->area()<<std::endl; // Throws error as Polygon doesn't have area() method. Unless area has been defined as virtual.
    std::cout<<"asdf"<<std::endl;
    poly_rect->printArea();
    poly_triangle->printArea();

    Polygon* poly1 = new Rectangle2(100,100);
    Polygon* poly2 = new Triangle(100,100);
    delete poly1;
    delete poly2; 

    return 0;
}