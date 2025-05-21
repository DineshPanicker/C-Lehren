// SequenceManager.hpp
#pragma once
#include "SequenceItem.hpp"
#include <vector>
#include <memory>
#include <iostream>

class SequenceManager
{
public:
    void addItem(std::unique_ptr<SequenceItem> item)
    {
        if (item)
        {
            items.push_back(std::move(item));
        }
    }

    void showAll() const
    {
        std::cout << "Stored SequenceItems:\n";
        for (const auto &item : items)
        {
            item->display();
        }
    }

private:
    std::vector<std::unique_ptr<SequenceItem>> items;
};
