#include "MateriaSource.hpp"


MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_materias[i] = NULL;
}


MateriaSource::MateriaSource(const MateriaSource & source)
{
	*this = source;
}


MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if (_materias[i])
			delete _materias[i];
}


MateriaSource & MateriaSource::operator=(const MateriaSource & rhs)
{
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


void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_materias[i])
		{
			_materias[i] = materia;
			break ;
		}
	}
}


AMateria* MateriaSource::createMateria(const std::string & type)
{
	for (int i = 0; i < 4; i++)
		if (!type.compare(_materias[i]->getType()))
			return (_materias[i]->clone());
	std::cout << "Unkown Materia type" << std::endl;
	return (NULL);
}
