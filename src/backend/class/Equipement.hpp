#ifndef EQUIPEMENT_HPP
#define EQUIPEMENT_HPP

#include "../../main.hpp"

class Equipement
{
	private:
		string id;
		string description;
		string pairedUserID;

	public:
		// Constructeur / Destructeurs
    	Equipement(const string& _id, const string& _description, const string& _pairedUserID);
		~Equipement();

		// Getters
		string getId() const;
		string getDescription() const;
		string getPairedUserID() const;

		// Setters
		void setId(const string& _id);
		void setDescription(const string& _description);
		void setPairedUserID(const string& _pairedUserID);

		// Opérateur de comparaison
		bool operator==(const Equipement& other) const;
};

#endif