/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:09:26 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 20:09:55 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "----- Beginning of virtual destructor test -----" << std::endl;

	std::cout << std::endl;
	const Animal *dog = new Dog();
	std::cout << std::endl;
	const Animal *cat = new Cat();
	std::cout << std::endl;
	const Animal *animalArray[ANIMALS_NUM];

	for (int i = 0; i < ANIMALS_NUM; i++)
	{
		animalArray[i] = new Dog();
		std::cout << std::endl;
		animalArray[++i] = new Cat();
		std::cout << std::endl;
	}

	delete dog; // should not create a leak
	std::cout << std::endl;
	delete cat;
	std::cout << std::endl;
	for (int i = 0; i < ANIMALS_NUM; i++)
	{
		delete animalArray[i];
		std::cout << std::endl;
	}

	std::cout << "----- End of virtual destructor test -----" << std::endl;
	std::cout << std::endl;
	std::cout << "----- Beginning of deep copy test with copy constructor -----" << std::endl;

	std::cout << std::endl;
	const Dog *dog1 = new Dog();
	std::cout << std::endl;
	const Dog *dogCopy = new Dog(*dog1);
	std::cout << std::endl;

	dog1->getBrain()->setIdea("I'm hungry");
	dog1->getBrain()->setIdea("I want that bone");
	dogCopy->getBrain()->setIdea("I'm sleepy");
	dogCopy->getBrain()->setIdea("I wanna go to bed");

	std::cout << "dog1's brain: " << std::endl;
	dog1->getBrain()->printIdeas();
	std::cout << std::endl;
	std::cout << "dogCopy's brain: " << std::endl;
	dogCopy->getBrain()->printIdeas();
	std::cout << std::endl;
	
	delete dogCopy;
	std::cout << std::endl;

	std::cout << "dog1's brain after deleting dogCopy: " << std::endl;
	dog1->getBrain()->printIdeas();
	std::cout << std::endl;

	delete dog1;
	std::cout << std::endl;

	std::cout << "----- End of deep copy test with copy constructor -----" << std::endl;
	std::cout << std::endl;
	std::cout << "----- Beginning of deep copy test with copy assignment operator -----" << std::endl;

	std::cout << std::endl;
	Dog *dog2 = new Dog();
	std::cout << std::endl;
	Dog *dogCopy2 = new Dog();
	std::cout << std::endl;
	*dogCopy2 = *dog2;
	std::cout << std::endl;

	dog2->getBrain()->setIdea("I'm thirsty");
	dog2->getBrain()->setIdea("I want that coke");
	dogCopy2->getBrain()->setIdea("I'm tired");
	dogCopy2->getBrain()->setIdea("I wanna go on the sofa");

	std::cout << "dog2's brain: " << std::endl;
	dog2->getBrain()->printIdeas();
	std::cout << std::endl;
	std::cout << "dogCopy2's brain: " << std::endl;
	dogCopy2->getBrain()->printIdeas();
	std::cout << std::endl;

	std::cout << std::endl;
	delete dogCopy2;
	std::cout << std::endl;

	std::cout << "dog2's brain after deleting dogCopy2: " << std::endl;
	dog2->getBrain()->printIdeas();
	std::cout << std::endl;

	delete dog2;
	std::cout << std::endl;

	std::cout << "----- End of deep copy test with copy assignment operator -----" << std::endl;

	return 0;
}