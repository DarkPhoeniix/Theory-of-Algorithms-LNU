#include "Application.h"
#include "Sort.h"
#include "Utility.h"

#include <iostream>
#include <chrono>

namespace
{
    bool validate(int argc, char* argv[])
    {
        bool result = true;
        if (argc < 4)
        {
            result &= 0;
        }

        int lowerBound = std::stoi(argv[1]);
        int upperBound = std::stoi(argv[2]);
        int step = std::stoi(argv[3]);

        if (lowerBound < 0 || upperBound < 0 || step < 0)
        {
            result &= 0;
        }
        else if (lowerBound > upperBound)
        {
            result &= 0;
        }
        else if ((upperBound - lowerBound) % step != 0)
        {
            result &= 0;
        }

        return result;
    }
}

Application::Application()
{
    arrayGenerators["fillRandom"] = Utility::fillRandom;
    arrayGenerators["fillSorted"] = Utility::fillSorted;
    arrayGenerators["fillSortedReversed"] = Utility::fillSortedReversed;
    arrayGenerators["fillSortedWithSubArrays"] = Utility::fillSortedSubArrays;
    arrayGenerators["fillSortedWithSwaps"] = Utility::fillSortedWithSwaps;

    sortingAlgorithms["bubbleSort"] = Sort::bubbleSort;
    sortingAlgorithms["radixSort"] = Sort::radixSort;
}

int Application::execute(int argc, char* argv[])
{
    if (!validate(argc, argv))
    {
        return 1;
    }

    int lowerBound = std::stoi(argv[1]);
    int upperBound = std::stoi(argv[2]);
    int step = std::stoi(argv[3]);

    for (int size = lowerBound; size <= upperBound; size += step)
    {
        for (auto arrayGen : arrayGenerators)
        {
            int* arrayToSort = new int[size];
            arrayGen.second(arrayToSort, size, -(size/2), (size/2));
            for(auto sortingAlgorithm : sortingAlgorithms)
            {
                std::chrono::time_point start = std::chrono::high_resolution_clock::now();
                sortingAlgorithm.second(arrayToSort, size);
                std::chrono::time_point end = std::chrono::high_resolution_clock::now();

                std::cout << sortingAlgorithm.first << "using" << arrayGen.first << '\n'
                          << "size: " << size << '\n'
                          << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
            }
        }
    }

    return 0;
}
