#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <algorithm>

class Harl {

public:
    Harl();
    ~Harl();

    void complain( std::string level );

private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
};

typedef struct	s_level_ptr {
	std::string	level;
	void	(Harl::*f)();
}				t_level_ptr;

#endif