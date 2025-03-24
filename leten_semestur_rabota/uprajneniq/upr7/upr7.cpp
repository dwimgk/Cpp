#include <iostream>
#include <vector>

using namespace std;

/*
1. klas za pesen ot playlist. Edna pesen sudurja:
- author
- song name
- release year
- length
- genre

- da se napravi ekspliciten konstruktor za klasa

2.da se napravi klas za playlist. Edin playlist sudurja::
- kolekciq ot pesni (purviq klas)
- operator za subirane (+), koito priema kato param pesen i dobavq tazi pesen v kolekciqta.
- operator za subirane (-), koito priema kato param pesen i izvajda tazi pesen ot kolekciqta.
- funkciq, koqto vrushta obshtata duljina na playlista
- operator za ednakvost (==), priema kato param playlist. Dva playlista sa ednakvi, ako produljitelnostta e ednakva.
- funk za kombinirane na playlisti koqto priema DVA param drug playlist i genre, i wrushta kato result nov playlist 
smesvaiki na edno mqsto tezi pesni ot dvata playlista
- da napravim funkciq za razburkvane na playlista. Vsqka pesen da se ozove na novo mqsto vutre
*/

class Song {
public:
    string author, songName, releaseYear;
    double length;
    string genre;

    Song(string author, string songName, string releaseYear, double length, string genre) {
        this->author = author;
        this->songName = songName;
        this->releaseYear = releaseYear;
        this->length = length;
        this->genre = genre;
    }
};

// START, END
// ((random * END) - END) + START
int randomNumber(int from, int to) {
    srand(time(0));
    int r = rand();
    double _r = (double)rand() / (double)RAND_MAX;

    double result = ((to * _r) - from + to);
    return (((to - from) * _r) + from);
}

class Playlist {
public:
    vector<Song> songList;

    void operator+(Song song) {
        songList.push_back(song);
    }
    Playlist* operator-(Song song) {
        vector<Song> newVector;

        for (int i = 0;i < songList.size(); i++) {
            if (song.songName != songList[i].songName) {
                newVector.push_back(songList[i]);
            }
        }
        this->songList = newVector;
        return this;
    }
    double playlistLength() {
        double fullLength =0;
        for (int i = 0;i < songList.size(); i++) {
            fullLength += songList[i].length;
        }
        return fullLength;
    }
    bool operator==(Playlist second) {
        double firstLength, secondLength;
        firstLength = playlistLength();
        secondLength = second.playlistLength();

        if (firstLength == secondLength) {
            return true;
        }
        else return false;
    }
    Playlist* combined(Playlist& second, string combiGenre) {
        Playlist* combi = new Playlist;

        for (int i = 0;i < this->songList.size(); i++) {
            if (songList[i].genre == combiGenre) {
                combi->songList.push_back(songList[i]);
            }
        }
        for (int i = 0;i < second.songList.size(); i++) {
            if (second.songList[i].genre == combiGenre) {
                combi->songList.push_back(second.songList[i]);
            }
        }

        return combi;
    }
    void shuffle() {
        vector<Song> shuffled;

        int remaining = this->songList.size();

        while (remaining > 0) {
            int i = randomNumber(0, remaining-1);
            shuffled.push_back(this->songList[i]);
            this->songList.erase(this->songList.begin() + i, this->songList.begin() + i + 1);
            remaining--;
        }
        this->songList = shuffled;
    }
    Playlist shuffleAssign() {
        Playlist shuffled;

        int remaining = this->songList.size();

        while (remaining > 0) {
            int i = randomNumber(0, remaining - 1);
            shuffled.songList.push_back(this->songList[i]);
            this->songList.erase(this->songList.begin() + i, this->songList.begin() + i + 1);
            remaining--;
        }
        this->songList = shuffled.songList;
        return shuffled;
    }
};

ostream& operator<<(ostream& o, Playlist& p) {
    o << "Total Length: " << p.playlistLength() << " seconds" << endl;

    for (Song s : p.songList) {
        o << s.songName << " by " << s.author << " in " << s.releaseYear << " .  Duration: " << s.length << endl;
    }
    return o;
}

int main()
{
    Song s1("GP", "Shalcheto", "24.12.2000", 300, "pop");
    Song s2("Krisko", "Bazooka", "24.12.2000", 360, "rap");
    Song s3("Hozier", "Wildflower & Barley", "24.12.2000", 240, "blues");
    Song s4("50 Cent", "Many men", "24.12.2000", 300, "rap");
    Song s5("GASP", "Some of us", "24.12.2000", 300, "metal");

    Playlist p;
    p + s1;
    p + s2;
    p + s3;
    p + s4;
    p - s4;
    p + s4;
    p + s5;

    cout << p;
    Playlist s = p.shuffleAssign();

    cout << endl << endl;
    cout << s;

    cout << endl << endl;
    bool equal = p == s;
    cout << "It is " << boolalpha << equal << " that the two playlists are equal." << endl;
    return 0;

    /*bool running = true;
    int input;
    while (running) {
        cout << "1. Add song" << endl << "2. Create Playlist" << endl << "3. Add song" << endl << "4. Remove song" << endl << "5. Compare playlists by length" << endl << "What do you wish to do?" << endl;
        cin >> input;

        if()
    }*/
}