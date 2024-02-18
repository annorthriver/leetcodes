#include <vector>

template <typename T>
void print(const std::vector<T>& container)
{
    for (T x : container)
        std::cout << x << ' ';
    std::cout << '\n';
}

template <typename T>
void print(const std::vector<std::vector<T>>& container)
{
    for (auto x : container)
        print(x);
}