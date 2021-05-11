#include <iostream>

using namespace std;

typedef void(*Fun)(void);

class Base
{
public:
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() { cout << "Base::h" << endl; }

private:
    virtual void baseTest() { cout << "Base::baseTest" << endl; }

};

class Base1
{
public:
    virtual void f() { cout << "Base1::f" << endl; }
    virtual void g() { cout << "Base1::g" << endl; }
    virtual void h() { cout << "Base1::h" << endl; }
};

class Driver : public Base, public Base1
{
public:
    virtual void f1() { cout << "Driver::f1" << endl; }
    virtual void g1() { cout << "Driver::g1" << endl; }
    virtual void h1() { cout << "Driver::h1" << endl; }
    virtual void f() { cout << "Driver::f" << endl; }
    virtual void g() { cout << "Driver::g" << endl; }
    virtual void h() { cout << "Driver::h" << endl; }
};

typedef void(Base::*Fun1)();

int main()
{
    #if 0
    Base *b = new Base();
    cout << "Class object addr: " << b << endl;

    cout << "V-Table addr: " << (int*)*(int*)b + 0*sizeof(int*)/4<< endl;
    cout << "V-Table addr: " << (int*)*(int*)b + 1*sizeof(int*)/4 << endl;
    cout << "V-Table addr: " << (int*)*(int*)b + 2*sizeof(int*)/4 << endl;
    int faddr = *((int*)*(int*)b + 0*sizeof(int*)/4);
    int gaddr = *((int*)*(int*)b + 1*sizeof(int*)/4);
    int haddr = *((int*)*(int*)b + 2*sizeof(int*)/4);

    cout << "V-Table with 1st V-Fun addr: " << (int*)faddr << endl;
    cout << "V-Table with 2st V-Fun addr: " << (int*)gaddr << endl;
    cout << "V-Table with 3st V-Fun addr: " << (int*)haddr << endl;

    Fun pFun = NULL;
    pFun = (Fun)faddr;
    pFun();

    pFun = (Fun)gaddr;
    pFun();

    pFun = (Fun)haddr;
    pFun();
    #endif

    #if 0
    Base b1;
    cout << "Class object addr: " << &b1 << endl;
    cout << "V-Table addr: " << (int*)*(int*)(&b1) << endl;

    faddr = *((int*)*(int*)b + 0*sizeof(int*)/4);
    gaddr = *((int*)*(int*)b + 1*sizeof(int*)/4);
    haddr = *((int*)*(int*)b + 2*sizeof(int*)/4);

    cout << "V-Table with 1st V-Fun addr: " << (int*)faddr << endl;
    cout << "V-Table with 2st V-Fun addr: " << (int*)gaddr << endl;
    cout << "V-Table with 3st V-Fun addr: " << (int*)haddr << endl;

    ((void(*)(void))faddr)();
    ((void(*)(void))gaddr)();
    ((void(*)(void))haddr)();
    #endif // 0

    Fun pFun = NULL;


    Base *pB = new Base();
    cout << "Base object addr: " << (int*)pB << endl;
    cout << "1st V-Table addr: " << (int*)*(int*)pB << endl;
    int fBaddr = *((int*)*(int*)pB + 0*sizeof(int*)/4);
    int gBaddr = *((int*)*(int*)pB + 1*sizeof(int*)/4);
    int hBaddr = *((int*)*(int*)pB + 2*sizeof(int*)/4);
    int tBaddr = *((int*)*(int*)pB + 3*sizeof(int*)/4);
    cout << "V-Table with 1st V-Fun addr: " << (int*)fBaddr << endl;
    cout << "V-Table with 2st V-Fun addr: " << (int*)gBaddr << endl;
    cout << "V-Table with 3st V-Fun addr: " << (int*)hBaddr << endl;
    cout << "V-Table with 4st V-Fun addr: " << (int*)tBaddr << endl;

    pFun = (Fun)fBaddr;
    pFun();

    pFun = (Fun)gBaddr;
    pFun();

    pFun = (Fun)hBaddr;
    pFun();

    pFun = (Fun)tBaddr;
    pFun();

    Driver *pD = new Driver;
    cout << "\nDriver object addr: " << (int*)pD << endl;
    cout << "1st V-Table addr: " << (int*)pD << endl;
    int faddr = *((int*)*(int*)pD + 0*sizeof(int*)/4);
    int gaddr = *((int*)*(int*)pD + 1*sizeof(int*)/4);
    int haddr = *((int*)*(int*)pD + 2*sizeof(int*)/4);
    int taddr = *((int*)*(int*)pD + 3*sizeof(int*)/4);
    int f1addr = *((int*)*(int*)pD + 4*sizeof(int*)/4);
    int g1addr = *((int*)*(int*)pD + 5*sizeof(int*)/4);
    int h1addr = *((int*)*(int*)pD + 6*sizeof(int*)/4);

    cout << "V-Table with 1st V-Fun addr: " << (int*)faddr << endl;
    cout << "V-Table with 2st V-Fun addr: " << (int*)gaddr << endl;
    cout << "V-Table with 3st V-Fun addr: " << (int*)haddr << endl;
    cout << "V-Table with 4st V-Fun addr: " << (int*)taddr << endl;
    cout << "V-Table with 5st V-Fun addr: " << (int*)f1addr << endl;
    cout << "V-Table with 6st V-Fun addr: " << (int*)g1addr << endl;
    cout << "V-Table with 7st V-Fun addr: " << (int*)h1addr << endl;

    pFun = (Fun)faddr;
    pFun();

    pFun = (Fun)gaddr;
    pFun();

    pFun = (Fun)haddr;
    pFun();

    //is unsafe, the private virtual function of base class is traversed through pointer.
    pFun = (Fun)taddr;
    pFun();

    pFun = (Fun)f1addr;
    pFun();

    pFun = (Fun)g1addr;
    pFun();

    pFun = (Fun)h1addr;
    pFun();

    cout << "\n2st V-Table addr: " << (int*)pD + 2 << endl;

    faddr = *((int*)*(int*)((int*)pD + 2) + 0*sizeof(int*)/4);
    gaddr = *((int*)*(int*)((int*)pD + 2) + 1*sizeof(int*)/4);
    haddr = *((int*)*(int*)((int*)pD + 2) + 2*sizeof(int*)/4);

    cout << "V-Table with 1st V-Fun addr: " << (int*)faddr << endl;
    cout << "V-Table with 2st V-Fun addr: " << (int*)gaddr << endl;
    cout << "V-Table with 3st V-Fun addr: " << (int*)haddr << endl;

    pFun = (Fun)faddr;
    pFun();

    pFun = (Fun)gaddr;
    pFun();

    pFun = (Fun)haddr;
    pFun();

    return 0;
}
