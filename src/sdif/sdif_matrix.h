#ifndef SDIF_FILE_H
#define SDIF_FILE_H

#include "ceammc_object.h"

#include "mSDIFFile.hpp"

class SDIFMatrixClass : public BaseObject {
    t_outlet* _out1;

    DataTypeSDIFMatrix* _sdifMatrixData;
    DataPtr _dPtr;

public:
    SDIFMatrixClass(const PdArgs& args);

    virtual void onBang() override;
    virtual void dump() const override;

    virtual void onData(const DataPtr& d) override;
    virtual void onList(const AtomList& l) override;

    void m_clear(t_symbol* s, const AtomList& l);

    void m_newmatrix(t_symbol* s, const AtomList& l);

    void m_rowat(t_symbol* s, const AtomList& l);
    void m_columnat(t_symbol* s, const AtomList& l);

    void m_get(t_symbol* s, const AtomList& l);
    void m_set(t_symbol* s, const AtomList& l);

    void m_type(t_symbol* s, const AtomList& l);

    void m_set_size(t_symbol* s, const AtomList& l);

    void m_resize(t_symbol* s, const AtomList& l);
    void m_erase_data(t_symbol* s, const AtomList& l);

    void m_1nvt(t_symbol* s, const AtomList& l);

};

#endif // SDIF_FILE_H
