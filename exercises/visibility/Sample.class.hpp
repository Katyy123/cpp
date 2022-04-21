#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

# include <iostream>

class Sample {

public:
	int	publicFoo;
	Sample(void);
	~Sample(void);
	void	publicFunct(void);

private:
	int	_privateFoo;
	void	_privateFunct(void);
};

#endif