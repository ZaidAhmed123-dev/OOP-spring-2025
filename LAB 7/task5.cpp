#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;

public:
    Media(string t, string p, string id, string pub)
        : title(t), publicationDate(p), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() {
        cout << "\n   Media Information   \n";
        cout << "Title: " << title << "\nPublished: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher
             << "\nStatus: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << "\n'" << title << "' has been successfully checked out.\n";
        } else {
            cout << "\nSorry, '" << title << "' is currently unavailable.\n";
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << "\n'" << title << "' has been returned. Thank you!\n";
        } else {
            cout << "\n'" << title << "' is already in the library.\n";
        }
    }

    string getTitle() { return title; }
    string getPublicationDate() { return publicationDate; }

    virtual string getCreator() { return ""; } 
    virtual ~Media() {}
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string p, string id, string pub, string auth, string isbn, int pages)
        : Media(t, p, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPage Count: " << numberOfPages << endl;
    }

    string getCreator() override { return author; }
};

class DVD : public Media {
    string director;
    int duration;
    float rating;

public:
    DVD(string t, string p, string id, string pub, string dir, int dur, float rate)
        : Media(t, p, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " min\nIMDb Rating: " << rating << endl;
    }

    string getCreator() override { return director; }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string p, string id, string pub, string art, int tracks, string gen)
        : Media(t, p, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTotal Tracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }

    string getCreator() override { return artist; }
};

class Library {
private:
    Media* items[100];
    int itemCount;

public:
    Library() : itemCount(0) {}

    void addItem(Media* newItem) {
        if (itemCount < 100) {
            items[itemCount] = newItem;
            itemCount++;
            cout << "\nItem '" << newItem->getTitle() << "' added to the library.\n";
        } else {
            cout << "\nLibrary storage is full! Cannot add more items.\n";
        }
    }

    void search(string title) {
        bool found = false;
        for (int i = 0; i < itemCount; i++) {
            if (items[i]->getTitle() == title) {
                cout << "\nItem found!\n";
                items[i]->displayInfo();
                found = true;
            }
        }
        if (!found)
            cout << "\nNo item with the title '" << title << "' exists in our collection.\n";
    }

    void search(string creator, bool isDirectorOrAuthor) {
        bool found = false;
        for (int i = 0; i < itemCount; i++) {
            if (items[i]->getCreator() == creator) {
                cout << "\nMedia by '" << creator << "' found:\n";
                items[i]->displayInfo();
                found = true;
            }
        }
        if (!found)
            cout << "\nSorry, no media found by '" << creator << "'.\n";
    }

    void search(int year) {
        bool found = false;
        for (int i = 0; i < itemCount; i++) {
            if (items[i]->getPublicationDate() == to_string(year)) {
                cout << "\nMedia from the year " << year << " found:\n";
                items[i]->displayInfo();
                found = true;
            }
        }
        if (!found)
            cout << "\nNo media items found from the year " << year << ".\n";
    }

    ~Library() {
        for (int i = 0; i < itemCount; i++) {
            delete items[i];
            items[i] = nullptr;
        }
        cout << "\nLibrary system is shutting down. All resources cleared.\n";
    }
};

int main() {
    Library library;

    Book* b1 = new Book("To Kill a Mockingbird", "1960", "B002", "J.B. Lippincott & Co.", "Harper Lee", "9780061120084", 281);
    library.addItem(b1);

    DVD* d1 = new DVD("The Matrix", "1999", "D002", "Warner Bros", "Lana & Lilly Wachowski", 136, 8.7);
    library.addItem(d1);

    CD* c1 = new CD("Back in Black", "1980", "C002", "Atlantic Records", "AC/DC", 10, "Rock");
    library.addItem(c1);

    cout << "\n--- Searching for Titles ---\n";
    library.search("The Matrix");

    cout << "\n\t\t Searching by Author/Director \n";
    library.search("Harper Lee", true);
    library.search("Lana & Lilly Wachowski", true);

    cout << "\n\t\t Searching by Publication Year \n";
    library.search(1980);

    return 0;
}

