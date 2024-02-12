#ifndef IWORKSHOP_HPP
# define IWORKSHOP_HPP

// ? Workshop interface to abstarct type detail away and store all Workshops type in one single std::set<IWorkshop *>
class IWorkshop
{
public:
    // ? virtual destructor to ensure when delete called on IWorkshop it call the destructor of the concrete class also
    virtual ~IWorkshop() {};

    virtual void    signup(Worker *worker) = 0;
    virtual void    unregister(Worker *worker) = 0;
    virtual void    tool_loosed(Worker *worker) = 0;
    virtual void    executeWorkDay() = 0; // ? not nessecry to include this in the interface.
};

#endif
