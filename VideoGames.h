#pragma once
#include "Media.h"
class VideoGames : public Media {
public: 
    VideoGames(const std::string& title, int year, const std::string& publisher, int ratint);
    void displayInfo() const override;
    bool search(const std::string& term) const override;

    const std::string& getPublisher() const;
    int rating;

private:
    std::string publisher;
    int rating;


};
