#pragma once
#include "Media.h"

class Movie : public Media {
public:
    Movie(const std::string& title, int year, const std::string& director, int duration, int rating);
    void displayInfo() const override;
    bool search(const std::string& term) const override;

    const std::string& getDirector() const;
    int getDuration() const;
    int getRating() const;

private:
    std::string director;
    int duration;
    int rating;
};
