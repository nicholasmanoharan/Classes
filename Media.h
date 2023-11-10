#pragma once
#include <string>

class Media {
public:
    Media(const std::string& title, int year);
    virtual ~Media();
    virtual void displayInfo() const;
    virtual bool search(const std::string& term) const;
    
    const std::string& getTitle() const;
    int getYear() const;

private:
    std::string title;
    int year;
};
