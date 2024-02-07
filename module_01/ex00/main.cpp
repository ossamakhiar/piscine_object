#include "Worker.hpp"


// ? Creating a worker and printing its details.
// ? The goal is to ensure that the Position and Statistic are constructed
// ? when the Worker is created and destroyed when it is destroyed.
void    test1()
{
    Position    crd = {1, 1, 1};
    Statistic   stat = {5, 8};

    Worker  worker("john", crd, stat);

    std::cout << worker << "\n";
    std::cout << "\e[1;32m---------------\e[0m\n";

    worker.set_cords({2, 0, 3});
    worker.set_stat({12, 20});


    std::cout << worker << "\n";
    std::cout << "\e[1;32m---------------\e[0m\n";
}

// ? This testing aims to observe the relationship between the Worker and Shovel (aggregation) and how it functions.
// ? The process involves creating multiple shovels and assigning them to different workers. 
// ? When a shovel is given to another worker, it is taken from the first worker.
void    test2()
{
    Position    crd = {1, 1, 1};
    Statistic   stat = {5, 8};
    Shovel  *shovel1 = new Shovel();


    Worker  john("john", crd, stat);

    std::cout << john << "\n";

    try {
        john.take_shovel(shovel1);
        john.use_shovel();

        Worker steeve("steeve", crd, stat);


        steeve.take_shovel(shovel1);
        steeve.use_shovel();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    delete shovel1;
}

// ? testing destroying a shovel that is used by a worker
void    test3()
{
    Position    crd = {5, 1, 4};
    Statistic   stat = {5, 8};
    Shovel  *shovel1 = new Shovel();
    Shovel  *shovel2 = new Shovel();

    Worker  alan("alan", crd, stat);

    try {
        alan.take_shovel(shovel1);

        delete shovel1;
        alan.use_shovel();
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }

    try {
        alan.take_shovel(shovel2);
        alan.use_shovel();
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }

    delete  shovel2;
}

int main(void)
{
    // test1();

    // test2();
    test3();
    return (0);
}