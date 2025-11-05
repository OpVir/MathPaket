// alg.hpp
#pragma once
#include "exceptions.hpp"
#include <vector>

namespace alg
{

    template <typename T>
    auto inc(T &t);

    // Скаляры
    template <typename T>
    auto sum(const T &t1, const T &t2);

    template <typename T>
    auto sub(const T &t1, const T &t2);

    template <typename T>
    auto mul(const T &t1, const T &t2);

    template <typename T>
    auto pow(const T &t, std::size_t n);

    // Векторы
    template <typename T>
    auto sum(const std::vector<T> &v1, const std::vector<T> &v2);

    template <typename T>
    auto sub(const std::vector<T> &v1, const std::vector<T> &v2);

    template <typename T>
    auto mul(const std::vector<T> &v, const T &scalar);

    template <typename T>
    auto dot(const std::vector<T> &v1, const std::vector<T> &v2);

    template <typename T>
    auto pow(const std::vector<T> &v, std::size_t n);

    // Матрицы
    template <typename T>
    auto sum(const std::vector<std::vector<T>> &m1, const std::vector<std::vector<T>> &m2);

    template <typename T>
    auto sub(const std::vector<std::vector<T>> &m1, const std::vector<std::vector<T>> &m2);

    template <typename T>
    auto mul(const std::vector<std::vector<T>> &m, const T &scalar);

    template <typename T>
    auto dot(const std::vector<std::vector<T>> &m1, const std::vector<std::vector<T>> &m2);

    template <typename T>
    auto pow(const std::vector<std::vector<T>> &m, std::size_t n);
}

template <typename T>
auto alg::inc(T &t)
{
    return ++t;
}
// Реализации для скаляров

template <typename T>
auto alg::sum(const T &t1, const T &t2)
{
    return t1 + t2;
}

template <typename T>
auto alg::sub(const T &t1, const T &t2)
{
    return t1 - t2;
}

template <typename T>
auto alg::mul(const T &t1, const T &t2)
{
    return t1 * t2;
}

template <typename T>
auto alg::pow(const T &t, std::size_t n)
{
    if (n == 0)
    {
        return T(1);
    }
    T r = t;
    for (std::size_t i = 1; i < n; ++i)
    {
        r = r * t;
    }
    return r;
}

// Реализации для векторов
template <typename T>
auto alg::sum(const std::vector<T> &v1, const std::vector<T> &v2)
{
    if (v1.size() != v2.size())
    {
        throw exc::invalid_data("Vector size mismatch in sum()");
    }
    std::vector<T> r(v1.size());
    for (std::size_t i = 0; i < v1.size(); ++i)
    {
        r[i] = v1[i] + v2[i];
    }
    return r;
}

template <typename T>
auto alg::sub(const std::vector<T> &v1, const std::vector<T> &v2)
{
    if (v1.size() != v2.size())
    {
        throw exc::invalid_data("Vector size mismatch in sub()");
    }
    std::vector<T> r(v1.size());
    for (std::size_t i = 0; i < v1.size(); ++i)
    {
        r[i] = v1[i] - v2[i];
    }
    return r;
}

template <typename T>
auto alg::mul(const std::vector<T> &v, const T &scalar)
{
    std::vector<T> r(v.size());
    for (std::size_t i = 0; i < v.size(); ++i)
    {
        r[i] = v[i] * scalar;
    }
    return r;
}

template <typename T>
auto alg::dot(const std::vector<T> &v1, const std::vector<T> &v2)
{
    if (v1.size() != v2.size())
    {
        throw exc::invalid_data("Vector size mismatch in dot()");
    }
    T res{};
    for (std::size_t i = 0; i < v1.size(); ++i)
    {
        res += v1[i] * v2[i];
    }
    return res;
}

template <typename T>
auto alg::pow(const std::vector<T> &v, std::size_t n)
{
    std::vector<T> r(v.size());
    for (std::size_t i = 0; i < v.size(); ++i)
    {
        r[i] = alg::pow(v[i], n);
    }
    return r;
}

// Реализации для матриц
template <typename T>
auto alg::sum(const std::vector<std::vector<T>> &m1, const std::vector<std::vector<T>> &m2)
{
    if (m1.size() != m2.size() || m1[0].size() != m2[0].size())
    {
        throw exc::invalid_data("Matrix size mismatch in sum()");
    }
    std::vector<std::vector<T>> r(m1.size(), std::vector<T>(m1[0].size()));
    for (std::size_t i = 0; i < m1.size(); ++i)
    {
        for (std::size_t j = 0; j < m1[0].size(); ++j)
        {
            r[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return r;
}

template <typename T>
auto alg::sub(const std::vector<std::vector<T>> &m1, const std::vector<std::vector<T>> &m2)
{
    if (m1.size() != m2.size() || m1[0].size() != m2[0].size())
    {
        throw exc::invalid_data("Matrix size mismatch in sub()");
    }
    std::vector<std::vector<T>> r(m1.size(), std::vector<T>(m1[0].size()));
    for (std::size_t i = 0; i < m1.size(); ++i)
    {
        for (std::size_t j = 0; j < m1[0].size(); ++j)
        {
            r[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return r;
}

template <typename T>
auto alg::mul(const std::vector<std::vector<T>> &m, const T &scalar)
{
    std::vector<std::vector<T>> r(m.size(), std::vector<T>(m[0].size()));
    for (std::size_t i = 0; i < m.size(); ++i)
    {
        for (std::size_t j = 0; j < m[0].size(); ++j)
        {
            r[i][j] = m[i][j] * scalar;
        }
    }
    return r;
}

template <typename T>
auto alg::dot(const std::vector<std::vector<T>> &m1, const std::vector<std::vector<T>> &m2)
{
    if (m1[0].size() != m2.size())
    {
        throw exc::invalid_data("Matrix size mismatch in dot()");
    }
    std::vector<std::vector<T>> r(m1.size(), std::vector<T>(m2[0].size(), 0));
    for (std::size_t i = 0; i < m1.size(); ++i)
    {
        for (std::size_t j = 0; j < m2[0].size(); ++j)
        {
            for (std::size_t k = 0; k < m1[0].size(); ++k)
            {
                r[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return r;
}

template <typename T>
auto alg::pow(const std::vector<std::vector<T>> &m, std::size_t n)
{
    if (m.empty() || m.size() != m[0].size())
    {
        throw exc::invalid_data("Matrix must be square for pow()");
    }
    auto result = m;
    for (std::size_t i = 1; i < n; ++i)
    {
        result = alg::dot(result, m);
    }
    return result;
}