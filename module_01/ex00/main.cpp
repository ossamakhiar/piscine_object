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


    Position    crd1 = {2, 0, 3};
    Statistic   stat1 = {12, 20};
    worker.set_cords(crd1);
    worker.set_stat(stat1);


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

    try {
        shovel_workshop1.signup(&alan);
        hammer_workshop1.signup(&alan);
    }
    catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << "\n";
    }

    try {
        shovel_workshop1.signup(&steeve);
        hammer_workshop1.signup(&steeve);
    } catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << "\n";
    }

    try {
        hammer_workshop1.signup(&bent);
        shovel_workshop1.signup(&bent);
    } catch (std::exception& e) {
        std::cout << "ERROR: " << e.what() << "\n";
    }

    shovel_workshop1.executeWorkDay();
    hammer_workshop1.executeWorkDay();

    std::cout << ORANGE << "bent" << WHITE << " will unsubscribe from the workshops\n";
    shovel_workshop1.unregister(&bent);
    hammer_workshop1.unregister(&bent);
    std::cout << "\n";

    shovel_workshop1.executeWorkDay();
    hammer_workshop1.executeWorkDay();

    delete shovel2;
    delete hammer2; 
}


// ? This test ensures that when a worker passes away, they are no longer tied to the tools,
// ? and any workshops they participated in will no longer retain those associations
void    test5()
{
    Position    crd = {5, 1, 4};
    Statistic   stat = {5, 8};
    Worker  *alan = new Worker("alan", crd, stat);
    Tool    *shovel = new Shovel();
    Tool    *shovel1 = new Shovel();
    Tool    *hammer = new Hammer();

    IWorkshop    *shovel_workshop = new Workshop<Shovel>();
    IWorkshop    *hammer_workshop = new Workshop<Hammer>();

    alan->take_tool(shovel);
    alan->take_tool(shovel1);
    alan->take_tool(hammer);

    shovel_workshop->signup(alan);
    hammer_workshop->signup(alan);

    shovel_workshop->executeWorkDay();
    hammer_workshop->executeWorkDay();

    std::cout << "\e[1;35mWhat will happen if will remove alan\n\e[0m";
    delete alan;

    delete shovel;
    delete shovel1;
    delete hammer;
    delete hammer_workshop;
    delete shovel_workshop;

}

int main(void)
{
    // test1();

    // test2();
    // test3();
    // test4();
    test5();
    return (0);
}