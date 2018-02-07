#ifndef SDIF_DATA_TYPES_H
#define SDIF_DATA_TYPES_H

#include "ceammc_data.h"
#include "mSDIFFile.hpp"
#include "ceammc_atomlist.h"

using namespace ceammc;

class DataTypeSubList : public AbstractData {
    AtomList* _atomList = 0;

public:
    static const DataType dataType = 200;

    explicit DataTypeSubList(AtomList* l);

    virtual void dump() override;
    virtual DataType type() const override;
    virtual AbstractData* clone() const override;
    virtual std::string toString() const override;

    AtomList* list() { return _atomList; }
};

#endif // SDIF_DATA_TYPES_H