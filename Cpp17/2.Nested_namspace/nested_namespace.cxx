#include <iostream>

int add(int x, int y)
{
    return (x+y)*3;
}

namespace foo
{
    int add(int x, int y)
    {
        return (x+y)*2;
    }
}


namespace foo::goo
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    namespace active = foo::goo; // active now refers to foo::goo

    std::cout << active::add(1, 2) << '\n'; // This is really foo::goo::add()
    std::cout << foo::add(1,2) << std::endl;
    std::cout << ::add(1,2) << std::endl;
    

    return 0;
} // The active alias ends here