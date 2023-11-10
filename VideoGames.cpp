#pragma once
#include "Media.h"

class VideoGame : public Media {
public:
    VideoGame(const std::string& title, int year, const std::string& publisher, int rating);
    void displayInfo() const override;
    bool search(const std::string& term) const override;

    const std::string& getPublisher() const;
    int getRating() const;

private:
    std::string publisher;
    int rating;
};
