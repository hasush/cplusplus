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
    Polygon polygon(3,5);
    Rectangle2 rect2(3,5);
    Triangle triangle(3,5);
    std::cout<<rect2.area()<<std::endl;
    std::cout<<triangle.area()<<std::endl;
    rect2.set_values(4,6);
    triangle.set_values(4,6);
    std::cout<<rect2.area()<<std::endl;
    std::cout<<triangle.area()<<std::endl;
    rect2.print_something();

    return 0;
}