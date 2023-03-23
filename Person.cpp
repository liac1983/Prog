#include "Person.h"
#include "Date.h"

// Default constructor
Person::Person(): name_("NO_NAME"), birth_date_(Date()) {}

// Constructor
Person::Person(const std::string& name, const Date& birth_date): name_(name), birth_date_(birth_date) {}

// Get name
std::string Person::get_name() const { return name_; }

// Get birth date
Date Person::get_birth_date() const { return birth_date_; }