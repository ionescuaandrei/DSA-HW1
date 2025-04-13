#include "../ds/queue1.h"
#include <vector>
#include <sstream>
#include "Song.h"
using namespace std;

class PlaylistManager {
    private:
        Queue<Song> vip;
        Queue<Song> regular;
        Queue<Song> low;

        vector<Song> history;
        Song* currentSong = nullptr;

    public:
        void addSong(Song& song);
        void play(ostream& output);
        void skip(int seconds, ostream& output);
        void replay(ostream& output);
        void removeSong(Song& song, ostream& output);
        void show(ostream& output);
        void displayHistory(ostream& output);

        // Helper function to convert a queue to string representation
        string queueToString(Queue<Song>& q) {
            string result = "";
            Queue<Song> tempQueue;
            
            while (!q.isEmpty()) {
                Song s = q.dequeue();
                if (!result.empty()) {
                    result += ", ";
                }
                result += s.name;
                tempQueue.enqueue(s);
            }
            
            // Restore the queue
            while (!tempQueue.isEmpty()) {
                q.enqueue(tempQueue.dequeue());
            }
            
            return result;
        }
};

void PlaylistManager::addSong(Song& song) {
    switch (song.preference) {
        case 1:
            vip.enqueue(song);
            break;
        case 2:
            regular.enqueue(song);
            break;
        case 3:
            low.enqueue(song);
            break;
        default:
            cout << "No selected preference" << endl;
    }
}

void PlaylistManager::play(ostream& output) {
    if (currentSong != nullptr) {
        output << "Already playing: " << currentSong->name << endl;
        return;
    }

    if (!vip.isEmpty()) {
        currentSong = new Song(vip.dequeue());
    } else if (!regular.isEmpty()) {
        currentSong = new Song(regular.dequeue());
    } else if (!low.isEmpty()) {
        currentSong = new Song(low.dequeue());
    } else {
        output << "No songs in the playlist." << endl;
        return;
    }

    output << "Now playing: " << currentSong->name << " (" << currentSong->duration << "s)" << endl;
}

void PlaylistManager::skip(int seconds, ostream& output) {
    if (currentSong == nullptr) {
        output << "No song is currently playing." << endl;
        return;
    }

    if (seconds >= currentSong->duration) {
        output << "Skipped " << seconds << "s. Song finished." << endl;
        history.push_back(*currentSong);
        delete currentSong;
        currentSong = nullptr;
    } else {
        currentSong->duration -= seconds;
        output << "Skipped " << seconds << "s. " << currentSong->duration << "s remaining." << endl;
    }
}

void PlaylistManager::replay(ostream& output) {
    if (history.empty()) {
        output << "No songs in history." << endl;
        return;
    }

    Song lastSong = history.back();
    output << "Replaying: " << lastSong.name << endl;
    
    switch (lastSong.preference) {
        case 1:
            vip.enqueue(lastSong);
            break;
        case 2:
            regular.enqueue(lastSong);
            break;
        case 3:
            low.enqueue(lastSong);
            break;
    }
}

void PlaylistManager::removeSong(Song& song, ostream& output) {
    if (currentSong != nullptr && currentSong->name == song.name) {
        output << "Cannot remove the currently playing song." << endl;
        return;
    }

    output << "Removed: " << song.name << endl;
}

void PlaylistManager::show(ostream& output) {
    output << "Playlist:" << endl;
    
    output << "Preference 1: ";
    if (!vip.isEmpty()) {
        output << queueToString(vip) << endl;
    } else {
        output << endl;
    }
    
    output << "Preference 2: ";
    if (!regular.isEmpty()) {
        output << queueToString(regular) << endl;
    } else {
        output << endl;
    }
    
    output << "Preference 3: ";
    if (!low.isEmpty()) {
        output << queueToString(low) << endl;
    } else {
        output << endl;
    }
}

void PlaylistManager::displayHistory(ostream& output) {
    output << "History:" << endl;
    
    if (history.empty()) {
        return;
    }
    
    for (size_t i = 0; i < history.size(); i++) {
        output << (i+1) << ". " << history[i].name << endl;
    }
}

