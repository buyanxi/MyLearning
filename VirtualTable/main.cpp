#include <iostream>

using namespace std;

typedef void(*Fun)(void);

class Base
{
 public:
        virtual void f() { cout << "Base::f" << endl; }
        virtual void g() { cout << "Base::g" << endl; }
        virtual void h() { cout << "Base::h" << endl; }
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
    int a = 1;
    int c = 2;
    int &p = a;
    int *ptr = &a;

    printf("p: %ld, %d\n", &p, p);
    printf("ptr: %ld, %d\n", ptr, *ptr);

    p = c;
    ptr = &c;
    printf("p: %ld, %d\n", &p, p);
    printf("ptr: %ld, %d\n", ptr, *ptr);

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

    Driver *pD = new Driver;
    cout << "Class object addr: " << (int*)pD << endl;

    cout << "1st V-Table addr: " << (int*)pD << endl;
    int faddr = *((int*)*(int*)pD + 0*sizeof(int*)/4);
    int gaddr = *((int*)*(int*)pD + 1*sizeof(int*)/4);
    int haddr = *((int*)*(int*)pD + 2*sizeof(int*)/4);
    int f1addr = *((int*)*(int*)pD + 3*sizeof(int*)/4);
    int g1addr = *((int*)*(int*)pD + 4*sizeof(int*)/4);
    int h1addr = *((int*)*(int*)pD + 5*sizeof(int*)/4);

    cout << "V-Table with 1st V-Fun addr: " << (int*)faddr << endl;
    cout << "V-Table with 2st V-Fun addr: " << (int*)gaddr << endl;
    cout << "V-Table with 3st V-Fun addr: " << (int*)haddr << endl;
    cout << "V-Table with 4st V-Fun addr: " << (int*)f1addr << endl;
    cout << "V-Table with 5st V-Fun addr: " << (int*)g1addr << endl;
    cout << "V-Table with 6st V-Fun addr: " << (int*)h1addr << endl;
    pFun = (Fun)faddr;
    pFun();

    pFun = (Fun)gaddr;
    pFun();

    pFun = (Fun)haddr;
    pFun();

    pFun = (Fun)f1addr;
    pFun();

    pFun = (Fun)g1addr;
    pFun();

    pFun = (Fun)h1addr;
    pFun();

    cout << "2st V-Table addr: " << (int*)pD + 2 << endl;

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
