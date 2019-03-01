#include "linklist.h"

/***************************************************************/

void createlist_mhs(listmhs &LM){
    first(LM) = NULL;
}

void createlist_mk(listmk &LK){
    first(LK) = NULL;
}

void createlist_rls(listrls &LR){
    first(LR) = NULL;
}

/***************************************************************/

adrrls alokasi_rls(adrmhs atas, adrmk bawah){
    adrrls R;

    R = new elemenrls;
    next(R) = NULL;
    prev(R) = NULL;
    up(R) = atas;
    down(R) = bawah;

    return R;
}

/***************************************************************/

adrmhs findelemen_mhs(listmhs LM, mahasiswa X){
    adrmhs P;

    if(first(LM) != NULL){
        P = first(LM);
        do{
            if(info(P).nim == X.nim){
                return P;
            }
            P = next(P);
        }while(P != NULL);

        return NULL;
    }
    else{
        return NULL;
    }
}

adrmk findelemen_mk(listmk LK, matakuliah X){
    adrmk Q;

    if(first(LK) != NULL){
        Q = first(LK);
        do{
            if(info(Q).namaK == X.namaK){
                return Q;
            }
            Q = next(Q);
        }while(Q != NULL);

        return NULL;
    }
    else{
        return NULL;
    }
}

adrmk findelemen_mk_last(listmk LK, matakuliah X){
    adrmk Q;
    adrmk N;

    if(first(LK) != NULL){
        Q = first(LK);
        N = NULL;
        do{
            if(info(Q).namaK == X.namaK){
                N = Q;
            }
            Q = next(Q);
        }while(Q != NULL);

        return N;
    }
    else{
        return NULL;
    }
}

/***************************************************************/

void printinfo_mhs(listmhs LM){
    adrmhs P;

    if(first(LM) != NULL){
        P = first(LM);
        do{
            cout<<"Nama  : "<<info(P).namaM<<endl;
            cout<<"NIM   : "<<info(P).nim<<endl;
            cout<<"Kelas : "<<info(P).kelas<<endl;
            cout<<endl;
            P = next(P);
        }while(P != NULL);
    }
    else{
        cout<<"Kosong!"<<endl;
    }
}

void printinfo_mk(listmk LK){
    adrmk Q;

    if(first(LK) != NULL){
        Q = first(LK);
        do{
            cout<<"Nama MK    : "<<info(Q).namaK<<endl;
            cout<<"Kode MK    : "<<info(Q).kode<<endl;
            cout<<"Nama Dosen : "<<info(Q).dosen<<endl;
            cout<<endl;
            Q = next(Q);
        }while(Q != NULL);
    }
    else{
        cout<<"Kosong!"<<endl;
    }
}

/***************************************************************/

void insertlast_mhs(listmhs &LM, adrmhs P){
    if(first(LM) == NULL){
        first(LM) = P;
    }
    else{
        adrmhs n;

        n = first(LM);
        while(next(n) != NULL){
            n = next(n);
        }

        next(n) = P;
    }
}

void insertfirst_mk(listmk &LK, adrmk Q){
    if(first(LK) == NULL){
        first(LK) = Q;
    }
    else{
        next(Q) = first(LK);
        first(LK) = Q;
    }
}

void insertlast_mk(listmk &LK, adrmk Q){
    if(first(LK) == NULL){
        first(LK) = Q;
    }
    else{
        adrmk n;

        n = first(LK);
        while(next(n) != NULL){
            n = next(n);
        }

        next(n) = Q;
    }
}

void insertafter_mk(listmk &LK, adrmk &Prec, adrmk Q){
    if(next(Prec) != NULL){
        next(Q) = next(Prec);
        next(Prec) = Q;
    }
    else{
        next(Prec) = Q;
    }
}

void insertlast_rls(listrls &LR, adrrls R){
    if(first(LR) == NULL){
        first(LR) = R;
    }
    else{
        adrrls n;

        n = first(LR);
        while(next(n) != NULL){
            n = next(n);
        }

        next(n) = R;
        prev(R) = n;
    }
}

/***************************************************************/

void delete_mhs(listmhs &LM, adrmhs &P){
    if(first(LM) == NULL){
        cout<<"Kosong!"<<endl;
    }
    else if(next(first(LM)) == NULL){
        first(LM) = NULL;
        delete P;
    }
    else{
        if(first(LM) == P){
            first(LM) = next(P);
            next(P) = NULL;
            delete P;
        }
        else{
            adrmhs n;

            n = first(LM);
            while(next(n) != P){
                n = next(n);
            }

            next(n) = next(P);
            next(P) = NULL;
            delete P;
        }
    }

}

void delete_mk(listmk &LK, adrmk &Q){
    if(first(LK) == NULL){
        cout<<"Kosong!"<<endl;
    }
    else if(next(first(LK)) == NULL){
        first(LK) = NULL;
        delete Q;
    }
    else{
        if(first(LK) == Q){
            first(LK) = next(Q);
            next(Q) = NULL;
            delete Q;
        }
        else{
            adrmk n;

            n = first(LK);
            while(next(n) != Q){
                n = next(n);
            }

            next(n) = next(Q);
            next(Q) = NULL;
            delete Q;
        }
    }
}

void delete_rls(listrls &LR, adrrls &R){
    if(first(LR) == NULL){
        /* Tidak Ada Relasi Apapun */
    }
    else if(next(first(LR)) == NULL){
        if(R = first(LR)){
            next(R) = NULL;
            prev(R) = NULL;
            up(R) = NULL;
            down(R) = NULL;
            first(LR) = NULL;
            delete R;
        }
    }
    else{
        if(first(LR) == R){
            first(LR) = next(R);
            prev(first(LR)) = NULL;
            next(R) = NULL;
            up(R) = NULL;
            down(R) = NULL;
            delete R;
        }
        else if(next(R) == NULL){
            adrrls n;

            n = first(LR);
            while(next(n) != R){
                n = next(n);
            }

            next(n) = NULL;
            prev(R) = NULL;
            up(R) = NULL;
            down(R) = NULL;
            delete R;
        }
        else{
            adrrls n;

            n = first(LR);
            while(next(n) != R){
                n = next(n);
            }

            next(n) = next(R);
            prev(next(R)) = n;
            next(R) = NULL;
            prev(R) = NULL;
            up(R) = NULL;
            down(R) = NULL;
            delete R;
        }
    }
}

/***************************************************************/
