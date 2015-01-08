/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:31:36 by wbeets            #+#    #+#             */
/*   Updated: 2015/01/08 10:31:38 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int		main(){
	FragTrap	Zaz("Zaz");
	FragTrap	ClapTrap;
	FragTrap	Xavier(Zaz);

	FragTrap *Clappie = new FragTrap("Clappie");
	std::cout << *Clappie << std::endl;
	std::cout << ClapTrap << std::endl;
	std::cout << ClapTrap << std::endl;
	std::cout << ClapTrap << std::endl;

	Zaz.vaulthunter_dot_exe("Zaz");	
	ClapTrap.vaulthunter_dot_exe("Kwame");	
	ClapTrap.vaulthunter_dot_exe("Xavier");	
	ClapTrap.vaulthunter_dot_exe("Power Ranger");	

	Zaz.takeDamage(80);
	Zaz.takeDamage(40);
	Zaz.takeDamage(40);
	Zaz.beRepaired(31);
	Zaz.beRepaired(70);
	Clappie->rangedAttack("Xavier");
	Zaz.meleeAttack("Xavier");
	delete Clappie;
}
