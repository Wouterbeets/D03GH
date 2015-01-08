/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 10:31:26 by wbeets            #+#    #+#             */
/*   Updated: 2015/01/08 10:31:27 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <cstdlib>
#include <ctime>
//operators
FragTrap::FragTrap( std::string name ) :_name( name ) {
	std::cout << "wow! can youbelieve it? me "<< this->_name << " im being asebled in the DEFAULT CONSTRUCTOR yipeee!" << std::endl;
	this->_init();
	return;
}

FragTrap::FragTrap( FragTrap const & src ) {
	std::cout << "Haa its so good be unique! Hey >=( !! that guy looks just like me!" << std::endl;
	*this = src;
		return;
}

FragTrap::~FragTrap( void ) {
	std::cout << "Please dont teabag me when im dead ='(" << std::endl;
	return;
}
//constructors
FragTrap &	FragTrap::operator=(FragTrap const & rhs){
	std::cout << "im being constucted to look just like " << rhs.getName() << std::endl;
	this->_init();
	this->_name = rhs.getName();
	this->_hitpoints = rhs.getHitpoints();
	this->_maxHitPoints = rhs.getMaxHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
	this->_level = rhs.getLevel();
	this->_meleeAttackDamage = rhs.getMeleeAttackDamage();
	this->_rangedAttackDamage = rhs.getRangedAttackDamage();
	this->_armorDamageReduction = rhs.getArmorDamageReduction();
	return *this;
}

std::ostream &		operator<<( std::ostream & o, FragTrap const & i ){
	std::cout << i.getQuote() << std::endl;
	return o;
}

std::string		FragTrap::getName( void ) const {
	return this->_name;
}

unsigned int	FragTrap::getHitpoints( void ) const {
	return this->_hitpoints;
}

unsigned int	FragTrap::getMaxHitPoints( void ) const {
	return this->_maxHitPoints;
}

unsigned int	FragTrap::getEnergyPoints( void ) const {
	return this->_energyPoints;
}

unsigned int	FragTrap::getMaxEnergyPoints( void ) const {
	return this->_maxEnergyPoints;
}

unsigned int	FragTrap::getLevel( void ) const {
	return this->_level;
}

unsigned int	FragTrap::getMeleeAttackDamage( void ) const {
	return this->_meleeAttackDamage;
}

unsigned int	FragTrap::getRangedAttackDamage( void ) const {
	return this->_rangedAttackDamage;
}

unsigned int	FragTrap::getArmorDamageReduction( void ) const {
	return this->_armorDamageReduction;
}



void			FragTrap::rangedAttack(std::string const & target) const {
	std::cout << this->_name << " attacks " << target << " for " << this->_rangedAttackDamage << " of damage " <<std::endl;
}

void			FragTrap::meleeAttack(std::string const & target) const {
	std::cout << this->_name << " attacks " << target << " for " << this->_meleeAttackDamage << std::endl;
}

void			FragTrap::takeDamage(unsigned int amount){
	unsigned int	dam = amount > this->_armorDamageReduction ? amount - this->_armorDamageReduction : 0;
	if (this->_hitpoints < dam){
		this->_hitpoints = 0;
		std::cout << "please don't teabag my body when now that i've died" << std::endl;
	}else if (this->_hitpoints == 0){
		std::cout << this->_name << " is already dead, you cna;y kill it any further, it squecks and creaks when you attack it" << std::endl;
	} else {
		this->_hitpoints -= dam;
		std::cout << "owwww" << std::endl;
	}
}

void			FragTrap::beRepaired(unsigned int amount){
		this->_hitpoints += (amount + this->_hitpoints) < this->_maxHitPoints ? amount : this->_maxHitPoints - this->_hitpoints;
		if(this->_hitpoints == this->_maxHitPoints){
			std::cout << "wooooOOOOOWWW, i feel good Ta na Na na Ta na Na" << std::endl;
		} else {
			std::cout << "i believe thats a little better" << std::endl;
		}
}

void			FragTrap::_init(){
		this->_hitpoints = HIT_POINTS;
		this->_maxHitPoints =  MAX_HIT_POINTS;
		this->_energyPoints = ENERGY_POINTS;
		this->_maxEnergyPoints = MAX_ENERGY_POINTS;
		this->_level = LEVEL;
		this->_meleeAttackDamage = MELEE_ATTACK_DAMAGE;
		this->_rangedAttackDamage = RANGED_ATTACK_DAMAGE;
		this->_armorDamageReduction = ARMOR_DAMAGE_REDUCTION;
		std::srand(std::time(NULL));
}

void			FragTrap::vaulthunter_dot_exe(std::string const & target) const{
	std::cout << this->_name << " " <<  this->_getRanAttack() << std::endl;
	std::cout << target << " is crying in pain" << std::endl;
}

std::string		FragTrap::_getRanAttack( void ) const {
	static std::string	str[5] = {
			"opens a small hatch on it's chest, a tiny barrel slides out of it. a second later there is loud flash! The laser has fired an left a smoking black trail on the floor in its wake",
			"reloads it's weapon and suddenly explodes in flaming ball of fire. a moment laters is stepts out of the flames practicly unharmed ",
			"rolls closer to the enemy and kicks him in the balls... ow darn, no legs",
			"rolls away from the opponents and grabs his sniper riflle. aims, and FIRES! a great bolt of electricity flashes from the nuzzle of the gun. the enemy is completly missed though.... he hit a sheep instead",
			"falls alseep"
	};
	return str[rand() % 5];
}

std::string		FragTrap::getQuote( void ) const {
	static std::string 	str[20] = {"Great - another dead Vault Hunter. Handsome Jack's been busy. Wait a minute - You're not dead! YES! Now I can get off this glacier! Claptrap, your metaphorical ship has finally come in! (Right after intro, when Claptrap discovers you are not dead)",
	"Allow me to introduce myself - I am CL4P-TP steward bot, but my friends call me Claptrap! Or they would, if any of them were still alive. Or had existed in the first place! (Right after intro)",
	"Oh - I've got something for you! Here - take this ECHO communicator that I totally didn't loot from one of these corpses (Right after intro scene)",
	"Man, this is great! Now that I've met a mighty Vault Hunter, I can finally join the resistance in Sanctuary, take vengeance against Jack for killing my product line, and repair my central processor so I can stop thinking out loud! I wonder what it's like to have a belly button. (Shortly after intro)",
	"Well done! Your ability to walk short distances without dying will be Handsome Jack's Downfall! (Shortly after intro)",
	"Vamanos, minion! Arriba, arriba!",
	"Sorry about the mess. Everything Jack kills, he dumps here -- bandits, Vault Hunters, Claptrap units... If I sound pleased about this, it's only because my programmers made this my default tone of voice! I'm actually quite depressed! (Claptrap, when showing around Claptrap's Place)",
	"Just a little added security. Gotta keep those Bullymongs at bay, or they'll rip your eyes out (Claptrap, explaining why he has an eye scanner in the door to his place. Not two minutes pass, and a Bullywong named Knuckle Dragger enters from the completely exposed ceiling, and rips Claptrap's eye out.)",
	"Apart from the excruciating pain, this is great! I've been waiting for a mighty Vault Hunter to help me reach Sanctuary. I will be your wise leader, and you shall be my fearsome minion! (Claptrap, shortly after his eye gets ripped out)",
	"Great! Just let me get this door open and we'll hunt ourselves a Bullymong (During the mission Blindsided)",
	"Onward, seeing-eye minion! Let me know if I'm gonna run into anything!... Ah! I'll just assume you didn't see that (During the mission Blindsided)",
	"Ugh--- AGAIN?! Jack's tearing Pandora apart to find the Vault. They say Jack's drilling operations are causing those earthquakes. That, or your mom just got outta bed. ZING! (Blindsided)",
	"Oh! My eye just switched back on! I see a tough-looking minion, and an incredibly handsome robot. Which means that whoever has my eye... is very close (Blindsided)",
	"Got my eye? Great! Now we just gotta find someone to put it back into me. Much as I'm sure you'd like to jam your fist into my skull, optic surgery is best left for professionals (After retrieving Claptrap's Eye)",
	"Well, it was nice knowing ya! I hear getting eaten alive by Bullymongs isn't such a bad way to go (After Claptrap fails to open the Hyperion Barge Door)",
	"Did you know my head is at your crotch level? I'm trying not to think about it",
	"You make me so proud, minion. The way you're carrying on my fight against Handsome Jack. It brings a tear to my eye. A figurative one, of course. The saline content of actual tears would rust my eye quicker than you could say 'tetanus shot.'",
	"The jerk kept me as his torture plaything for a few months. We played game like 'dodge the blowtorch' and 'don't get dunked into the pool of acid.' I was really good at the first one. (about Captain Flynt)",
	"Now I've got my eyesight back, and you are far uglier than I remembered! (After Sir Hammerlock repairs his eye)",
	"I am the last Claptrap in existence and I AM GOING TO TEABAG YOUR CORPSE!"};

	return str[rand() % 20];
}





