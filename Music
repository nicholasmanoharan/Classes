#include "Music.h"
#include <iostream>

Music::Music(const std::string& title, int year, const std::string& artist, int duration, const std::string& publisher)
    : Media(title, year), artist(artist), duration(duration), publisher(publisher) {}

void Music::displayInfo() const {
    Media::displayInfo();
    std::cout << "Artist: " << artist << "\nDuration: " << duration << " minutes\nPublisher: " << publisher << std::endl;
}

bool Music::search(const std::string& term) const {
    return Media::search(term) || (artist.find(term) != std::string::npos) ||
           (std::to_string(duration).find(term) != std::string::npos) || (publisher.find(term) != std::string::npos);
}

const std::string& Music::getArtist() const {
    return artist;
}

int Music::getDuration() const {
    return duration;
}

const std::string& Music::getPublisher() const {
    return publisher;
}
