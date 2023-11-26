#ifndef USER_HPP
#define USER_HPP

#include "../../main.hpp"

using namespace std;

class User
{
	private:
		string id;
		string cardID;
		string name;

	public:
		// Constructeur / Destructeurs
		User();
    	User(const string& _id, const string& _cardID, const string& _name);
		~User();

		// Getters
		string getId() const;
		string getCardID() const;
		string getName() const;

		// Setters
		void setId(const string& _id);
		void setCardID(const string& _cardID);
		void setName(const string& _name);

		// Opérateur de comparaison
		bool operator==(const User& other) const;
};

#endif