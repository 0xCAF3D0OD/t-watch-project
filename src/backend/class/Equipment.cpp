#include "Equipment.hpp"

// Constructeur / Destructeur /////////////////////////////////////////////////////////////////////////

Equipment::Equipment()
{}

Equipment::Equipment(const string& _id, const string& _description, const string& _pairedUserID)
		: id(_id), description(_description), pairedUserID(_pairedUserID)
{}

Equipment::~Equipment()
{}

// Getters ////////////////////////////////////////////////////////////////////////////////////////////

string Equipment::getId() const
{
	return id;
}

string Equipment::getDescription() const
{
	return description;
}

string Equipment::getPairedUserID() const
{
	return pairedUserID;
}

// Setters ////////////////////////////////////////////////////////////////////////////////////////////

void Equipment::setId(const string& _id)
{
	id = _id;
}

void Equipment::setDescription(const string& _description)
{
	description = _description;
}

void Equipment::setPairedUserID(const string& _pairedUserID)
{
	pairedUserID = _pairedUserID;
}

// Opérateur de comparaison ///////////////////////////////////////////////////////////////////////////

bool Equipment::operator==(const Equipment& other) const
{
	return id == other.id && description == other.description && pairedUserID == other.pairedUserID;
}