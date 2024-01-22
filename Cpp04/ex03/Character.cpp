#include "Character.hpp"


Character::Character()
{
	//std::cout << "Default constructor called" << sdt::endl;
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}


Character::Character(const Character& character)
{
	*this = character;
}


Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if (_materias[i])
			delete _materias[i];
	//std::cout << "Character destructor called" << std::endl
}


Character & Character::operator=(const Character & rhs)
{
	_name = rhs._name;
	for (int i = 0; i < 4; i++)
	{
		if (rhs._materias[i])
		{
			if (_materias[i])
				delete _materias[i];
			_materias[i] = rhs._materias[i]->clone();
		}
		else
			_materias[i] = NULL;
	}
	return (*this);
}


Character::Character(std::string name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}


std::string const & Character::getName() const
{
	return (_name);
}


void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_materias[i])
		{
			_materias[i] = m;
			break ;
		}
	}
}


void Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0)
		_materias[idx] = NULL;
}


void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0 || !_materias[idx])
		return ;
	_materias[idx]->use(target);
}



