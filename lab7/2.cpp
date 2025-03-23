#include <iostream>
#include <string>
using namespace std;

class Shape{
	public:
	string position;
	string color;
	int borderthick;
	
	Shape(string p,string c, int bd):position(p),color(c),borderthick(bd){}
	
	virtual void draw() {
		cout<<"SHape class."<<endl;
	}
	
	virtual void calculatearea(){
			cout<<"SHape class."<<endl;
	}
	
	virtual void calculateperimeter()
	{
			cout<<"SHape class."<<endl;
	}
	
};

class Circle:public Shape{
	public:
		float radius;
		int centerx;
		int centery;
		
		 Circle(string p, string c, int bd, float r, int x, int y) 
        : Shape(p, c, bd), radius(r), centerx(x), centery(y) {}
		
		void draw() override{
		cout<<"Drawing circle."<<endl;
	}
	
	void calculatearea()override{
			int area;
			area=(0.5)*3.142*(radius)*radius;
			cout<<"Area of Circle: "<<area<<endl;
	}
	
	void calculateperimeter()override
	{
		int per;
			per=2*3.142*(radius);
			cout<<"Perimeter of Circle: "<<per<<endl;
	}
};


class Rectangle:public Shape{
	public:
		int length;
		int width;
		
		Rectangle(string p, string c, int bd, int l, int w) 
        : Shape(p, c, bd), length(l), width(w) {}
	void draw() override{
		cout<<"Drawing rectangle."<<endl;
	}
	
	void calculatearea()override{
			int area;
			area=(length*width);
			cout<<"Area of Rectangle: "<<area<<endl;
	}
	
	void calculateperimeter()override
	{
		int per;
			per=(2*length)+(2*width);
			cout<<"Perimeter of Rectangle: "<<per<<endl;
	}
};

class Triangle:public Shape{
	public:
		int a;
		int b;
		int c;
		int base;
		int height;
		
		Triangle(string p, string c, int bd, int A, int B, int C, int base, int height) 
        : Shape(p, c, bd), a(A), b(B), c(C), base(base), height(height) {}
		
	void draw() override{
		cout<<"Drawing Triangle."<<endl;
	}
	
	void calculatearea()override{
			int area;
			area=(0.5)*(base*height);
			cout<<"Area of Triangle: "<<area<<endl;
	}
	
	void calculateperimeter()override
	{
		int per;
			per=a+b+c;
			cout<<"Perimeter of Triangle: "<<per<<endl;
	}
};

class Polygon:public Shape{
	public:
		int a;
		int b;
		int c;
		int d;
		
		Polygon(string p, string c, int bd, int A, int B, int C, int D) 
        : Shape(p, c, bd), a(A), b(B), c(C), d(D) {}
		
	void draw() override{
		cout<<"Drawing Polygon."<<endl;
	}
	
	void calculatearea()override{
			int area;
			area=(a*b);
			cout<<"Area of Polygon where it a Rectangle: "<<area<<endl;
	}
	
	void calculateperimeter()override
	{
		int per;
			per=a+b+c+d;
			cout<<"Perimeter of Polygon: "<<per<<endl;
	}
};

int main() {
    Shape* s1 = new Circle("Center", "Red", 2, 5.0, 0, 0);
    Shape* s2 = new Rectangle("Top Left", "Blue", 3, 10, 5);
    Shape* s3 = new Triangle("Bottom Left", "Green", 1, 3, 4, 5, 6, 8);
    Shape* s4 = new Polygon("Random", "Yellow", 2, 4, 5, 4, 5);

    s1->draw();
    s1->calculatearea();
    s1->calculateperimeter();
    cout << "----------------------\n";

    s2->draw();
    s2->calculatearea();
    s2->calculateperimeter();
    cout << "----------------------\n";

    s3->draw();
    s3->calculatearea();
    s3->calculateperimeter();
    cout << "----------------------\n";

    s4->draw();
    s4->calculatearea();
    s4->calculateperimeter();
    cout << "----------------------\n";

    delete s1;
    delete s2;
    delete s3;
    delete s4;

    return 0;
}

