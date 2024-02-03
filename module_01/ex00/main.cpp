#include "Worker.hpp"

int main(void)
{
    Position    crd = {1, 1, 1};
    Statistic   stat = {5, 8};

    Worker  worker(crd, stat);

    std::cout << worker << "\n";
    std::cout << "\e[1;32m---------------\e[0m\n";

    worker.set_cords({2, 0, 3});
    worker.set_stat({12, 20});


    std::cout << worker << "\n";
    std::cout << "\e[1;32m---------------\e[0m\n";
    return (0);
}