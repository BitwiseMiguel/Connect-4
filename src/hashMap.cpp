#include "hashMap.hpp"

HashMap::HashMap(const uint32_t &theSize)
    : size{theSize} {
        table = new Data[theSize];
    }

HashMap::HashMap(const HashMap &other) {
    table = new Data[size];
    *table = *other.table;
}

HashMap::HashMap(HashMap &&other)
    : table{other.table} {
        other.table = nullptr;
    }

HashMap::~HashMap() {
    delete[] table;
}

void HashMap::put(const uint64_t &key, const uint8_t &value) {
    uint32_t idx = calculateIndex(key);
    table[idx].key = key;
    table[idx].value = value;
}

uint8_t HashMap::get(const uint64_t &key) const {
    uint32_t idx = calculateIndex(key);
    if (table[idx].key == key) {
        return table[idx].value;
    }
    return DEADCODE;
}
