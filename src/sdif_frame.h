#ifndef SDIF_FILE_H
#define SDIF_FILE_H

#include "ceammc_object.h"

#include "mSDIFFile.hpp"

class SDIFFrameClass : public BaseObject {
    t_outlet* _out1;

    DataTypeSDIFFrame* _sdifFrameData;
    DataPtr _dPtr;


public:
    SDIFFrameClass(const PdArgs& args);

    virtual void onBang() override;
    virtual void dump() const override;
    virtual void onData(const DataPtr& d) override;
    virtual void onList(const AtomList& l) override;
    virtual void onFloat(float f) override;

    void m_info(t_symbol* s, const AtomList& l);
    void m_clear(t_symbol* s, const AtomList& l);

    void m_newframe(t_symbol* s, const AtomList& l);

};

#endif // SDIF_FILE_H
