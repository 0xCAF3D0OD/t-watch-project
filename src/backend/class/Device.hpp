#ifndef DEVICE_HPP
#define DEVICE_HPP

#include "../../main.hpp"
#include "User.hpp"

class User;

class Device
{
	private:
		string	id;
		string	description;
		string	pairedUserID;

	public:
		// Constructeur / Destructeurs
    	Device(const string& _id, const string& _description);
		~Device();

		// Getters
		string getId() const;
		string getDescription() const;
		string getPairedUserID() const;

		// Setters
		void setId(const string& _id);
		void setDescription(const string& _description);
		void setPairedUserID(const string& _pairedUserID);

		// Opérateur de comparaison
		bool operator==(const Device& other) const;
};

#endif