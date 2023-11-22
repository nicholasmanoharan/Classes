#include "VideoGames.h"
#include <iostream>

VideoGames::VideoGames(const std::string& title, int year, const std::string& publusher, int rating) : Media (title, year), publisher(publisher), rating(rating) {}

void VideoGame::displayInfo() const{
    Media::displayInfo();
    std::cout << "Publisher: " << publisher << "\nRating: " << rating << std::endl;
}

bool VideoGames::Search(const std::string& term) const {
    return Media::search(term) || (publisher.find(term) !=npos || (std::to_string(rating).find(term) != std::string::npos);
}

const std::string& VideoGames::getPublisher() const {
    return publisher;
}

int VideoGames::getRating() const {
    return rating
}
