/*					2204040183 EBUBEKÝR KURT AYRIK HESAPLAMA YAPILARI PROJESÝ
	Bu projede 2 algoritma kullanýldý. Bir tanesi sorting algoritmasý. Bunu comparePlayers fonksiyonunda kullandým.
	Bir diðeri ise Greedy yani açgözlü algoritma. Vektör olarak aldýðým futbolcularý deðerlerine göre sýralýyor ve ona göre takým 1,2,3,4'e atýyor.
*/	


#include "AHY.h"

std::vector<Player> players = {
     	{"Cengiz Ünder", "Fenerbahçe", "Kanat", 20000000.00},
        {"Sebastian Szymanski", "Fenerbahçe", "Orta Saha", 25000000.00},
        {"Ferdi Kadýoðlu", "Fenerbahçe", "Bek", 24000000.00},
        {"Dominik Livakovic", "Fenerbahçe", "Kaleci", 21000000.00},
        {"Rodrigo Becao", "Fenerbahçe", "Stoper", 16000000.00},
        {"Michy Batshuayi", "Fenerbahçe", "Forvet", 12000000.00},
        {"Ýrfan Can Kahveci", "Fenerbahçe", "Kanat", 11500000.00},
        {"Dusan Tadic", "Fenerbahçe", "Kanat", 10000000.00},
        {"Jayden Oosterwolde", "Fenerbahçe", "Bek", 9000000.00},
        {"Edin Dzeko", "Fenerbahçe", "Forvet", 8500000.00},
        {"Emre Mor", "Fenerbahçe", "Kanat", 7000000.00},
        {"Alexander Djiku", "Fenerbahçe", "Stoper", 15000000.00},
        {"Serdar Aziz", "Fenerbahçe", "Stoper", 4000000.00},
        {"Bartuð Elmaz", "Fenerbahçe", "Orta Saha", 2000000.00},
        {"Bright Osayi Samuel", "Fenerbahçe", "Bek", 16000000.00},
        {"Miguel Crespo", "Fenerbahçe", "Orta Saha", 7500000.00},
        {"Ryan Kent", "Fenerbahçe", "Kanat", 6000000.00},
        {"Ýsmail Yüksek", "Fenerbahçe", "Orta Saha", 9500000.00},
        {"Mert Hakan Yandaþ", "Fenerbahçe", "Orta Saha", 5000000.00},
        {"Fernando Muslera", "Galatasaray", "Kaleci", 16000000.00},
        {"Victor Nelsson", "Galatasaray", "Stoper", 12000000.00},
        {"Davinson Sanchez", "Galatasaray", "Stoper", 12000000.00},
        {"Abdülkerim Bardakçý", "Galatasaray", "Stoper", 12000000.00},
        {"Kaan Ayhan", "Galatasaray", "Stoper", 7000000.00},
        {"Angelino", "Galatasaray", "Bek", 5000000.00},
        {"Sacha Boey", "Galatasaray", "Bek", 19000000.00},
        {"Lucas Torreira", "Galatasaray", "Orta Saha", 20000000.00},
        {"Tanguy Ndombele", "Galatasaray", "Orta Saha", 5000000.00},
        {"Wilfried Zaha", "Galatasaray", "Kanat", 15000000.00},
        {"Kerem Aktürkoðlu", "Galatasaray", "Kanat", 15000000.00},
        {"Tete", "Galatasaray", "Kanat", 20000000.00},
        {"Barýþ Alper Yýlmaz", "Galatasaray", "Forvet", 10000000.00},
        {"Dries Mertens", "Galatasaray", "Orta Saha", 5000000.00},
        {"Mauro Ýcardi", "Galatasaray", "Forvet", 23000000.00},
        {"Cedric Bakambu", "Galatasaray", "Forvet", 5000000.00},
        {"Hakim Ziyech", "Galatasaray", "Orta Saha", 15000000.00},
        {"Kerem Demirbay", "Galatasaray", "Orta Saha", 4000000.00},
        {"Hamza Akman", "Galatasaray", "Orta Saha", 500000.00},
        {"Sergio Oliviera", "Galatasaray", "Orta Saha", 5000000.00},
        {"Ersin Destanoðlu", "Beþiktaþ", "Kaleci", 5000000.00},
        {"Mert Günok", "Beþiktaþ", "Kaleci", 5000000.00},
        {"Daniel Amartey", "Beþiktaþ", "Stoper", 11000000.00},
        {"Tayyip Talha Sonuç", "Beþiktaþ", "Stoper", 4000000.00},
        {"Eric Bailey", "Beþiktaþ", "Stoper", 4500000.00},
        {"Arthur Masuaku", "Beþiktaþ", "Bek", 7000000.00},
        {"Valentin Rosier", "Beþiktaþ", "Bek", 6000000.00},
        {"Amir Hadziahmetovic", "Beþiktaþ", "Orta Saha", 11000000.00},
        {"Jean Onana", "Beþiktaþ", "Orta Saha", 4500000.00},
        {"Gedson Fernandes", "Beþiktaþ", "Orta Saha", 20000000.00},
        {"Alex Oxlade-Chamberlain", "Beþiktaþ", "Orta Saha", 12000000.00},
        {"Salih Uçan", "Beþiktaþ", "Orta Saha", 7000000.00},
        {"Bahtiyor Zaynutdinov", "Beþiktaþ", "Orta Saha", 8000000.00},
        {"Ante Rebic", "Beþiktaþ", "Kanat", 5000000.00},
        {"Jakson Muleka", "Beþiktaþ", "Kanat", 5000000.00},
        {"Milot Rashica", "Beþiktaþ", "Kanat", 10000000.00},
        {"Vincent Aboubakar", "Beþiktaþ", "Forvet", 11000000.00},
        {"Cenk Tosun", "Beþiktaþ", "Forvet", 4000000.00},
        {"Onur Bulut", "Beþiktaþ", "Bek", 3500000.00},
        {"Necip Uysal", "Beþiktaþ", "Joker", 2000000.00},
        {"Nicolas Pepe", "Trabzonspor", "Kanat", 14000000.00},
        {"Paul Onuachu", "Trabzonspor", "Forvet", 13000000.00},
        {"Anastasios Bakasetas", "Trabzonspor", "Orta Saha", 10000000.00},
        {"Mahmoud Trezeguet", "Trabzonspor", "Kanat", 10000000.00},
        {"Uðurcan Çakýr", "Trabzonspor", "Kaleci", 10000000.00},
        {"Abdülkerim Ömür", "Trabzonspor", "Orta Saha", 9000000.00},
        {"Batista Mendy", "Trabzonspor", "Orta Saha", 7000000.00},
        {"Enis Bardhi", "Trabzonspor", "Orta Saha", 6000000.00},
        {"Berat Özdemir", "Trabzonspor", "Orta Saha", 4000000.00},
        {"Umut Bozok", "Trabzonspor", "Santrafor", 3500000.00},
        {"Edin Visca", "Trabzonspor", "Kanat", 3000000.00},
        {"Yusuf Sarý", "Adana DS", "Kanat", 5000000.00},
        {"Andreaw Gravillon", "Adana DS", "Stoper", 4500000.00},
        {"Dorukhan Toköz", "Adana DS", "Orta Saha", 4500000.00},
        {"Pape Abou Cisse", "Adana DS", "Stoper", 3500000.00},
        {"Jonas Svensson", "Adana DS", "Bek", 6000000.00},
        {"Mbaye Niang", "Adana DS", "Forvet", 5000000.00},
        {"Emre Akbaba", "Adana DS", "Orta Saha", 2000000.00},
        {"Mario Balotelli", "Adana DS", "Forvet", 4000000.00},
        {"Semih Güler", "Adana DS", "Stoper", 2500000.00},
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

