#include <iostream>
#include <vector>
using namespace std;

class ArtPiece {
    friend ostream& operator<<(ostream& o, ArtPiece& a);
protected:
    string title, artist;
    int year;
    int maxAllowedBids;
public:
    vector<int> bids;
    ArtPiece(){}

    ArtPiece(string title, string artist, int year, int bids) {
        this->title = title;
        this->artist = artist;
        this->year = year;
        this->maxAllowedBids = bids;
    }
    virtual void displayInfo() = 0;

    bool operator==(ArtPiece* other) {
        return (this->title == other->title && this->artist == other->artist);
    }

    void bidStatus() {
        int highest = bids[0];

        for (int bid : bids) {
            highest = (bid > highest) ? bid : highest;
        }
        int remaining = maxAllowedBids - bids.size();

        cout << "Current top bid: " << highest << ", remaining bids: " << remaining << endl;
    }

    string getTitle() {
        return title;
    }
    string getArtist() {
        return artist;
    }
    int getMaxAllowedBids() {
        return maxAllowedBids;
    }
    int remainingBids() {
        return maxAllowedBids - bids.size();
    }
};

ostream& operator<<(ostream& o, ArtPiece& a) {
    o << "This artpiece is " << a.title << " by " << a.artist << ", released in " << a.year << endl;
}


class Painting : public ArtPiece {
public:
    string medium;
    double height, width;

    void displayInfo() override {
        cout << *this;
        cout << " . Painted on " << medium << " medium with dimensions " << height << " x " << width << endl;
    }
};
class Sculpture : public ArtPiece {
public:
    string material;
    double weight;

    void displayInfo() override {
        cout << *this;
        cout << " . Sculpted using " << material << "material and weighs " << weight << endl;
    }
};


class Gallery {
public:
    vector<ArtPiece*> auctionItems;

    void addAuctionItem(ArtPiece* toAdd) {
        auctionItems.push_back(toAdd);
    }
    void displayAll() {
        for (ArtPiece* item : auctionItems) {
            cout << *item;
        }
    }

    ArtPiece* searchForItem(string title, string artist) {
        for (ArtPiece* item : auctionItems) {
            if (item->getArtist() == artist && item->getTitle() == title) return item;
        }
        return nullptr;
    }

    vector<ArtPiece*> getActiveAuctions() {
        vector<ArtPiece*> results;

        for (ArtPiece* item : auctionItems) {
            int remaining = item->getMaxAllowedBids() - item->bids.size();
            if (remaining > 0) results.push_back(item);
        }
        return results;
    }

    bool placeBid(ArtPiece* item, int amount) {
        for (ArtPiece* i : auctionItems) {
            if (item == i) {
                if (i->remainingBids() > 0) {
                    int highestItemBid = i->bids[0];
                    for (int bid : i->bids) {
                        highestItemBid = (bid > highestItemBid) ? bid : highestItemBid;
                    }

                    if (amount > highestItemBid) {
                        i->bids.push_back(amount);
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    
}