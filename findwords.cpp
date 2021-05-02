/*

Kelompok 5
1. M Dzaky Fadhil Athaya - 2017051005
2. Rifan Setiadi - 2017051019
3. Diva Amartya Syafitri - 2017051088

*/


#include <iostream>
#include <cstring>

using namespace std;
const int cols = 16, rows = 15;

 char words[rows][cols] = {"tgbwwinterwsesn",
                                "aaunttmmhfoodnb",
                                "jlwcqldzmpmvdmr",
                                "asagmquwvvbsohi",
                                "bwplotanadtpgnc",
                                "rewngodjcpnatnk",
                                "eeotwosbqharrsa",
                                "azcgeswewnaknpb",
                                "dinnerqodlwdcar",
                                "onopkwmparktzcc",
                                "qbfrogmamwpweey",
                                "lqzqnnmrzjjsclg",
                                "mosgzczetdbooto",
                                "pdcrzmsngrdnrpz",
                                "ohnkzwaterjgtra"};


char getWordCol[cols]; // variabel menampung karakter pada setiap kolom tertentu 

// Prototype
char *getWordVertical(int getIndex);
char *reverse(char *getWords);
bool searchVertical(char *getWord);
bool searchHorizontal(char *getWord);


int main()
{
    char word[16];
    int n;
    cin>>n;
    cin.ignore(1,'\n');
    for (int i=0;i<n;i++){
        cin.getline(word,16,'\n');
        if (searchVertical(word) || searchHorizontal(word))
            cout << "Ada\n";
        else 
            cout << "Tidak Ada\n";
    }
    return 0;
}

// fungsi 

// fungsi menyusun karakter yang ada di kolom tertentu pada setiap baris
char *getWordVertical(int getIndex){
    for (int i = 0; i < rows; i++){
        // menyimpan karakter yang terdapat di kolom tertentu pada setiap baris
        getWordCol[i] = words[i][getIndex];
    }

    return getWordCol;
}


// fungsi membalik kata
char *reverse(char *getWord){
    static char getCharacter[cols];
    int index = 0;
    for (int i = (strlen(getWord)-1); i >= 0; i--){
        getCharacter[index] = getWord[i];
        index++;
    }

    return getCharacter;
}


// fungsi mencari kata secara vertikal
bool searchVertical(char *getWord){
    // kondisi status awal
    bool status = false;

    for (int i = 0; i < cols-1; i++){
        // memanggil fungsi untuk menyimpan karakter yang terdapat di kolom tertentu setiap baris
        char *chrCol = getWordVertical(i);
        // lalu mencari kata yang dicari ada atau tidak
        if (strstr(chrCol,getWord)){
            status = true;
            break;
        }

        if (i == cols-2){
            for (int i = 0; i < cols-1; i++){
                // mencari kata pada susunan kata words[i] yang sudah dibalik
                if (strstr(reverse(chrCol),getWord)){
                    status = true;
                    break;
                }
            }
        }
    }

    return status;
}

// fungsi mencari kata secara horizontal
bool searchHorizontal(char *getWord){
    // kondisi status awal
    bool status = false; 

    for (int i = 0; i < rows; i++){

        // mencari apakah kata yang dicari itu ada
        if (strstr(words[i],getWord)){
            status = true;
            break;    
        }
        
        if (i == rows-1){
            for (int i = 0; i < rows; i++){
                // mencari kata pada susunan kata words[i] yang sudah dibalik
                if (strstr(reverse(words[i]),getWord)){
                    status = true;
                    break;
                }
            }
        }
    }
    return status;
}
