#include <iostream>

using namespace std;


class S {
public:
    S() {}

    virtual double calculateS() = 0;
};


class rectangle : public S{
protected:
    int a;
    int b;
public:
    rectangle(int a, int b): a{a}, b{b} {}

    double calculateS() override {
        return a * b;
    }
};


class circle : public S {
protected:
    const float pi = 3.1415926535897;
    int r;
public:
    circle(int r) : r{ r } {};

    double calculateS() override {
        return pi * (r * r);
    }
};


class triangle : public S {
protected:
    int a;
    int b;
    int c;
public:
    triangle(int a, int b, int c) {
        if (a + b > c && a + c > b && b + c > a) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        else
        {
            delete this;
        }
    }

    double calculateS() override {
        return 0.5 * (a * b);
    }
};


class trapeze : public S {
protected:
    int a;
    int b;
    int h;
public:
    trapeze(int a, int b, int h) : a{a}, b{b}, h{h} {}

    double calculateS() override {
        return (a + b) / 2 * h;
    }
};

int main()
{
    S* f;

    f = new rectangle{ 3,5 };
    cout << f->calculateS() << endl;
    
    delete f;

    f = new circle{ 5 };
    cout << f->calculateS() << endl;

    delete f;

    f = new triangle{ 3,4,5 };
    cout << f->calculateS() << endl;

    delete f;

    f = new trapeze{ 3,5,4 };
    cout << f->calculateS() << endl;

    delete f;
}