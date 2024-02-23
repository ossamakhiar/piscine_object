#ifndef PACKAGE_REDUCTION_DISCOUNT_HPP
# define PACKAGE_REDUCTION_DISCOUNT_HPP

#include "command.hpp"

class PackageReductionDiscount : public Command
{
private:
    /* data */

public:
    PackageReductionDiscount(const std::string& date_, const std::string& client_, const std::vector<Article>& articles_) : Command(date_, client_, articles_) {

    };

    ~PackageReductionDiscount() {

    }

    double  get_total_price() {
        double  total = Command::get_total_price();
    
        total -= (total > 150) * 10;
        return (total);
    }
};



#endif