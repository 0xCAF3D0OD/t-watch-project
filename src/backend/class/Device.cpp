#include "Device.hpp"

// Constructeur / Destructeur /////////////////////////////////////////////////////////////////////////

Device::Device()
{}

Device::Device(const string& _id, const string& _description)
		: id(_id), description(_description), pairedUserID("")
{}

Device::~Device()
{}

// Getters ////////////////////////////////////////////////////////////////////////////////////////////

string Device::getId() const
{
	return id;
}

string Device::getDescription() const
{
	return description;
}

string Device::getPairedUserID() const
{
	return pairedUserID;
}

// Setters ////////////////////////////////////////////////////////////////////////////////////////////

void Device::setId(const string& _id)
{
	id = _id;
}

void Device::setDescription(const string& _description)
{
	description = _description;
}

void Device::setPairedUserID(const string& _pairedUserID)
{
	pairedUserID = _pairedUserID;
}

// Opérateur de comparaison ///////////////////////////////////////////////////////////////////////////

bool Device::operator==(const Device& other) const
{
	return id == other.id && description == other.description && pairedUserID == other.pairedUserID;
}