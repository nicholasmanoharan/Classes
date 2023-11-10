#include "Movie.h"
#include <iostream>

Movie::Movie(const std::string& title, int year, const std::string& director, int duration, int rating)
    : Media(title, year), director(director), duration(duration), rating(rating) {}

void Movie::displayInfo() const {
    Media::displayInfo();
    std::cout << "Director: " << director << "\nDuration: " << duration << " minutes\nRating: " << rating << std::endl;
}

bool Movie::search(const std::string& term) const {
    return Media::search(term) || (director.find(term) != std::string::npos) ||
           (std::to_string(duration).find(term) != std::string::npos) || (std::to
