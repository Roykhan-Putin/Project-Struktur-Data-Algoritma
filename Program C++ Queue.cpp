#include <iostream>
#include <string.h>

using namespace std;

struct node{
    string nama;
    int noAntri;
    int pesanan;
    node *next;
};

node *head, *next, *curr, *newnode, *tail, *dump;

//IsEmpty
int IsEmpty(){
    if(head == NULL){
        return 1;
    }else {
        return 0;
    }
}

//IsFull
int IsFull(int stokk){
    if(stokk == 0){
        return 1;
    }else {
        return 0;
    }
}

//enqueue
void enqueue(string nnama, int mantri, int pesanann){
    if(IsEmpty() == 1){
        head = new node();
        head -> nama = nnama;
        head -> noAntri = mantri;
        head -> pesanan = pesanann;
        head -> next = NULL;
        tail = head;
    }else{
        newnode = new node();
        newnode -> nama = nnama;
        newnode -> noAntri = mantri;
        newnode -> pesanan = pesanann;
        newnode -> next = NULL;
        tail -> next = newnode;
        tail = newnode;
    }
}


//dequeue
void dequeue(){
    if(IsEmpty() == 1){
        cout << "(kosong)" << endl;
    }else{
        dump = head;
        head = head->next;
        dump->next = NULL;
        delete dump;
    }
}

//destroy
void destroy(){
    if(IsEmpty() == 1){
        cout<<"(kosong)"<<endl;
    }else{
        curr = head;
        while(curr != NULL){
            dump = curr;
            curr = curr->next;
            dump->next = NULL;
            delete dump;
        }
        head = NULL;
    }
}

//display
void display(){
int nomor;
nomor = 1;
cout<<"Daftar antrian :"<<endl;
    if(IsEmpty() == 1){
        cout<<"(kosong)"<<endl;
    }else{
        curr = head;
        while(curr != NULL){
            cout << nomor << ". " << curr->nama << " (" << "A" << curr-> noAntri << ")" <<endl;
            curr = curr -> next;
            nomor++;
        }
    }
}


int main(){
    cout << "=============================================================="<< endl;
    cout << "IMPLEMENTASI ALGORITMA QUEUE PADA RESTORAN ALL YOU CAN EAT BBQ" << endl;
    cout << "==============================================================" << endl;
    cout << "Oleh : " << endl;
    cout << "1. Rivaldy Arrayan Yuwono (181221041)" << endl;
    cout << "2. Achmad Roykhan Sabiq (181221050)" << endl << endl;

    char pilih;
    node number;
    int stok, pesan, hasil = 0;
    number.noAntri = 1;
        cout << "Input stok hari ini : "; cin >> stok;
    repeat :
        cout << "pilih : " << endl;
        cout << "1. masuk / insert" << endl;
        cout << "2. keluar / remove" << endl;
        cout << "3. clear all" << endl;
        cout << "4. tampil / display" << endl;
        cout << "5. tambah stok" << endl;
        cout << "6. selesai" << endl;
        cout << "pilihan anda (1/2/3/4/5/6) = "; cin >> pilih ;
    switch (pilih){
        case '1' :{
            if (IsFull(stok) == 1){
                cout << "Stok habis" << endl << endl;
                goto repeat;
            }else{
                string jeneng;
                cin.ignore();
            cout << "Nama : "; getline(cin, jeneng);
                pesan_lagi:
            cout << "Jumlah pesanan : "; cin >> pesan;
                    if(pesan > stok){
                        cout << "Stok tidak mencukupi" << endl;
                        cout << "Jumlah stok saat ini adalah " << stok << endl;
                            goto pesan_lagi;
                    }else {
                        enqueue(jeneng, number.noAntri, pesan);
                            stok = stok - pesan;    
                            hasil = hasil + pesan;            
                    }
            cout << "No antrian : " << "A" << number.noAntri << endl;
            number.noAntri++;
            cout << endl;
            goto repeat;
            }
        break;}

        case '2' :
            dequeue();
            cout << endl;
            goto repeat;
        break;
    
        case '3' :
            destroy();
            cout << endl;
            goto repeat;
        break;

        case '4' :
            cout << "stok = " << stok << endl;  
            display();
            cout << endl;
            goto repeat;
        break;

        case '5' :
            int sstok;
                cout << "input stok tambahan : "; cin >> sstok;
                    stok = stok + sstok;
                cout << "jumlah stok sekarang adalah " << stok << endl;
                cout <<endl;
            goto repeat;
        break;

        case '6' :
                cout << endl << "program selesai" << endl;
                cout << "Hasil penjualan hari ini : " << hasil << endl;
                cout << "Terimakasih atas kerja kerasnya onee-chan //>.<//" << endl;
                cout << endl;
        break;

        default :
                cout << "salah..." << endl;
                cout << "ulangi!!" << endl;
                cout << endl;
            goto repeat;
        break;
    } 

    return 0;
}