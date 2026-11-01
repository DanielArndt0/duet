#include "Duet.h"

#include <string>
#include <utility>

int main()
{
    Duet<int, std::string> entry(1, "one");

    entry.setFirst(2);
    entry.setSecond("two");

    if (entry.getFirst() != 2 || entry.getSecond() != "two")
        return 1;

    entry.setDuet(3, "three");

    Duet<int, std::string> copied(entry);
    Duet<int, std::string> moved(std::move(copied));

    const Duet<int, std::string> &readOnly = moved;
    if (readOnly.getFirst() != 3 || readOnly.getSecond() != "three")
        return 1;

    Duet<int, std::string> created =
        Duet<int, std::string>::CreateDuet(4, "four");

    return created.getFirst() == 4 && created.getSecond() == "four" ? 0 : 1;
}
