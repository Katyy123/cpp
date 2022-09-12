#include <iostream>
#include <vector>
#include "Span.hpp"

#define VALUE 42

int main(void) {

    {
        Span sp = Span(5);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        //test Span is full
        try {
            sp.addNumber(29);
        }
        catch(std::exception & e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << std::endl;

    {
        Span sp = Span(5);
        std::vector<int> myVector;

        myVector.push_back(8);
        myVector.push_back(14);
        myVector.push_back(26);
        myVector.push_back(1);
        myVector.push_back(4);
        
        sp.addNumber(myVector.begin(), myVector.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << std::endl;

    {
        //test No span can be found
        Span sp = Span(1);
        
        sp.addNumber(42);

        try {
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        }
        catch(std::exception & e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        }
        catch(std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << std::endl;

    {
        //test with min 10000 numbers
        Span sp = Span(20000);
		std::vector<int>	myVector;

        srand(time(NULL));
		while (myVector.size() < 20000)
			myVector.push_back(rand());

		sp.addNumber(myVector.begin(), myVector.end());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    }

    return 0;
}