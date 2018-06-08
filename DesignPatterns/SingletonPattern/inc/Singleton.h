#ifndef CSINGLETON_H
#define CSINGLETON_H


class CSingleton
{
public:
    static CSingleton* GetInstance();

    static CSingleton &_GetInstance()
    {
        static CSingleton m_cSingleton;
        return m_cSingleton;
    }

public:
    int Operate();

private:
    CSingleton();
    virtual ~CSingleton();
    CSingleton(const CSingleton&) {}
	CSingleton& operator=(const CSingleton&) {}

private:
    static CSingleton* m_pcSingleton;

    //static CSingleton m_cSingleton;
};

#endif // CSINGLETON_H
