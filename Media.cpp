#include "Media.h"
#include <iostream>

Media::Media(const std::string& title, int year) : title(title), year(year) {}

Media::~Media() {}

void Media::displayInfo() const {
    std::cout << "Title: " << title << "\nYear: " << year << std::endl;
}

bool Media::search(const std::string& term) const {
    return (title.find(term) != std::string::npos) || (std::to_string(year).find(term) != std::string::npos);
}

const std::string& Media::getTitle() const {
    return title;
}

int Media::getYear() const {
    return year;
}
