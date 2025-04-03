#include "ds/queue1.h"
#include <vector>
#include "Song.h"
using namespace std;


class PlaylistManager{
    private:
        Queue<Song> vip;
        Queue<Song> regular;
        Queue<Song> low;

        vector<Song> history;
        Song* currentSong = nullptr;
        int totalDuration = 0;

    public:
        void addSong(Song& song);
        void play();
        void skip(int seconds);
        void replay();
        void removeSong(Song& song);
        void show();
        void displayHistory();
};
