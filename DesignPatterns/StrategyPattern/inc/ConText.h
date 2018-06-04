#ifndef CCONTEXT_H
#define CCONTEXT_H

#ifndef CISTRATEGY_H
#include "IStrategy.h"
#endif // CISTRATEGY_H

typedef enum _Brocade_Bag
{
    FIRST_BROCADE_BAG = 0,
    SECOND_BROCADE_BAG,
    THIRD_BROCADE_BAG
}BrocadeBag;

class CConText
{
public:
    CConText();
    virtual ~CConText();

    void CreateIStrategy(BrocadeBag eBrocadeBag);
    void DeleteIStrategy();
    void Operrate();

private:
    CIStrategy *m_pcIStrategy;
};

#endif // CCONTEXT_H
