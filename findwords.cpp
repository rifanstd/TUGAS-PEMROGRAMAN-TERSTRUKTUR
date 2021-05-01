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
char *reverse(char *);
bool searchVertical(char *);
bool searchHorizontal(char *);


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
    // membalik kata dengan fungsi strrev()
    char *reverseWord = strrev(getWord);

    return reverseWord;
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
            // membalik kata/word
            char *reverseWord = reverse(getWord);
            for (int i = 0; i < cols-1; i++){
                // mencari kata yang sudah dibalik, atau mencari kata dari kanan-kiri
                if (strstr(chrCol,reverseWord)){
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

        // mencari apakah kata yang dicari itu ada, dari kiri-kanan
        if (strstr(words[i],getWord)){
            status = true;
            break;    
        }
        
        if (i == rows-1){
            // membalik kata/word
            char *reverseWord = reverse(getWord);
            for (int i = 0; i < rows; i++){
                // mencari kata yang sudah dibalik, atau mencari kata dari kanan-kiri
                if (strstr(words[i],reverseWord)){
                    status = true;
                    break;
                }
            }
        }
    }
}
