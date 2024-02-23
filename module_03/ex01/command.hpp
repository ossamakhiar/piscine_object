#ifndef COMMAND_HPP
# define COMMAND_HPP

#include <iostream>
#include <string>
#include <vector>

struct Article
{
    std::string article;
    double      price;
    int         quantity;

    double  get_subtotal() {
        return (quantity * price);
    }
};


class Command
{
protected:
    static int              count;
    int                     id;
    std::string             date;
    std::string             client;
    std::vector<Article>    articles;

public:
    Command(const std::string& date_, const std::string& client_, const std::vector<Article>& articles_) {
        id = count;
        date = date_;
        client = client_;
        articles = articles_;
        count++;
    };

    virtual ~Command() {

    };

    virtual double get_total_price() {
        double  total = 0;
        for (size_t i = 0; i < articles.size(); i++)
            total += articles[i].get_subtotal();
        // Violation of the principle
        // if (is_thuesday())
        //     // something
        // else if (total > 150)
        //     // something
        // else if (sfg)
        return (total);
    };
};

int Command::count = 0;

#endif