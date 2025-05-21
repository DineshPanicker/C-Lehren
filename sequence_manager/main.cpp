#include "SequenceItem.hpp"

int main()
{
    ActionInstance action(42);

    // Create original
    SequenceItem original(1, "FadeIn", &action);
    original.print();

    std::cout << "\n--- Copy ---\n";
    SequenceItem copy = original;
    copy.print();

    std::cout << "\n--- Move ---\n";
    SequenceItem moved = std::move(copy);
    moved.print();

    std::cout << "\n--- dynamic_cast demo ---\n";
    Object *basePtr = new SequenceItem(2, "Hold", &action);
    SequenceItem *derivedPtr = dynamic_cast<SequenceItem *>(basePtr);
    if (derivedPtr)
    {
        std::cout << "dynamic_cast succeeded\n";
        derivedPtr->print();
    }
    else
    {
        std::cout << "dynamic_cast failed\n";
    }
    delete basePtr;

    return 0;
}
