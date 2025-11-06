#ifndef PARAMSDB_HPP
#define PARAMSDB_HPP

#include <unordered_map>
#include <string>
#include <stdexcept>
#include <iostream>

namespace paramsbase
{
   

class ParamsContainer {
private:
    std::unordered_map<std::string, int> params;

public:
    void set(const std::string& name, int value) {
        params[name] = value;
    }
    
    bool get(const std::string& name, int& value) const {
        auto it = params.find(name);
        if (it != params.end()) {
            value = it->second;
            return true;
        }
        return false;
    }
    
    
    int& operator[](const std::string& name) {
        return params[name];
    }
    
    const int& operator[](const std::string& name) const {
        auto it = params.find(name);
        if (it == params.end()) {
            throw std::out_of_range("Key not found: " + name);
        }
        return it->second;
    }
    
    bool contains(const std::string& name) const {
        return params.find(name) != params.end();
    }
    
    bool remove(const std::string& name) {
        return params.erase(name) > 0;
    }
    
    void clear() {
        params.clear();
    }
    
    size_t size() const {
        return params.size();
    }
    
    bool empty() const {
        return params.empty();
    }
    
};
} // namespace paramsbase

#endif