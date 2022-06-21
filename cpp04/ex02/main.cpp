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
	// const AAnimal* meta = new AAnimal(); //can't be instantiate since AAnimal is abstract
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();

	std::cout << std::endl;
	std::cout << "Animal: ";
	//meta->makeSound();

	std::cout << j->getType() << ": ";
	j->makeSound();

	std::cout << i->getType() << ": ";
	i->makeSound();
	std::cout << std::endl;

	//delete meta;
	delete j;
	delete i;
}