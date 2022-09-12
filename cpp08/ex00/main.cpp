#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

#define VALUE 42

int main(void) {
   
    {
        std::vector<int> myCont;
        std::vector<int>::const_iterator it;
        std::vector<int>::const_iterator it2;
        int position = 0;

        myCont.push_back(10);
        myCont.push_back(21);
        myCont.push_back(34);
        myCont.push_back(7);
        myCont.push_back(VALUE);

        it = easyfind(myCont, VALUE);
        for (it2 = myCont.begin(); it2 != myCont.end(); it2++)
        {
            if (*it2 == VALUE)
                break;
            ++position;
        }
        if (it2 == it)
            std::cout << "easyfind() function works well" << std::endl;
        else
            std::cout << "easyfind() function does not work well" << std::endl;
        std::cout << "Position of the value: " << position << std::endl;
    }

    {
        std::list<int> myCont;
        std::list<int>::const_iterator it;
        std::list<int>::const_iterator it2;
        int position = 0;

        myCont.push_back(VALUE);
        myCont.push_back(21);
        myCont.push_back(VALUE);
        myCont.push_back(7);
        myCont.push_back(VALUE);

        it = easyfind(myCont, VALUE);
        for (it2 = myCont.begin(); it2 != myCont.end(); it2++)
        {
            if (*it2 == VALUE)
                break;
            ++position;
        }
        if (it2 == it)
            std::cout << "easyfind() function works well" << std::endl;
        else
            std::cout << "easyfind() function does not work well" << std::endl;
        std::cout << "Position of the value: " << position << std::endl;
    }

    {
        std::deque<int> myCont;
        std::deque<int>::const_iterator it;

        myCont.push_back(20);
        myCont.push_back(21);
        myCont.push_back(89);
        myCont.push_back(7);
        myCont.push_back(98);

        try {
        it = easyfind(myCont, VALUE);
        }
        catch(std::exception & e) {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::vector<int> myCont;
        std::vector<int>::const_iterator it;

        try {
        it = easyfind(myCont, VALUE);
        }
        catch(std::exception & e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}