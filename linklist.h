#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define down(P) P->down
#define up(P) P->up

/******************************************************/

typedef struct elemenmhs *adrmhs;

struct mahasiswa{
    string namaM;
    string nim;
    string kelas;
    string kodeS[50];
};

struct elemenmhs{
    mahasiswa info;
    adrmhs next;
};

struct listmhs{
    adrmhs first;
};

/******************************************************/

typedef struct elemenmk *adrmk;

struct matakuliah{
    string namaK;
    string kode;
    string dosen;
};

struct elemenmk{
    matakuliah info;
    adrmk next;
};

struct listmk{
    adrmk first;
};

/******************************************************/

typedef struct elemenrls *adrrls;

struct elemenrls{
    adrrls next;
    adrrls prev;
    adrmhs up;
    adrmk down;
};

struct listrls{
    adrrls first;
};

/******************************************************/

void createlist_mhs(listmhs &LM);
void createlist_mk(listmk &LK);
void createlist_rls(listrls &LR);

adrrls alokasi_rls(adrmhs atas, adrmk bawah);

adrmhs findelemen_mhs(listmhs LM, mahasiswa X);
adrmk findelemen_mk(listmk LK, matakuliah X);
adrmk findelemen_mk_last(listmk LK, matakuliah X);

void printinfo_mhs(listmhs LM);
void printinfo_mk(listmk LK);

void insertlast_mhs(listmhs &LM, adrmhs P);
void insertfirst_mk(listmk &LK, adrmk Q);
void insertlast_mk(listmk &LK, adrmk Q);
void insertafter_mk(listmk &LK, adrmk &Prec, adrmk Q);
void insertlast_rls(listrls &LR, adrrls R);

void delete_mhs(listmhs &LM, adrmhs &P);
void delete_mk(listmk &LK, adrmk &Q);
void delete_rls(listrls &LR, adrrls &R);

/******************************************************/

#endif // LINKLIST_H_INCLUDED
