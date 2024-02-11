#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"


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
        john.take_tool(shovel1);
        john.work(shovel1);

        Worker steeve("steeve", crd, stat);


        steeve.take_tool(shovel1);
        steeve.work(shovel1);
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
    Hammer  *hammer1 = new Hammer();

    Worker  alan("alan", crd, stat);

    try {
        alan.take_tool(shovel1);

        delete shovel1;
        alan.work(shovel1);
        std::cout << "here\n";
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }

    try {
        alan.take_tool(shovel2);
        alan.take_tool(hammer1);
        alan.work(hammer1);
    } catch (std::exception& e) {
        std::cout << e.what() << "\n";
    }

    delete  shovel2;
    delete  hammer1;
}

void    test4()
{
    Position    crd = {5, 1, 4};
    Statistic   stat = {5, 8};
    Worker  alan("alan", crd, stat), bent("bent", crd, stat), steeve("steeve", crd, stat);
    Hammer  hammer;
    Shovel  shovel;
    Hammer  *hammer2 = new Hammer();
    Shovel  *shovel2 = new Shovel();

    Workshop<Shovel>    shovel_workshop1;
    Workshop<Hammer>    hammer_workshop1;

    std::cout << alan << "\n";
    std::cout << bent << "\n";
    std::cout << steeve << "\n";

    std::cout << "****************************\n";

    alan.take_tool(&shovel);
    alan.take_tool(&hammer);

    bent.take_tool(hammer2);

    steeve.take_tool(shovel2);

    alan.workshop_subscribing(&shovel_workshop1);
    alan.workshop_subscribing(&hammer_workshop1);

    bent.workshop_subscribing(&shovel_workshop1);
    bent.workshop_subscribing(&hammer_workshop1);

    steeve.workshop_subscribing(&shovel_workshop1);
    steeve.workshop_subscribing(&hammer_workshop1);

    shovel_workshop1.executeWorkDay();
    hammer_workshop1.executeWorkDay();

    std::cout << ORANGE << "bent" << WHITE << " will unsubscribe from the workshops\n";
    bent.workshop_unsubscribing(&shovel_workshop1);
    bent.workshop_unsubscribing(&hammer_workshop1);
    std::cout << "\n";

    shovel_workshop1.executeWorkDay();
    hammer_workshop1.executeWorkDay();

    delete shovel2;
    delete hammer2;
}

int main(void)
{
    // test1();

    // test2();
    // test3();
    test4();
    return (0);
}