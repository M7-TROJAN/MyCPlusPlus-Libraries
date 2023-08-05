#include "date.h"
using namespace std;

int main()
{

    stDate Date = readDateOldVersion();
    std::cout << "\n" << formateDate(Date) << "\n";
    std::cout << "\n" << formateDate(Date, "dd/mm/yyyy") << "\n";
    std::cout << "\n" << formateDate(Date, "yyyy/dd/mm") << "\n";
    std::cout << "\n" << formateDate(Date, "mm/dd/yyyy") << "\n";
    std::cout << "\n" << formateDate(Date, "mm-dd-yyyy") << "\n";
    std::cout << "\n" << formateDate(Date, "dd mm yyyy") << "\n";
    std::cout << "\n" << formateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";
    system("pause > nul");
}