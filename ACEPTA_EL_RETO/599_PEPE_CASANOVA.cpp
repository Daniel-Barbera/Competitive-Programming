#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define INF 0x3f3f3f3f3f

int numSongs, sideSize;
long long bestScore;

struct Song {
    int size, score;

    bool operator> (Song other) const {
        return (double) score / size > (double) other.score / other.size;
    }
};


vector<Song> songs;

long long maxScore(int sizeA, int sizeB, long long score, int idx) {
    // Base case
    if (sizeA > sideSize || sizeB > sideSize) return -INF;
    if (idx == songs.size()) {
        bestScore = max(score, bestScore);
        return bestScore; 
    }


    // Trim according to approx. best possible score in branch
    // Upper bound is calculated thinking of the problem as a fractioned knapsack, which
    // produces a good approximation of the best possible solution in the current branch.
    int crtBest = score;
    int remSpace = 2*sideSize - sizeA - sizeB;
    for (int i = idx; i < songs.size(); ++i) {
        Song song = songs[i];
        if (song.size >= remSpace) {
            crtBest += ceil(((double) song.score / song.size) * remSpace); // <- fill the gap with densest object
            break; 
        } else { // keep adding items
            crtBest += song.score;
            remSpace -= song.size;  
        }
    }

    if (crtBest <= bestScore) return -INF;
    // Transition
    // Trim if both sides have the same capacity
    if (sizeA == sizeB) {
        return max(
                    maxScore(sizeA + songs[idx].size, sizeB, score + songs[idx].score, idx + 1), // <- take
                    maxScore(sizeA, sizeB, score, idx + 1) // <- don't take
                );
    }

    return max(
                maxScore(sizeA, sizeB + songs[idx].size, score + songs[idx].score, idx + 1), // <- take & put in B
                max(
                    maxScore(sizeA + songs[idx].size, sizeB, score + songs[idx].score, idx + 1), // <- take & put in A
                    maxScore(sizeA, sizeB, score, idx + 1) // <- don't take
                )
            );
}

int main() {

    while (cin >> numSongs && numSongs) {
        cin >> sideSize;
        Song song; 
        while (numSongs--) {
            cin >> song.size >> song.score;
            songs.push_back(song);
        }
        sort(songs.begin(), songs.end(), greater<Song>());
        bestScore = 0;
        cout << maxScore(0, 0, 0, 0) << '\n';
        songs.clear();
    }

    return 0; 
}