#pragma once
#include "Media.h"

class Music : public Media {
public:
    Music(const std::string& title, int year, const std::string& artist, int duration, const std::string& publisher);
    void displayInfo() const override;
    bool search(const std::string& term) const override;

    const std::string& getArtist() const;
    int getDuration() const;
    const std::string& getPublisher() const;

private:
    std::string artist;
    int duration;
    std::string publisher;
};
