#ifndef SEQUENCE_ITEM_HPP
#define SEQUENCE_ITEM_HPP

#include <string>
#include <iostream>

// Base class for dynamic_cast demonstration
class Object
{
public:
    virtual ~Object() {} // Required for dynamic_cast to work
};

// Dummy dependent class that is dynamically allocated
class ActionInstance
{
public:
    int actionId;

    ActionInstance(int id) : actionId(id) {}

    // Copy constructor
    ActionInstance(const ActionInstance &other) : actionId(other.actionId) {}

    void print() const
    {
        std::cout << "ActionInstance ID: " << actionId << std::endl;
    }
};

// Our main class of interest
class SequenceItem : public Object
{
public:
    int mId;
    std::string mName;
    ActionInstance *mpAction;

    // Constructor using initialization list
    SequenceItem(int id, const std::string &name, ActionInstance *action);

    // Copy constructor: deep copies mpAction
    SequenceItem(const SequenceItem &other);

    // Move constructor: steals mpAction
    SequenceItem(SequenceItem &&other) noexcept;

    // Copy assignment: deep copy
    SequenceItem &operator=(const SequenceItem &other);

    // Move assignment: steal pointer
    SequenceItem &operator=(SequenceItem &&other) noexcept;

    // Destructor
    virtual ~SequenceItem();

    void print() const;
};

#endif // SEQUENCE_ITEM_HPP
