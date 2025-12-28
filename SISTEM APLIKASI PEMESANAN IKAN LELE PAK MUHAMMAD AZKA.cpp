#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ================= STRUKTUR DATA =================
struct Pemesanan {
    string kodeP;
    string namaP;
    string noWA;
    string alamatP;
    string tanggalP;
    int jumlah;
    int harga;
};

// ================= SUB MENU =================
int displaySubMenu() {
    int subPilihan;
    cout << "\n=========== SUB-MENU ============" << endl;
    cout << "1. Tambah / Hapus Pesanan" << endl;
    cout << "2. Edit Pemesanan Sebelumnya" << endl;
    cout << "3. Lihat Pesanan" << endl;
    cout << "Masukkan pilihan Anda (1/2/3): ";
    cin >> subPilihan;
    cin.ignore();
    return subPilihan;
}

// ================= TAMBAH PESANAN =================
void tambahPemesanan(vector<Pemesanan>& daftarPemesanan, int& total) {
    Pemesanan p;

    cout << "Input Kode Pemesanan   : ";
    getline(cin, p.kodeP);
    cout << "Input Nama Pemesan     : ";
    getline(cin, p.namaP);
    cout << "Input No Whatsapp      : ";
    getline(cin, p.noWA);
    cout << "Input Alamat Pemesan   : ";
    getline(cin, p.alamatP);
    cout << "Input Tanggal Pesanan  : ";
    getline(cin, p.tanggalP);
    cout << "Masukkan Jumlah Pesanan: ";
    cin >> p.jumlah;
    cin.ignore();

    p.harga = 21000 * p.jumlah;
    total += p.harga;

    daftarPemesanan.push_back(p);

    cout << "Pesanan berhasil ditambahkan!" << endl;
}

// ================= EDIT PESANAN =================
void editPemesanan(vector<Pemesanan>& daftarPemesanan, int& total) {
    string kodeEdit;
    cout << "Masukkan Kode Pemesanan yang ingin diedit: ";
    getline(cin, kodeEdit);

    for (size_t i = 0; i < daftarPemesanan.size(); i++) {
        if (daftarPemesanan[i].kodeP == kodeEdit) {
            int hargaLama = daftarPemesanan[i].harga;

            cout << "Edit Nama Pemesan     : ";
            getline(cin, daftarPemesanan[i].namaP);
            cout << "Edit No Whatsapp      : ";
            getline(cin, daftarPemesanan[i].noWA);
            cout << "Edit Alamat Pemesan   : ";
            getline(cin, daftarPemesanan[i].alamatP);
            cout << "Edit Tanggal Pesanan  : ";
            getline(cin, daftarPemesanan[i].tanggalP);
            cout << "Edit Jumlah Pesanan   : ";
            cin >> daftarPemesanan[i].jumlah;
            cin.ignore();

            daftarPemesanan[i].harga = 21000 * daftarPemesanan[i].jumlah;
            total = total - hargaLama + daftarPemesanan[i].harga;

            cout << "Pemesanan berhasil diubah!" << endl;
            return;
        }
    }
    cout << "Kode pemesanan tidak ditemukan." << endl;
}

// ================= HAPUS PESANAN =================
void hapusPemesanan(vector<Pemesanan>& daftarPemesanan, int& total) {
    string kodeHapus;
    cout << "Masukkan Kode Pemesanan yang ingin dihapus: ";
    getline(cin, kodeHapus);

    for (size_t i = 0; i < daftarPemesanan.size(); i++) {
        if (daftarPemesanan[i].kodeP == kodeHapus) {
            total -= daftarPemesanan[i].harga;
            daftarPemesanan.erase(daftarPemesanan.begin() + i);
            cout << "Pemesanan berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Kode pemesanan tidak ditemukan." << endl;
}

// ================= LIHAT PESANAN =================
void lihatPemesanan(const vector<Pemesanan>& daftarPemesanan) {
    if (daftarPemesanan.empty()) {
        cout << "Belum ada data pemesanan." << endl;
        return;
    }

    cout << "\n========= DAFTAR PEMESANAN =========" << endl;
    for (size_t i = 0; i < daftarPemesanan.size(); i++) {
        cout << "Kode Pemesanan   : " << daftarPemesanan[i].kodeP << endl;
        cout << "Nama Pemesan     : " << daftarPemesanan[i].namaP << endl;
        cout << "No Whatsapp      : " << daftarPemesanan[i].noWA << endl;
        cout << "Alamat Pemesan   : " << daftarPemesanan[i].alamatP << endl;
        cout << "Tanggal Pesanan  : " << daftarPemesanan[i].tanggalP << endl;
        cout << "Jumlah Pesanan   : " << daftarPemesanan[i].jumlah << endl;
        cout << "Harga            : Rp" << daftarPemesanan[i].harga << endl;
        cout << "----------------------------------" << endl;
    }
}

// ================= MAIN PROGRAM =================
int main() {
    vector<Pemesanan> daftarPemesanan;
    int total = 0;
    int pilihan;
    string ulang;

    do {
        cout << "\n========== MENU UTAMA ==========" << endl;
        cout << "1. Pemesanan Ikan" << endl;
        cout << "2. Kelola Data Pemesanan" << endl;
        cout << "Masukkan pilihan (1/2): ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            tambahPemesanan(daftarPemesanan, total);
        }
        else if (pilihan == 2) {
            int subPilihan = displaySubMenu();
            switch (subPilihan) {
                case 1: {
                    int ph;
                    cout << "1. Tambah Pesanan" << endl;
                    cout << "2. Hapus Pesanan" << endl;
                    cout << "Pilih (1/2): ";
                    cin >> ph;
                    cin.ignore();

                    if (ph == 1)
                        tambahPemesanan(daftarPemesanan, total);
                    else if (ph == 2)
                        hapusPemesanan(daftarPemesanan, total);
                    else
                        cout << "Pilihan tidak valid." << endl;
                    break;
                }
                case 2:
                    editPemesanan(daftarPemesanan, total);
                    break;
                case 3:
                    lihatPemesanan(daftarPemesanan);
                    break;
                default:
                    cout << "Pilihan tidak valid." << endl;
            }
        }
        else {
            cout << "Pilihan tidak valid!" << endl;
        }

        cout << "\nTotal sementara: Rp" << total << endl;
        cout << "Kembali ke menu awal? (iya/tidak): ";
        getline(cin, ulang);

    } while (ulang == "iya" || ulang == "IYA");

    cout << "\n====================================" << endl;
    cout << "TOTAL PEMBELIAN AKHIR: Rp" << total << endl;
    cout << "Terima kasih telah memesan!" << endl;
    cout << "====================================" << endl;

    return 0;
}
