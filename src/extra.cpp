#include <vector>
#include <set>

#include <chrono>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

int main()
{
    std::ofstream output;
    output.open("minibench.csv");
    output << "length,deleting,Class\n";

    for (int i = 2; i < 4000; i += 2)
    {
        std::vector<int> vec(i, 42);
        vec[i / 2] = i / 2;
        
        std::set<int> set;
        for (int j = 0; j < vec.size(); j++)
        {
           set.insert(j);
        }

        // bench
        auto vec_start = std::chrono::high_resolution_clock::now();
        auto ptr = std::find(vec.begin(), vec.end(), i / 2);
        vec.erase(ptr);
        auto vec_end = std::chrono::high_resolution_clock::now();

        auto set_start = std::chrono::high_resolution_clock::now();
        set.erase(i / 2);
        auto set_end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::nano> vec_diff = vec_end - vec_start;
        std::chrono::duration<double, std::nano> set_diff = set_end - set_start;

        // std::cout << vec_diff.count() << " " << set_diff.count() << std::endl;
        output << i << "," << vec_diff.count() << ",Vector\n";
        output << i << "," << set_diff.count() << ",Set\n";
    }
    output.close();
}