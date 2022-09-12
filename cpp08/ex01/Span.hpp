#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iterator>
# include <exception>
# include <vector>

class Span {

    public:
        Span(unsigned int N);
        Span(Span const & span);
        ~Span();

        Span & operator=(Span const & span);

        class InvalidSizeException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        class FullSpanException : public std::exception {
            public:
                virtual const char * what() const throw();
        };
        class NoSpanCanBeFoundException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        void addNumber(unsigned int n);

        unsigned int shortestSpan();
        unsigned int longestSpan();

    private:
        Span();
        std::vector<int> _numbers;
        unsigned int _N;//max number of int Span can store
};

#endif