#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "linklist.h"

using namespace std;

adrmhs buatbaru_mhs(){
    adrmhs P;

    P = new elemenmhs;
    next(P) = NULL;

    cout<<"Masukan Nama  : "; cin>>info(P).namaM;
    cout<<"Masukan NIM   : "; cin>>info(P).nim;
    cout<<"Masukan Kelas : "; cin>>info(P).kelas;

    return P;
}

adrmk buatbaru_mk(){
    adrmk Q;

    Q = new elemenmk;
    next(Q) = NULL;

    cout<<"Masukan Nama MK    : "; cin>>info(Q).namaK;
    cout<<"Masukan Kode MK    : "; cin>>info(Q).kode;
    cout<<"Masukan Nama Dosen : "; cin>>info(Q).dosen;

    return Q;
}

void mainmenu(listmhs LM, listmk LK, listrls LR){

    adrmhs P;
    adrmk Q, Prec, Q2;
    adrrls R, N;

    int indeks;
    int pilihan;

    string subpilih;
    string carinim;
    string carikode;
    string carikelas;
    string carinamaK;

    matakuliah cariprec;

    do{
        menuutama:
        system("cls");
        cout<<"===== PROGRAM MAHASISWA & MATAKULIAH YANG DIAMBIL ====="<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        cout<<endl;
        cout<<"1.  Input Mahasiswa"<<endl;
        cout<<"2.  Input Matakuliah"<<endl;
        cout<<"3.  Delete Mahasiswa"<<endl;
        cout<<"4.  Delete Matakuliah"<<endl;
        cout<<"5.  Memilih/Mengambil Matakuliah"<<endl;
        cout<<"6.  Delete Matakuliah Mahasiswa"<<endl;
        cout<<"7.  Show Info Mahasiswa Tertentu"<<endl;
        cout<<"8.  Show Info Matakuliah Tertentu"<<endl;
        cout<<"9.  Show Info Semua Mahasiswa"<<endl;
        cout<<"10. Show Info Semua Matakuliah"<<endl;
        cout<<"11. Report Matakuliah Yang Diambil Mahasiswa"<<endl;             //Mahasiswa + Matakuliahnya
        cout<<"12. Report Dosen Yang Mengajar Di Kelas Tertentu"<<endl;         //Kelas + Dosen-Dosennya
        cout<<"13. Report Mahasiswa Yang Mengambil Matakuliah Tertentu"<<endl;  //Matakuliah + Mahasiswa2nya
        cout<<"14. Exit/Keluar"<<endl;
        cout<<endl;

        cout<<"Masukan Pilihan : "; cin>>pilihan;

        switch(pilihan){

            /*************************************************************************************/

            case 1 : /** [OK] INPUT MAHASISWA [DISIMPAN DI LAST] **/

                system("cls");
                P = buatbaru_mhs();
                insertlast_mhs(LM,P);
                break;

            /*************************************************************************************/

            case 2 : /** [OK] INPUT MATAKULIAH [SORT BERDASARKAN NAMA MK & DISIMPAN DI LAST] **/

                system("cls");
                Q = buatbaru_mk();

                cariprec.namaK = info(Q).namaK;
                Prec = findelemen_mk_last(LK,cariprec);

                if(Prec != NULL){
                    insertafter_mk(LK,Prec,Q);
                }
                else{
                    if(first(LK) == NULL){
                        insertfirst_mk(LK,Q);
                    }
                    else{
                        insertlast_mk(LK,Q);
                    }
                }
                break;

            /*************************************************************************************/

            case 3 : /** [OK] DELETE MAHASISWA **/

                system("cls");
                cout<<"Masukan NIM Dihapus : "; cin>>carinim;

                if(first(LM) != NULL){

                    P = first(LM);
                    while((info(P).nim != carinim) && (next(P) != NULL)){
                        P = next(P);
                    }

                    if(info(P).nim == carinim){
                        cout<<endl;
                        system("cls");
                        cout<<"Data Mahasiswa"<<endl;
                        cout<<endl;
                        cout<<"Nama  : "<<info(P).namaM<<endl;
                        cout<<"NIM   : "<<info(P).nim<<endl;
                        cout<<"Kelas : "<<info(P).kelas<<endl;
                        cout<<endl;
                        cout<<"Hapus Data Mahasiswa Diatas (Y/N)? : "; cin>>subpilih;

                        if(subpilih == "Y"){
                            system("cls");

                            if(first(LR) != NULL){
                                R = first(LR);

                                do{

                                    while((info(up(R)).nim != info(P).nim) && (next(R) != NULL)){
                                        R = next(R);
                                    }

                                    if(info(up(R)).nim == info(P).nim){
                                        if(next(R) == NULL){
                                            delete_rls(LR,R);
                                            delete_mhs(LM,P);
                                            cout<<"Data Mahasiswa Berhasil Dihapus!"<<endl;
                                            goto menuutama;
                                        }
                                        else{
                                            N = next(R);
                                            delete_rls(LR,R);
                                        }
                                    }

                                    else{
                                        delete_mhs(LM,P);
                                        cout<<"Data Mahasiswa Berhasil Dihapus!"<<endl;
                                        break;
                                    }

                                    R = N;

                                }while(R != NULL);
                            }
                            else{
                                delete_mhs(LM,P);
                                cout<<"Data Mahasiswa Berhasil Dihapus!"<<endl;
                            }
                        }
                        else if(subpilih == "N"){
                            system("cls");
                            cout<<"Data Mahasiswa Tidak Dihapus!"<<endl;
                        }
                        else{
                            system("cls");
                            cout<<"Inputan Salah!"<<endl;
                        }

                    }
                    else{
                        system("cls");
                        cout<<"NIM Tidak Ditemukan!"<<endl;
                    }
                }
                else{
                    system("cls");
                    cout<<"NIM Tidak Ditemukan!"<<endl;
                }
                getch();
                break;

            /*************************************************************************************/

            case 4 : /** [OK] DELETE MATAKULIAH **/

                system("cls");
                cout<<"Masukan Kode MK Dihapus : "; cin>>carikode;

                if(first(LK) != NULL){

                    Q = first(LK);
                    while((info(Q).kode != carikode) && (next(Q) != NULL)){
                        Q = next(Q);
                    }

                    if(info(Q).kode == carikode){
                        cout<<endl;
                        system("cls");
                        cout<<"Data Matakuliah"<<endl;
                        cout<<endl;
                        cout<<"Nama MK    : "<<info(Q).namaK<<endl;
                        cout<<"Kode MK    : "<<info(Q).kode<<endl;
                        cout<<"Nama Dosen : "<<info(Q).dosen<<endl;
                        cout<<endl;
                        cout<<"Hapus Data Matakuliah Diatas (Y/N)? : "; cin>>subpilih;

                        if(subpilih == "Y"){
                            system("cls");

                            if(first(LR) != NULL){
                                R = first(LR);

                                do{

                                    while((info(down(R)).kode != info(Q).kode) && (next(R) != NULL)){
                                        R = next(R);
                                    }

                                    if(info(down(R)).kode == info(Q).kode){
                                        if(next(R) == NULL){
                                            delete_rls(LR,R);
                                            delete_mk(LK,Q);
                                            cout<<"Data Matakuliah Berhasil Dihapus!"<<endl;
                                            goto menuutama;
                                        }
                                        else{
                                            N = next(R);
                                            delete_rls(LR,R);
                                        }
                                    }
                                    else{
                                        delete_mk(LK,Q);
                                        cout<<"Data Matakuliah Berhasil Dihapus!"<<endl;
                                        break;
                                    }

                                    R = N;

                                }while(R != NULL);
                            }
                            else{
                                delete_mk(LK,Q);
                                cout<<"Data Matakuliah Berhasil Dihapus!"<<endl;
                            }

                            cout<<"Data Matakuliah Berhasil Dihapus!"<<endl;
                        }
                        else if(subpilih == "N"){
                            system("cls");
                            cout<<"Data Matakuliah Tidak Dihapus!"<<endl;
                        }
                        else{
                            system("cls");
                            cout<<"Inputan Salah!"<<endl;
                        }

                    }
                    else{
                        system("cls");
                        cout<<"Kode MK Tidak Ditemukan!"<<endl;
                    }
                }
                else{
                    system("cls");
                    cout<<"Kode MK Tidak Ditemukan!"<<endl;
                }
                getch();
                break;

            /*************************************************************************************/

            case 5 : /** [OK] MENGAMBIL MATAKULIAH **/

                system("cls");
                cout<<"Masukan NIM : "; cin>>carinim;

                if(first(LM) != NULL){
                    P = first(LM);
                    while((info(P).nim != carinim) && (next(P) != NULL)){
                        P = next(P);
                    }

                    if(info(P).nim == carinim){
                        system("cls");
                        cout<<"NIM "<<carinim<<" Ditemukan!"<<endl;
                        cout<<"------------------------------------------"<<endl;
                        cout<<endl;
                        cout<<"Matakuliah Yang Tersedia : "<<endl;
                        cout<<endl;
                        printinfo_mk(LK);

                        if(first(LK) != NULL){
                            cout<<"Masukan Kode MK Yang Akan Diambil : "; cin>>carikode;
                            cout<<endl;

                            if(first(LR) != NULL){
                                R = first(LR);
                                while((info(up(R)).nim != carinim) && (next(R) != NULL)){
                                    R = next(R);
                                }

                                if((info(up(R)).nim == info(P).nim) && (info(down(R)).kode == carikode)){
                                    cout<<"Matakuliah Tersebuh Sedang Diambil!"<<endl;
                                }
                                else{
                                    Q = first(LK);
                                    while((info(Q).kode != carikode) && (next(Q) != NULL)){
                                        Q = next(Q);
                                    }

                                    if(info(Q).kode == carikode){
                                        R = alokasi_rls(P,Q);
                                        insertlast_rls(LR,R);
                                        system("cls");
                                        cout<<info(P).namaM<<" Telah Mengambil Matakuliah : "<<endl;
                                        cout<<endl;
                                        cout<<"Nama MK    : "<<info(Q).namaK<<endl;
                                        cout<<"Kode MK    : "<<info(Q).kode<<endl;
                                        cout<<"Nama Dosen : "<<info(Q).dosen<<endl;
                                    }
                                    else{
                                        system("cls");
                                        cout<<"Inputan Salah!"<<endl;
                                    }
                                }
                            }
                            else{
                                Q = first(LK);
                                while((info(Q).kode != carikode) && (next(Q) != NULL)){
                                    Q = next(Q);
                                }

                                if(info(Q).kode == carikode){
                                    R = alokasi_rls(P,Q);
                                    insertlast_rls(LR,R);
                                    system("cls");
                                    cout<<info(P).namaM<<" Telah Mengambil Matakuliah : "<<endl;
                                    cout<<endl;
                                    cout<<"Nama MK    : "<<info(Q).namaK<<endl;
                                    cout<<"Kode MK    : "<<info(Q).kode<<endl;
                                    cout<<"Nama Dosen : "<<info(Q).dosen<<endl;
                                }
                                else{
                                    system("cls");
                                    cout<<"Inputan Salah!"<<endl;
                                }
                            }
                        }
                    }
                    else{
                        system("cls");
                        cout<<"NIM Tidak Ditemukan!"<<endl;
                    }
                }
                else{
                    system("cls");
                    cout<<"NIM Tidak Ditemukan!"<<endl;
                }
                getch();
                break;

            /*************************************************************************************/

            case 6 : /** [OK] DELETE MATAKULIAH YANG SEDANG DIAMBIL MAHASISWA **/

                system("cls");
                cout<<"Masukan NIM : "; cin>>carinim;

                if(first(LM) != NULL){

                    P = first(LM);
                    while((info(P).nim != carinim) && (next(P) != NULL)){
                        P = next(P);
                    }

                    if(info(P).nim == carinim){
                        cout<<endl;
                        system("cls");
                        cout<<"Nama  : "<<info(P).namaM<<endl;
                        cout<<"-------------------------------"<<endl;
                        cout<<endl;

                        N = first(LR);

                        cout<<"Matakuliah Yang Sedang Diambil : "<<endl;

                        do{
                            while((info(up(N)).nim != carinim) && (next(N) != NULL)){
                                N = next(N);
                            }

                            if(info(up(N)).nim == carinim){
                                cout<<info(down(N)).namaK<<endl;
                            }

                            N = next(N);
                        }while(N != NULL);

                        cout<<endl;
                        cout<<"Masukan Nama MK Yang Ingin Dihapus : "; cin>>carinamaK;

                        if(first(LR) != NULL){
                            R = first(LR);

                            while((info(down(R)).namaK != carinamaK) && (next(R) != NULL)){
                                R = next(R);
                            }

                            if(info(down(R)).namaK == carinamaK){
                                delete_rls(LR,R);
                                cout<<"Matakuliah Yang Diambil Berhasil Dihapus!"<<endl;
                                break;
                            }
                            else{
                                system("cls");
                                cout<<"Tidak Ada Matakuliah Tersebut!"<<endl;
                            }
                        }
                    }
                    else{
                        system("cls");
                        cout<<"NIM Tidak Ditemukan!"<<endl;
                    }
                }
                else{
                    system("cls");
                    cout<<"NIM Tidak Ditemukan!"<<endl;
                }
                getch();
                break;

            /*************************************************************************************/

            case 7 : /** [OK] SHOW MAHASISWA TERTENTU **/

                system("cls");
                cout<<"Masukan NIM Dicari : "; cin>>carinim;

                if(first(LM) != NULL){

                    P = first(LM);
                    while((info(P).nim != carinim) && (next(P) != NULL)){
                        P = next(P);
                    }

                    if(info(P).nim == carinim){
                        cout<<endl;
                        system("cls");
                        cout<<"NIM Ditemukan!"<<endl;
                        cout<<endl;
                        cout<<"Nama  : "<<info(P).namaM<<endl;
                        cout<<"NIM   : "<<info(P).nim<<endl;
                        cout<<"Kelas : "<<info(P).kelas<<endl;
                    }
                    else{
                        system("cls");
                        cout<<"NIM Tidak Ditemukan!"<<endl;
                    }
                }
                else{
                    system("cls");
                    cout<<"NIM Tidak Ditemukan!"<<endl;
                }
                getch();
                break;

            /*************************************************************************************/

            case 8 : /** [OK] SHOW MATAKULIAH TERTENTU **/

                system("cls");
                cout<<"Masukan Kode MK Dicari : "; cin>>carikode;

                if(first(LK) != NULL){

                    Q = first(LK);
                    while((info(Q).kode != carikode) && (next(Q) != NULL)){
                        Q = next(Q);
                    }

                    if(info(Q).kode == carikode){
                        cout<<endl;
                        system("cls");
                        cout<<"Kode MK Ditemukan!"<<endl;
                        cout<<endl;
                        cout<<"Nama MK    : "<<info(Q).namaK<<endl;
                        cout<<"Kode MK    : "<<info(Q).kode<<endl;
                        cout<<"Nama Dosen : "<<info(Q).dosen<<endl;
                    }
                    else{
                        system("cls");
                        cout<<"Kode MK Tidak Ditemukan!"<<endl;
                    }
                }
                else{
                    system("cls");
                    cout<<"Kode MK Tidak Ditemukan!"<<endl;
                }
                getch();
                break;

            /*************************************************************************************/

            case 9 : /** [OK] SHOW SEMUA MAHASISWA **/

                system("cls");
                cout<<"Data Mahasiswa : "<<endl;
                cout<<endl;
                printinfo_mhs(LM);
                getch();
                break;

            /*************************************************************************************/

            case 10 : /** [OK] SHOW SEMUA MATAKULIAH **/

                system("cls");
                cout<<"Data Matakuliah : "<<endl;
                cout<<endl;
                printinfo_mk(LK);
                getch();
                break;

            /*************************************************************************************/

            case 11 : /** [OK] REPORT MATAKULIAH YANG DIAMBIL MAHASISWA **/

                system("cls");
                cout<<"Masukan NIM : "; cin>>carinim;

                if(first(LM) != NULL){
                    if(first(LR) != NULL){

                        R = first(LR);

                        while((info(up(R)).nim != carinim) && (next(R) != NULL)){
                            R = next(R);
                        }

                        if(info(up(R)).nim == carinim){
                            system("cls");
                            cout<<"Nama : "<<info(up(R)).namaM<<endl;
                            cout<<"-------------------------------"<<endl;
                            cout<<endl;
                            cout<<"Matakuliah Yang Diambil : "<<endl;
                            do{
                                while((info(up(R)).nim != carinim) && (next(R) != NULL)){
                                    R = next(R);
                                }

                                if(info(up(R)).nim == carinim){
                                    cout<<info(down(R)).namaK<<endl;
                                }
                                else if(next(R) == NULL){
                                    if(info(up(R)).nim == carinim){
                                        cout<<info(down(R)).namaK<<endl;
                                    }
                                    else{
                                        break;
                                    }
                                }

                                R = next(R);
                            }while(R != NULL);
                        }
                        else{
                            cout<<"NIM Tidak Ditemukan / Mahasiswa Tidak Mengambil Matakuliah Manapun"<<endl;
                        }
                    }
                    else{
                        system("cls");
                        cout<<"Tidak Mengambil Matakuliah Manapun!"<<endl;
                    }
                }
                else{
                    system("cls");
                    cout<<"NIM Tidak Ditemukan!"<<endl;
                }
                getch();
                break;

            /*************************************************************************************/

            case 12 : /** [OK] REPORT DOSEN YANG MENGAJAR DIKELAS TERTENTU **/

                system("cls");
                cout<<"Masukan Kelas : "; cin>>carikelas;

                if(first(LM) != NULL){
                    if(first(LR) != NULL){

                        R = first(LR);

                        system("cls");
                        while((info(up(R)).kelas != carikelas) && (next(R) != NULL)){
                            R = next(R);
                        }

                        if(info(up(R)).kelas == carikelas){
                            cout<<"Kelas : "<<info(up(R)).kelas<<endl;
                            cout<<"-------------------------------"<<endl;
                            cout<<endl;
                            cout<<"Dosen Yang Mengajar : "<<endl;
                            cout<<endl;
                            cout<<info(down(R)).dosen<<" - "<<info(down(R)).namaK<<endl;

                            N = first(LR);
                            R = next(R);

                            while(R != NULL){
                                while(info(up(R)).kelas != carikelas && next(R) != NULL){
                                    R = next(R);
                                }

                                if(info(up(R)).kelas == carikelas){
                                    N = first(LR);

                                    while((info(up(N)).kelas != carikelas || info(down(N)).dosen != info(down(R)).dosen) && next(N) != R){
                                        N = next(N);
                                    }

                                    if(info(up(N)).kelas == carikelas && info(down(N)).dosen != info(down(R)).dosen){
                                        cout<<info(down(R)).dosen<<" - "<<info(down(R)).namaK<<endl;
                                    }
                                }
                                R = next(R);
                            }
                        }
                        else{
                            cout<<"Kelas Tidak Ditemukan!"<<endl;
                        }
                    }
                    else{
                        system("cls");
                        cout<<"Tidak Ada Dosen Yang Mengajar!"<<endl;
                    }
                }
                else{
                    system("cls");
                    cout<<"Kelas Tidak Ditemukan!"<<endl;
                }
                getch();
                break;

            /*************************************************************************************/

            case 13 : /** [OK] MAHASISWA YANG MENGAMBIL MATAKULIAH TERTENTU **/

                system("cls");
                cout<<"Masukan Kode MK : "; cin>>carikode;

                if(first(LK) != NULL){
                    if(first(LR) != NULL){

                        R = first(LR);

                        while((info(down(R)).kode != carikode) && (next(R) != NULL)){
                            R = next(R);
                        }

                        if(info(down(R)).kode == carikode){
                            system("cls");
                            cout<<"Matakuliah : "<<info(down(R)).namaK<<endl;
                            cout<<"-------------------------------"<<endl;
                            cout<<endl;
                            cout<<"Mahasiswa Yang Mengambil : "<<endl;
                            do{
                                while((info(down(R)).kode != carikode) && (next(R) != NULL)){
                                    R = next(R);
                                }

                                if(info(down(R)).kode == carikode){
                                    cout<<info(up(R)).namaM<<endl;
                                }
                                else if(next(R) == NULL){
                                    if(info(down(R)).kode == carikode){
                                        cout<<info(up(R)).namaM<<endl;
                                    }
                                    else{
                                        break;
                                    }
                                }

                                R = next(R);
                            }while(R != NULL);
                        }
                        else{
                            cout<<"Kode MK Tidak Ditemukan / Tidak Ada Mahasiswa Yang Mengambil"<<endl;
                        }
                    }
                    else{
                        system("cls");
                        cout<<"Tidak Ada Mahasiswa Yang Mengambil!"<<endl;
                    }
                }
                else{
                    system("cls");
                    cout<<"Kode MK Tidak Ditemukan!"<<endl;
                }
                getch();
                break;

            /*************************************************************************************/

            case 14 : /** [OK] EXIT **/

                system("cls");
                cout<<"Terimakasih!"<<endl;
                getch();
                break;

            /*************************************************************************************/

            default : /** [OK] USER SALAH INPUT **/

                system("cls");
                cout<<"Inputan Salah!"<<endl;
                getch();
                break;

            /***************************************************************/
        }

    }while(pilihan != 14);
}

int main()
{
    listmhs LM;
    listmk LK;
    listrls LR;

    createlist_mhs(LM);
    createlist_mk(LK);
    createlist_rls(LR);

    mainmenu(LM,LK,LR);

    return 0;
}
