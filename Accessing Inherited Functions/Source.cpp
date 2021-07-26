#include<iostream>

using namespace std;

class A
{
public:
    A() {
        callA = 0;
    }
private:
    int callA;
    void inc() {
        callA++;
    }

protected:
    int func(int& a)
    {
        a = a * 2;
        cout << "A's func will be called once." << endl;
        inc();
        return a;
    }
public:
    int getA() {
        return callA;
    }
};

class B : public A
{
public:
    B() {
        callB = 0;
    }
private:
    int callB;
    void inc() {
        callB++;
    }
protected:
    int func(int& a)
    {
        a = a * 3;
        cout << "B's func will be called once." << endl;
        inc();
        return a;
    }
public:
    int getB() {
        return callB;
    }
};

class C :public B
{
public:
    C() {
        callC = 0;
    }
private:
    int callC;
    void inc() {
        callC++;
    }
protected:
    int func(int& a)
    {
        a = a * 5;
        cout << "C's func will be called once." << endl;
        inc();
        return a;
     
    }
public:
    int getC() {
        return callC;
    }
};

class D: public C
{

    int val;
public:
    //Initially val is 1
    D()
    {
        val = 1;
    }


    //Implement this function
    int update_val(int new_val)
    {
        val = new_val;
        val = A::func(val);
        val = B::func(val);
        val = C::func(val);
       
        return val;
    }
    //For Checking Purpose
    void check(int); //Do not delete this line.
};

int main()
{   
    int input;
    D value;
    cin >> input;
    input = value.update_val(input);
    cout << input << endl;
}