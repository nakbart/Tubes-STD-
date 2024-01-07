#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define first(L) (L).first

typedef struct elmSosmed *adrSosmed;
typedef struct elmUser *adrUser;

struct listSosmed {
    adrSosmed first;
};

struct listUser {
    adrUser first;
};

struct infoSosmed {
    string nama;
    string kode;
    int sejak;
};

struct infoUser {
    string nama;
    string id;
    int umur;
};

struct elmSosmed {
    infoSosmed info;
    adrSosmed next;
    listUser user;
};

struct elmUser {
    infoUser info;
    adrUser next;
};

void createListSosmed(listSosmed &L);
void createListUser(listUser &L);
bool isSosmedEmpty(listSosmed L);
bool isUserEmpty(listUser L);
adrSosmed createElmSosmed(infoSosmed x);
adrUser createElmUser(infoUser x);
void insertFirstSosmed(listSosmed &L, adrSosmed P);
void insertFirstUser(listUser &L, adrUser P);
void insertLastSosmed(listSosmed &L, adrSosmed P);
void insertLastUser(listUser &L, adrUser P);
void deleteSosmed(listSosmed &L, string kode, adrSosmed &P);
void deleteUser(listSosmed &L, string kode, string namaUser, adrUser &P);
adrSosmed searchSosmed(listSosmed L, string kode);
adrUser searchUser(listSosmed L, string kode, string namaUser);
int countSosmed(listSosmed L);
int countUser(listUser L);
void showAllSosmed(listSosmed L);
void showAllUser(listUser L);
void clearScreen();
void enterUntukLanjut();

#endif // ADT_H_INCLUDED
