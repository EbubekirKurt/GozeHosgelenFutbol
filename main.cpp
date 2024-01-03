/*					2204040183 EBUBEK�R KURT AYRIK HESAPLAMA YAPILARI PROJES�
	Bu projede 2 algoritma kullan�ld�. Bir tanesi sorting algoritmas�. Bunu comparePlayers fonksiyonunda kulland�m.
	Bir di�eri ise Greedy yani a�g�zl� algoritma. Vekt�r olarak ald���m futbolcular� de�erlerine g�re s�ral�yor ve ona g�re tak�m 1,2,3,4'e at�yor.
*/	


#include "AHY.h"

std::vector<Player> players = {
     	{"Cengiz �nder", "Fenerbah�e", "Kanat", 20000000.00},
        {"Sebastian Szymanski", "Fenerbah�e", "Orta Saha", 25000000.00},
        {"Ferdi Kad�o�lu", "Fenerbah�e", "Bek", 24000000.00},
        {"Dominik Livakovic", "Fenerbah�e", "Kaleci", 21000000.00},
        {"Rodrigo Becao", "Fenerbah�e", "Stoper", 16000000.00},
        {"Michy Batshuayi", "Fenerbah�e", "Forvet", 12000000.00},
        {"�rfan Can Kahveci", "Fenerbah�e", "Kanat", 11500000.00},
        {"Dusan Tadic", "Fenerbah�e", "Kanat", 10000000.00},
        {"Jayden Oosterwolde", "Fenerbah�e", "Bek", 9000000.00},
        {"Edin Dzeko", "Fenerbah�e", "Forvet", 8500000.00},
        {"Emre Mor", "Fenerbah�e", "Kanat", 7000000.00},
        {"Alexander Djiku", "Fenerbah�e", "Stoper", 15000000.00},
        {"Serdar Aziz", "Fenerbah�e", "Stoper", 4000000.00},
        {"Bartu� Elmaz", "Fenerbah�e", "Orta Saha", 2000000.00},
        {"Bright Osayi Samuel", "Fenerbah�e", "Bek", 16000000.00},
        {"Miguel Crespo", "Fenerbah�e", "Orta Saha", 7500000.00},
        {"Ryan Kent", "Fenerbah�e", "Kanat", 6000000.00},
        {"�smail Y�ksek", "Fenerbah�e", "Orta Saha", 9500000.00},
        {"Mert Hakan Yanda�", "Fenerbah�e", "Orta Saha", 5000000.00},
        {"Fernando Muslera", "Galatasaray", "Kaleci", 16000000.00},
        {"Victor Nelsson", "Galatasaray", "Stoper", 12000000.00},
        {"Davinson Sanchez", "Galatasaray", "Stoper", 12000000.00},
        {"Abd�lkerim Bardak��", "Galatasaray", "Stoper", 12000000.00},
        {"Kaan Ayhan", "Galatasaray", "Stoper", 7000000.00},
        {"Angelino", "Galatasaray", "Bek", 5000000.00},
        {"Sacha Boey", "Galatasaray", "Bek", 19000000.00},
        {"Lucas Torreira", "Galatasaray", "Orta Saha", 20000000.00},
        {"Tanguy Ndombele", "Galatasaray", "Orta Saha", 5000000.00},
        {"Wilfried Zaha", "Galatasaray", "Kanat", 15000000.00},
        {"Kerem Akt�rko�lu", "Galatasaray", "Kanat", 15000000.00},
        {"Tete", "Galatasaray", "Kanat", 20000000.00},
        {"Bar�� Alper Y�lmaz", "Galatasaray", "Forvet", 10000000.00},
        {"Dries Mertens", "Galatasaray", "Orta Saha", 5000000.00},
        {"Mauro �cardi", "Galatasaray", "Forvet", 23000000.00},
        {"Cedric Bakambu", "Galatasaray", "Forvet", 5000000.00},
        {"Hakim Ziyech", "Galatasaray", "Orta Saha", 15000000.00},
        {"Kerem Demirbay", "Galatasaray", "Orta Saha", 4000000.00},
        {"Hamza Akman", "Galatasaray", "Orta Saha", 500000.00},
        {"Sergio Oliviera", "Galatasaray", "Orta Saha", 5000000.00},
        {"Ersin Destano�lu", "Be�ikta�", "Kaleci", 5000000.00},
        {"Mert G�nok", "Be�ikta�", "Kaleci", 5000000.00},
        {"Daniel Amartey", "Be�ikta�", "Stoper", 11000000.00},
        {"Tayyip Talha Sonu�", "Be�ikta�", "Stoper", 4000000.00},
        {"Eric Bailey", "Be�ikta�", "Stoper", 4500000.00},
        {"Arthur Masuaku", "Be�ikta�", "Bek", 7000000.00},
        {"Valentin Rosier", "Be�ikta�", "Bek", 6000000.00},
        {"Amir Hadziahmetovic", "Be�ikta�", "Orta Saha", 11000000.00},
        {"Jean Onana", "Be�ikta�", "Orta Saha", 4500000.00},
        {"Gedson Fernandes", "Be�ikta�", "Orta Saha", 20000000.00},
        {"Alex Oxlade-Chamberlain", "Be�ikta�", "Orta Saha", 12000000.00},
        {"Salih U�an", "Be�ikta�", "Orta Saha", 7000000.00},
        {"Bahtiyor Zaynutdinov", "Be�ikta�", "Orta Saha", 8000000.00},
        {"Ante Rebic", "Be�ikta�", "Kanat", 5000000.00},
        {"Jakson Muleka", "Be�ikta�", "Kanat", 5000000.00},
        {"Milot Rashica", "Be�ikta�", "Kanat", 10000000.00},
        {"Vincent Aboubakar", "Be�ikta�", "Forvet", 11000000.00},
        {"Cenk Tosun", "Be�ikta�", "Forvet", 4000000.00},
        {"Onur Bulut", "Be�ikta�", "Bek", 3500000.00},
        {"Necip Uysal", "Be�ikta�", "Joker", 2000000.00},
        {"Nicolas Pepe", "Trabzonspor", "Kanat", 14000000.00},
        {"Paul Onuachu", "Trabzonspor", "Forvet", 13000000.00},
        {"Anastasios Bakasetas", "Trabzonspor", "Orta Saha", 10000000.00},
        {"Mahmoud Trezeguet", "Trabzonspor", "Kanat", 10000000.00},
        {"U�urcan �ak�r", "Trabzonspor", "Kaleci", 10000000.00},
        {"Abd�lkerim �m�r", "Trabzonspor", "Orta Saha", 9000000.00},
        {"Batista Mendy", "Trabzonspor", "Orta Saha", 7000000.00},
        {"Enis Bardhi", "Trabzonspor", "Orta Saha", 6000000.00},
        {"Berat �zdemir", "Trabzonspor", "Orta Saha", 4000000.00},
        {"Umut Bozok", "Trabzonspor", "Santrafor", 3500000.00},
        {"Edin Visca", "Trabzonspor", "Kanat", 3000000.00},
        {"Yusuf Sar�", "Adana DS", "Kanat", 5000000.00},
        {"Andreaw Gravillon", "Adana DS", "Stoper", 4500000.00},
        {"Dorukhan Tok�z", "Adana DS", "Orta Saha", 4500000.00},
        {"Pape Abou Cisse", "Adana DS", "Stoper", 3500000.00},
        {"Jonas Svensson", "Adana DS", "Bek", 6000000.00},
        {"Mbaye Niang", "Adana DS", "Forvet", 5000000.00},
        {"Emre Akbaba", "Adana DS", "Orta Saha", 2000000.00},
        {"Mario Balotelli", "Adana DS", "Forvet", 4000000.00},
        {"Semih G�ler", "Adana DS", "Stoper", 2500000.00},
        {"Younes Belhanda", "Adana DS", "Orta Saha", 2000000.00}
};

std::vector<Team> teams = {
    {"TEAM ALDAS", {}, 0.0},
    {"TEAM AKANERAIVA", {}, 0.0},
    {"TEAM FURKAN", {}, 0.0},
    {"TEAM MEMOLI", {}, 0.0}
};

int main() {
    setlocale(LC_ALL, "Turkish");
    createTeams(players, teams);
    printTeams(teams);

    return 0;
}

