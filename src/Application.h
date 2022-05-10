#ifndef TASK_01_APPLICATION_H
#define TASK_01_APPLICATION_H

#include <iostream>
#include <map>
#include <functional>

class Application{
public:
    Application();
    int execute(int argc, char* argv[]);
private:
    using SortingAlgorithm = std::function<void(int*, size_t)>;
    using ArrayGenerator = std::function<void(int*, int, int, int)>;

    std::map<std::string, ArrayGenerator> arrayGenerators;
    std::map<std::string, SortingAlgorithm> sortingAlgorithms;
};

#endif
