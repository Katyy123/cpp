/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:09:26 by cfiliber          #+#    #+#             */
/*   Updated: 2022/06/20 15:59:27 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// j->makeSound();
// meta->makeSound();

std::cout << std::endl;
std::cout << "Animal: ";
meta->makeSound();

std::cout << j->getType() << ": ";
j->makeSound();

std::cout << i->getType() << ": ";
i->makeSound();
std::cout << std::endl;

delete meta;
delete j;
delete i;

std::cout << std::endl;
const WrongAnimal* wrong_meta = new WrongAnimal();
const WrongAnimal* wrong_cat = new WrongCat();
const WrongCat* wrong_cat_2 = new WrongCat();

std::cout << std::endl;
std::cout << "Animal: ";
wrong_meta->makeSound();

std::cout << wrong_cat->getType() << ": ";
wrong_cat->makeSound();

std::cout << wrong_cat_2->getType() << "_2: ";
wrong_cat_2->makeSound();
std::cout << std::endl;

delete wrong_meta;
delete wrong_cat;
delete wrong_cat_2;

return 0;
}