#if (__cplusplus >= 199711L)

#include <iostream>
#include <string>
#include <sstream>
#include <cstddef>
#include <cstdint>
#include <cstdlib>

using namespace std;

struct Orang {
    string nama;
    int hariLahir;
    int bulanLahir;
    int tahunLahir;
};

uint32_t determineSeedOf(const Orang& o) {
    uint32_t seed = 0;
    for (char ch : o.nama) {
        ch += ((ch >= 'A') && (ch <= 'Z')) ? 32 : 0;
        seed = (seed + (uint32_t)ch * ch) % 0xFFFF;
    }
    seed = (seed + o.hariLahir * 3) % 0xFFFF;
    seed = (seed + o.bulanLahir * 4) % 0xFFFF;
    seed = (seed + o.tahunLahir * 5) % 0xFFFF;
    return seed;
}

int main() {
    cout << " *** SELAMAT DATANG DI PT. PENCARI CINTA SEJATI ***" << endl;

    while (true) {
        Orang o1, o2;
        o1 = Orang{"", 0, 0, 0};
        o2 = Orang{"", 0, 0, 0};

        cout << "Masukkan nama anda: ";
        getline(cin, o1.nama);

        cout << "Masukkan nama pasangan anda: ";
        getline(cin, o2.nama);

        char inputTanggalLahirCh;
        cout << "Tingkatkan akurasi Dr. Cinta? (Y/N): ";
        cin >> inputTanggalLahirCh;

        bool inputTanggalLahir = (inputTanggalLahirCh == 'Y') || (inputTanggalLahirCh == 'y');
        if (inputTanggalLahir) {
            cout << "Masukkan tanggal lahir anda (DD MM YYYY): ";
            cin >> o1.hariLahir >> o1.bulanLahir >> o1.tahunLahir;

            cout << "Masukkan tanggal lahir pasangan anda (DD MM YYYY): ";
            cin >> o2.hariLahir >> o2.bulanLahir >> o2.tahunLahir;
        }

        uint32_t seed = 0;
        seed += determineSeedOf(o1);
        seed += determineSeedOf(o2);
        srand(seed);

        int result = rand() % 100;
        cout << "Hasil: " << result << "%!" << endl;
        char playAgainCh;
        cout << "Main lagi? (Y/N): ";
        cin >> playAgainCh;

        cin.ignore();

        if (!((playAgainCh == 'Y') || (playAgainCh == 'y'))) {
            break;
        }
    }

    return 0;
}

#else
#error Hanya dapat dicompile dengan C++11!
#endif

