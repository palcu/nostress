/***************************************************
 * Alex Palcuie
 * FMI No Stress - 2015
 * licenta - 100p
 * alex [dot] palcuie [at] gmail [dot] com
****************************************************/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> Meeting;
vector<Meeting> decan, mihaela;

int get_overlap_length(Meeting a, Meeting b) {
    int left = max(a.first, b.first);
    int right = min(a.second, b.second);
    return right - left;
}

int main(){
    ifstream fin("licenta.in");
    ofstream fout("licenta.out");
    
    int minMeetingLength;
    fin >> minMeetingLength; 

    int n; fin >> n;
    for (int i=0; i<n; i++) {
        int x, y; fin >> x >> y;
        decan.push_back({x, y});
    }

    fin >> n;
    for (int i=0; i<n; i++) {
        int x, y; fin >> x >> y;
        mihaela.push_back({x, y});
    }

    sort(decan.begin(), decan.end());
    sort(mihaela.begin(), mihaela.end());

    int i=0, j=0;
    bool canMeet = false;
    while (i<decan.size() && j<mihaela.size() && !canMeet) {
        int length = get_overlap_length(decan[i], mihaela[j]);
        if (length >= minMeetingLength) {
            canMeet = true;
            int start_time = max(decan[i].first, mihaela[j].first);
            fout << start_time << " " << start_time + minMeetingLength << "\n";
        } else if (decan[i].second < mihaela[j].second) {
            i++;
        } else {
            j++;
        }
    }

    if (!canMeet) {
        fout << "-1\n";
    }
    
    return 0;
}

