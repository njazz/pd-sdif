#include "ceammc_data.h"
#include "ceammc_factory.h"

#include "../mlist/mlist_data_type.h"

#include "ceammc_dataatom.h"

#include "image_obj.h"

#include "math.h"

using namespace cimg_library;
using namespace ceammc;

ImageObj::ImageObj(const PdArgs& args)
    : BaseObject(args)
    , _img(new DataTypeImage(0))
    , _dPtr(new DataPtr(_img))
{
    _out1 = createOutlet();
}

void ImageObj::onBang()
{
    if (!_img->img())
        return;

    //    int w = _img->img()->width();
    //    int h = _img->img()->height();

    //    post("out img %i %i", w, h);

    AtomList* ret = new AtomList((new DataAtom(*_dPtr))->toAtom());
    ret->output(_out1);
};

void ImageObj::onData(const DataPtr& d)
{
    DataTypeImage* img = const_cast<DataTypeImage*>(d.as<DataTypeImage>());

    if (!img)
        return;

    if (!img->img())
        return;

    int w = img->img()->width();
    int h = img->img()->height();

    _img = img;
    _dPtr = new DataPtr(img);
}

void ImageObj::onList(const AtomList& l)
{
    if (l.size() == 1)
        if (l.at(0).isData()) {

            DataTypeImage* img = const_cast<DataTypeImage*>(DataAtom(l.at(0)).data().as<DataTypeImage>());

            post("img %lu", (long)img);

            if (img)
                if (img->img())
                    post("img: %i %i", img->img()->width(), img->img()->height());

            onData(DataAtom(l.at(0)).data());
            return;
        }
}

void ImageObj::dump() const
{
    OBJ_DBG << "DATA: MList";
    BaseObject::dump();
    OBJ_DBG << "id:       " << _dPtr->desc().id;
    OBJ_DBG << "refcount: " << _dPtr->refCount();
    OBJ_DBG << "contents:  " << _img->toString();
}

// ==========
void ImageObj::m_read(t_symbol* s, const AtomList& l)
{
    if (l.size() < 1)
        return;

    try {
        _img = new DataTypeImage(new CImg<unsigned char>(l.at(0).asString().c_str()));
        post("loaded [%i,%i]", _img->img()->width(), _img->img()->height());

        _dPtr = new DataPtr(_img);

    } catch (std::exception& e) {
        error("error: %s", e.what());
        _img = 0;
    }
}
void ImageObj::m_write(t_symbol* s, const AtomList& l)
{
    if (l.size() < 1)
        return;

    if (!_img)
        return;

    if (!_img->img()) {
        error("cannot write empty file");
        return;
    }

    try {
        _img->img()->save(l.at(0).asString().c_str());
    } catch (std::exception& e) {
        error("error: %s", e.what());
        _img = 0;
    }
}

// ==========

extern "C" {
void setup_image()
{
    ObjectFactory<ImageObj> f("image");

    f.addMethod("read", &ImageObj::m_read);
    f.addMethod("write", &ImageObj::m_write);
}
}
