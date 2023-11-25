#ifndef EQUIPMENT_HPP
#define EQUIPMENT_HPP

#include "../../main.hpp"

using namespace std;

class Equipment
{
	private:
		string id;
		string description;
		string pairedUserID;

	public:
		// Constructeur / Destructeurs
		Equipment();
    	Equipment(const string& _id, const string& _description, const string& _pairedUserID);
		~Equipment();

		// Getters
		string getId() const;
		string getDescription() const;
		string getPairedUserID() const;

		// Setters
		void setId(const string& _id);
		void setDescription(const string& _description);
		void setPairedUserID(const string& _pairedUserID);

		// Opérateur de comparaison
		bool operator==(const Equipment& other) const;
};

#endif