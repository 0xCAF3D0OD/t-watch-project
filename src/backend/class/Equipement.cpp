#include "Equipement.hpp"

// Constructeur / Destructeur /////////////////////////////////////////////////////////////////////////

Equipement::Equipement(const string& _id, const string& _description, const string& _pairedUserID)
		: id(_id), description(_description), pairedUserID(_pairedUserID)
{}

Equipement::~Equipement()
{}

// Getters ////////////////////////////////////////////////////////////////////////////////////////////

string Equipement::getId() const
{
	return id;
}

string Equipement::getDescription() const
{
	return description;
}

string Equipement::getPairedUserID() const
{
	return pairedUserID;
}

// Setters ////////////////////////////////////////////////////////////////////////////////////////////

void Equipement::setId(const string& _id)
{
	id = _id;
}

void Equipement::setDescription(const string& _description)
{
	description = _description;
}

void Equipement::setPairedUserID(const string& _pairedUserID)
{
	pairedUserID = _pairedUserID;
}

// Opérateur de comparaison ///////////////////////////////////////////////////////////////////////////

bool Equipement::operator==(const Equipement& other) const
{
	return id == other.id && description == other.description && pairedUserID == other.pairedUserID;
}