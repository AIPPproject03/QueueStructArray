#include <iostream>
#include <conio.h>
#define MAX 10
using namespace std;

/*  

					THIS PROGRAM MADE BY TEAM ALPHA
					COPYRIGHT AIPP_PROJECT03
					
					PROGRAM OF QUEUE WITH 3 CONDITION :
					
					1) FUNCTION TO SEARCH THE ELEMENT INSIDE THE QUEUE
					2) FUNCTION TO EDIT THE ELEMENT INSIDE THE QUEUE
					3) FUNCTION TO CALCULATE THE TOTAL VALUE, AVERAGE, LARGEST AND SMALLEST

**/


//==================================(Struct Array Untuk Program Queue)======================================//
struct Queue{
	int pertama = 0; /* Digunakan Untuk Menyimpan Inputan Dan Mempermudah Untuk Mengetahui Inputan Yang Pertama **/
	int masuk[MAX]; /* Digunakan Untuk Membuat Array Dan Didalamnya Dimasukan Batasan Dalam Menginput Data = MAX **/
}antrian;

//==================================(Pengkondisian isFull dan IsEmpty)======================================//
bool isFull(){
	if(antrian.pertama >= MAX){ /* Jika Antrian Telah Mencapai MAX, Maka Bool isFull Akan Bernilai True Atau Benar **/
		return true;
	}
	else{
		return false;
	}
}
bool isEmpty(){
	if(antrian.pertama == 0){ /* Jika Antrian = 0 Maka Kondisi Bool isEmpty Bernilai True Atau Benar **/
		return true;
	}
	else{
		return false;
	}
}

//==================================(Kumpulan Function Untuk Program Queue)======================================//
void Enqueue(){   /* Digunakan Untuk Menginput Elemen Pada Queue **/
	if(!isFull()){ /* Kondisi Jika Data Didalam Array Belum Penuh (!isFull --> Tidak Penuh) **/                               
		cout <<" Input Element : ";
		cin >> antrian.masuk[antrian.pertama]; /* Inputan Akan Masuk Kedalam Array Masuk Dan Dihitung Jumlahnya Pada (int pertama) **/
		antrian.pertama++; /* Setelah Menginput Maka Jumlah (int pertama) Akan Bertambah. Oleh Karena Itu Ditambahkan ++ **/
	}
	else{
		cout <<" The Queue Is Full"<< endl; /* Jika Inputan Didalam Array Sudah Mencapai Batas, Maka Akan Ada Peringatan Penuh **/
	}
}

void Dequeue(){ /* Digunakan Untuk Mengeluarkan Elemen Pertama Dan Kemudian Memajukan Elemen Dibelakang **/
	if(!isEmpty()){ /* Kondisi Jika Data Didalam Array Sudah Mempunya Isi (!isEmpty --> Sudah Ada Data Yang Diinput) **/ 
	cout <<" The First Position In The Queue ("<< antrian.masuk[0] <<") Has Been Out..."<< endl; /* Menampilkan Elemen Pertama Yang Akan Keluar **/
		for(int i = 0; i <= antrian.pertama-1; i++){ /* Pengulangan Ini Digunakan Untuk Mengeluarkan Semua Inputan Pada Array **/
			antrian.masuk[i] = antrian.masuk[i+1]; /* Instruksi Ini Digunakan Untuk Menambahkan Data Pada Array Sebelum Dihilangkan **/
		}
		antrian.pertama--; /* Disini Instruksi Yang Digunakan Untuk Menghilangkan Data Pada Array Yang Prtama **/
	}
	else{
		cout <<" The Queue Is Empty"<< endl; /* Jika Tidak Ada Inputan Atau Array Kosong Maka Akan Ada Peringatan**/
	}
}

void Show(){  /* Digunakan Untuk Menampilkan Isi Didalam Queue **/
	if(!isEmpty()){ /* Kondisi Jika Data Didalam Array Sudah Mempunya Isi (!isEmpty --> Sudah Ada Data Yang Diinput) **/ 
		cout <<" The Elemen That You Have Is : "<< endl;
		for(int x = 0; x <= antrian.pertama-1; x++){ /* Pengulangan Ini Digunakan Untuk Mengeluarkan Semua Inputan Pada Array **/
			cout <<" Position-"<< x+1 <<" : "<< antrian.masuk[x] << endl;
		}
	}
	else{
		cout <<" The Queue Is Empty"<< endl;  /* Jika Tidak Ada Inputan Atau Array Kosong Maka Akan Ada Peringatan**/
	}
}

void Search(){   /* Digunakan Untuk Mencari Elemen Didalam Queue **/
    int s;
    if(!isEmpty()){ /* Kondisi Jika Data Didalam Array Sudah Mempunya Isi (!isEmpty --> Sudah Ada Data Yang Diinput) **/ 
        bool found = false; /* Kondisi Ini Digunakan Untuk Mengetahui Data Yang Ditemukan Di Dalam Array Queue **/
        cout <<"What Element Do You Wanna Search : "; 
        cin >> s;
        cout << endl;
        for(int i = 0; i <= antrian.pertama-1; i++){ /* Pengulangan Ini Digunakan Untuk Mengeluarkan Semua Inputan Pada Array **/
            if(antrian.masuk[i] == s){ /* Instruksi Ini Digunakan Untuk Menyocokkan Elemen Didalam Array Dengan Inputan Elemen Yang Ingin Kita Cari **/
                cout <<"Your Element "<< s <<" Found In Position : "<< i+1 << endl;
                found = true; /* Kondisi Ini Digunakan Untuk Menyelesaikan Instruksi Jika Sudah Ditemukan Elemen Yang Ingin Dicari **/
            }
        }
        if(!found){ /* Kondisi Ini Digunakkan Jika Tidak Ditemukan Elemen Yang Ingin Dicari **/
            cout << "Your Element " << s << " Not Found" << endl;
        }
    }
    else{
        cout <<"The Queue Is Empty"<< endl;  /* Jika Tidak Ada Inputan Atau Array Kosong Maka Akan Ada Peringatan**/
    }
}

void Edit(){    /* Digunakan Untuk Mengedit Elemen Yang Berada Pada Posisi Masukan Tertentu**/
	int e;
	if(!isEmpty()){ /* Kondisi Jika Data Didalam Array Sudah Mempunya Isi (!isEmpty --> Sudah Ada Data Yang Diinput) **/ 
		bool found = false; /* Kondisi Ini Digunakan Untuk Menyelesaikan Instruksi Jika Sudah Ditemukan Elemen Yang Ingin Dicari **/
		cout <<" What Element Do You Want To Edit : ";
		cin >> e;
		for(int i = 0; i <= antrian.pertama-1; i++){ /* Pengulangan Ini Digunakan Untuk Mengeluarkan Semua Inputan Pada Array **/
		if(i+1 == e){  /* Instruksi Ini Digunakan Untuk Menyocokkan Elemen Didalam Array Dengan Inputan Elemen Yang Ingin Kita Cari Untuk Diedit **/
			cout <<" In Position ("<< e <<") And The Element Is ("<< antrian.masuk[e-1] <<") Will Be Edited..."<< endl;
			found = true;
			cout << endl;
			cout <<" Change The Elemen To : ";
			cin >> antrian.masuk[e-1]; /* Instruksi Untuk Mengubah Data Dalam Array Yang Telah Dipilih Kemudian Menjadi Data Inputan Yang Baru **/
		}
	}
	if(!found){ /* Kondisi Ini Digunakkan Jika Tidak Ditemukan Elemen Yang Ingin Dicari **/
			cout <<" The Element Is Not Found" << endl;
		}
	}
	else{
		cout <<" The Queue Is Empty"<< endl; /* Jika Tidak Ada Inputan Atau Array Kosong Maka Akan Ada Peringatan**/
	}
}

void Result(){   /* Digunakan Untuk Menghitung Nilai Total, Rata-Rata, Terbesar Dan Terkecil Dari Semua Elemen Pada Array **/
    int total = 0;
    int largest = antrian.masuk[0]; /* Kondisi Untuk Mencari Elemen Yang Terbesar Pada Array Queue **/
    int smallest = antrian.masuk[0]; /* Kondisi Untuk Mencari Elemen Yang Terkecil Pada Array Queue **/
if(!isEmpty()){ /* Kondisi Jika Data Didalam Array Sudah Mempunya Isi (!isEmpty --> Sudah Ada Data Yang Diinput) **/ 
    for(int i = 0; i <= antrian.pertama-1; i++){  /* Pengulangan Untuk Menampilkan Semua Data Inputan Pada Array Queue **/
        total += antrian.masuk[i]; /* Rumus Untuk Menjumlahkan Semua Nilai Pada Data Didalam Array Untuk Masuk Kedalam Variabel total **/
        if(antrian.masuk[i] > largest){ /* Pengkondisian Jika Kumpulan Data Pada Array Terdapat Nilai int Yang Paling Besar **/
            largest = antrian.masuk[i]; /* Setelah Dikompilasi, Akan Ditentukan Dan Masuk Kedalam Variabel largest **/
        }
        if(antrian.masuk[i] < smallest){ /* Pengkondisian Jika Kumpulan Data Pada Array Terdapat Nilai int Yang Paling Kecil **/
            smallest = antrian.masuk[i]; /* Setelah Dikompilasi, Akan Ditentukan Dan Masuk Kedalam Variabel smallest **/
        }
    }
    double average = (double) total / antrian.pertama; /* Rumus Untuk Menentukan Nilai Rata-Rata Setelah Semua Data Diatas Dimasukan Dalam Variabel Yang Telah Ditentukan **/
    cout << " Value      : " << total << endl;
    cout << " Average    : " << average << endl;
    cout << " Largest    : " << largest << endl;
    cout << " Smallest   : " << smallest << endl;
    }
else{
	cout <<" The Queue Is Empty"<< endl; /* Jika Tidak Ada Inputan Atau Array Kosong Maka Akan Ada Peringatan**/
    }
}

void Empty(){ /* Digunakan Untuk Mengosongkan Queue **/
	if (!isEmpty()){ /* Kondisi Jika Data Didalam Array Sudah Mempunya Isi (!isEmpty --> Sudah Ada Data Yang Diinput) **/ 
	cout <<" The Queue Is Now Empty"<< endl;
	antrian.pertama = 0; /* Kembali Ke 0 Agar Kondisi Array Queue Kosong Kembali **/
}
else{
	cout <<" The Queue Is Empty"<< endl; /* Jika Tidak Ada Inputan Atau Array Kosong Maka Akan Ada Peringatan**/
}
}

//==================================(Program Utama Yang Akan Dieksekusi)======================================//
int main(){
	int menu;
	do{	
	system("cls");
	Show();
	    cout <<"_______________________________________________________________________"<< endl;
		cout <<"|                         ___________________                         |"<< endl;
		cout <<"|========================|([<PROGRAM QUEUE>])|========================|"<< endl;
		cout <<"|========================|{By.The Alpha Team}|========================|"<< endl;
		cout <<"|+=+=+=+=+=+=+=+=+=+=+=+=|-------------------|=+=+=+=+=+=+=+=+=+=+=+=+|"<< endl;
		cout <<"| 1) Enqueue                                                          |"<< endl;
		cout <<"| 2) Dequeue                                                          |"<< endl;
		cout <<"| 3) Search Element                                                   |"<< endl;
		cout <<"| 4) Edit The Element                                                 |"<< endl;
		cout <<"| 5) The Result (Total, Average, Largest And Smallest Values)         |"<< endl;
		cout <<"| 6) Empty The Queue                                                  |"<< endl;
		cout <<"| 7) Exit                                                             |"<< endl;
		cout <<"|_____________________________________________________________________|"<< endl;
		cout <<"|/////////////////////////////////////////////////////////////////////|"<< endl;
		cout <<"| Choose What To Do : ";
		cin >> menu;
		    switch (menu){
		    	case 1:
		    	system("cls");
		    	Enqueue();
		    	break;
		    	case 2:
		   		system("cls");
		   		Dequeue();
		    	break;
		    	case 3:
		   		system("cls");
		   		Search();
		    	break;
		    	case 4:
		    	system("cls");
		    	Edit();
		    	break;
		    	case 5:
		    	system("cls");
		    	Result();
		    	break;
		    	case 6:
		    	system("cls");
		    	Empty();
		    	break;
		    	case 7:
		    	break;
		    	default:
		    	cout <<" Sorry! Invalid Command"<< endl;	
			}getch();
	}while(menu != 7);
}
