#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>



int main()
{
    setlocale(LC_ALL, "ru"); 
    std::vector<double> vec1; 
    double value = 0; 
    while (std::cin >> value && value != EOF) {
        vec1.push_back(sqrt(value));
    }
    for (int i = vec1.size() - 1; i >= 0; i--) {
        std::cout << std::fixed << std::setprecision(4) << vec1[i] << std::endl;
    }


}
