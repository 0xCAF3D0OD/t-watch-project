#include "User.hpp"

// Constructeur / Destructeur /////////////////////////////////////////////////////////////////////////

User::User(){}

User::User(const string& _id, const string& _cardID, const string& _name)
		: id(_id), cardID(_cardID), name(_name)
{}

User::~User()
{}

// Getters ////////////////////////////////////////////////////////////////////////////////////////////

string User::getId() const
{
	return id;
}

string User::getCardID() const
{
	return cardID;
}

string User::getName() const
{
	return name;
}

// Setters ////////////////////////////////////////////////////////////////////////////////////////////

void User::setId(const string& _id)
{
	id = _id;
}

void User::setCardID(const string& _cardID)
{
	cardID = _cardID;
}

void User::setName(const string& _name)
{
	name = _name;
}

// Opérateur de comparaison ///////////////////////////////////////////////////////////////////////////

bool User::operator==(const User& other) const
{
	return id == other.id && cardID == other.cardID && name == other.name;
}