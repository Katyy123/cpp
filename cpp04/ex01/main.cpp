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
const Animal* dog = new Dog();
std::cout << std::endl;
const Animal* cat = new Cat();
std::cout << std::endl;
const Animal* animalArray[ANIMALS_NUM];

for (int i = 0; i < ANIMALS_NUM; i++) {
	animalArray[i] = new Dog();
	std::cout << std::endl;
	animalArray[++i] = new Cat();
	std::cout << std::endl;
}

delete dog;//should not create a leak
std::cout << std::endl;
delete cat;
std::cout << std::endl;
for(int i = 0; i < ANIMALS_NUM; i++) {
	delete animalArray[i];
	std::cout << std::endl;
}

std::cout << "----- Deep copy test with copy constructor -----" << std::endl;
Dog dogToCopy;
std::cout << std::endl;
{
	Dog copiedDog = dogToCopy;
	std::cout << std::endl;
}
std::cout << "----- End of Deep copy test with copy constructor -----" << std::endl;
std::cout << std::endl;


std::cout << "----- Deep copy test with copy assignment operator -----" << std::endl;
Dog dogToCopy_2;
std::cout << std::endl;
Dog copiedDog_2;
std::cout << std::endl;
{
	copiedDog_2 = dogToCopy_2;
}
std::cout << "----- End of Deep copy test with copy assignment operator -----" << std::endl;
std::cout << std::endl;

return 0;
}

// int main()
// {
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// // std::cout << j->getType() << " " << std::endl;
// // std::cout << i->getType() << " " << std::endl;
// // i->makeSound(); //will output the cat sound!
// // j->makeSound();
// // meta->makeSound();

// std::cout << std::endl;
// std::cout << "Animal: ";
// meta->makeSound();

// std::cout << j->getType() << ": ";
// j->makeSound();

// std::cout << i->getType() << ": ";
// i->makeSound();
// std::cout << std::endl;

// delete meta;
// delete j;
// delete i;

// std::cout << std::endl;
// const WrongAnimal* wrong_meta = new WrongAnimal();
// const WrongAnimal* wrong_cat = new WrongCat();
// const WrongCat* wrong_cat_2 = new WrongCat();

// std::cout << std::endl;
// std::cout << "Animal: ";
// wrong_meta->makeSound();

// std::cout << wrong_cat->getType() << ": ";
// wrong_cat->makeSound();

// std::cout << wrong_cat_2->getType() << "_2: ";
// wrong_cat_2->makeSound();
// std::cout << std::endl;

// delete wrong_meta;
// delete wrong_cat;
// delete wrong_cat_2;

// return 0;
// }