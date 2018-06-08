#ifndef CSINGLETON_H
#define CSINGLETON_H


class CSingleton
{
public:
    CSingleton* GetInstance();

private:
    CSingleton();
    virtual ~CSingleton();

private:
    CSingleton* m_cSingleton;
};

#endif // CSINGLETON_H
