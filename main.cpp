#include "tubes.h"
#include <stdio.h>

int main() {
    listSosmed L;
    string input, kode, namaUser;
    adrSosmed pSosmed;
    adrUser pUser;
    infoSosmed iSosmed;
    infoUser iUser;
    int n;

    createListSosmed(L);

    while (true) {
        clearScreen();
        cout << "========== DATA SOSMED DAN USER ==========" << endl;
        cout << "1. Insert Sosmed" << endl;
        cout << "2. Insert User" << endl;
        cout << "3. Search Sosmed" << endl;
        cout << "4. Search User" << endl;
        cout << "5. Delete Sosmed" << endl;
        cout << "6. Delete User" << endl;
        cout << "7. Show Jumlah Sosmed" << endl;
        cout << "8. Show Jumlah User" << endl;
        cout << "9. Show All Sosmed" << endl;
        cout << "10. Show All User" << endl;
        cout << "11. Exit" << endl;
        cout << "==========================================" << endl;
        cout << endl;

        cout << "Pilih: ";
        cin >> input;
        cout << endl;

        if (input == "1") {         // Insert Sosmed
            cout << "Masukkan Nama               : "; cin >> iSosmed.nama;
            cout << "Masukkan Kode               : "; cin >> iSosmed.kode;
            cout << "Masukkan Awal Tahun Berdiri : "; cin >> iSosmed.sejak;
            cout << endl;

            pSosmed = createElmSosmed(iSosmed);
            insertFirstSosmed(L, pSosmed);

            cout << "Insert Sosmed Baru berhasil" << endl;
            cout << endl;

            enterUntukLanjut();

        } else if (input == "2") {  // Insert User
            if (countSosmed(L) == 0) {
                cout << "List Sosmed Masih Kosong! Isikan dulu" << endl;
                cout << endl;

                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan Kode dari Sosmed : "; cin >> kode;
            cout << endl;

            pSosmed = searchSosmed(L, kode);

            if (pSosmed == NULL) {
                cout << "Sosmed dengan kode " << kode << " tidak dapat ditemukan!" << endl;
                cout << endl;

                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan Nama : "; cin >> iUser.nama;
            cout << "Masukkan ID   : "; cin >> iUser.id;
            cout << "Masukkan Umur : "; cin >> iUser.umur;
            cout << endl;

            pUser = createElmUser(iUser);
            insertFirstUser(pSosmed->user, pUser);

            cout << "Insert User Baru berhasil" << endl;
            cout << endl;

            enterUntukLanjut();

        } else if (input == "3") {  // Search Sosmed
            if (countSosmed(L) == 0) {
                cout << "List Sosmed Masih Kosong! Isikan dulu" << endl;
                cout << endl;

                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan kode : "; cin >> kode;
            cout << endl;

            pSosmed = searchSosmed(L, kode);

            if (pSosmed == NULL) {
                cout << "Data Sosmed dengan Kode " << kode << "tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                cout << "Nama               : " << info(pSosmed).nama << endl;
                cout << "Kode               : " << info(pSosmed).kode << endl;
                cout << "Awal Tahun Berdiri : " << info(pSosmed).sejak << endl;
                cout << endl;
            }

            enterUntukLanjut();

        } else if (input == "4") {  // Search User
            if (countSosmed(L) == 0) {
                cout << "List Sosmed Masih Kosong! Isikan dulu" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan Kode Sosmed : "; cin >> kode;

            pSosmed = searchSosmed(L, kode);

            if (pSosmed == NULL) {
                cout << "Data Sosmed dengan Kode " << kode << "tidak dapat ditemukan!" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan nama User : "; cin >> namaUser;
            cout << endl;

            pUser = searchUser(L, kode, namaUser);

            if (pUser == NULL) {
                cout << "Data User dengan nama " << namaUser << "tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                cout << "Nama : " << info(pUser).nama << endl;
                cout << "ID   : " << info(pUser).id << endl;
                cout << "Umur : " << info(pUser).umur << endl;
                cout << endl;
            }

            enterUntukLanjut();

        } else if (input == "5") {  // Delete Sosmed
            if (countSosmed(L) == 0) {
                cout << "List Sosmed Masih Kosong! Isikan dulu" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan Kode : "; cin >> kode;
            cout << endl;

            deleteSosmed(L, kode, pSosmed);

            if (pSosmed == NULL) {
                cout << "Data Sosmed dengan kode " << kode << "tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                cout << "Data Sosmed yang terhapus" << endl;
                cout << "Nama               : " << info(pSosmed).nama << endl;
                cout << "Kode               : " << info(pSosmed).kode << endl;
                cout << "Awal Tahun Berdiri : " << info(pSosmed).sejak << endl;
                cout << endl;
            }

            enterUntukLanjut();

        } else if (input == "6") {  // Delete User
            if (countSosmed(L) == 0) {
                cout << "List Sosmed Mmsih kosong! Isikan dulu" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan Kode Sosmed : "; cin >> kode;

            pSosmed = searchSosmed(L, kode);

            if (pSosmed == NULL) {
                cout << "Data Sosmed dengan kode " << kode << "tidak dapat ditemukan!" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan nama User : "; cin >> namaUser;
            cout << endl;

            deleteUser(L, kode, namaUser, pUser);

            if (pUser == NULL) {
                cout << "Data User dengan nama " << namaUser << "tidak dapat ditemukan!" << endl;
                cout << endl;
            } else {
                cout << "Nama : " << info(pUser).nama << endl;
                cout << "ID   : " << info(pUser).id << endl;
                cout << "Umur : " << info(pUser).umur << endl;
                cout << endl;
            }

            enterUntukLanjut();

        } else if (input == "7") {  // Show Jumlah Sosmed
            n = countSosmed(L);

            cout << "Jumlah Sosmed dalam list adalah: " << n << " Sosmed" << endl;
            cout << endl;

            enterUntukLanjut();

        } else if (input == "8") {  // Show Jumlah User
            n = 0;

            pSosmed = first(L);

            while (pSosmed != NULL) {
                n += countUser(pSosmed->user);

                pSosmed = next(pSosmed);
            }

            cout << "Jumlah User dalam list adalah: " << n << endl;
            cout << endl;

            enterUntukLanjut();

        } else if (input == "9") {  // Show All Sosmed
            if (countSosmed(L) == 0) {
                cout << "List Sosmed Masih Kosong! Isikan dulu" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            showAllSosmed(L);
            enterUntukLanjut();
        } else if (input == "10") { // Show All User
            if (countSosmed(L) == 0) {
                cout << "List Sosmed Masih Kosong! Isikan dulu" << endl;
                cout << endl;
                enterUntukLanjut();
                continue;
            }

            cout << "Masukkan kode : ";
            cin >> kode;
            pSosmed = searchSosmed(L, kode);

            if (pSosmed == NULL) {
                cout << "Data Sosmed dengan Kode " << kode << "tidak dapat ditemukan!" << endl;
                enterUntukLanjut();
                continue;
            }

            showAllUser(pSosmed->user);
            cout << endl;

            enterUntukLanjut();

        } else if (input == "11") { // Exit
            break;
        } else {
            cout << "Input anda tidak valid." << endl;
            cout << endl;

            enterUntukLanjut();
        }
    }

    clearScreen();
    cout << "Bye!" << endl;

    return 0;
}
