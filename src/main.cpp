
#define PY_SSIZE_T_CLEAN
#include <python3.10/Python.h>
#include "Utility.h"

#include <iostream>
#include <chrono>


const int SIZE = 1000000;

int main(int argc, char* argv[])
{
    Py_Initialize();
    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is',ctime(time()))\n");
    Py_Finalize();
//    int* array = new int[SIZE];
//
//    Utility::fillRandom(array, SIZE, -100, 100);
//
//    std::chrono::time_point start = std::chrono::high_resolution_clock::now();
//    // TODO: sort here
//    std::chrono::time_point end = std::chrono::high_resolution_clock::now();
//
//    std::cout << "Data: " << '\n'
//        << "size: " << SIZE << '\n'
//        << "time: " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
//
//    delete[] array;

    return 0;
}
