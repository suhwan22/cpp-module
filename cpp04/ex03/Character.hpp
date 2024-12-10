/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhkim <suhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:39:29 by suhkim            #+#    #+#             */
/*   Updated: 2023/03/14 18:53:08 by suhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Ground.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria*	_inventory[4];
		Ground	_ground;

	public:
		Character();
		Character(std::string name);
		Character(const Character& obj);
		Character& operator=(const Character& obj);
		~Character();

		std::string	const & getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};

#endif
