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