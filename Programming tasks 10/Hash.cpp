#include <iostream>
#include "HashSet.h"
#include "WordHashSet.h"

int main()
{
    HashSet hashSet = HashSet(11);

    hashSet.insert(4578);
    hashSet.insert(3799);
    hashSet.insert(7777);
    hashSet.insert(7777);
    hashSet.insert(1337);
    hashSet.insert(5959);
    hashSet.insert(2774);
    hashSet.insert(9310);

    hashSet.print();

    std::cout << "Contains 7777 ? " << hashSet.contains(7777) << std::endl;
    std::cout << "Contains 8888 ? " << hashSet.contains(8888) << std::endl;

    std::cout << std::endl;

    WordHashSet wordHashSet = WordHashSet(29);

    wordHashSet.insert("table");
    wordHashSet.insert("chair");
    wordHashSet.insert("choir");
    wordHashSet.insert("maple");
    wordHashSet.insert("cable");
    wordHashSet.insert("chain");
    wordHashSet.insert("train");
    wordHashSet.insert("elpam");

    wordHashSet.print();

    std::cout << "Contains stove ? " << wordHashSet.contains("stove") << std::endl;
    std::cout << "Contains train ? " << wordHashSet.contains("train") << std::endl;

}


