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

    for (int i = 2; i < 200000; i += 2)
    {
        std::vector<int> vec(i, 42);
        vec[i / 2] = 1;
        
        std::set<int> set;
        for (int j = 0; j < vec.size(); j++)
        {
            if (j == i / 2) 
            {
                set.insert(1);
            }
            else 
            {
                set.insert(42);
            }
        }

        // bench
        auto vec_start = std::chrono::high_resolution_clock::now();
        auto ptr = std::find(vec.begin(), vec.end(), 1);
        vec.erase(ptr);
        auto vec_end = std::chrono::high_resolution_clock::now();

        auto set_start = std::chrono::high_resolution_clock::now();
        set.erase(1);
        auto set_end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> vec_diff = vec_end - vec_start;
        std::chrono::duration<double, std::milli> set_diff = set_end - set_start;

        // std::cout << vec_diff.count() << " " << set_diff.count() << std::endl;
        output << i << "," << vec_diff.count() << ",Vector\n";
        output << i << "," << set_diff.count() << ",Set\n";
    }
    output.close();
}