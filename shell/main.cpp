/*
 * Creato da Pasquale e Nazzaro il 01/11/2024
 * -> Simulare una shell di unix/linux in modo molto creativo
 */

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<string,int> comandi;
    string percorso = "C:/Users/Ricchione>";
    vector<string> directory = {"Desktop", "Documenti", "Download"};
    string scelta;
    bool check = false;
    bool quit = false;

    comandi.insert(pair<string,int>("cd",1));
    comandi.insert(pair<string,int>("ls",2));
    comandi.insert(pair<string,int>("rm",3));
    comandi.insert(pair<string,int>("history xyzn",4));
    comandi.insert(pair<string,int>("issue xyzn",5));
    comandi.insert(pair<string,int>("somma",6)); //DA RIVEDERE MEGLIO
    comandi.insert(pair<string,int>("somma&",7)); //DA RIVEDERE MEGLIO
    comandi.insert(pair<string,int>("quit",8));

    map<string,int>::iterator it;


    while(!quit){
        cout<<percorso;
        getline(cin, scelta);

        istringstream stream(scelta);
        string tmp;
        stream >> tmp;

        for(auto& a : comandi){
            if(tmp == a.first){
                if(!check){
                    check = true;
                    break;
                }
            }
        }

        if(check){
            auto it = comandi.find(tmp);

            switch (it->second) {
                case 1:
                    cout<<"hai inserito il comando "<< it->first<<endl;
                    stream >> tmp;
                    for (int i = 0; i < 3; i++) {
                        if(tmp == directory[i]){
                            percorso = "C:/Users/Ricchione/" + tmp + ">";
                        }
                    }
                    break;
                case 2:
                    cout<<"Hai inseirto il comando "<<it->first<<endl;
                case 8:
                    quit = true;

            }
        }else{
            cout<<"hai inserito un comando non valido"<<endl;
        }
    }

    return 0;
}
