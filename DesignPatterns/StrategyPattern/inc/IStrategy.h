#ifndef CISTRATEGY_H
#define CISTRATEGY_H


class CIStrategy
{
public:
    CIStrategy() {}
    virtual ~CIStrategy() {}
    virtual void Operate() = 0;

};

#endif // CISTRATEGY_H
