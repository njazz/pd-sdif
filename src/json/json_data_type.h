#ifndef JSON_DATA_TYPES_H
#define JSON_DATA_TYPES_H

#include "ceammc_atomlist.h"
#include "ceammc_data.h"
#include "json.hpp"

using json = nlohmann::json;
using namespace ceammc;

class DataTypeMList;

class DataTypeJSON : public AbstractData {
    nlohmann::json _json = "{}"_json;

public:
    static const DataType dataType = 500;

    explicit DataTypeJSON(std::string jsonString);

    virtual void dump() override;
    virtual DataType type() const override;
    virtual AbstractData* clone() const override;
    virtual std::string toString() const override;

    const nlohmann::json json() { return _json; }

    template<typename T>
    inline
    void set(T key, nlohmann::json j) { _json[key] = j; }

    void toFile(std::string fileName);
    void fromFile(std::string fileName);

    void clear() { _json.clear(); }
};

#endif // SDIF_DATA_TYPES_H
