#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "mechanic.h"
#include "string.h"

POINT GateSpawnX (State *S){
    POINT P;
    if(Info(First(Area(*S)))==0 || Info(First(Area(*S)))==1){
        Absis(P)=(GetLastIdxBrs(Peta(*S)))-1;
        Ordinat(P)=NKolEff(Peta(*S))/2;
    }
    else if(Info(First(Area(*S)))==2 || Info(First(Area(*S)))==3){
        Absis(P)=1;
        Ordinat(P)=NKolEff(Peta(*S))/2;
    }
    return P;
}

POINT GateSpawnY (State *S){
    POINT P;
    if(Info(First(Area(*S)))==0 || Info(First(Area(*S)))==2){
        Absis(P)=NBrsEff(Peta(*S))/2;
        Ordinat(P)=(GetLastIdxKol(Peta(*S)))-1;
    }
    else if(Info(First(Area(*S)))==1 || Info(First(Area(*S)))==3){
        Absis(P)=NBrsEff(Peta(*S))/2;
        Ordinat(P)=GetFirstIdxKol(Peta(*S))+1;
    }
    return P;
}

/*
********
*      *
*      *
*      *
*/

void W(State *S){
	POINT P1, P2, P3;
    int lahan;
    lahan = Info(First(Area(*S)));
	P1=CopyP(Position(*S));
	P2=PlusDelta(P1,-1,0);
	P3=CopyP(Office(*S));

	if(NEQPOINT(P1, P3) || lahan != 0){
		if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='*' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='W' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='A'){
			printf("a\n");
            Position(*S)=P1;
		}
		else if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='-' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='O'){
			printf("b\n");
            Position(*S)=CopyP(P2);
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='-';
			Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
        }
		else if((Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='^')){
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='-';
            MoveMapUp(&Area(*S)); 
            P2=GateSpawnX(S);
            Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
			Position(*S)=CopyP(P2);
            			printf("c\n");
		}
	}
	else{
		if(Elmt(Peta(*S),Absis(P2),Ordinat(P2)) =='*' || Elmt(Peta(*S),Absis(P2),Ordinat(P2)) =='A'){
			Position(*S)=P1;
			printf("d\n");
		}
		else if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='-'){
			printf("e\n");
            Position(*S)=CopyP(P2);
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='O';
			Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
		}
		else if((Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='^')){
			printf("f\n");
            Elmt(Peta(*S),Absis(P1),Ordinat(P1))='O';
            MoveMapUp(&Area(*S)); 
            P2=GateSpawnX(S);
            Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
			Position(*S)=CopyP(P2);
		}
	}

    if (!Prep(*S)) {
        timeFlow(S,1);
    }
}

void A(State *S){
	POINT P1, P2, P3;
    int lahan;
    lahan = Info(First(Area(*S)));
	P1=Position(*S);
	P2=PlusDelta(P1,0,-1);
	P3=Office(*S);

	if(NEQPOINT(P1, P3) || lahan != 0){
		if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='*' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='W' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='A'){
			Position(*S)=P1;
		}
		else if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='-' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='O'){
			Position(*S)=P2;
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='-';
			Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
		}
		else if((Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='<')){
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='-';
            MoveMapLeft(&Area(*S));
            P2 = GateSpawnY(S);
            Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
            Position(*S)=P2;
		}
	}
	else{
		if(Elmt(Peta(*S),Absis(P2),Ordinat(P2)) =='*' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='A'){
			Position(*S)=P1;
		}
		else if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='-'){
			Position(*S)=P2;
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='O';
			Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
		}
		else if((Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='<')){
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='O';
            MoveMapLeft(&Area(*S));
            P2 = GateSpawnY(S);
            Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
            Position(*S)=P2;
		}
	}
    if (!Prep(*S)) {
        timeFlow(S,1);
    }
}

void Su(State *S){
	POINT P1, P2, P3;
    int lahan;
    lahan = Info(First(Area(*S)));
	P1=Position(*S);
	P2=NextX(P1);
	P3=Office(*S);

	if(NEQPOINT(P1, P3) || lahan != 0){
		if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='*' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='W' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='A'){
			Position(*S)=P1;
		}
		else if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='-' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='O'){
			Position(*S)=P2;
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='-';
			Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
		}
		else if((Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='V')){
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='-';
            MoveMapDown(&Area(*S)); 
            P2=GateSpawnX(S);
            Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
            Position(*S)=P2;
		}
	}
	else{
		if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='*' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='A'){
			Position(*S)=P1;
		}
		else if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='-'){
			Position(*S)=P2;
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='O';
			Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
		}
		else if((Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='V')){
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='O';
            MoveMapDown(&Area(*S)); 
            P2=GateSpawnX(S);
            Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
            Position(*S)=P2;
		}
	}
    if (!Prep(*S)) {
        timeFlow(S,1);
    }
}


void D(State *S){
	POINT P1, P2, P3;
    int lahan;
    lahan = Info(First(Area(*S)));
	P1=Position(*S);
	P2=NextY(P1);
	P3=Office(*S);


	if(NEQPOINT(P1, P3) || lahan != 0){
		if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='*' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='W' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='A'){
			Position(*S)=P1;
		}
		else if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='-' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='O'){
			Position(*S)=P2;
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='-';
			Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
		}
		else if((Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='>')){
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='-';
            MoveMapRight(&Area(*S));
            P2 = GateSpawnY(S);
            Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
			Position(*S)=P2;
		}
	}
	else{
		if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='*' || Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='A'){
			Position(*S)=P1;
		}
		else if(Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='-'){
			Position(*S)=P2;
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='O';
			Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
		}
		else if((Elmt(Peta(*S),Absis(P2),Ordinat(P2))=='>')){
			Elmt(Peta(*S),Absis(P1),Ordinat(P1))='O';
            MoveMapRight(&Area(*S));
            P2 = GateSpawnY(S);
            Elmt(Peta(*S),Absis(P2),Ordinat(P2))='P';
            Position(*S)=P2;
		}
	}
    if (!Prep(*S)) {
        timeFlow(S,1);
    }
}


void Build(State *S){
    int i, ID, quest,L, butuh_uang, butuh_waktu;
    boolean build;
    POINT P = MakePOINT(-1,-1);
    printf("Ingin membangun apa?\nList:\n");
	for(i=0; i< 10/*DataWahana(*S).length*/; i++){
		if(DataWahana(*S)[i].starter && DataWahana(*S)[i].nama.Length 
                && EQPOINT(DataWahana(*S)[i].position,P)){
			PrintKata(DataWahana(*S)[i].nama);			
			printf(" , ID : ");
			printf("%d",i);
			printf("\n");
		}
	}

	scanf("%d",&ID);

    if (!DataWahana(*S)[ID].starter || NEQPOINT(DataWahana(*S)[ID].position,P)) {
            printf("Invalid command\n");
            sleep(1);
            scanf("%c",&i);
            return;
        }

    build=true;
    i=0;
    while(build && i < 5){
        if(DataWahana(*S)[ID].bahan[i] > Storage(*S)[i].quantity){
            build=false;
        }
        else{
            i++;
        }
    }

    butuh_uang = MoneyNeeded(*S)+DataWahana(*S)[ID].harga;
    butuh_waktu = TimeNeeded(*S)+60; //TimeNeeded(*S)+=DataWahana(*S)[ID].time_needed;

    if (!IsPosisiEmpty(&PetaAddress(*S),Position(*S),DataWahana(*S)[ID].size)){
        printf("Tidak memungkinkan untuk membangun wahana di posisi ini.\n");
        printf("Wahana tidak boleh dibangun di-sekitar Office, Antrian, dan Dinding\n");
    
    } else if(butuh_waktu > Durasi(OpenTime(*S), CloseTime(*S))){
		printf("Anda tidak punya waktu cukup untuk menambah aksi ini\n");
		printf("Silahkan undo beberapa action jika ingin tetap melakukan aksi ini.");
	
    } else if(butuh_uang > Money(*S) ){
        printf("Jumlah uang tidak mencukupi. Silakan ulangi lagi!");
    
    } else if (!build) {
        printf("Bahan-bahan tidak cukup");
    
    } else if (IsFullStackt(Act(*S))) {
        printf("Kamu sudah terlalu banyak melakukan aksi untuk hari ini.\n");
        printf("Coba lagi esok hari.\n");
    
    } else {
        // update Prep[3]
        MoneyNeeded(*S)+=DataWahana(*S)[ID].harga;
		TimeNeeded(*S)+=60; //TimeNeeded(*S)+=DataWahana(*S)[ID].time_needed;
        TempActs(*S)++;

        // Update Data Wahana
        DataWahana(*S)[ID].history = AlokasiH(&DataWahana(*S)[ID]);
        DataWahana(*S)[ID].position = Position(*S);
        DataWahana(*S)[ID].income = 0;
        DataWahana(*S)[ID].income1 = 0;
        DataWahana(*S)[ID].count_used = 0;
        DataWahana(*S)[ID].count_used1 = 0;
        DataWahana(*S)[ID].broke = false;
        DataWahana(*S)[ID].lahan = Info(First(Area(*S)));

        ListWahana(*S)[NWahana(*S)] = &DataWahana(*S)[ID];
        NWahana(*S)++;

        for(i = 0; i < 5; i++) {
            Storage(*S)[i].quantity -= DataWahana(*S)[ID].bahan[i];
        }

        // gerak kiri satu langkah
        A(S);

        // Update pada Map
        setAddressMap(&PetaAddress(*S), &DataWahana(*S)[ID], DataWahana(*S)[ID].position);
        SetWahana(&Peta(*S), DataWahana(*S)[ID].position, DataWahana(*S)[ID].size);
        
        // Push ke Stack
        quest=ID*10+2;
        Push(&Act(*S), quest);	
		printf("Proses build tersimpan ke dalam stack to-do.");
	}
    sleep(1);
    scanf("%c",&i);
}


void Upgrade(State *S){
    POINT posisi_wahana;
    int ID, ID_kiri, ID_kanan, ID_pilih, i, butuh_uang, butuh_waktu;
    infostack quest;
    BinTree anak_kiri, anak_kanan;
    boolean build;

    posisi_wahana = NextY(Position(*S));
    
    if (!IsWahana(Peta(*S),posisi_wahana)) {
        printf("Tidak ada wahana apapun di samping kanan\n");
        sleep(1);
        return;
    }

    ID = getWahanaAt(&PetaAddress(*S),posisi_wahana).ID;
    
    if (IsOneElmt(DataWahana(*S)[ID].upgrade_tree)) {
        printf("Wahana di samping tidak bisa di-upgrade ke wahana apapun\n");
        sleep(1);
        return;
    }

    PrintTree(DataWahana(*S)[ID].upgrade_tree, 2);
    anak_kanan = Right(DataWahana(*S)[ID].upgrade_tree);
    anak_kiri = Left(DataWahana(*S)[ID].upgrade_tree);
    
    printf("\nIngin melakukan upgrade apa?\nList :\n");
    if (anak_kiri) {
        ID_kiri = Akar(anak_kiri);
        printf("- "); PrintKata(DataWahana(*S)[ID_kiri].nama);
        printf(" (ID : %d) ", ID_kiri); printf("\n");
    }
    if (anak_kanan) {
        ID_kanan = Akar(anak_kanan);
        printf("- "); PrintKata(DataWahana(*S)[ID_kanan].nama);
        printf(" (ID : %d) ", ID_kanan); printf("\n");
    }

    scanf("%d", &ID_pilih);
    scanf("%c", &i); // skip \n

    if (ID_pilih != ID_kiri && ID_pilih != ID_kanan) {
        printf("Input tidak valid\n");
        sleep(1);
        return;
    }

    build=true;
    i=0;
    while(build && i < 5){
        if(DataWahana(*S)[ID_pilih].bahan[i] > Storage(*S)[i].quantity){
            build=false;
        }
        else{
            i++;
        }
    }

    butuh_uang = MoneyNeeded(*S)+DataWahana(*S)[ID_pilih].uang;
    butuh_waktu = TimeNeeded(*S)+120;

    if(butuh_waktu > Durasi(OpenTime(*S), CloseTime(*S))){
		printf("Anda tidak punya waktu cukup untuk menambah aksi ini\n");
		printf("Silahkan undo beberapa action jika ingin tetap melakukan aksi ini.");
	
    } else if(butuh_uang > Money(*S) ){
        printf("Jumlah uang tidak mencukupi. Silakan ulangi lagi!");
    
    } else if (!build) {
        printf("Bahan-bahan tidak cukup");
    
    } else if (IsFullStackt(Act(*S))) {
        printf("Kamu sudah terlalu banyak melakukan aksi untuk hari ini.\n");
        printf("Coba lagi esok hari.\n");
    
    } else {

        // update Prep[3]
        MoneyNeeded(*S)+=DataWahana(*S)[ID_pilih].harga;
		TimeNeeded(*S)+=120; //TimeNeeded(*S)+=DataWahana(*S)[ID].time_needed;
        TempActs(*S)++;

        // Update Data Wahana
        DataWahana(*S)[ID_pilih].history = KonsB(DataWahana(*S)[ID].history, &DataWahana(*S)[ID_pilih]);
        DataWahana(*S)[ID_pilih].position = DataWahana(*S)[ID].position;
        DataWahana(*S)[ID_pilih].income = DataWahana(*S)[ID].income;
        DataWahana(*S)[ID_pilih].income1 = DataWahana(*S)[ID].income1;
        DataWahana(*S)[ID_pilih].count_used = DataWahana(*S)[ID].income;
        DataWahana(*S)[ID_pilih].count_used1 = DataWahana(*S)[ID].income1;
        DataWahana(*S)[ID_pilih].broke = false;
        DataWahana(*S)[ID].lahan = Info(First(Area(*S)));

        for(i = 0; i < 5; i++) {
            if (ListWahana(*S)[i]) {
                if ((*ListWahana(*S)[i]).ID == ID) {
                    ListWahana(*S)[i] = &DataWahana(*S)[ID_pilih];
                }
            }
        }

        for(i = 0; i < 5; i++) {
            Storage(*S)[i].quantity -= DataWahana(*S)[ID_pilih].bahan[i];
        }

        // Update pada Map
        setAddressMap(&PetaAddress(*S), &DataWahana(*S)[ID_pilih], DataWahana(*S)[ID].position);
        
        // Push ke Stack
        quest= ID_pilih*1000 + ID*10 + 3;
        Push(&Act(*S), quest);	
		printf("Proses upgrade tersimpan ke dalam stack to-do.");
    }
    sleep(1);
} 

void Buy(State *S){
	int i, N, ID, quest,butuh_uang, butuh_waktu;

    printf("Storage : \n");
    for(i=0; i<5;i++){
        PrintKata(Storage(*S)[i].nama); printf(" : ");
        printf("%d ", Storage(*S)[i].quantity);
    }

	printf("\nIngin membeli apa?\nList :\n");
    for(i=0; i<5;i++){
        printf("- "); PrintKata(Storage(*S)[i].nama); 
        printf(" (ID : %d) (%d / item)", i,Storage(*S)[i].harga);
        printf("\n");
    }

	printf("Format input : jumlah(spasi)id material\n");

	scanf("%d", &N);
    scanf("%d",&ID);

    if (ID > 4 || ID < 0) {
        printf("Invalid command\n");
        sleep(1);
        return;
    }

    butuh_uang = MoneyNeeded(*S) + Storage(*S)[ID].harga*N;
    butuh_waktu = TimeNeeded(*S) + 20;

	if (butuh_uang > Money(*S)){
		printf("Jumlah uang tidak mencukupi. Silakan ulangi lagi!");
	} else if (butuh_waktu > Durasi(OpenTime(*S), CloseTime(*S))){
        printf("Waktu tidak mencukupi. Silakan undo beberapa action jika ingin membeli item.");
    } else if(IsFullStackt(Act(*S))) {
        printf("Kamu sudah terlalu banyak melakukan aksi untuk hari ini.\n");
        printf("Coba lagi esok hari.\n");
    } else{
        // update Temp[3]
        TimeNeeded(*S) += 20;
        MoneyNeeded(*S)+=Storage(*S)[ID].harga*N;
        TempActs(*S)++;

        // update player
        Storage(*S)[ID].quantity += N;

        // update stack
        quest=(N*1000)+(ID*10)+1;
        Push(&Act(*S), quest);
        printf("Proses buy tersimpan dalam stack\n");
	}
    scanf("%c", &i);  // skip \n
    sleep(1);
}

void Undo(State * S){
    int quest;

    if (IsEmptyStackt(Act(*S))) {
        printf("Kamu belum melakukan apa-apa hari ini\n");
        sleep(1);
        return;
    }

    Pop(&Act(*S), &quest);
    if (quest % 10 == 1) {
        UnBuy(S,quest);
    } else if (quest % 10 == 2) {
        UnBuild(S,quest);
    } else if (quest % 10 == 3) {
        UnUpgrade(S,quest);
    }

}

void Main(State * S){
    address_c P;

    while(!IsEmptyStackt(Act(*S))) {
        Undo(S);
    }

    Time(*S) = OpenTime(*S);
    
    P = generateCustomer(S);
    InsertFirst(&DataCustomers(*S), P);
    Enqueue(&Antrian(*S), P);

    Prep(*S) = false;
    printf("\nEntering main phase...\n");
    sleep(1);
}


//********* Fungsi-Fungsi untuk command *************//
void Execute(State * S) {
/* I.S. user memberi command untuk Execute */
/* F.S. semua aksi yang disimpan pada stack sudah dieksekusi.*/
    Money(*S) -= MoneyNeeded(*S);

    CreateEmptyStackt(&Act(*S));

    Main(S);
}

void Serve(State * S) {
/* I.S. user memberi command untuk serve */
/* F.S. serve customer terdepan pada Antrian(S),.*/
    infoqueue P;
    int i,idwahana,choice,num;
    int daftarID[5];

    if (NEQPOINT(NextY(Position(*S)),LocAntrian(*S)) &&
        NEQPOINT(NextX(Position(*S)),LocAntrian(*S)) &&
        NEQPOINT(NextX(LocAntrian(*S)),Position(*S)) &&
        NEQPOINT(NextY(LocAntrian(*S)),Position(*S))) {
        printf("\nAnda tidak sedang berada di samping antrian!\n");
        sleep(1);
        return;
    }

    // Ambil informasi customer terdepan
    P = InfoHead(Antrian(*S));

    printf("// Daftar wahana yang dapat di-serve //\n\n");

    num = 0;
    for(i = 0; i < 5; i++) {
        idwahana = Play(P,i);
        if (idwahana != -1) {
            daftarID[num] = idwahana;
            num++;
            printf("%d. ", num);
            PrintKata(DataWahana(*S)[idwahana].nama);
            printf("\n");
        }
    }
    
    printf("Masukkan pilihan: ");
    scanf("%d", &choice);
    scanf("%c", &i); // skip \n

    if (!isBetween(choice,1,num)) {
        printf("\nInvalid command. \n");
        sleep(1);
        return;
    }

    choice--;
    idwahana = daftarID[choice];
    
    // jika berhasil wahana yang dipilih user adalah DataWahana(*S)[idwahana]
    // jika wahana rusak
    if (DataWahana(*S)[idwahana].broke) {
        printf("\n// Gagal melayani pengunjung, wahana sedang rusak //\n");
        sleep(1);
        return;
    }

    // jika wahana full
    if (IsWahanaFull(&(DataWahana(*S)[idwahana]))) {
        printf("// Gagal melayani pengunjung, wahana sudah penuh //\n");
        sleep(1);
        return;
    }

    // jika wahana tidak penuh dan tidak rusak, maka berhasil melayani customer
    Money(*S) += DataWahana(*S)[idwahana].harga;

    // jumlah orang pada wahana tersebut akan bertambah    
    DataWahana(*S)[idwahana].banyak_orang++;

    // pendapatan yang tercatat akan bertambah
    DataWahana(*S)[idwahana].income += DataWahana(*S)[idwahana].harga;
    DataWahana(*S)[idwahana].income1 += DataWahana(*S)[idwahana].harga;
    
    // banyak pemakaian yang tercatat akan bertambah
    DataWahana(*S)[idwahana].count_used++;
    DataWahana(*S)[idwahana].count_used1++;

    // Pengunjung tersebut akan di-dequeue, lokasinya akan berpindah ke wahana
    Dequeue(&Antrian(*S),&P);
    Loc(P) = idwahana;
    Playtime(P) = DataWahana(*S)[idwahana].durasi; // waktu bermain customer akan di-set dengan durasi wahana
    Prio(P)--;  // prioritas pemain akan meningkat

    // wahana tersebut akan dihapus dari daftar wahana customer
    for(i = 0; i < 5; i++) {
        if (Play(P,i) == idwahana){
            Play(P,i) = -1;
        }
    }

    triggerBroke(&DataWahana(*S)[idwahana],S);  
    //  ada 10% chance wahana tersebut berubah menjadi rusak

    timeFlow(S,10);
}

void Repair(State * S) {
// I.S. user memberi command untuk repair
/* F.S. jika di sebelah kanan user terdapat wahana, 
        dan jika wahana tersebut rusak, dan jika uang user mencukupi, 
        wahana tersebut akan mulai reparation*/
    POINT posisi_wahana;
    address_w address_wahana_kanan;

    posisi_wahana = NextY(Position(*S));
    
    if (!IsWahana(Peta(*S),posisi_wahana)) {
        printf("\nTidak ada wahana apapun di samping kanan\n");
        sleep(1);
        return;
    }

    address_wahana_kanan = Elmt(PetaAddress(*S),Absis(posisi_wahana),Ordinat(posisi_wahana));

    if (!(*address_wahana_kanan).broke) {
        printf("\nwahana di samping kanan tidak rusak!\n");
        sleep(1);
        return;
    } 

    if (Money(*S) < (*address_wahana_kanan).harga_repair) {
        printf("\nUang tidak cukup!\n");
        sleep(1);
        return;
    }

    (*address_wahana_kanan).time_reparation = (*address_wahana_kanan).durasi_repair;
    Money(*S) -= (*address_wahana_kanan).harga_repair;
    timeFlow(S,5);  //  waktu yang diperlukan untuk memulai perbaikan wahana adalah 5 menit (opsional)
    printf("\n// Memperbaiki ");
    PrintKata((*address_wahana_kanan).nama);
    sleep(1);
}


void Detail(State * S) {
/* I.S. user memberi command untuk melihat detail wahana*/
/* F.S. jika di sebelah kanan user terdapat wahana, 
        akan ditampilkan detail dari wahana tersebut
        dan waktu akan bertambah sebanyak 2 menit (opsional)*/
    POINT posisi_wahana;
    Wahana wahana_kanan;

    posisi_wahana = NextY(Position(*S));
    
    if (!IsWahana(Peta(*S),posisi_wahana)) {
        printf("Tidak ada wahana apapun di samping kanan");
        sleep(1);
        return;
    }

    wahana_kanan = getWahanaAt(&PetaAddress(*S), posisi_wahana);

    printDetail(S,&wahana_kanan);
    timeFlow(S,5); // melihat detail membutuhkan waktu 5 menit. (opsional)
    sleep(1);
}


void OFFice(State * S) {
/* I.S. user memberi command untuk mengakses office */
/* F.S. jika user berada pada posisi office, akan ditampilkan antarmuka office
        selama di dalam office, user dapat memberi command Details, Report, Exit
        user akan terus berada di office hingga memberi command Exit*/
    char choice[12];
    int choice_w;
    boolean exit;

    if (NEQPOINT(Position(*S), Office(*S))) {
        printf("\n// Anda tidak sedang berada di Office! //\n");
        sleep(1);
        return;
    }
    
    printf("\n// Memasuki office mode //\n");
    sleep(1);

    exit = false;

    do {
        printf("Masukkan perintah (Details / Report / Exit):");
        fgets(choice, 12, stdin);
        if (strcmp(choice, "Details\n") == 0) {
            printListWahana(S); // tampilkan semua pilihan wahana
            scanf("%d", &choice_w);
            if (ListWahana(*S)[choice_w]) {
                printDetail(S,ListWahana(*S)[choice_w]);
                timeFlow(S,5); // melihat detail membutuhkan waktu 2 menit.
            } else {
                printf("Invalid Command.");
            }

        } else if (strcmp(choice, "Report\n") == 0) {
            printListWahana(S); // tampilkan semua pilihan wahana
            scanf("%d", &choice_w);
            if (ListWahana(*S)[choice_w]) {
                printReport(ListWahana(*S)[choice_w]);
                timeFlow(S,5); // melihat report membutuhkan waktu 2 menit.
            } else {
                printf("Invalid Command.");
            }

        } else if (strcmp(choice, "Exit\n") == 0) {
            exit = true;

        } else {
            printf("Invalid Command!");
        }
    } while (!exit);

    printf("Anda keluar dari Office.");
    sleep(1);
    scanf("%c", &choice); // skip \n
}   


void PrepP(State * S) {
    address_c P;
    int i;
    
    Day(*S)++;
    Time(*S) = CloseTime(*S);

    TempActs(*S) = 0;
    MoneyNeeded(*S) = 0;
    TimeNeeded(*S) = 0;

    // Reset harian wahana
    for(i = 0; i < NWahana(*S); i++){
        (*ListWahana(*S)[i]).banyak_orang = 0;
        (*ListWahana(*S)[i]).income1 = 0;
        (*ListWahana(*S)[i]).count_used1 = 0;
    }

    // Reset All Cutomer
    while (!IsEmpty(DataCustomers(*S))){
        DelFirst(&(DataCustomers(*S)), &P);
        Dealokasi(&P);
    }
    while (!IsEmptyQueue(Antrian(*S))){
        Dequeue(&Antrian(*S), &P);
    }

    Prep(*S) = true;
    printf("\nEntering Preparation phase...\n");
    sleep(1);
}


//********* Sub-Fungsi untuk Fungsi-fungsi Command *********//
// ****** Sub-Fungsi Undo ****** //
void UnBuy(State * S, infostack quest) {
    int ID;
    int N;

    ID = (quest / 10) % 100;
    N = quest / 1000;

    Storage(*S)[ID].quantity -= N;
    TempActs(*S)--;
    MoneyNeeded(*S) -= Storage(*S)[ID].harga * N;
    TimeNeeded(*S) -= 20;
}

void UnBuild(State * S, infostack quest) {
    int ID,i;
    
    ID = (quest / 10) % 100;

    RemoveWahana(&Peta(*S), DataWahana(*S)[ID].position, DataWahana(*S)[ID].size);
    RemoveAddress(&PetaAddress(*S), &DataWahana(*S)[ID]);

    DealokasiH(DataWahana(*S)[ID].history);
    DataWahana(*S)[ID].position = MakePOINT(-1,-1);

    for(i = 0; i < 5; i++) {
        Storage(*S)[i].quantity += DataWahana(*S)[ID].bahan[i];

        if (ListWahana(*S)[i]) {
            if ((*ListWahana(*S)[i]).ID == ID) {
                ListWahana(*S)[i] = Nil;
                NWahana(*S)--;
            }
        }
    }

    TempActs(*S)--;
    MoneyNeeded(*S) -= DataWahana(*S)[ID].uang;
    TimeNeeded(*S) -= 60;
}

void UnUpgrade(State * S, infostack quest) {
    int ID,i;
    ListHistory L;
    address_w address_wahana;

    ID = quest / 1000;

    L = DataWahana(*S)[ID].history;

    while (Next(Next(L)) != Nil) {
        L = Next(L);
    }
    // berhenti ketika Next(L) = node terakhir

    DealokasiH(Next(L));
    Next(L) = Nil;

    address_wahana = Info(L);

    setAddressMap(&PetaAddress(*S), address_wahana, address_wahana->position);

    DataWahana(*S)[ID].position = MakePOINT(-1,-1);

    for(i = 0; i < 5; i++) {
        Storage(*S)[i].quantity += DataWahana(*S)[ID].bahan[i];

        if (ListWahana(*S)[i]) {
            if ((*ListWahana(*S)[i]).ID == ID) {
                ListWahana(*S)[i] = address_wahana;
            }
        }
    }

    TempActs(*S)--;
    MoneyNeeded(*S) -= DataWahana(*S)[ID].uang;
    TimeNeeded(*S) -= 120;
}

// ****** Sub-Fungsi Execute ****** //
void ExecuteBuild(State * S, infostack quest) {

    // int ID;
    // address_w address_wahana_baru;

    // ID = (quest % 1000) / 10;
    // address_wahana_baru = &GetWahana(*S,ID);

    // ListWahana(*S)[NWahana(*S)] = address_wahana_baru;  //  add as last el
    // NWahana(*S)++;

    // setAddressMap(&PetaAddress(*S), address_wahana_baru, GetWahana(*S,ID).position);
}    

void ExecuteBuy(State * S, infostack quest) {
}

void ExecuteUpgrade(State * S, infostack quest) {
    
    int i;
    IdWahana ID,IDnext;  //  IDnext adalah ID wahana hasil upgrade
    address_w address_wahana;  //  address wahana hasil uprade.
    boolean choice;

    ID = (quest % 1000) / 10;

    choice = quest / 1000;
    IDnext = SearchSubPohon(GetWahana(*S,ID).upgrade_tree, ID, choice);

    address_wahana = &GetWahana(*S,IDnext);
    i = 0;
    while (i < NWahana(*S) && ListWahana(*S)[i]->ID != ID) {
        i++;
    }
    
    ListWahana(*S)[i] = address_wahana;
    setAddressMap(&PetaAddress(*S), address_wahana, GetWahana(*S,ID).position);

    GetWahana(*S,IDnext).history = KonsB(GetWahana(*S,ID).history,address_wahana);
}

//********** Fungsi-fungsi untuk Support ************//
boolean isBetween(int val, int lower, int upper) {
// true jika lower <= val <= upper
    return val >= lower && val <= upper;
}

void printListWahana(State * S) {
/* I.S. Sembarang */
/* F.S. Menampilkan semua nama wahana yang dimiliki pemain*/
    int i;
    
    printf("Daftar Wahana yang dimiliki : \n");
    
    for(i = 0; i < ((*S).NWahana); i++) {
        printf("%d. ", i+1);
        PrintKata(((*ListWahana(*S)[i])).nama); 
        printf(" ( ID : %d )", (*ListWahana(*S)[i]).ID); 
        printf("\n");
    }
}

void incrementTime(State * S) {
/* I.S. Sembarang */
/* F.S. Time(S) akan bertambah satu menit, dan semua proses lain akan dijalankan paralel */
    // waktu bertambah satu menit
    Time(*S) = NextMenit(Time(*S));

    // Proses SETIAP CUSTOMER
    ProcessAllCustomers(S);

    // Proses SETIAP WAHANA
    ProcessAllWahanas(S);
}


void timeFlow(State * S, int N) {
    // I.S. Sembarang
    // F.S. Time(S) akan bertambah sebanyak N menit
    int i;
    for(i=0; i<N; i++) {
        incrementTime(S);
    }
}


void ProcessAllCustomers(State * S) {
// I.S. Sembarang
/* F.S. Akan dilakukan proses terhadap semua customer dalam satu satuan waktu
        sehingga seolah-olah proses paralel 
        setelah proses semua cutomer, ada 16.7% chance generate customer*/
    // KAMUS
    int rand_num,count_play,chance;
    address_c P,Prec;
    boolean quit,masuk_antrian;
    
    // CEK SETIAP CUSTOMER
    P = First(DataCustomers(*S)); Prec = Nil;
    while (P != Nil) {
        quit = false;
        masuk_antrian = false;
        Playtime(P) -= 1;
        if (Playtime(P) == 0) {
            if (Loc(P) != -1) {  //  customer berada pada suatu wahana
                //  jika customer sudah tidak lagi memiliki daftar wahana 
                //  yang ingin dinaiki, atau jika antrian penuh,
                //  ia akan keluar
                count_play = PlayCount(P);  //  menghitung daftar wahana customer
                if (count_play == 0 || IsFullQueue(Antrian(*S))) {  
                    quit = true;
                } else {
                    Loc(P) = -1;
                    Playtime(P) = 10;
                    masuk_antrian = true;
                }
            } else {   //  customer berada pada antrian
                Kesabaran(P) -= 1;
                Prio(P) -= 1;
                ReSort(&Antrian(*S),P); // customer akan diposisikan ke urutan yang semestinya
                if (Kesabaran(P) == 0) {  //  jika kesabaran customer habis, ia akan keluar.
                    quit = true;
                } else {
                    Playtime(P) = 10;
                }
            }
        }

        if (masuk_antrian) {
            Enqueue(&Antrian(*S),P);
            Prec = P;
            P = Next(P);
        } else if (quit) {
            // jika berada pada antrian, customer akan di-dequeue
            if (Loc(P) == -1) {
                Dequeue(&Antrian(*S),&P);
            }
            if (P == First(DataCustomers(*S))) {
                DelFirst(&DataCustomers(*S), &P);
                Dealokasi(&P);
                P = First(DataCustomers(*S)); //  ke customer selanjutnya
            } else {
                DelAfter(&DataCustomers(*S), &P, Prec);
                Dealokasi(&P);
                Prec = P;
                P = Next(Prec); //  ke customer selanjutnya
            }
        } else {
            Prec = P;
            P = Next(P);  //  ke customer selanjutnya
        }
    }

    //  PADA KONDISI INI, P = Nil, Prec menunjukkan customer terakhir
    rand_num = Randomize(0,100);
    chance = 5 + Day(*S);
    if (chance > 16) {chance = 16;}

    printf("%d\n",rand_num);
    if (rand_num < chance) {  //  16.7 % chance for generate customer
        printf("BOOM!\n");
        P = generateCustomer(S);
        printf("BOOM!\n");
        if (P) {  //  if generate customer succes
            if (!IsEmpty(DataCustomers(*S))) {  //  jika list tidak kosong
                InsertAfter(&DataCustomers(*S), P, Prec);  // masukkan customer setelah Prec ke data
                Enqueue(&Antrian(*S), P);   //  masukkan customer ke antrian
            } else {
                InsertFirst(&DataCustomers(*S),P);
                Enqueue(&Antrian(*S),P);
            }
        }
        printf("BOOM!");
    }
}


void ProcessAllWahanas(State * S) {
// I.S. Sembarang
/* F.S. Akan dilakukan proses terhadap semua wahana dalam satu satuan waktu
        sehingga seolah-olah proses paralel */
    //  CEK SETIAP WAHANA
    int i;
    
    for(i=0; i<(*S).NWahana; i++) {
        if ((*ListWahana(*S)[i]).time_reparation != 0) {  // wahana sedang dalam perbaikan 
            (*ListWahana(*S)[i]).time_reparation -= 1;
            if ((*ListWahana(*S)[i]).time_reparation == 0) {  // jika wahana selesai diperbaiki
                (*ListWahana(*S)[i]).broke = false;
            }
        }
    }
}


address_c generateCustomer(State * S) {
/* I.S. Sembarang */
/* F.S. didatangkan seorang customer baru. 
    jika antrian sudah penuh, maka customer tersebut pulang lagi
    jika tidak penuh, maka customer akan tercatat di data_customer
    dan customer akan masuk antrian*/
    address_c P;
    int i;

    P = Alokasi();
    if (!P) {  //  jika alokasi gagal, langsung keluar tidak melakukan apa-apa
        return P;
    }

    if (IsFullQueue(Antrian(*S))) {  //  Jika Antrian penuh, langsung keluar
        Dealokasi(&P);               //  P di-dealokasi
        P = Nil;
        return P;
    }
    printf("Generating...\n");
    Prio(P) = 15;  //  priority default = 15 (opsional)
    Kesabaran(P) = 5;  //  kesabaran default = 5 (opsional)
    Loc(P) = -1;  //  langsung masuk antrian
    Playtime(P) = 10;  //  inisiasi waktu = 10(opsional)
    for(i = 0; i < 5; i++) {
        Play(P,i) = -1;
    }

    //  penentuan wahana yang ingin dinaiki customer, 
    //  lagi-lagi dengan RNG.
    RandomPlay(P,S);  

    return P;
}


void triggerBroke(address_w W, State * S) {
// I.S. seorang pengunjung baru saja berhasil dilayani
// F.S. ada kemungkinan wahana dengan address W menjadi rusak
    int rand_num;
    address_c P,Prec;

    rand_num = Randomize(0,10);
    if (rand_num < 1) { // 10% chance wahana broke
        (*W).broke = true;
        printf("\nPerhatian : Wahana ");
        PrintKata((*W).nama);
        printf(" rusak, harap segera perbaiki.\n");
        sleep(1);
    }

    if ((*W).broke) {
        //  Jika wahana rusak, maka akan dilakukan proses setiap customer
        //  Jika Antrian tidak penuh,
        //  untuk customer yg berada di wahana tersebut akan pindah ke Antrian
        //  Loc(P) berubah menjadi -1, dan di-enqueue
        //  Jika Antrian penuh, cutomer pulang.
        P = First(DataCustomers(*S));
        while (P != Nil) {
            if (Loc(P) == (*W).ID) {
                Loc(P) = -1;
                Prio(P)--;
                Playtime(P) = 10;
                if (!IsFullQueue(Antrian(*S))) {
                    Enqueue(&Antrian(*S),P);
                    Prec = P;
                    P = Next(P);
                } else {  //  jika antrian penuh, customer pulang.
                    if (P == First(DataCustomers(*S))) {
                        DelFirst(&DataCustomers(*S),&P);
                        Dealokasi(&P);
                        P = First(DataCustomers(*S));
                    } else {
                        DelAfter(&DataCustomers(*S),&P,Prec);
                        Dealokasi(&P);
                        Prec = P;
                        P = Next(P);
                    }
                }
            } else {
                Prec = P;
                P = Next(P);
            }
        }
    }
}

void PrintAntrian(State * S) {
    address_c P;
    int i,idx,j,ID,count,real_head;

    if (IsEmptyQueue(Antrian(*S))){
    }
    else{
        real_head = Head(Antrian(*S));
        P = InfoHead(Antrian(*S));
        do 
        {
            printf("  (");
            count = 0;
            for(j = 0; j < 5; j++) {
                ID = Play(P,j);
                if (ID != -1) {
                    if (count > 0) {
                        printf(", ");
                    }
                    PrintKata(DataWahana(*S)[ID].nama);
                    count++;
                }
            }
            printf(")");
            printf(" kesabaran : ");
            printf("%d", Kesabaran(P));  
            printf("\n");            
            Head(Antrian(*S)) = (Head(Antrian(*S)) + 1) % MaxEl(Antrian(*S));
            P = InfoHead(Antrian(*S));
        } while (Head(Antrian(*S)) != (Tail(Antrian(*S)) + 1) % MaxEl(Antrian(*S)));
    }
    Head(Antrian(*S)) = real_head;
}

/*
printf("  (");
            count = 0;
            for(j = 0; j < 5; j++) {
                ID = Play(P,j);
                if (ID != -1) {
                    if (count > 0) {
                        printf(", ");
                    }
                    PrintKata(DataWahana(*S)[ID].nama);
                    count++;
                }
            }
            printf(")");
            printf(" kesabaran : ");
            printf("%d", Kesabaran(P));  
            printf("\n");
*/

//********** Fungsi-fungsi RNG ***********//
int Randomize(int lower_bound, int upper_bound) {
// menghasilkan bilangan random antara lower_bound dan upper_bound
    return ((rand() % (upper_bound - lower_bound)) + lower_bound);
}


void RandomPlay(address_c P, State * S) {
// I.S. Sembarang
/* F.S. RNG for Play(P)*/
    int rand_num,i,nplay,j;
    boolean found;
    rand_num = Randomize(0,100);
    printf("test\n");
    // 50 % chance 1 wahana, 25 % chance 2 wahana
    // 13 % chance 3 wahana, 7 % chance 4 wahana
    // 5 % chance 5 wahana (opsional)
    if (rand_num < 50) {
        nplay = 1;
    } else if (rand_num < 75) {
        nplay = 2;
    } else if (rand_num < 88) {
        nplay = 3;
    } else if (rand_num < 95) {
        nplay = 4;
    } else {
        nplay = 5;
    }
    printf("test\n");

    if (nplay > NWahana(*S)) { 
        nplay = NWahana(*S);
    }
    printf("test\n");

    i = 0;
    while (i < nplay) {
        rand_num = Randomize(0,NWahana(*S));
        if (ListWahana(*S)[rand_num]) 
        {
            found = false;
            j = 0;
            while (Play(P,j) != -1 && !found) 
            {
                if (Play(P,j) == (*ListWahana(*S)[rand_num]).ID) {
                    found = true;
                }
                j++;
            }
            if (!found){
                Play(P,j) = (*ListWahana(*S)[rand_num]).ID;
                i++;
            }
        }
    }
    printf("test\n");

}