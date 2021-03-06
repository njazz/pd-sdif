#ifndef JSON_OBJ_H
#define JSON_OBJ_H

#include "ceammc_object.h"

#include "../json/json_data_type.h"

class JSONToList : public BaseObject {
    t_outlet* _out1;

    AtomList* _list;

public:
    JSONToList(const PdArgs& args);

    //    virtual void onBang() override;
    virtual void dump() const override;

    virtual void onBang() override;

    virtual void onData(const DataPtr& d) override;
    virtual void onList(const AtomList& l) override;
};

#endif // SDIF_FILE_H
