#include <iostream>
#include <ctime>
#include <sstream>
using namespace std;

struct TiketKonser {
    string kodeBooking;
    string namaPembeli;
    string email;
    string events;
    string tglEvent;
    string jnsTiket;
    string danaKembali;
    string tujuan;
    string tglPembelian;
    int jmlTiket;
    int menu;
    int event;
    int jenisTiket;
    int pembayaran;
    int bank;
    int totalHarga;
    char ulang;
};

struct Event {
    string namaEvent;
    string tglEvent;
    int hargaVIP;
    int hargaFestival;
    string lokasi;
};

Event eventList[] = {
    {"Sheila On 7", "14 Juli 2024", 750000, 450000, "Gor Satria Purwokerto"},
    {"Tulus", "21 Juli 2024", 275000, 200000, "Terminal Bulupitu"},
    {"Tiara Andini", "28 Juli 2024", 175000, 250000, "Gor Satria Purwokerto"}
};

void tampilkanMenu(TiketKonser &pembeli) {
    cout << "=======================================================\n";
    cout << "|\t\t\t MENU                         |\n";
    cout << "=======================================================\n";
    cout << "| 1. | Pemesanan Tiket                                |\n";
    cout << "| 2. | Pembatalan Tiket                               |\n";
    cout << "| 3. | Riwayat Pembelian                              |\n";
    cout << "| 4. | Keluar                                         |\n";
    cout << "=======================================================\n";
    cout << "Masukkan Pilihan Anda [1-4] : ";
    cin >> pembeli.menu;
    cin.ignore(); // Mengabaikan newline character setelah memasukkan menu
    cout << endl << endl;
}

void inputDataPembeli(TiketKonser &pembeli) {
    cout << "=======================================================\n";
    cout << "|\t\t\t DATA                         |\n";
    cout << "=======================================================\n";
    cout << " Nama Pembeli        : ";
    getline(cin, pembeli.namaPembeli);
    cout << " Masukkan Email Anda : ";
    getline(cin, pembeli.email);
    cout << " Jumlah Tiket        : ";
    cin >> pembeli.jmlTiket;
    cout << "=======================================================\n";
    cout << endl << endl;
}

void pilihEvent(TiketKonser &pembeli) {
    cout << "=======================================================\n";
    cout << "\t\t\t EVENT                    \n";
    cout << "=======================================================\n";
    cout << " NO. | Deskripsi                                       \n";
    cout << "-------------------------------------------------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << " " << i + 1 << ".  | " << eventList[i].namaEvent << "\n";
        cout << "     | Tanggal  : " << eventList[i].tglEvent << "\n";
        cout << "     | Waktu    : 21.00 WIB\n";
        cout << "     | Lokasi   : " << eventList[i].lokasi << "\n\n";
    }
    cout << "=======================================================\n";
    cout << "Masukkan Pilihan Anda [1-3] : ";
    cin >> pembeli.event;
    cin.ignore(); // Mengabaikan newline character setelah memasukkan event
    cout << endl << endl;
}

void pilihJenisTiket(TiketKonser &pembeli) {
    cout << "=======================================================\n";
    cout << "|\t\t\tJENIS TIKET                   |\n";
    cout << "=======================================================\n";
    cout << "| NO.| Jenis Tiket          | Harga                   |\n";
    cout << "-------------------------------------------------------\n";
    cout << "| 1. | VIP                  | Rp " << eventList[pembeli.event - 1].hargaVIP << "               |\n";
    cout << "| 2. | Festival             | Rp " << eventList[pembeli.event - 1].hargaFestival << "               |\n";
    cout << "=======================================================\n";
    cout << "Masukkan Pilihan Anda [1-2] : ";
    cin >> pembeli.jenisTiket;
    cin.ignore(); // Mengabaikan newline character setelah memasukkan jenis tiket
    cout << endl;
    if (pembeli.jenisTiket != 1 && pembeli.jenisTiket != 2) {
        cout << "Pilihan Tidak Tersedia\n\n";
        pembeli.jenisTiket = -1; // Menandai bahwa input tidak valid
    }
}

void pilihMetodePembayaran(TiketKonser &pembeli) {
    cout << "=======================================================\n";
    cout << "|\t\t   METODE PEMBAYARAN                  |\n";
    cout << "=======================================================\n";
    cout << "| 1. | Bank                                           |\n";
    cout << "| 2. | Dana                                           |\n";
    cout << "| 3. | Shopeepay                                      |\n";
    cout << "=======================================================\n";
    cout << "Masukkan Pilihan Anda [1-3] : ";
    cin >> pembeli.pembayaran;
    cin.ignore(); // Mengabaikan newline character setelah memasukkan metode pembayaran
    cout << endl << endl;

    if (pembeli.pembayaran == 1) {
        cout << "=======================================================\n";
        cout << "|\t\t   METODE PEMBAYARAN                  |\n";
        cout << "=======================================================\n";
        cout << "| NO.| Nama Bank                                      |\n";
        cout << "-------------------------------------------------------\n";
        cout << "| 1. | Bank BNI                                       |\n";
        cout << "| 2. | Bank BRI                                       |\n";
        cout << "| 3. | Bank Mandiri                                   |\n";
        cout << "=======================================================\n";
        cout << "Masukkan Pilihan Anda [1-3] : ";
        cin >> pembeli.bank;
        cin.ignore(); // Mengabaikan newline character setelah memasukkan bank
        cout << endl << endl;
        if (pembeli.bank == 1) {
            cout << "| Bank BNI     : 1709087264 (Chelsea)                 |\n";
        } else if (pembeli.bank == 2) {
            cout << "| Bank BRI     : 1563892873669523 (Chelsea)           |\n";
        } else if (pembeli.bank == 3) {
            cout << "| Bank Mandiri : 1456370298721 (Chelsea)              |\n";
        } else {
            cout << "Pilihan Tidak Tersedia\n";
        }
    } else if (pembeli.pembayaran == 2) {
        cout << "| Dana         : 087563890261 (Chelsea)      |\n";
    } else if (pembeli.pembayaran == 3) {
        cout << "| Shopeepay    : 087563890261 (Chelsea)      |\n";
    } else {
        cout << "Pilihan Tidak Tersedia\n";
    }
    cout << "=======================================================\n";
    cout << endl << endl;
}

const string bulan[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

string tglPembelian() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;
    ss << ltm->tm_mday << " " << bulan[ltm->tm_mon] << " " << 1900 + ltm->tm_year;
    return ss.str();
}

int urutanPesanan = 0;
string kodeBooking(const string &namaPembeli, const string &event, int urutan) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;
    ss << namaPembeli[0] << event[0] << ltm->tm_mday << 1 + ltm->tm_mon << 1900 + ltm->tm_year << urutan;

    return ss.str();
}

void tiket(TiketKonser &pembeli, Event eventList[]) {
    if (pembeli.event >= 1 && pembeli.event <= 3) {
        pembeli.events = eventList[pembeli.event - 1].namaEvent;
        pembeli.tglEvent = eventList[pembeli.event - 1].tglEvent;
        if (pembeli.jenisTiket == 1) {
            pembeli.jnsTiket = "VIP";
            pembeli.totalHarga = pembeli.jmlTiket * eventList[pembeli.event - 1].hargaVIP;
        } else if (pembeli.jenisTiket == 2) {
            pembeli.jnsTiket = "Festival";
            pembeli.totalHarga = pembeli.jmlTiket * eventList[pembeli.event - 1].hargaFestival;
        } else {
            cout << "Pilihan Tidak Tersedia\n\n";
            return;
        }
        pembeli.kodeBooking = kodeBooking(pembeli.namaPembeli, pembeli.events, urutanPesanan);
        pembeli.tglPembelian = tglPembelian();
    } else {
        cout << "Pilihan Tidak Tersedia\n\n";
    }
}

const int maksTiket = 100;
TiketKonser riwayatTiket[maksTiket];
int countRiwayat = 0;

void riwayatPemesanan() {
    if (countRiwayat == 0) {
        cout << "Tidak ada riwayat pembelian.\n";
        return;
    }

    cout << "=======================================================\n";
    cout << "|\t\t    RIWAYAT PEMESANAN                 |\n";
    cout << "=======================================================\n";
    for (int i = 0; i < countRiwayat; ++i) {
        const TiketKonser &pembeli = riwayatTiket[i];
        cout << " Kode Booking      : " << pembeli.kodeBooking << endl;
        cout << " Nama              : " << pembeli.namaPembeli << endl;
        cout << " Tanggal Pembelian : " << pembeli.tglPembelian << endl;
        cout << " Jumlah Tiket      : " << pembeli.jmlTiket << endl;
        cout << " Event             : " << pembeli.events << endl;
        cout << " Tanggal Event     : " << pembeli.tglEvent << endl;
        cout << " Jenis Tiket       : " << pembeli.jnsTiket << endl;
        cout << " Total Harga       : Rp " << pembeli.totalHarga << endl;
        cout << "=======================================================\n";
    }
    
}


void pembatalanTiket() {
    if (countRiwayat == 0) {
        cout << "Tidak ada tiket untuk dibatalkan.\n";
        return;
    }

    string kodeBookingInput;
    cout << "Masukkan kode booking untuk membatalkan tiket: ";
    cin >> kodeBookingInput;
    cin.ignore();  // Mengabaikan newline character setelah memasukkan kode booking

    bool found = false;
    for (int i = 0; i < countRiwayat; ++i) {
        if (riwayatTiket[i].kodeBooking == kodeBookingInput) {
            TiketKonser &pembeli = riwayatTiket[i];
            cout << "=======================================================\n";
            cout << "|\tPEMBATALAN PEMESANAN TIKET        |\n";
            cout << "=======================================================\n";
            cout << " Nama Pembeli                    : " << pembeli.namaPembeli << endl;
            cout << " Tanggal Pembelian               : " << pembeli.tglPembelian << endl;
            cout << " Jumlah Tiket                    : " << pembeli.jmlTiket << endl;
            cout << " Event                           : " << pembeli.events << endl;
            cout << " Tanggal Event                   : " << pembeli.tglEvent << endl;
            cout << " Jenis Tiket                     : " << pembeli.jnsTiket << endl;
            cout << " Total Harga                     : Rp " << pembeli.totalHarga << endl;
            cout << " Pengembalian [ShpPay/Dana/Bank] : ";
            getline(cin, pembeli.danaKembali);
            cout << " Masukkan Rekening/Nomor Tujuan  : ";
            getline(cin, pembeli.tujuan);
            cout << "=======================================================\n";
            cout << " Pembatalan Tiket Konser Berhasil!\n Dana akan dikembalikan melalui Nomor/Rekening tujuan\n";
            found = true;

            // Menghapus tiket dengan mengganti elemen saat ini dengan elemen terakhir
            riwayatTiket[i] = riwayatTiket[countRiwayat - 1];
            countRiwayat--;
            break;
        }
    }

    if (!found) {
        cout << "Tidak ditemukan tiket dengan kode booking tersebut.\n";
    }
}


int main() {
    TiketKonser pembeli;

    do {
        tampilkanMenu(pembeli);
        
        switch (pembeli.menu) {
            case 1:
                inputDataPembeli(pembeli);
                pilihEvent(pembeli);
                if (pembeli.event >= 1 && pembeli.event <= 3) {
                    pilihJenisTiket(pembeli);
                    if (pembeli.jenisTiket == -1) {
                        // Jika jenis tiket tidak valid, hentikan proses pemesanan
                        break;
                    }
                    pilihMetodePembayaran(pembeli);
                    if ((pembeli.pembayaran == 1 && (pembeli.bank == 1 || pembeli.bank == 2 || pembeli.bank == 3)) || (pembeli.pembayaran > 1 && pembeli.pembayaran < 4)) {
                        urutanPesanan++;
                        tiket(pembeli, eventList);
                        if (countRiwayat < maksTiket) {
                            riwayatTiket[countRiwayat++] = pembeli;
                        } else {
                            cout << "Riwayat tiket penuh. Tidak dapat menyimpan riwayat baru.\n";
                        }
                        cout << "=======================================================\n";
                        cout << "|\t\t   RESI TIKET KONSER                  |\n";
                        cout << "=======================================================\n";
                        cout << " Nama              : " << pembeli.namaPembeli << endl;
                        cout << " Kode Booking      : " << pembeli.kodeBooking << endl;
                        cout << " Tanggal Pembelian : " << pembeli.tglPembelian << endl;
                        cout << " Jumlah Tiket      : " << pembeli.jmlTiket << endl;
                        cout << " Event             : " << pembeli.events << endl;
                        cout << " Tanggal Event     : " << pembeli.tglEvent << endl;
                        cout << " Jenis Tiket       : " << pembeli.jnsTiket << endl;
                        cout << " Total Harga       : Rp " << pembeli.totalHarga << endl;
                        cout << "=======================================================\n\n";
                    }
                } else {
                    cout << "Pilihan Tidak Tersedia\n";
                    cout << endl;
                }
                break;
            case 2:
                pembatalanTiket();
                break;
            case 3:
                riwayatPemesanan();
                break;
            case 4:
                cout << "Terima Kasih. Program Keluar\n";
                break;
            default:
                cout << "Pilihan Tidak Tersedia\n";
        }

        cout << endl;
        cout << "Ingin kembali ke menu utama? (Y/T) : ";
        cin >> pembeli.ulang;
    } while (pembeli.ulang == 'Y' || pembeli.ulang == 'y');
    cout << endl;
    return 0;
}
