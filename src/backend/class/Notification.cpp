#include "Notification.hpp"

// Constructeur / Destructeur ///////////////////////////////////////////////////////////////////////////////////
Notification::Notification(const string& _eqtID, const string& _title, const string& _description,
							const unsigned int& _priority, const unsigned int& _id, bool _acked)
	: eqtID(_eqtID), title(_title), description(_description), priority(_priority), id(_id), acked(_acked)
{}

Notification::~Notification()
{}

// Getters //////////////////////////////////////////////////////////////////////////////////////////////////////

string Notification::getEqtID() const
{
	return eqtID;
}

string Notification::getTitle() const
{
	return title;
}

string Notification::getDescription() const
{
	return description;
}

unsigned int Notification::getPriority() const
{
	return priority;
}

unsigned int Notification::getID() const
{
	return id;
}

bool Notification::getAcked() const
{
	return acked;
}

// Setters //////////////////////////////////////////////////////////////////////////////////////////////////////

void Notification::setEqtID(const string& _eqtID)
{
	eqtID = _eqtID;
}

void Notification::setTitle(const string& _title)
{
	title = _title;
}

void Notification::setDescription(const string& _description)
{
	description = _description;
}

void Notification::setPriority(const unsigned int& _priority)
{
	priority = _priority;
}

void Notification::setID(const unsigned int& _id)
{
	id = _id;
}

void Notification::setAcked(bool _acked)
{
	acked = _acked;
}

// Opérateur de comparaison ////////////////////////////////////////////////////////////////////////////////////

bool Notification::operator==(const Notification& other) const {
	return eqtID == other.eqtID && title == other.title && description == other.description &&
			priority == other.priority && id == other.id && acked == other.acked;
}
