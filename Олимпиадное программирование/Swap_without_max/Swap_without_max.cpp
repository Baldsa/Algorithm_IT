#include <iostream>
#include <vector>
#include <algorithm>

//std::string Solution(std::vector<int>, std::vector<int>, int, int, int);


int main() {
    int number_of_values;
    std::cin >> number_of_values;
    while (number_of_values--) {
        int size;
        std::cin >> size;
        std::vector<int> vec1(size), vec2(size);
        for (int i = 0; i < size; i++) {
            std::cin >> vec1[i];
        }
        for (int i = 0; i < size; i++) {
            std::cin >> vec2[i];
        }
        int max_a = *std::max_element(vec1.begin(), vec1.end());
        int max_b = *std::max_element(vec2.begin(), vec2.end());
        int index_1 = std::distance(vec1.begin(), std::max_element(vec1.begin(), vec1.end()));
        int index_2 = std::distance(vec2.begin(), std::max_element(vec2.begin(), vec2.end()));
        bool possible = true;
        for (int i = 0; i < size; i++) {
            if ((vec1[i] <= max_a) && (vec2[i] <= max_b)) {
                std::cout << "Yes\n";
                break;
            }
            else
            {
                int temp = vec1[index_1];
                vec1[index_1] = vec2[index_2];
                vec2[index_2] = temp;
                for (int i = 0; i < size; i++) {
                    if ((vec1[i] <= max_b) && (vec2[i] <= max_a)) {
                        std::cout << "Yes\n";
                        break;
                    }
                    else
                    {
                        std::cout << "No\n";
                    }

                }

            }
        }
        
    }
}
// 7 9 7  max = 9 
// 7 6 9  max = 9 
/*std::string Solution(std::vector<int> vec1, std::vector<int> vec2, int max_1, int max_2, int size) {
    int size = size; 
    int last_num = vec1[size - 1];
    if (last_num == max_1){
        vec2.()
    
    }
 */





