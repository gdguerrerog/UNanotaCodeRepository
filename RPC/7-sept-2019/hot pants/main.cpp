#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;


const string WORSE = " are worse than ";

string * splitString(string s, string delimiter){
    string s1, s2;

    s1 = s.substr(0, s.find(delimiter));
    s2 = s.substr(s1.length() + delimiter.length(), s.length());

    string * exit = new string[2];
    exit[0] = s1;
    exit[1] = s2;

    return exit;
}

void insertOnGraph(int * * graph, int n, int m,  int val){
    graph[n][m] = val;
    graph[m][n] = -1 * val;
}

vector<int> findOnGraph(int * * graph, int indexToSearch, int sizeArr, int toSearch){
    vector<int> exit;
    for(int i = 0; i < sizeArr; i++) if(graph[indexToSearch][i] == toSearch) exit.push_back(i);
    return exit;
}

void solve(int n, int m, string * queries){
    string * splited;
    map<string, int> usedCountries;
    int currentCountryId = 0;
    for(int i = 0; i < n + m ;i++){
        splited = splitString(queries[i], WORSE);
        if(usedCountries.find(splited[0]) == usedCountries.end()){
            usedCountries[splited[0]] = currentCountryId;
            currentCountryId++;
        }
        if(usedCountries.find(splited[1]) == usedCountries.end()){
            usedCountries[splited[1]] = currentCountryId;
            currentCountryId++;
        }

    }

    int * * graph;

    int high_id, low_id;
    vector<int> high, low;
    for(int i = 0; i < n; i++){
        splited = splitString(queries[i], WORSE);
        high_id = usedCountries[splited[1]];
        low_id = usedCountries[splited[0]];
        high = findOnGraph(graph, high_id, currentCountryId, 1);
        low = findOnGraph(graph, low_id, currentCountryId, -1);
        high.push_back(high_id);
        low.push_back(low_id);
        for(vector<int>::iterator it = high.begin(); it != high.end(); ++it){
            for(vector<int>::iterator it2 = low.begin(); it2 != low.end(); ++it2){
                insertOnGraph(graph, *it, *it2, -1);
            }
        }
    }
}

void consoleInput(){
    int n ,m;
    cin >> n >> m;
    string vals[n + m];
    string input;
    for(int i = 0; i < n + m; i++){
        cin >> input;
        vals[i] = input;
    }
    cout << "Test";
    solve(n, m, vals);

}

void testInput(){
    string vals[9] = {
    "Mexicans are worse than Americans",
    "Russians are worse than Mexicans",
    "NorthKoreans are worse than Germans",
    "Canadians are worse than Americans",
    "Russians are worse than Americans",
    "Germans are worse than NorthKoreans",
    "NorthKoreans are worse than Mexicans",
    "NorthKoreans are worse than French",
    "Mexicans are worse than Canadians"
    };

    solve(4, 5, vals);
}

int main()
{
    consoleInput();
    //testInput();
    return 0;
}
