#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

# include <iostream>

class Sample {

public:
	Sample(void);
	~Sample(void);
	static int	getNbInst(void); //non member function

private:
	static int	_nbInst; //non member attribute
};

#endif