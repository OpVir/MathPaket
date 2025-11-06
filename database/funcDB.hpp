#ifndef FUNCDB_HPP
#define FUNCDB_HPP

#include <string>
#include <unordered_map>
#include <functional>

namespace database
{
    template<typename ..._T>
    class FuncContainer
    {
    private:
    using SupportTypes = _T...;
    std::unordered_map<std::string, std::function<SupportTypes(SupportTypes)>> funcs;
    public:

        auto get(std::string name) -> std::function;
        template<typename ReturnType, typename ...ParamsTypes>
        auto set(std::string name, std::function<ReturnType(ParamsTypes...>)) -> void;
    };
    
} // namespace database

#endif