#ifndef FUNCDB_HPP
#define FUNCDB_HPP

#include <string>
#include <unordered_map>
#include <functional>
#include <variant>
#include <any>
#include <iostream>
namespace database
{
    class FuncContainer
    {
    private:
    std::unordered_map<std::string, std::any> funcs;
    public:
        template<typename ReturnType, typename ...ParamsTypes>
        auto get(std::string name) -> std::function<ReturnType(ParamsTypes...)>{
            auto it = funcs.find(name);
            if (it == funcs.end()) {
                throw std::runtime_error("Function not found: " + name);
            }
            return std::any_cast<std::function<ReturnType(ParamsTypes...)>>(it->second);        
        }
        template<typename ReturnType, typename ...ParamsTypes>
        auto set(std::string name, std::function<ReturnType(ParamsTypes...)> func) -> void{
            funcs[name] = func;
        }
    };
    
} // namespace database
#endif