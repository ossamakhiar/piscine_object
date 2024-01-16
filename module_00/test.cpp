#include <iostream>
#include <vector>
#include <map>


class Test {
    int x;

public:
    Test(int _x) : x(_x) {
        std::cout << "construction... of TEST\n";
    }

    Test(const Test& other)
    {
        std::cout << "Copying TEST..\n";
        this->x = other.x;
    }

    ~Test() {
        std::cout << "Test destruction...~~\n";
    }

    int get_x() const {
        return (x);
    }
};



class Holder {
    // std::vector<std::pair<int, Test> >   db;
    Test    *db;

public:
    Holder();

    void    createTest(const Test test);
    friend  std::ostream& operator<<(std::ostream& os, const Holder& h);
};



std::ostream& operator<<(std::ostream& os, const Holder& h)
{
    std::cout << h.db->get_x() << "\n";
    return (os);
}

Holder::Holder()
{
    std::cout << "Holder construction\n";
}

void    func1(const Test& t)
{
    Test lt = t;
}


void    Holder::createTest(const Test test)
{
    std::cout << "storing test\n";
    db = new Test(test);
    // func1(test);
    std::cout << "hereeee\n";
}




void    func(Holder& h)
{
    Test    t(88);

    h.createTest(t);
}


int main(void)
{
    Holder h;
    func(h);

    std::cout << "Printing\n";
    std::cout << h << "\n";
}