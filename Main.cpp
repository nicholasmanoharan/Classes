#include <iostream>
#include <vector>
#include "Media.h"
#include "VideoGame.h"
#include "Music.h"
#include "Movie.h"

void addMedia(std::vector<Media*>& mediaList) {
    std::cout << "Select media type to add:\n";
    std::cout << "1. Video Game\n";
    std::cout << "2. Music\n";
    std::cout << "3. Movie\n";
    int choice;
    std::cin >> choice;
    std::cin.ignore(); 

    std::string title, artistOrDirector, publisherOrRating;
    int year, durationOrRating;

    std::cout << "Title: ";
    std::getline(std::cin, title);

    std::cout << "Year: ";
    std::cin >> year;
    std::cin.ignore();

    if (choice == 1) { // Video Game inputs
        std::cout << "Publisher: ";
        std::getline(std::cin, publisherOrRating);

        std::cout << "Rating: ";
        std::cin >> durationOrRating;
        std::cin.ignore(); 

        mediaList.push_back(new VideoGame(title, year, publisherOrRating, durationOrRating));
    } else if (choice == 2) { // Music inputs
        std::cout << "Artist: ";
        std::getline(std::cin, artistOrDirector);

        std::cout << "Duration (in minutes): ";
        std::cin >> durationOrRating;
        std::cin.ignore(); 

        std::cout << "Publisher: ";
        std::getline(std::cin, publisherOrRating);

        mediaList.push_back(new Music(title, year, artistOrDirector, durationOrRating, publisherOrRating));
    } else if (choice == 3) { // Movie inputs
        std::cout << "Director: ";
        std::getline(std::cin, artistOrDirector);

        std::cout << "Duration (in minutes): ";
        std::cin >> durationOrRating;
        std::cin.ignore(); 

        std::cout << "Rating: ";
        std::cin >> publisherOrRating;
        std::cin.ignore(); 

        mediaList.push_back(new Movie(title, year, artistOrDirector, durationOrRating, std::stoi(publisherOrRating)));
    } else {
        std::cout << "Invalid choice.\n";
    }
}

void searchMedia(const std::vector<Media*>& mediaList) {
    std::cout << "Enter a search term (title or year): ";
    std::string term;
    std::cin >> term;

    bool found = false;
    for (const Media* media : mediaList) {
        if (media->search(term)) {
            media->displayInfo();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching media found.\n";
    }
}

void deleteMedia(std::vector<Media*>& mediaList) {
    std::cout << "Enter a search term (title or year) to delete: ";
    std::string term;
    std::cin >> term;

    std::vector<Media*>::iterator it = mediaList.begin();
    while (it != mediaList.end()) {
        if ((*it)->search(term)) {
            (*it)->displayInfo();
            std::cout << "Do you want to delete this item? (Y/N): ";
            char choice;
            std::cin >> choice;

            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                std::cout << "Invalid choice. Please enter Y or N: ";
                std::cin >> choice;
            }

            if (choice == 'Y' || choice == 'y') {
                delete *it;
                it = mediaList.erase(it);
                std::cout << "Item deleted.\n";
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }
}

void clearMemory(std::vector<Media*>& mediaList) {
    for (Media* media : mediaList) {
        delete media;
    }
}

int main() {
    std::vector<Media*> mediaList;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. ADD\n";
        std::cout << "2. SEARCH\n";
        std::cout << "3. DELETE\n";
        std::cout << "4. QUIT\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); 

        switch (choice) {
            case 1:
                addMedia(mediaList);
                break;
            case 2:
                searchMedia(mediaList);
                break;
            case 3:
                deleteMedia(mediaList);
                break;
            case 4:
                clearMemory(mediaList);
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
