
#include "Application.h"
#include "Sort.h"
#include "Utility.h"

#include <iostream>
#include <chrono>
#include <pybind11/embed.h>
#include <pybind11/cast.h>
#include <pybind11/stl.h>

namespace
{
    bool validate(int argc, char* argv[])
    {
        bool result = true;

        if (argc < 6)
        {
            result &= 0;
        }

        int lowerBound = std::stoi(argv[2]);
        int upperBound = std::stoi(argv[3]);
        int step = std::stoi(argv[4]);

        if ((lowerBound < 0) || (upperBound < 0) || (step < 0))
        {
            result &= 0;
        }
        else if (lowerBound > upperBound)
        {
            result &= 0;
        }
        else if (argv[5] != std::string("-py") && argv[5] != std::string("-cpp"))
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
    sortingAlgorithms["stdSort"] = Sort::stdSort;
}

int Application::execute(int argc, char* argv[])
{
    if (!validate(argc, argv))
    {
        return 1;
    }

    pybind11::scoped_interpreter guard{};
    pybind11::exec(R"(
                import sys
                import os
                sys.path.append(os.path.abspath(os.getcwd()))
    )");

    pybind11::module_ pyBubbleSortModule = pybind11::module_::import("scripts.bubble_sort");
    pybind11::module_ pyRadixSortModule = pybind11::module_::import("scripts.radix_sort");
    pybind11::module_ pyStdSortModule = pybind11::module_::import("scripts.std_sort");

    std::string name = argv[1];
    int lowerBound = std::stoi(argv[2]);
    int upperBound = std::stoi(argv[3]);
    int step = std::stoi(argv[4]);
    std::string type = argv[5];

    std::chrono::time_point start = std::chrono::high_resolution_clock::now();
    std::chrono::time_point end = std::chrono::high_resolution_clock::now();
    for (int size = lowerBound; size <= upperBound; size += step)
    {
        for (const auto &arrayGenerator: arrayGenerators)
        {
            int *arrayToSort = new int[size];
            arrayGenerator.second(arrayToSort, size, -(size / 2), (size / 2));

            if (type == "-cpp")
            {
                auto sortingAlgorithm = sortingAlgorithms.find(name)->second;
                start = std::chrono::high_resolution_clock::now();
                sortingAlgorithm(arrayToSort, size);
                end = std::chrono::high_resolution_clock::now();
            }
            else
            {
                if (argv[1] == std::string("bubbleSort"))
                {
                    auto sortingAlgorithm = pyBubbleSortModule.attr("bubble_sort");
                    pybind11::list pyList = pybind11::cast(std::vector<int>(arrayToSort, arrayToSort + size));
                    start = std::chrono::high_resolution_clock::now();
                    sortingAlgorithm(pyList);
                    end = std::chrono::high_resolution_clock::now();
                }
                else if (argv[1] == std::string("radixSort"))
                {
                    auto sortingAlgorithm = pyRadixSortModule.attr("radix_sort");
                    pybind11::list pyList = pybind11::cast(std::vector<int>(arrayToSort, arrayToSort + size));
                    start = std::chrono::high_resolution_clock::now();
                    sortingAlgorithm(pyList);
                    end = std::chrono::high_resolution_clock::now();
                }
                else if (argv[1] == std::string("stdSort"))
                {
                    auto sortingAlgorithm = pyStdSortModule.attr("std_sort");
                    pybind11::list pyList = pybind11::cast(std::vector<int>(arrayToSort, arrayToSort + size));
                    start = std::chrono::high_resolution_clock::now();
                    sortingAlgorithm(pyList);
                    end = std::chrono::high_resolution_clock::now();
                }
            }

            std::cout << name << " using " << arrayGenerator.first << '\n'
                      << "size: " << size << '\n'
                      << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                      << " ms" << '\n' << std::endl;

            delete[] arrayToSort;
        }
    }

    return 0;
}
