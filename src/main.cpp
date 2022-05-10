
#include "Utility.h"
#include "Sort.h"

#include <exception>
#include <vector>
#include <pybind11/embed.h>
#include <pybind11/cast.h>
#include <pybind11/stl.h>

const int SIZE = 10;

int main(int argc, char* argv[])
{
    pybind11::scoped_interpreter guard{};
    pybind11::exec(R"(
                import sys
                import os
                sys.path.append(os.path.abspath(os.getcwd()))
    )");

    pybind11::module_ pyModule = pybind11::module_::import("scripts.bubble_sort");

    int* array = new int[SIZE];
    Utility::fillRandom(array, SIZE, -100, 100);

    auto pyBubbleSort = pyModule.attr("bubble_sort");
    pybind11::list pyList = pybind11::cast(std::vector<int>(array, array + SIZE));
    pyBubbleSort(pyList, SIZE);

    delete[] array;
    return 0;
}
