#ifndef IHUMAN_H
#define IHUMAN_H


class IHuman
{
public:
    IHuman() {}
    virtual ~IHuman() {}

    virtual void Laugh() = 0;
    virtual void Cry() = 0;
    virtual void Talk() = 0;
};

#endif // IHUMAN_H
