#ifndef NOTIFICATION_HPP
#define NOTIFICATION_HPP

#include "../../main.hpp"

class Notification
{
	private:
		string			eqtID;
		string			title;
		string			description;
		unsigned int	priority;
		unsigned long	id;
		bool			acked;

	public:
		// Constructeur / Destructeurs
    	Notification(const string& _eqtID, const string& _title, const string& _description,
						const unsigned int& _priority, const unsigned int& _id, bool _acked);
		~Notification();

		// Getters
		string			getEqtID() const;
		string			getTitle() const;
		string			getDescription() const;
		unsigned int	getPriority() const;
		unsigned int	getID() const;
		bool			getAcked() const;

		// Setters
		void	setEqtID(const string& _eqtID);
		void	setTitle(const string& _title);
		void	setDescription(const string& _description);
		void	setPriority(const unsigned int& _priority);
		void	setID(const unsigned int& _id);
		void	setAcked(bool _acked);

		// Opérateur de comparaison
		bool operator==(const Notification& other) const;
};

#endif