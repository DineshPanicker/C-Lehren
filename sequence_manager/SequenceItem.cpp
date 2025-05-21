#include "SequenceItem.hpp"

// Constructor with init list
SequenceItem::SequenceItem(int id, const std::string &name, ActionInstance *action)
    : mId(id), mName(name),
      mpAction(action ? new ActionInstance(*action) : nullptr)
{
    std::cout << "SequenceItem created\n";
}

// Copy constructor
SequenceItem::SequenceItem(const SequenceItem &other)
    : mId(other.mId), mName(other.mName)
{
    if (other.mpAction)
        mpAction = new ActionInstance(*other.mpAction); // deep copy
    else
        mpAction = nullptr;

    std::cout << "SequenceItem copied\n";
}

// Move constructor
SequenceItem::SequenceItem(SequenceItem &&other) noexcept
    : mId(other.mId),
      mName(std::move(other.mName)),
      mpAction(other.mpAction)
{
    other.mpAction = nullptr; // release ownership
    std::cout << "SequenceItem moved\n";
}

// Copy assignment operator
SequenceItem &SequenceItem::operator=(const SequenceItem &other)
{
    if (this != &other)
    {
        mId = other.mId;
        mName = other.mName;

        delete mpAction;
        mpAction = other.mpAction ? new ActionInstance(*other.mpAction) : nullptr;

        std::cout << "SequenceItem copy-assigned\n";
    }
    return *this;
}

// Move assignment operator
SequenceItem &SequenceItem::operator=(SequenceItem &&other) noexcept
{
    if (this != &other)
    {
        mId = other.mId;
        mName = std::move(other.mName);

        delete mpAction;
        mpAction = other.mpAction;
        other.mpAction = nullptr;

        std::cout << "SequenceItem move-assigned\n";
    }
    return *this;
}

// Destructor
SequenceItem::~SequenceItem()
{
    delete mpAction;
    std::cout << "SequenceItem destroyed\n";
}

void SequenceItem::print() const
{
    std::cout << "SequenceItem [" << mId << "] " << mName << std::endl;
    if (mpAction)
        mpAction->print();
    else
        std::cout << "(No ActionInstance)\n";
}
