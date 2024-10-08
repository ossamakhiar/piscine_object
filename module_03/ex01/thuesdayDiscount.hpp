#ifndef THUESDAY_DISCOUNT_HPP
# define THUESDAY_DISCOUNT_HPP

#include "command.hpp"
#include <ctime>

class ThuesdayDiscount : Command
{
private:
    /* data */

    bool    is_thuesday()
    {
        std::time_t now = std::time(0);
        std::tm* time_info = std::localtime(&now);
    
        return (time_info->tm_wday == 2);
    }

public:
    ThuesdayDiscount(const std::string& date_, const std::string& client_, const std::vector<Article>& articles_) : Command(date_, client_, articles_) {

    };

    ~ThuesdayDiscount() {

    }

    double get_total_price() {
        double total = Command::get_total_price();
        double discount = 0;
    
        if (is_thuesday())
            discount = total * 0.1;
        return (total - discount);
    }
};



#endif