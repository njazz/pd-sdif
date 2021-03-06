#ifndef SDIF_FILE_H
#define SDIF_FILE_H

#include "ceammc_object.h"
#include "image_data_type.h"

// TODO
#define cimg_OS 0
//#define cimg_use_png 1
#define cimg_use_cpp11 1
#define cimg_use_jpeg 1
#include "CImg.h"

class ImageObj : public BaseObject {
    t_outlet* _out1;

    DataTypeImage* _img;
    DataPtr* _dPtr = 0;

    //cimg_library::CImg<unsigned char>* _img = 0;

    bool _outputData = false;

public:
    ImageObj(const PdArgs& args);

    virtual void onBang() override;
    virtual void dump() const override;

    virtual void onData(const DataPtr& d) override;
    virtual void onList(const AtomList& l) override;

//    virtual void onFloat(float f) override;
//    virtual void onSymbol(t_symbol* s) override;

    void m_read(t_symbol* s, const AtomList& l);
    void m_write(t_symbol* s, const AtomList& l);
};

#endif // SDIF_FILE_H
