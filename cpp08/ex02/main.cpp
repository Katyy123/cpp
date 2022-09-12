#include <iostream>
#include "MutantStack.hpp"
#include "MutantStack.tpp"
#include <list>

int main()
{
    {
        //test with MutantStack
        std::cout << " ---------- Test with MutantStack ---------- " << std::endl << std::endl;

        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Top element: " << mstack.top() << std::endl;

        mstack.pop();
        std::cout << "Size: " << mstack.size() << std::endl;
        std::cout << std::endl;

        mstack.push(3);
        mstack.push(-5);
        mstack.push(737);
        mstack.push(0);
        mstack.push(342);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "Elements (from 'front' to 'back'): " << std::endl;
        while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
        }
        std::cout << std::endl;

        std::stack<int> copy(mstack);
        std::cout << "Top element of mstack: " << mstack.top() << std::endl;
        std::cout << "Top element of copy: " << copy.top() << std::endl;
        std::cout << "Size of mstack: " << mstack.size() << std::endl;
        std::cout << "Size of copy: " << copy.size() << std::endl;
    }

    std::cout << std::endl << std::endl;

    {
        //test with std::list
        std::cout << " ---------- Test with std::list ---------- " << std::endl << std::endl;
        std::list<int> mstack;

        mstack.push_back(5);
        mstack.push_back(17);

        std::cout << "Top element: " << mstack.back() << std::endl;

        mstack.pop_back();
        std::cout << "Size: " << mstack.size() << std::endl;
        std::cout << std::endl;

        mstack.push_back(3);
        mstack.push_back(-5);
        mstack.push_back(737);
        mstack.push_back(0);
        mstack.push_back(342);

        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "Elements (from 'front' to 'back'): " << std::endl;
        while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
        }
        std::cout << std::endl;

        std::list<int> copy(mstack);
        std::cout << "Top element of mstack: " << mstack.back() << std::endl;
        std::cout << "Top element of copy: " << copy.back() << std::endl;
        std::cout << "Size of mstack: " << mstack.size() << std::endl;
        std::cout << "Size of copy: " << copy.size() << std::endl;
    }

    return 0;
}