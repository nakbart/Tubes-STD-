#include "tubes.h"

void createListSosmed(listSosmed &L) {
     first(L) = NULL;
}

void createListUser(listUser &L) {
     first(L) = NULL;
}

bool isSosmedEmpty(listSosmed L) {
    if (first(L) == NULL) {
        return true;
    }
    return false;
}

bool isUserEmpty(listUser L) {
    if (first(L) == NULL) {
        return true;
    }
    return false;
}

adrSosmed createElmSosmed(infoSosmed x) {
    listUser L;

    adrSosmed P = new elmSosmed;
    createListUser(L);

    info(P) = x;
    next(P) = NULL;
    P->user = L;
    return P;
}

adrUser createElmUser(infoUser x) {
    adrUser P = new elmUser;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertFirstSosmed(listSosmed &L, adrSosmed P) {
    next(P) = first(L);
    first(L) = P;
}

void insertFirstUser(listUser &L, adrUser P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLastSosmed(listSosmed &L, adrSosmed P) {
    adrSosmed last;

    if (first(L) == NULL) {
        first(L) = P;
    } else {
        last = first(L);
        while (next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}

void insertLastUser(listUser &L, adrUser P) {
    adrUser last;

    if (first(L) == NULL) {
        first(L) = P;
    } else {
        last = first(L);
        while (next(last) != NULL) {
            last = next(last);
        }
        next(last) = P;
    }
}

adrSosmed searchSosmed(listSosmed L, string kode) {
    adrSosmed P = first(L);

    while (P != NULL) {
        if (info(P).kode == kode) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

adrUser searchUser(listSosmed L, string kode, string namaUser) {
    adrUser Q;
    adrSosmed P = searchSosmed(L, kode);

    if (P == NULL) {
        return NULL;
    }

    Q = P->user.first;

    while (Q != NULL) {
        if (info(Q).nama == namaUser) {
            return Q;
        }

        Q = next(Q);
    }

    return NULL;
}

void deleteSosmed(listSosmed &L, string kode, adrSosmed &P) {
    adrSosmed prec;

    P = searchSosmed(L, kode);

    if (P != NULL) {
        if (first(L) == P) {
            first(L) = next(P);
        } else {
            prec = first(L);

            while (next(prec) != P) {
                prec = next(prec);
            }

            next(prec) = next(P);
        }

        next(P) = NULL;
    }
}

void deleteUser(listSosmed &L, string kode, string namaUser, adrUser &P) {
    adrSosmed pSosmed;
    adrUser prec;

    P = searchUser(L, kode, namaUser);

    if (P != NULL) {
        pSosmed = searchSosmed(L, kode);

        if (first(pSosmed->user) == P) {
            first(pSosmed->user) = next(P);
        } else {
            prec = first(pSosmed->user);

            while (next(prec) != P) {
                prec = next(prec);
            }

            next(prec) = next(P);
        }

        next(P) = NULL;
    }
}

int countSosmed(listSosmed L) {
    int n = 0;
    adrSosmed P = first(L);

    while (P != NULL) {
        P = next(P);
        n++;
    }
    return n;
}

int countUser(listUser L) {
    int n = 0;
    adrUser P = first(L);

    while (P != NULL) {
        P = next(P);
        n++;
    }
    return n;
}

void showAllSosmed(listSosmed L) {
    adrSosmed P = first(L);

    if (first(L) == NULL) {
        cout << "Tidak ada data" << endl;
    } else {
        cout << "=========== Data Sosmed ===========" << endl;

        while (P != NULL) {
            cout << "Nama               : " << info(P).nama << endl;
            cout << "Kode               : " << info(P).kode << endl;
            cout << "Awal Tahun Berdiri : " << info(P).sejak << endl;
            cout << endl;

            P = next(P);
        }

        cout << "===================================" << endl;
    }
}

void showAllUser(listUser L) {
    adrUser P = first(L);

    if (first(L) == NULL) {
        cout << "Tidak ada data" << endl;
    } else {
        cout << "============ Data User ============" << endl;

        while (P != NULL) {
            cout << "Nama : " << info(P).nama << endl;
            cout << "ID   : " << info(P).id << endl;
            cout << "Umur : " << info(P).umur << endl;
            cout << endl;
            P = next(P);
        }

        cout << "===================================" << endl;
    }
}

void clearScreen() {
    cout << "\033[H\033[2J" << flush;
}

void enterUntukLanjut() {
    cout << "Tekan Enter untuk lanjut...";
    fflush(stdin);
    getchar();
    cout << endl;
}
