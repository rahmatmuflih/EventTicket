#include <iostream>  
#include <conio.h>  
#define max 100

using namespace std;

int n;

struct node{
   int idsponsor;
   string nama;
   string tempat;
   node *prev, *next;
};
node *baru, *head=NULL, *tail=NULL,*help,*del;

struct event{
   int atas; 
   int id[max]; 
   string tgl[max];
   string nama[max]; 
   string jam[max];
   string tm[max];
}M;

void awal(){ M.atas = -1; }

int Kosong(){
      if (M.atas == -1)
         return 1;
      else
         return 0;
   }

int Penuh(){
   if (M.atas == max - 1)
      return 1;
   else 
      return 0;
}

void Ganti(){
   string cari;
   cout << "Masukan event yang dicari : ";
   fflush(stdin);
   getline(cin, cari);
    for (int i = 0; i < M.atas + 1; i++) {
      if (M.nama[i] == cari) {
         cout << "ID EVENT             : " << M.id[i] << endl;
         cout << "NAMA EVENT           : " << M.nama[i] << endl;
         cout << "TEMPAT EVENT         : " << M.tm[i] << endl;
         cout << "Masukkan Tanggal Baru: "; getline(cin, M.tgl[i]);
         cout << "Masukkan Jam Baru    : "; getline(cin, M.jam[i]);
      }
   }
}

void input(int id, string nama, string tm, string tgl, string jam){
   if (Kosong() == 1 || Penuh() == 0) {
      M.atas++;
      M.id[M.atas] = id;
      M.nama[M.atas] = nama;
      M.tgl[M.atas] = tgl;
      M.jam[M.atas] = jam;
      M.tm[M.atas] = tm; 
      cout << "Data " << M.id[M.atas] << " telah di simpan!\n";
   } else 
      cout << "Penyimpanan Data Penuh!";
}

void hapus(){ 
   if (Kosong() == 0) { 
      cout << "Data event teratas telah dihapus"; 
      M.atas--;
   } else 
      cout << "Data kosong";
}

void tampil(){
   if (Kosong() == 0) {
      for (int i = M.atas; i >= 0; i--) {
         cout << "\n Event ke " << i + 1 << " : " << endl;
         cout << "\tNama EVENT      : " << M.nama[i] << endl; 
         cout << "\tID EVENT        : " << M.id[i] << endl; 
         cout << "\tTempat EVENT    : " << M.tm[i] << endl; 
         cout << "\tTanggal EVENT   : " << M.tgl[i] << endl; 
         cout << "\tJam EVENT       : " << M.jam[i] << endl;  
      }
   } else 
      cout << "Data kosong"; 
}

void sort() { 
   int i, j, temp1; 
   string temp2,temp3, temp4, temp5; 


   for(i = 1; i < n; i++){
   	  for (j = n - 1; j >= i; j--) { 
         if (M.nama[j] < M.nama[j - 1]){ 
			
            temp2 = M.nama[j];
            M.nama[j] = M.nama[j - 1];
            M.nama[j - 1] = temp2;
            
			temp1 = M.id[j];
			M.id[j] = M.id[j-1];
            M.id[j-1] = temp1;
				
            temp3 = M.jam[j];
            M.jam[j] = M.jam[j-1];
           	M.jam[j-1] = temp3;
           		
			temp4 = M.tm[j];
        	M.tm[j] = M.tm[j-1];
        	M.tm[j-1] = temp4;
			
            temp5 = M.tgl[j];
           	M.tgl[j] = M.tgl[j-1];
           	M.tgl[j-1] = temp5;            
         }
   	   }
	}
   cout << "Data setelah diurutkan berdasarkan nama = " << endl;
   tampil();
}

void masuklah() {
   int pil, id[max];
   string nama[max], tm[max],tgl[max],jam[max];
   awal();
   do {
      cout << ("/////////////////////////////////////////////////////////////") << endl;
      cout << ("//                   Menu Membuat Tiket                    //") << endl;
      cout << ("/////////////////////////////////////////////////////////////") << endl;
      cout << ("//   [1] Masukkan Event         [2] Kembali                //") << endl;
      cout << ("/////////////////////////////////////////////////////////////") << endl;
      cout << ("Select Menu: ");
      cin >> pil;
      switch (pil) {

      case 1:
         cout << "Masukan banyak event max[100] : ";
         cin >> n;
         for (int i = 0; i < n; i++) {
            cout << "Masukan ID Event        = ";
            cin >> id[i];
            cout << "Masukan Nama Event      = ";
            fflush(stdin);
            getline(cin, nama[i]);
            cout << "Masukan Tempat Event    = ";
            fflush(stdin);
            getline(cin, tm[i]);
            cout << "Masukan Tanggal Event   = ";
            fflush(stdin);
            getline(cin, tgl[i]);
            cout << "Masukan Jam Event       = ";
            fflush(stdin);
            getline(cin,jam[i]);
            
               input(id[i], nama[i], tm[i], tgl[i], jam[i]);
         }
         break;
      case 2:
         cout<<"Back to Menu..";
      }
      getchar();
      cout << endl;
      cout << endl;
      system("pause");
      system("cls");   
   }while (pil != 2);
}

void buat_baru(){
   baru = new(node);
   cout<<"Masukkan ID Sponsor : ";cin>>baru->idsponsor;
   cout<<"Masukkan Nama Sponsor : ";fflush(stdin);getline(cin, baru->nama);
   cout<<"Masukkan Tempat Sponsor : ";fflush(stdin);getline(cin, baru->tempat);
   cout<<"\n\t---Data telah dimasukkan---";
   cout<<"\n\nPRESS ENTER TO CONTINUE...";
   getch();
   baru->prev=NULL;
   baru->next=NULL;
}

void insert_data(){
   buat_baru();
   if(head==NULL){
      head=baru;
      tail=baru;
   }else{
      baru->next=head;
      head=baru;
   }
   cout<<endl<<endl;
}

void hapus_data(){
   int hapus,idsponsor;
   if(head==NULL){
      cout<<"\nLinked List kosong, \nPenghapusan tidak dapat dilakukan"<<endl;
   }else{
      cout<<"\nSponsor Terbaru Telah Dihapus "<<endl;
      del = head;
      head = head->next;
      delete del;
   }
}

void cetak_data(){
   if (head==NULL)
      cout<<"\nData tidak dapat ditemukan!"<<endl;
   else{
      help=head;
      while(help!=NULL){
      	cout<<"\n ID Sponsor : "<<help->idsponsor;
      	cout<<"\n Nama Sponsor : "<<help->nama;
      	cout<<"\n Tempat Sponsor : "<<help->tempat;
      	help=help->next;
      	
      }
   } 
   getch();
}

void sponsor(){
    int pil;
      do{
      cout << ("//////////////////////////////////////////////////////////////") << endl;
      cout << ("//                 Sponsor Event                            //") << endl;
      cout << ("//////////////////////////////////////////////////////////////") << endl;
      cout << ("//  [1] Tambah Sponsor [2] Hapus Sponsor   [3] Lihat Sponsor//") << endl;
      cout << ("//                     [4] Back                             //") << endl;
      cout << ("//////////////////////////////////////////////////////////////") << endl;
      cin >> pil;
      switch (pil) {
      case 1:
        insert_data();
          break;
      case 2:
        hapus_data();
          break;
      case 3:
        cetak_data();
         break;
      case 4:
        cout<<"Back to Menu..";
         break;
      }
      getchar();
      cout << endl;
      cout << endl;
      system("pause");
      system("cls");
   }
   while (pil != 4);
}

void utama() {
   int pil;
   awal();
   do {
   cout << "=================== APLIKASI TIKET EVENT ===================" << endl;
   cout << "||                                                        ||" << endl;
   cout << "|| MENU UTAMA:                                            ||" << endl;
   cout << "||                                                        ||" << endl;
   cout << "||   [1] Buat Event Baru    [2] Tampilkan Event           ||" << endl;
   cout << "||   [3] Re-Schedule Event  [4] Batalkan Event            ||" << endl;
   cout << "||   [5] Sponsor Event      [6] Exit                      ||" << endl;
   cout << "||                                                        ||" << endl;
   cout << "============================================================" << endl;
      cin >> pil;
      switch (pil) {
      case 1:
         masuklah();
         break;
      case 2:
         sort();
         break;
      case 3:
      	 Ganti();
         break;
      case 4:
         hapus();
         break;
      case 5:
         sponsor();
         break;
      case 6:
         cout << "Terima Kasih";
      }
      getchar();
      cout << endl;
      cout << endl;
      system("pause");
      system("cls");
   }while (pil != 6);
}

int main() {
    utama(); 
      
}
