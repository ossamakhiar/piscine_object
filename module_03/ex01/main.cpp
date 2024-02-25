/***************************/
/** Open/Closed principle **/
/***************************/

#include "packageReductionDiscount.hpp"
#include "thuesdayDiscount.hpp"
#include <ctime>

int main(void)
{
    std::vector<Article>    arts;

    arts.push_back({"Apple Vision Pro", 4152.0, 4});
    arts.push_back({"Macbook 2023", 968.0, 2});
    arts.push_back({"PS5", 745.5, 3});

    Command command("2024-02-23", "oussama", arts);
    std::cout << "Regular Command Total Price: " << command.get_total_price() << "\n";

    ThuesdayDiscount    thuersday_command("2024-02-24", "alan walker", arts);
    std::cout << "Thuersday Discount Command Total Price: " << thuersday_command.get_total_price() << "\n";

    PackageReductionDiscount    reduction_command("2024-02-24", "alan walker", arts);
    std::cout << "PackageReductionDiscount Command Total Price: " << reduction_command.get_total_price() << "\n";

    return (0);
}