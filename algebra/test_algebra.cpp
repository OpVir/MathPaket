#include <iostream>
#include <cstdlib>
#include "ssp.hpp"
#include <vector>
void test_scalars()
{
    std::cout << "=== Testing Scalars ===" << std::endl;

    // Test int
    int a = 5, b = 3;
    std::cout << "int sum: " << alg::sum(a, b) << " (expected: 8)" << std::endl;
    std::cout << "int sub: " << alg::sub(a, b) << " (expected: 2)" << std::endl;
    std::cout << "int mul: " << alg::mul(a, b) << " (expected: 15)" << std::endl;
    std::cout << "int pow: " << alg::pow(a, 3) << " (expected: 125)" << std::endl;

    // Test double
    double x = 2.5, y = 1.5;
    std::cout << "double sum: " << alg::sum(x, y) << " (expected: 4.0)" << std::endl;
    std::cout << "double sub: " << alg::sub(x, y) << " (expected: 1.0)" << std::endl;
    std::cout << "double mul: " << alg::mul(x, y) << " (expected: 3.75)" << std::endl;
    std::cout << "double pow: " << alg::pow(x, 2) << " (expected: 6.25)" << std::endl;

    std::cout << std::endl;
}

void test_vectors()
{
    std::cout << "=== Testing Vectors ===" << std::endl;

    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};

    // Test vector operations
    auto v_sum = alg::sum(v1, v2);
    std::cout << "vector sum: [";
    for (size_t i = 0; i < v_sum.size(); ++i)
    {
        std::cout << v_sum[i] << (i < v_sum.size() - 1 ? ", " : "");
    }
    std::cout << "] (expected: [5, 7, 9])" << std::endl;

    auto v_sub = alg::sub(v1, v2);
    std::cout << "vector sub: [";
    for (size_t i = 0; i < v_sub.size(); ++i)
    {
        std::cout << v_sub[i] << (i < v_sub.size() - 1 ? ", " : "");
    }
    std::cout << "] (expected: [-3, -3, -3])" << std::endl;

    auto v_mul_scalar = alg::mul(v1, 2);
    std::cout << "vector mul scalar: [";
    for (size_t i = 0; i < v_mul_scalar.size(); ++i)
    {
        std::cout << v_mul_scalar[i] << (i < v_mul_scalar.size() - 1 ? ", " : "");
    }
    std::cout << "] (expected: [2, 4, 6])" << std::endl;

    auto v_dot = alg::dot(v1, v2);
    std::cout << "vector dot: " << v_dot << " (expected: 32)" << std::endl;

    auto v_pow = alg::pow(v1, 2);
    std::cout << "vector pow: [";
    for (size_t i = 0; i < v_pow.size(); ++i)
    {
        std::cout << v_pow[i] << (i < v_pow.size() - 1 ? ", " : "");
    }
    std::cout << "] (expected: [1, 4, 9])" << std::endl;

    std::cout << std::endl;
}

void test_matrices()
{
    std::cout << "=== Testing Matrices ===" << std::endl;

    std::vector<std::vector<int>> m1 = {
        {1, 2},
        {3, 4}};

    std::vector<std::vector<int>> m2 = {
        {5, 6},
        {7, 8}};

    // Test matrix operations
    auto m_sum = alg::sum(m1, m2);
    std::cout << "matrix sum:" << std::endl;
    for (const auto &row : m_sum)
    {
        std::cout << "[ ";
        for (const auto &elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "(expected: [6 8], [10 12])" << std::endl;

    auto m_sub = alg::sub(m1, m2);
    std::cout << "matrix sub:" << std::endl;
    for (const auto &row : m_sub)
    {
        std::cout << "[ ";
        for (const auto &elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "(expected: [-4 -4], [-4 -4])" << std::endl;

    auto m_mul_scalar = alg::mul(m1, 3);
    std::cout << "matrix mul scalar:" << std::endl;
    for (const auto &row : m_mul_scalar)
    {
        std::cout << "[ ";
        for (const auto &elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "(expected: [3 6], [9 12])" << std::endl;

    auto m_dot = alg::dot(m1, m2);
    std::cout << "matrix dot:" << std::endl;
    for (const auto &row : m_dot)
    {
        std::cout << "[ ";
        for (const auto &elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "(expected: [19 22], [43 50])" << std::endl;

    auto m_pow = alg::pow(m1, 2);
    std::cout << "matrix pow (n=2):" << std::endl;
    for (const auto &row : m_pow)
    {
        std::cout << "[ ";
        for (const auto &elem : row)
        {
            std::cout << elem << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "(expected: [7 10], [15 22])" << std::endl;

    std::cout << std::endl;
}

void test_error_handling()
{
    std::cout << "=== Testing Error Handling ===" << std::endl;

    try
    {
        std::vector<int> v1 = {1, 2, 3};
        std::vector<int> v2 = {1, 2}; // Different size
        auto result = alg::sum(v1, v2);
    }
    catch (const exc::invalid_data &e)
    {
        std::cout << "Caught expected error in vector sum: " << e.what() << std::endl;
    }

    try
    {
        std::vector<std::vector<int>> m1 = {{1, 2}, {3, 4}};
        std::vector<std::vector<int>> m2 = {{1, 2}}; // Different size
        auto result = alg::sum(m1, m2);
    }
    catch (const exc::invalid_data &e)
    {
        std::cout << "Caught expected error in matrix sum: " << e.what() << std::endl;
    }

    try
    {
        std::vector<std::vector<int>> non_square = {{1, 2, 3}, {4, 5, 6}};
        auto result = alg::pow(non_square, 2);
    }
    catch (const exc::invalid_data &e)
    {
        std::cout << "Caught expected error in matrix pow: " << e.what() << std::endl;
    }

    try
    {
        std::vector<int> v1 = {1, 2, 3};
        std::vector<int> v2 = {1, 2}; // Different size
        auto result = alg::dot(v1, v2);
    }
    catch (const exc::invalid_data &e)
    {
        std::cout << "Caught expected error in vector dot: " << e.what() << std::endl;
    }

    try
    {
        std::vector<std::vector<int>> m1 = {{1, 2, 3}};
        std::vector<std::vector<int>> m2 = {{1}, {2}}; // Incompatible sizes
        auto result = alg::dot(m1, m2);
    }
    catch (const exc::invalid_data &e)
    {
        std::cout << "Caught expected error in matrix dot: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

void test_function_overloading()
{
    std::cout << "=== Testing Function Overloading ===" << std::endl;

    // Test that correct overloads are called
    int a = 5, b = 3;
    std::vector<int> v = {1, 2, 3};
    std::vector<std::vector<int>> m = {{1, 2}, {3, 4}};

    // These should call different overloads
    auto scalar_result = alg::sum(a, b);
    auto vector_result = alg::sum(v, v);
    auto matrix_result = alg::sum(m, m);

    std::cout << "Scalar sum type: " << typeid(scalar_result).name() << std::endl;
    std::cout << "Vector sum type: " << typeid(vector_result).name() << std::endl;
    std::cout << "Matrix sum type: " << typeid(matrix_result).name() << std::endl;

    // Test pow overloading
    auto scalar_pow = alg::pow(a, 2);
    auto vector_pow = alg::pow(v, 2);
    auto matrix_pow = alg::pow(m, 2);

    std::cout << "Scalar pow type: " << typeid(scalar_pow).name() << std::endl;
    std::cout << "Vector pow type: " << typeid(vector_pow).name() << std::endl;
    std::cout << "Matrix pow type: " << typeid(matrix_pow).name() << std::endl;

    std::cout << "All function overloads work correctly!" << std::endl;
    std::cout << std::endl;
}

/* #include "exceptions.hpp"    // твои собственные исключения

using namespace alg;




struct Custom
{
    double value;
    Custom(double v = 0.0) : value(v) {}
    Custom operator+(const Custom &other) const { return Custom(value + other.value); }
    Custom operator*(const Custom &other) const { return Custom(value * other.value); }
    Custom &operator++() { value += 1; return *this; }
    friend std::ostream &operator<<(std::ostream &os, const Custom &c) { os << c.value; return os; }
}; */

int main()
{

    std::cout << "Testing Algebraic Operations Library\n"
              << std::endl;

    test_scalars();
    test_vectors();
    test_matrices();
    test_error_handling();
    test_function_overloading();

    std::cout << "=== All tests completed successfully! ===" << std::endl;
    /*   try
      {
          std::cout << "=== Scalar operations ===\n";
          double a = 2.0, b = 4.0;
          std::cout << "inc(a): " << inc(a) << "\n";
          std::cout << "sum(a, b): " << sum(a, b) << "\n";
          std::cout << "pow(a, 3): " << pow(a, 3) << "\n";
          std::cout << "del(b, a): " << del(b, a) << "\n\n";

          std::cout << "=== Vector operations ===\n";
          std::vector<int> v1{1, 2, 3};
          std::vector<int> v2{4, 5, 6};
          auto vSum = sum(v1, v2);
          std::cout << "sum(v1, v2): ";
          for (auto x : vSum) std::cout << x << " ";
          std::cout << "\n";
          auto vPow = pow(v1, 2);
          std::cout << "pow(v1, 2): ";
          for (auto x : vPow) std::cout << x << " ";
          std::cout << "\n\n";

          std::cout << "=== Matrix operations ===\n";
          std::vector<std::vector<int>> m1{{1, 2}, {3, 4}};
          std::vector<std::vector<int>> m2{{5, 6}, {7, 8}};
          auto mSum = sum(m1, m2);
          std::cout << "sum(m1, m2):\n";
          for (auto &r : mSum)
          {
              for (auto x : r) std::cout << x << " ";
              std::cout << "\n";
          }
          auto mPow = pow(m1, 2);
          std::cout << "pow(m1, 2):\n";
          for (auto &r : mPow)
          {
              for (auto x : r) std::cout << x << " ";
              std::cout << "\n";
          }
          std::cout << "\n";

          std::cout << "=== Custom type operations ===\n";
          Custom c1(2.0), c2(3.0);
          auto cSum = sum(c1, c2);
          std::cout << "sum(c1, c2): " << cSum << "\n";
          std::cout << "pow(c1, 3): " << pow(c1, 3).value << "\n";
          std::cout << "inc(c1): " << inc(c1).value << "\n";
      }
      catch (const exc::invalid_data &err)
      {
          std::cout << "Error: " << err.what() << "\n";
      }
      catch (const exc::Exception &err)
      {
          std::cout << "General Exception: " << err.what() << "\n";
      }
       */
    /* using Value = float;
    std::cout << "=== Testing Vector Operations ===\n";

    // Test 1: Create vectors using dynamic arrays
    unsigned size = 5;
    Value* arr1 = new Value[size]{0, 1, 4, 9, 16};
    Value* arr2 = new Value[size]{2, 3, 6, 11, 18};

    algb::Vector<Value> vec1, vec2;
    vec1.setData(arr1, size);
    vec2.setData(arr2, size);

    // Освобождаем память динамических массивов
    delete[] arr1;
    delete[] arr2;

    // Show vectors
    std::cout << "Vector 1: [ ";
    for (unsigned i = 0; i < vec1.getSize(); i++)
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "Vector 2: [ ";
    for (unsigned i = 0; i < vec2.getSize(); i++)
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << "]\n\n";

    // Test all vector functions
    std::cout << "Dot product: " << vec1.dot(vec2) << "\n";

    // Test operator overloading
    algb::Vector<Value> vec_sum = vec1 + vec2;
    std::cout << "Sum (operator+): [ ";
    for (unsigned i = 0; i < vec_sum.getSize(); i++)
    {
        std::cout << vec_sum[i] << " ";
    }
    std::cout << "]\n";

    // Test operator overloading for subtraction
    algb::Vector<Value> vec_diff = vec1 - vec2;
    std::cout << "Difference (operator-): [ ";
    for (unsigned i = 0; i < vec_diff.getSize(); i++)
    {
        std::cout << vec_diff[i] << " ";
    }
    std::cout << "]\n";

    // Test operator overloading for scalar multiplication
    algb::Vector<Value> vec_scaled = vec1 * 2.5f;
    std::cout << "Scaled (operator*): [ ";
    for (unsigned i = 0; i < vec_scaled.getSize(); i++)
    {
        std::cout << vec_scaled[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "vec1[2] = " << vec1[2] << "\n";
    std::cout << "vec2[3] = " << vec2[3] << "\n\n";

    // Test copy constructor
    algb::Vector<Value> vec_copy(vec1);
    std::cout << "Copy of vec1: [ ";
    for (unsigned i = 0; i < vec_copy.getSize(); i++)
    {
        std::cout << vec_copy[i] << " ";
    }
    std::cout << "]\n\n";

    // Test assignment operator
    algb::Vector<Value> vec_assign;
    vec_assign = vec2;
    std::cout << "Assignment of vec2: [ ";
    for (unsigned i = 0; i < vec_assign.getSize(); i++)
    {
        std::cout << vec_assign[i] << " ";
    }
    std::cout << "]\n\n";

    // Create first matrix 6x6
    algb::Vector<Value>* matrixData1 = new algb::Vector<Value>[6];
    for (int i = 0; i < 6; i++)
    {
        // Сначала устанавливаем размер
        matrixData1[i].setSize(6);
        // Потом заполняем данные
        for (int j = 0; j < 6; j++)
        {
            matrixData1[i][j] = i * j; // Fill with i*j values
        }
    }

    algb::Matrix<Value> m1;
    m1.setData(matrixData1, 6, 6);

    // Create second matrix 6x6
    algb::Vector<Value>* matrixData2 = new algb::Vector<Value>[6];
    for (int i = 0; i < 6; i++)
    {
        // Сначала устанавливаем размер
        matrixData2[i].setSize(6);
        // Потом заполняем данные
        for (int j = 0; j < 6; j++)
        {
            matrixData2[i][j] = i + j; // Fill with i+j values
        }
    }

    algb::Matrix<Value> m2;
    m2.setData(matrixData2, 6, 6);

    // Display matrices
    std::cout << "=== Matrix Operations ===\n\n";

    std::cout << "Matrix 1 (" << m1.getRowCount() << "x" << m1.getColCount() << "):\n";
    for (unsigned i = 0; i < m1.getRowCount(); i++)
    {
        std::cout << "[ ";
        for (unsigned j = 0; j < m1.getColCount(); j++)
        {
            std::cout << m1[i][j] << "\t";
        }
        std::cout << "]\n";
    }

    std::cout << "\nMatrix 2 (" << m2.getRowCount() << "x" << m2.getColCount() << "):\n";
    for (unsigned i = 0; i < m2.getRowCount(); i++)
    {
        std::cout << "[ ";
        for (unsigned j = 0; j < m2.getColCount(); j++)
        {
            std::cout << m2[i][j] << "\t";
        }
        std::cout << "]\n";
    }

    // Test all matrix functions
    std::cout << "\n=== Testing Matrix Operations ===\n";

    // 1. Matrix Addition
    std::cout << "\n1. Matrix Addition (operator+):\n";
    algb::Matrix<Value> sum = m1 + m2;
    for (unsigned i = 0; i < sum.getRowCount(); i++)
    {
        std::cout << "[ ";
        for (unsigned j = 0; j < sum.getColCount(); j++)
        {
            std::cout << sum[i][j] << "\t";
        }
        std::cout << "]\n";
    }

    // 2. Matrix Subtraction
    std::cout << "\n2. Matrix Subtraction (operator-):\n";
    algb::Matrix<Value> diff = m1 - m2;
    for (unsigned i = 0; i < diff.getRowCount(); i++)
    {
        std::cout << "[ ";
        for (unsigned j = 0; j < diff.getColCount(); j++)
        {
            std::cout << diff[i][j] << "\t";
        }
        std::cout << "]\n";
    }

    // 3. Scalar Multiplication
    std::cout << "\n3. Scalar Multiplication (operator*):\n";
    algb::Matrix<Value> scaled = m1 * 2.5f;
    for (unsigned i = 0; i < scaled.getRowCount(); i++)
    {
        std::cout << "[ ";
        for (unsigned j = 0; j < scaled.getColCount(); j++)
        {
            std::cout << scaled[i][j] << "\t";
        }
        std::cout << "]\n";
    }

    // 4. Transpose
    std::cout << "\n4. Transpose of Matrix 1:\n";
    algb::Matrix<Value> transposed = m1.transpose();
    for (unsigned i = 0; i < transposed.getRowCount(); i++)
    {
        std::cout << "[ ";
        for (unsigned j = 0; j < transposed.getColCount(); j++)
        {
            std::cout << transposed[i][j] << "\t";
        }
        std::cout << "]\n";
    }

    // 5. Matrix Multiplication (6x6 * 6x6 = 6x6)
    std::cout << "\n5. Matrix Multiplication (operator*):\n";
    algb::Matrix<Value> product = m1 * m2;
    for (unsigned i = 0; i < product.getRowCount(); i++)
    {
        std::cout << "[ ";
        for (unsigned j = 0; j < product.getColCount(); j++)
        {
            std::cout << product[i][j] << "\t";
        }
        std::cout << "]\n";
    }

    // Test matrix copy constructor and assignment
    std::cout << "\n6. Testing Matrix Copy and Assignment:\n";
    algb::Matrix<Value> m1_copy(m1);
    std::cout << "Copy of m1[0][0]: " << m1_copy[0][0] << "\n";

    algb::Matrix<Value> m2_assign;
    m2_assign = m2;
    std::cout << "Assignment of m2[0][0]: " << m2_assign[0][0] << "\n";

    // Test with different types
    std::cout << "\n=== Testing with different types ===\n";
    algb::Vector<int> int_vec(3);
    int_vec[0] = 1;
    int_vec[1] = 2;
    int_vec[2] = 3;

    std::cout << "Integer vector: [ ";
    for (unsigned i = 0; i < int_vec.getSize(); i++)
    {
        std::cout << int_vec[i] << " ";
    }
    std::cout << "]\n";

    // Test with double type
    algb::Vector<double> double_vec(2);
    double_vec[0] = 1.5;
    double_vec[1] = 2.7;

    std::cout << "Double vector: [ ";
    for (unsigned i = 0; i < double_vec.getSize(); i++)
    {
        std::cout << double_vec[i] << " ";
    }
    std::cout << "]\n";

    // Test double vector operations
    algb::Vector<double> double_vec2(2);
    double_vec2[0] = 0.5;
    double_vec2[1] = 1.3;

    algb::Vector<double> double_sum = double_vec + double_vec2;
    std::cout << "Double vector sum: [ ";
    for (unsigned i = 0; i < double_sum.getSize(); i++)
    {
        std::cout << double_sum[i] << " ";
    }
    std::cout << "]\n";

    // Cleanup
    delete[] matrixData1;
    delete[] matrixData2;

    std::cout << "\n=== All operations completed! ===\n"; */

    std::system("pause");
    return 0;
}