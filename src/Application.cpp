#include <iostream>
#include "map"
#include "list"
#include "Sort.h"
#include "Utility.h"
#include <chrono>

class Application{
    typedef void (*ArrayGenerator)(int* array, int size, int leftBorder, int rightBorder);
    typedef void (*SortingAlgorithm)(int* array, size_t size);
public:
    Application()
    {
        arrayGenerators["fillRandom"] = (Utility::fillRandom);
        arrayGenerators["fillSorted"] = (Utility::fillSorted);
        arrayGenerators["fillSortedReversed"] = (Utility::fillSortedReversed);
        arrayGenerators["fillSortedWithSubArrays"] = (Utility::fillSortedSubArrays);
        arrayGenerators["fillSortedWithSwaps"] = (Utility::fillSortedWithSwaps);

        sortingAlgorithms["bubbleSort"] = Sort::bubbleSort;
        sortingAlgorithms["radixSort"] = Sort::radixSort;
    }

    int execute(int argc, char* argv[])
    {
        for (auto arrayGen : arrayGenerators){
            int* arrayToSort = new int[SIZE];
            arrayGen.second(arrayToSort, SIZE, std::stoi((std::string) argv[1]), std::stoi((std::string) argv[2]));
            for(auto sortingAlgorithm : sortingAlgorithms){
                std::chrono::time_point start = std::chrono::high_resolution_clock::now();
                sortingAlgorithm.second(arrayToSort, SIZE);
                std::chrono::time_point end = std::chrono::high_resolution_clock::now();

                std::cout << sortingAlgorithm.first << "using" << arrayGen.first << '\n'
                          << "size: " << SIZE << '\n'
                          << "time: " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
            }
        }
        return 0;
    }
private:
    std::map<std::string, ArrayGenerator> arrayGenerators;
    std::map<std::string, SortingAlgorithm> sortingAlgorithms;
    const int SIZE = 10000;
};
