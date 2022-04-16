#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS _HPP

# include <iostream>

class Sample {

public:
	float const	a;
	int			b;

	Sample(float const c);
	~Sample(void);

	void bla(void) const;
};

#endif