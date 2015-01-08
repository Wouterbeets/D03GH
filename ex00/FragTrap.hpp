/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:31:30 by wbeets            #+#    #+#             */
/*   Updated: 2015/01/08 10:31:33 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include <iostream>

#define HIT_POINTS  100
#define MAX_HIT_POINTS  100
#define ENERGY_POINTS  100
#define MAX_ENERGY_POINTS  100
#define LEVEL  1
#define NAME  Parameter_of_constructor
#define MELEE_ATTACK_DAMAGE  30
#define RANGED_ATTACK_DAMAGE  20
#define ARMOR_DAMAGE_REDUCTION  5


class FragTrap {
	public:
		//constructors
		FragTrap( std::string const name = "CLAPTRAP");
		FragTrap(FragTrap const & src);
		~FragTrap();

		//operator overloads
		FragTrap &	operator=(FragTrap const & rhs);

		//getters

		std::string		getName( void ) const;
		unsigned int	getHitpoints( void ) const;
		unsigned int	getMaxHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getMaxEnergyPoints( void ) const;
		unsigned int	getLevel( void ) const;
		unsigned int	getMeleeAttackDamage( void ) const;
		unsigned int	getRangedAttackDamage( void ) const;
		unsigned int	getArmorDamageReduction( void ) const;


		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			rangedAttack(std::string const & target) const;
		void			meleeAttack(std::string const & target) const;

		std::string		getQuote( void ) const;
		void			vaulthunter_dot_exe(std::string const & target) const;


		
	private:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_maxHitPoints;
		unsigned int	_energyPoints;
		unsigned int	_maxEnergyPoints;
		unsigned int	_level;
		unsigned int	_meleeAttackDamage;
		unsigned int	_rangedAttackDamage;
		unsigned int	_armorDamageReduction;

		std::string		_getRanAttack( void ) const;
		void			_init();

};

std::ostream &		operator<<(std::ostream & o, FragTrap const & i);

#endif /*FRAGtRAP_HPP*/
